// ライブラリのページを、タイトル・パス・docs の本文で検索する
// 空白で区切った語をすべて含むページを、タイトルに含むもの、パスに含むもの、本文に含むものの順に並べる
(function () {
    'use strict';
    const root = document.getElementById('site-search');
    if (!root) return;
    const input = root.querySelector('input');
    const list = root.querySelector('ul');
    const MAX_RESULTS = 20;
    const SNIPPET_RADIUS = 40;

    // 全角・半角と大文字・小文字の違いを無視して比べる
    const normalize = (s) => s.normalize('NFKC').toLowerCase();

    // 本文をテキストにする。HTML に変換済みならタグを取り除き、Markdown なら記法 (リンク、コード、見出しなど) を取り除く
    const plainText = (s) =>
        (/<\/[a-z]/i.test(s) ? new DOMParser().parseFromString(s, 'text/html').body.textContent : s)
            .replace(/\[([^\]]*)\]\([^)]*\)/g, '$1')
            .replace(/```\w*/g, ' ')
            .replace(/[`*#|]/g, ' ')
            .replace(/-{3,}/g, ' ')
            .replace(/\s+/g, ' ')
            .trim();

    let pages = null;
    let loading = null;
    let active = -1;

    function load() {
        if (!loading) {
            loading = fetch(root.dataset.index)
                .then((res) => res.json())
                .then((data) => {
                    pages = data.map((p) => {
                        const text = plainText(p.text);
                        return { ...p, text, keyTitle: normalize(p.title), keyPath: normalize(p.path), keyText: normalize(text) };
                    });
                });
        }
        return loading;
    }

    function search(query) {
        const terms = normalize(query).split(/\s+/).filter((t) => t.length > 0);
        if (terms.length === 0) return [];
        const res = [];
        for (const p of pages) {
            let score = 0;
            let found = true;
            for (const t of terms) {
                if (p.keyTitle.includes(t)) {
                    score += 100;
                } else if (p.keyPath.includes(t)) {
                    score += 10;
                } else if (p.keyText.includes(t)) {
                    score += 1;
                } else {
                    found = false;
                    break;
                }
            }
            if (found) res.push({ page: p, score, terms });
        }
        res.sort((a, b) => b.score - a.score || a.page.path.localeCompare(b.page.path));
        return res.slice(0, MAX_RESULTS);
    }

    // text の中の terms を <mark> で囲んで el に追加する
    function appendHighlighted(el, text, terms) {
        const key = normalize(text);
        // NFKC で長さが変わる文字があるとずれるので、そのときは強調しない
        if (key.length !== text.length) {
            el.append(text);
            return;
        }
        let pos = 0;
        while (pos < text.length) {
            let best = -1;
            let len = 0;
            for (const t of terms) {
                const i = key.indexOf(t, pos);
                if (i !== -1 && (best === -1 || i < best || (i === best && t.length > len))) {
                    best = i;
                    len = t.length;
                }
            }
            if (best === -1) break;
            el.append(text.slice(pos, best));
            const mark = document.createElement('mark');
            mark.textContent = text.slice(best, best + len);
            el.append(mark);
            pos = best + len;
        }
        el.append(text.slice(pos));
    }

    // 本文で最初に語が現れるあたりを切り出す
    function snippet(p, terms) {
        let first = -1;
        for (const t of terms) {
            const i = p.keyText.indexOf(t);
            if (i !== -1 && (first === -1 || i < first)) first = i;
        }
        if (first === -1) return p.text.slice(0, SNIPPET_RADIUS * 2) + (p.text.length > SNIPPET_RADIUS * 2 ? '…' : '');
        const l = Math.max(0, first - SNIPPET_RADIUS);
        const r = Math.min(p.text.length, first + SNIPPET_RADIUS);
        return (l > 0 ? '…' : '') + p.text.slice(l, r) + (r < p.text.length ? '…' : '');
    }

    function setActive(i) {
        const items = list.children;
        if (active >= 0 && active < items.length) items[active].classList.remove('active');
        active = i;
        if (active >= 0 && active < items.length) {
            items[active].classList.add('active');
            items[active].scrollIntoView({ block: 'nearest' });
        }
    }

    function render() {
        list.replaceChildren();
        active = -1;
        const query = input.value;
        if (!pages || query.trim() === '') {
            list.hidden = true;
            return;
        }
        const results = search(query);
        if (results.length === 0) {
            const li = document.createElement('li');
            li.textContent = '見つかりませんでした';
            list.append(li);
        }
        for (const { page, terms } of results) {
            const li = document.createElement('li');
            const a = document.createElement('a');
            a.href = page.url;
            appendHighlighted(a, page.title, terms);
            if (page.title !== page.path) {
                a.append(' ');
                const small = document.createElement('small');
                small.append('(');
                appendHighlighted(small, page.path, terms);
                small.append(')');
                a.append(small);
            }
            li.append(a);
            const p = document.createElement('p');
            appendHighlighted(p, snippet(page, terms), terms);
            li.append(p);
            list.append(li);
        }
        list.hidden = false;
    }

    input.addEventListener('focus', load);
    input.addEventListener('input', () => load().then(render));
    input.addEventListener('keydown', (e) => {
        const links = list.querySelectorAll('a');
        if (e.key === 'ArrowDown' && links.length > 0) {
            e.preventDefault();
            setActive((active + 1) % links.length);
        } else if (e.key === 'ArrowUp' && links.length > 0) {
            e.preventDefault();
            setActive((active - 1 + links.length) % links.length);
        } else if (e.key === 'Enter' && links.length > 0) {
            e.preventDefault();
            location.href = links[Math.max(active, 0)].href;
        } else if (e.key === 'Escape') {
            input.value = '';
            render();
            input.blur();
        }
    });

    // 入力欄の外で / を押すと検索ボックスに移る
    document.addEventListener('keydown', (e) => {
        if (e.key !== '/' || e.ctrlKey || e.metaKey || e.altKey) return;
        const tag = document.activeElement && document.activeElement.tagName;
        if (tag === 'INPUT' || tag === 'TEXTAREA' || (document.activeElement && document.activeElement.isContentEditable)) return;
        e.preventDefault();
        input.focus();
    });
})();
