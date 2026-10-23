# エージェント向けの注意

## push の前に

`main` に push すると CI の verify が走り、終わると auto-verifier が `.verify-helper/timestamps.remote.json` を更新するコミット (`[auto-verifier] verify commit ...`) を `origin/main` に積む。手元はたいていその分遅れているので、push の前に毎回確かめる。

```sh
git fetch
git log --oneline main..origin/main
```

auto-verifier のコミットだけなら `git rebase origin/main` してから push する。それ以外のコミットがあれば、rebase する前に中身を確かめる。
