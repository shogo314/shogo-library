---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/grid-graph.hpp
    title: "\u6587\u5B57\u5217\u76E4\u9762\u306E\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\
      \u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path.hpp
    title: "\u6700\u77ED\u8DEF"
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Grid"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/graph/grid-graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 2 \"src/graph/grid-graph.hpp\"\n\n/**\n * @file grid-graph.hpp\n * @brief \u6587\
    \u5B57\u5217\u76E4\u9762\u304B\u3089\u4F5C\u308B\u30B0\u30EA\u30C3\u30C9\u30B0\
    \u30E9\u30D5\n */\n\n#include <cassert>\n#include <cstddef>\n#include <iterator>\n\
    #include <string>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/utility/range.hpp\"\
    \n\n/**\n * @file range.hpp\n * @brief Python \u306E range \u306E\u3088\u3046\u306A\
    \u6574\u6570\u5217\u3068\u3001\u305D\u306E\u76F4\u7A4D\u306E Grid\n */\n\n#line\
    \ 12 \"src/utility/range.hpp\"\n#include <type_traits>\n#line 15 \"src/utility/range.hpp\"\
    \n\nstruct Range {\n   public:\n    using value_type = long long;\n    using const_reference\
    \ = value_type;\n    using size_type = long long;\n    using difference_type =\
    \ std::ptrdiff_t;\n\n    const value_type start;\n    const value_type stop;\n\
    \    const value_type step;\n\n   private:\n    const value_type norm_stop;\n\n\
    \    constexpr static value_type normalize(value_type _start, value_type _stop,\
    \ value_type _step) {\n        assert(_step != 0);\n        if (_step > 0) {\n\
    \            if (_start >= _stop) {\n                return _start;\n        \
    \    } else {\n                return _start + (_stop - _start + _step - 1) /\
    \ _step * _step;\n            }\n        } else {\n            if (_start <= _stop)\
    \ {\n                return _start;\n            } else {\n                return\
    \ _start - (_start - _stop - _step - 1) / _step * _step;\n            }\n    \
    \    }\n    }\n\n    constexpr Range(value_type _start, value_type _stop, value_type\
    \ _step, value_type _norm_stop)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(_norm_stop) {\n    }\n\n   public:\n    /**\n     * @brief start \u304B\
    \u3089 stop \u306E\u624B\u524D\u307E\u3067 step \u305A\u3064\u9032\u3080\u6574\
    \u6570\u5217\n     * @pre step != 0\n     */\n    constexpr Range(value_type _start,\
    \ value_type _stop, value_type _step)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(normalize(_start, _stop, _step)) {\n    }\n    constexpr Range(value_type\
    \ _start, value_type _stop)\n        : start(_start), stop(_stop), step(1), norm_stop(normalize(_start,\
    \ _stop, 1)) {}\n    explicit constexpr Range(value_type _stop)\n        : start(0),\
    \ stop(_stop), step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n\
    \        : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = void;\n\
    \        using reference = Range::const_reference;\n        using iterator_category\
    \ = std::random_access_iterator_tag;\n\n       private:\n        value_type first\
    \ = 0, stop = 0, step = 1, value = 0;\n\n        constexpr bool same_range(const\
    \ const_iterator& o) const noexcept {\n            return first == o.first &&\
    \ stop == o.stop && step == o.step;\n        }\n\n       public:\n        constexpr\
    \ const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Range& range, value_type value) noexcept\n            : first(range.start),\
    \ stop(range.stop), step(range.step), value(value) {}\n        constexpr reference\
    \ base() const noexcept {\n            return value;\n        }\n        constexpr\
    \ const_iterator& operator++() noexcept {\n            value += step;\n      \
    \      return *this;\n        }\n        constexpr const_iterator operator++(int)\
    \ noexcept {\n            const_iterator ret(*this);\n            value += step;\n\
    \            return ret;\n        }\n        constexpr const_iterator& operator+=(difference_type\
    \ _n) noexcept {\n            value += _n * step;\n            return *this;\n\
    \        }\n        constexpr friend const_iterator operator+(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret += _n;\n            return ret;\n        }\n        constexpr friend\
    \ const_iterator operator+(difference_type _n, const const_iterator& i) noexcept\
    \ {\n            const_iterator ret(i);\n            ret += _n;\n            return\
    \ ret;\n        }\n        constexpr const_iterator& operator--() noexcept {\n\
    \            value -= step;\n            return *this;\n        }\n        constexpr\
    \ const_iterator operator--(int) noexcept {\n            const_iterator ret(*this);\n\
    \            value -= step;\n            return ret;\n        }\n        constexpr\
    \ const_iterator& operator-=(difference_type _n) noexcept {\n            value\
    \ -= _n * step;\n            return *this;\n        }\n        constexpr friend\
    \ const_iterator operator-(const const_iterator& i, difference_type _n) noexcept\
    \ {\n            const_iterator ret(i);\n            ret -= _n;\n            return\
    \ ret;\n        }\n        constexpr reference operator[](difference_type i) const\
    \ noexcept { return value + i * step; }\n        constexpr reference operator*()\
    \ const noexcept {\n            return value;\n        }\n        constexpr friend\
    \ bool operator!=(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            return !a.same_range(b) || a.value != b.value;\n        }\n     \
    \   constexpr friend bool operator==(const const_iterator& a, const const_iterator&\
    \ b) noexcept {\n            return !(a != b);\n        }\n        constexpr friend\
    \ bool operator<(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            assert(a.same_range(b));\n            return a.step > 0 ? a.value\
    \ < b.value : a.value > b.value;\n        }\n        constexpr friend bool operator>(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return b < a; }\n   \
    \     constexpr friend bool operator<=(const const_iterator& a, const const_iterator&\
    \ b) noexcept { return !(b < a); }\n        constexpr friend bool operator>=(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return !(a < b); }\n\
    \        constexpr friend difference_type operator-(const const_iterator& a, const\
    \ const_iterator& b) {\n            assert(a.same_range(b));\n            if (a.step\
    \ > 0) {\n                return (a.value - b.value) / a.step;\n            }\
    \ else {\n                return (b.value - a.value) / (-a.step);\n          \
    \  }\n        }\n    };\n\n    constexpr const_iterator begin() const noexcept\
    \ {\n        return {*this, start};\n    }\n    constexpr const_iterator end()\
    \ const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n     *\
    \ @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr size_type count(value_type\
    \ x) const noexcept {\n        // step \u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    \u306B\u5206\u304B\u3089\u306A\u3044\u3068\u304D\u3082\u3001\u3088\u304F\u4F7F\
    \u3046 step = 1 \u3067\u306F\u5272\u308A\u7B97\u3092\u3057\u306A\u3044\n     \
    \   if (step == 1) return start <= x && x < stop;\n        if (step > 0) {\n \
    \           if (start <= x && x < stop) {\n                if ((x - start) % step\
    \ == 0) {\n                    return 1;\n                }\n            }\n \
    \       } else {\n            if (stop < x && x <= start) {\n                if\
    \ ((start - x) % (-step) == 0) {\n                    return 1;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n    /**\n     * @brief\
    \ x \u304C\u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(value_type\
    \ x) const noexcept {\n        return count(x) != 0;\n    }\n    /**\n     * @brief\
    \ x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * x \u304C\u542B\u307E\u308C\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(value_type\
    \ x) const {\n        assert(contains(x));\n        if (step == 1) return x -\
    \ start;\n        return (x - start) / step;\n    }\n    /**\n     * @brief \u8981\
    \u7D20\u304C x \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * x \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068 end() \u3092\u8FD4\u3059\n     */\n    constexpr const_iterator\
    \ find(value_type x) const noexcept {\n        if (contains(x)) {\n          \
    \  return {*this, x};\n        } else {\n            return {*this, norm_stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u4EE5\u4E0A\u306E\
    \u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * step > 0 \u3058\u3083\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr const_iterator lower_bound(value_type\
    \ x) const {\n        assert(step > 0);\n        if (norm_stop <= x) {\n     \
    \       return end();\n        } else if (x < start) {\n            return begin();\n\
    \        } else {\n            return {*this, start + (x - start + step - 1) /\
    \ step * step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x\
    \ \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n\
    \    constexpr const_iterator upper_bound(value_type x) const {\n        assert(step\
    \ > 0);\n        if (norm_stop <= x) {\n            return end();\n        } else\
    \ if (x < start) {\n            return begin();\n        } else {\n          \
    \  return {*this, start + (x - start + step) / step * step};\n        }\n    }\n\
    \    /**\n     * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u8981\u7D20\u6570\n   \
    \  */\n    constexpr size_type size() const noexcept {\n        if (step > 0)\
    \ {\n            return (norm_stop - start) / step;\n        } else {\n      \
    \      return (start - norm_stop) / (-step);\n        }\n    }\n    constexpr\
    \ value_type at(size_type i) const {\n        assert(0 <= i && i < size());\n\
    \        return start + i * step;\n    }\n    constexpr value_type operator[](size_type\
    \ i) const {\n        return at(i);\n    }\n    constexpr bool empty() const noexcept\
    \ {\n        return start == norm_stop;\n    }\n    constexpr value_type sum()\
    \ const noexcept {\n        return size() * (norm_stop - step + start) / 2;\n\
    \    }\n    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\u30A8\
    \u30E9\u30FC\n     */\n    constexpr value_type min() const {\n        assert(!empty());\n\
    \        if (step > 0) {\n            return start;\n        } else {\n      \
    \      return norm_stop - step;\n        }\n    }\n    /**\n     * @brief \u6700\
    \u5927\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ value_type max() const {\n        assert(!empty());\n        if (step > 0) {\n\
    \            return norm_stop - step;\n        } else {\n            return start;\n\
    \        }\n    }\n    /**\n     * @brief \u7DCF xor\n     * \u8CA0\u3092\u542B\
    \u3080\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr value_type product_xor()\
    \ const noexcept {\n        if (empty()) return 0;\n        assert(min() >= 0);\n\
    \        Range sorted_range(sorted());\n        value_type res = 0;\n        std::make_unsigned_t<value_type>\
    \ t = 1;\n        while (t <= static_cast<std::make_unsigned_t<value_type>>(max()))\
    \ {\n            std::make_unsigned_t<value_type> tmp = 0, n = size(), m = t,\
    \ a = sorted_range.step, b = sorted_range.start;\n            while (true) {\n\
    \                if (a >= m) {\n                    tmp += n * (n - 1) / 2 * (a\
    \ / m);\n                    a %= m;\n                }\n                if (b\
    \ >= m) {\n                    tmp += n * (b / m);\n                    b %= m;\n\
    \                }\n                std::make_unsigned_t<value_type> y_max = a\
    \ * n + b;\n                if (y_max < m) break;\n                n = y_max /\
    \ m;\n                b = y_max % m;\n                std::swap(m, a);\n     \
    \       }\n            if (tmp % 2 == 1) {\n                res += t;\n      \
    \      }\n            t <<= 1;\n        }\n        return res;\n    }\n    /**\n\
    \     * @brief \u9006\u9806\u306B\u3057\u305F\u3082\u306E\n     */\n    constexpr\
    \ Range reversed() const noexcept {\n        return {norm_stop - step, start -\
    \ step, -step, start - step};\n    }\n    /**\n     * @brief step > 0 \u3060\u3068\
    \u305D\u306E\u307E\u307E step < 0 \u3060\u3068\u9006\u9806\u306B\u3057\u305F\u3082\
    \u306E\n     */\n    constexpr Range sorted() const noexcept {\n        if (step\
    \ > 0) {\n            return {start, norm_stop, step, norm_stop};\n        } else\
    \ {\n            return {norm_stop - step, start - step, -step, start - step};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C [l, r) \u3067\u3042\
    \u308B\u7BC4\u56F2\u3092\u8FD4\u3059\n     */\n    constexpr Range clipped(value_type\
    \ l, value_type r) const {\n        if (l >= r) return {};\n        r--;  // \u4EE5\
    \u4E0B\u3067\u306F r \u3092\u542B\u3080 [l, r] \u3068\u3057\u3066\u6271\u3046\n\
    \        if (step > 0) {\n            value_type _start = [&] {\n            \
    \    if (norm_stop <= l) {\n                    return norm_stop;\n          \
    \      } else if (l < start) {\n                    return start;\n          \
    \      } else {\n                    return start + (l - start + step - 1) / step\
    \ * step;\n                }\n            }();\n            value_type _stop =\
    \ [&] {\n                if (norm_stop <= r) {\n                    return norm_stop;\n\
    \                } else if (r < start) {\n                    return start;\n\
    \                } else {\n                    return start + (r - start + step)\
    \ / step * step;\n                }\n            }();\n            return {_start,\
    \ _stop, step, _stop};\n        } else {\n            value_type _start = [&]\
    \ {\n                if (start - step <= r) {\n                    return start;\n\
    \                } else if (r < norm_stop - step) {\n                    return\
    \ norm_stop;\n                } else {\n                    return norm_stop +\
    \ (r - norm_stop) / step * step;\n                }\n            }();\n      \
    \      value_type _stop = [&] {\n                if (start - step <= l) {\n  \
    \                  return start;\n                } else if (l < norm_stop - step)\
    \ {\n                    return norm_stop;\n                } else {\n       \
    \             return norm_stop + (l - norm_stop - 1) / step * step;\n        \
    \        }\n            }();\n            return {_start, _stop, step, _stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u3092 Range \u3067\u6307\
    \u5B9A\u3057\u305F\u30B3\u30F3\u30C6\u30CA\n     */\n    constexpr Range slice(const\
    \ Range& r) const {\n        if (r.empty()) return {};\n        if (r.max() <\
    \ 0) return {};\n        if (r.min() >= size()) return {};\n        Range trimmed_range(r.clipped(0,\
    \ size()));\n        if (trimmed_range.empty()) return {};\n        value_type\
    \ _step = step * trimmed_range.step;\n        value_type _start = at(trimmed_range.start);\n\
    \        value_type _stop = _start + _step * trimmed_range.size();\n        return\
    \ {_start, _stop, _step, _stop};\n    }\n\n    static std::string type_str() {\n\
    \        return \"Range\";\n    }\n    std::string initializer_str() const {\n\
    \        return \"{\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \"}\";\n    }\n    std::string repr() const\
    \ {\n        return \"Range(\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \")\";\n    }\n\n    std::vector<value_type>\
    \ to_vector() const {\n        std::vector<value_type> ret;\n        ret.reserve(size());\n\
    \        if (step > 0) {\n            for (value_type x = start; x < stop; x +=\
    \ step) {\n                ret.push_back(x);\n            }\n        } else {\n\
    \            for (value_type x = start; x > stop; x += step) {\n             \
    \   ret.push_back(x);\n            }\n        }\n        return ret;\n    }\n\
    \    constexpr friend bool operator==(const Range& a, const Range& b) noexcept\
    \ {\n        if (a.empty() && b.empty()) return true;\n        if (a.size() !=\
    \ b.size()) return false;\n        if (a.start != b.start) return false;\n   \
    \     if (a.size() == 1) return true;\n        if (a.step != b.step) return false;\n\
    \        return true;\n    }\n    constexpr friend bool operator!=(const Range&\
    \ a, const Range& b) noexcept {\n        return !(a == b);\n    }\n};\n\n/**\n\
    \ * @brief 2 \u3064\u306E Range \u306E\u76F4\u7A4D rows \xD7 cols\n * (i, j) \u3092\
    \ i \u306E\u6607\u9806\u3001\u540C\u3058 i \u3067\u306F j \u306E\u6607\u9806 (\u884C\
    \u512A\u5148) \u306B\u4E26\u3079\u305F\u3082\u306E\u3068\u3057\u3066\u6271\u3046\
    \n */\nstruct Grid {\n   public:\n    using value_type = std::pair<long long,\
    \ long long>;\n    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const Range rows;\n    const Range cols;\n\n   private:\n    const long\
    \ long width;  // cols.size() (index \u3084 at \u3067\u6BCE\u56DE\u5272\u308A\u7B97\
    \u3057\u306A\u3044\u3088\u3046\u306B\u6301\u3063\u3066\u304A\u304F)\n\n   public:\n\
    \    /**\n     * @brief [0, h) \xD7 [0, w)\n     */\n    constexpr Grid(long long\
    \ h, long long w) : rows(h), cols(w), width(cols.size()) {}\n    constexpr Grid(const\
    \ Range& _rows, const Range& _cols) : rows(_rows), cols(_cols), width(cols.size())\
    \ {}\n    constexpr Grid(const Grid& o) = default;\n    Grid& operator=(const\
    \ Grid& o) = delete;\n\n    struct const_iterator {\n       public:\n        using\
    \ difference_type = Grid::difference_type;\n        using value_type = Grid::value_type;\n\
    \        using pointer = void;\n        using reference = value_type;\n      \
    \  using iterator_category = std::forward_iterator_tag;\n\n       private:\n \
    \       const Grid* rect = nullptr;\n        long long w = 0;   // cols.size()\n\
    \        long long ic = 0;  // rows \u306E\u4F55\u756A\u76EE\u304B\n        long\
    \ long jc = 0;  // cols \u306E\u4F55\u756A\u76EE\u304B\n\n       public:\n   \
    \     constexpr const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Grid* _rect, long long _w, long long _ic, long long _jc) noexcept\n        \
    \    : rect(_rect), w(_w), ic(_ic), jc(_jc) {}\n        constexpr value_type operator*()\
    \ const noexcept {\n            return {rect->rows.start + ic * rect->rows.step,\
    \ rect->cols.start + jc * rect->cols.step};\n        }\n        constexpr const_iterator&\
    \ operator++() noexcept {\n            if (++jc == w) {\n                jc =\
    \ 0;\n                ++ic;\n            }\n            return *this;\n      \
    \  }\n        constexpr const_iterator operator++(int) noexcept {\n          \
    \  const_iterator ret(*this);\n            ++*this;\n            return ret;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return a.ic == b.ic && a.jc\
    \ == b.jc;\n        }\n        constexpr friend bool operator!=(const const_iterator&\
    \ a, const const_iterator& b) noexcept {\n            return !(a == b);\n    \
    \    }\n    };\n\n    constexpr const_iterator begin() const noexcept {\n    \
    \    return {this, width, width == 0 ? rows.size() : 0, 0};\n    }\n    constexpr\
    \ const_iterator end() const noexcept {\n        return {this, width, rows.size(),\
    \ 0};\n    }\n    /**\n     * @brief \u8981\u7D20\u6570 rows.size() * cols.size()\n\
    \     */\n    constexpr size_type size() const noexcept {\n        return rows.size()\
    \ * width;\n    }\n    constexpr bool empty() const noexcept {\n        return\
    \ rows.empty() || cols.empty();\n    }\n    /**\n     * @brief (i, j) \u304C\u542B\
    \u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(long long i, long\
    \ long j) const noexcept {\n        return rows.contains(i) && cols.contains(j);\n\
    \    }\n    constexpr bool contains(const value_type& p) const noexcept {\n  \
    \      return contains(p.first, p.second);\n    }\n    /**\n     * @brief (i,\
    \ j) \u306E\u884C\u512A\u5148\u3067\u306E\u4F4D\u7F6E (\u30B0\u30EA\u30C3\u30C9\
    \u306E\u9802\u70B9\u756A\u53F7\u306B\u4F7F\u3046)\n     * (i, j) \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(long\
    \ long i, long long j) const {\n        assert(contains(i, j));\n        return\
    \ rows.index(i) * width + cols.index(j);\n    }\n    constexpr size_type index(const\
    \ value_type& p) const {\n        return index(p.first, p.second);\n    }\n  \
    \  /**\n     * @brief \u884C\u512A\u5148\u3067 k \u756A\u76EE\u306E\u8981\u7D20\
    \ (index \u306E\u9006)\n     */\n    constexpr value_type at(size_type k) const\
    \ {\n        assert(0 <= k && k < size());\n        return {rows[k / width], cols[k\
    \ % width]};\n    }\n    constexpr value_type operator[](size_type k) const {\n\
    \        return at(k);\n    }\n\n   private:\n    // \u8FD1\u508D\u306E\u65B9\u5411\
    \ (rows\u30FBcols \u306E\u4E2D\u3067\u306E\u4F4D\u7F6E\u306E\u5DEE) \u3092 Grid\
    \ \u306E\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5148\u982D 4 \u3064\u306F\
    \u4E0A\u4E0B\u5DE6\u53F3\u3060\u3051\u3092\u4E26\u3079\u305F\u5225\u306E\u8868\
    \n    // 4 \u8FD1\u508D\u3068 8 \u8FD1\u508D\u306E\u5883\u76EE\u304C\u5206\u304B\
    \u308B\u3088\u3046\u306B 2 \u884C\u306B\u5206\u3051\u3066\u3044\u308B\u306E\u3067\
    \u6574\u5F62\u3057\u306A\u3044\n    // clang-format off\n    static constexpr\
    \ int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0},\n            \
    \                                     {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,\
    \ 1}, {1, -1}, {1, 0}, {1, 1}};\n    // clang-format on\n\n   public:\n    /**\n\
    \     * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2\
    \ for \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Grid \u306B\u542B\
    \u307E\u308C\u308B\u65B9\u5411\u3092\u30D3\u30C3\u30C8\u3067\u6301\u3063\u3066\
    \u304A\u304D\u3001\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u9806\
    \u306B\u8FD4\u3059\n     */\n    struct Neighbors {\n        long long i, j, row_step,\
    \ col_step;\n        int first;      // neighbor_dirs[first + k] \u304C\u30D3\u30C3\
    \u30C8 k \u306E\u65B9\u5411\n        unsigned mask;  // Grid \u306B\u542B\u307E\
    \u308C\u308B\u65B9\u5411\n\n        struct iterator {\n            using difference_type\
    \ = std::ptrdiff_t;\n            using value_type = Grid::value_type;\n      \
    \      using pointer = void;\n            using reference = value_type;\n    \
    \        using iterator_category = std::forward_iterator_tag;\n\n            const\
    \ Neighbors* nb = nullptr;\n            unsigned rest = 0;  // \u307E\u3060\u8FD4\
    \u3057\u3066\u3044\u306A\u3044\u65B9\u5411\n\n            constexpr value_type\
    \ operator*() const noexcept {\n                const int k = nb->first + __builtin_ctz(rest);\n\
    \                return {nb->i + neighbor_dirs[k][0] * nb->row_step, nb->j + neighbor_dirs[k][1]\
    \ * nb->col_step};\n            }\n            constexpr iterator& operator++()\
    \ noexcept {\n                rest &= rest - 1;\n                return *this;\n\
    \            }\n            constexpr iterator operator++(int) noexcept {\n  \
    \              iterator ret(*this);\n                ++*this;\n              \
    \  return ret;\n            }\n            constexpr friend bool operator==(const\
    \ iterator& a, const iterator& b) noexcept { return a.rest == b.rest; }\n    \
    \        constexpr friend bool operator!=(const iterator& a, const iterator& b)\
    \ noexcept { return a.rest != b.rest; }\n        };\n        constexpr iterator\
    \ begin() const noexcept { return {this, mask}; }\n        constexpr iterator\
    \ end() const noexcept { return {this, 0}; }\n        constexpr long long size()\
    \ const noexcept { return __builtin_popcount(mask); }\n        constexpr bool\
    \ empty() const noexcept { return mask == 0; }\n    };\n\n   private:\n    constexpr\
    \ Neighbors neighbors(long long i, long long j, int first, int last) const {\n\
    \        assert(contains(i, j));\n        unsigned mask = 0;\n        for (int\
    \ k = first; k < last; k++) {\n            if (contains(i + neighbor_dirs[k][0]\
    \ * rows.step, j + neighbor_dirs[k][1] * cols.step)) mask |= 1u << (k - first);\n\
    \        }\n        return {i, j, rows.step, cols.step, first, mask};\n    }\n\
    \n   public:\n    /**\n     * @brief (i, j) \u306E\u4E0A\u4E0B\u5DE6\u53F3\u306E\
    \u3046\u3061 Grid \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\
    \u9806\u306B\u8FD4\u3059\n     * \u96A3\u306F rows\u30FBcols \u306E\u4E2D\u3067\
    \u96A3\u308A\u5408\u3046\u8981\u7D20 (i \xB1 rows.step \u306A\u3069)\u3002(i,\
    \ j) \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr Neighbors neighbors4(long long i, long long j) const {\n       \
    \ return neighbors(i, j, 0, 4);\n    }\n    constexpr Neighbors neighbors4(const\
    \ value_type& p) const {\n        return neighbors4(p.first, p.second);\n    }\n\
    \    /**\n     * @brief (i, j) \u3092\u56F2\u3080 8 \u3064\u306E\u3046\u3061 Grid\
    \ \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\u9806\u306B\
    \u8FD4\u3059\n     */\n    constexpr Neighbors neighbors8(long long i, long long\
    \ j) const {\n        return neighbors(i, j, 4, 12);\n    }\n    constexpr Neighbors\
    \ neighbors8(const value_type& p) const {\n        return neighbors8(p.first,\
    \ p.second);\n    }\n\n    static std::string type_str() {\n        return \"\
    Grid\";\n    }\n    std::string initializer_str() const {\n        return \"{\"\
    \ + rows.initializer_str() + \", \" + cols.initializer_str() + \"}\";\n    }\n\
    \    std::string repr() const {\n        return \"Grid(\" + rows.repr() + \",\
    \ \" + cols.repr() + \")\";\n    }\n\n    constexpr friend bool operator==(const\
    \ Grid& a, const Grid& b) noexcept {\n        if (a.empty() && b.empty()) return\
    \ true;\n        return a.rows == b.rows && a.cols == b.cols;\n    }\n    constexpr\
    \ friend bool operator!=(const Grid& a, const Grid& b) noexcept {\n        return\
    \ !(a == b);\n    }\n};\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n\
    \ * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\n#include\
    \ <iostream>\n#line 12 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u578B \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\
    \u548C\u3084\u672A\u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\
    \u306B\u304F\u3044\u3088\u3046\u306B)\n */\ntemplate <typename Cost = long long>\n\
    class Graph {\n   public:\n    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\
    \u9020\u4F53\n     *\n     * operator long long()\u3092\u5B9A\u7FA9\u3057\u3066\
    \u3044\u308B\u306E\u3067\u3001\u6574\u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\
    \u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\
    \u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\
    \u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\u304C\u3001\n   \
    \  * for (long long dst : g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\
    \u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\u308C\u308B\n   \
    \  */\n    struct Edge {\n        long long src = -1;  //!< \u59CB\u70B9\n   \
    \     long long dst = -1;  //!< \u7D42\u70B9\n        Cost cost = {};      //!<\
    \ \u30B3\u30B9\u30C8\n        long long id = -1;   //!< \u8FBA\u306E\u756A\u53F7\
    (\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\
    \u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C\
    2\u3064\u5B58\u5728\u3059\u308B)\n        Edge() = default;\n        Edge(long\
    \ long src, long long dst, Cost cost = 1, long long id = -1) : src(src), dst(dst),\
    \ cost(cost), id(id) {}\n        operator long long() const { return dst; }\n\
    \    };\n\n   private:\n    long long n;                       //!< \u9802\u70B9\
    \u6570\n    long long m;                       //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>>\
    \ g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\
    \n   public:\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n \
    \   /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u9802\u70B9\u6570\n     */\n    explicit Graph(long long n) : n(n), m(0),\
    \ g(n) {}\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long long size()\
    \ const { return n; }\n    /**\n     * @brief \u8FBA\u6570 (\u7121\u5411\u8FBA\
    \u306F 1 \u672C\u3068\u6570\u3048\u308B)\n     */\n    long long edge_count()\
    \ const { return m; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_edge(long long u, long long v, Cost w = 1) {\n        assert(0 <=\
    \ u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m});\n   \
    \     g[v].push_back({v, u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param\
    \ v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u3089\
    1\n     */\n    void add_directed_edge(long long u, long long v, Cost w = 1) {\n\
    \        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\
    \u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\
    \u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\
    \u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089\
    false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(long\
    \ long m, long long padding = -1, bool weighted = false, bool directed = false)\
    \ {\n        for (long long i = 0; i < m; i++) {\n            long long u, v;\n\
    \            std::cin >> u >> v;\n            u += padding, v += padding;\n  \
    \          Cost c(1);\n            if (weighted)\n                std::cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(u, v, c);\n\
    \            else\n                add_edge(u, v, c);\n        }\n    }\n    /**\n\
    \     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const\
    \ std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n\
    \     */\n    const std::vector<Edge>& operator[](long long v) const {\n     \
    \   assert(0 <= v && v < n);\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\
    \u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\
    \n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\
    \u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (long long i\
    \ = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n\n/**\n * @brief\
    \ \u7D4C\u8DEF (\u8DEF\u30FB\u9589\u8DEF)\u3002\u9577\u3055 cost\u3001\u305F\u3069\
    \u308B\u9802\u70B9\u306E\u5217 vertices\u3001\u305F\u3069\u308B\u8FBA\u306E\u5217\
    \ edges\n *\n * edges[k] \u306F vertices[k] \u304B\u3089 vertices[k + 1] \u3078\
    \u5411\u304B\u3046 (edges[k].src == vertices[k]\u3001edges[k].dst == vertices[k\
    \ + 1])\n * vertices \u306F edges \u3088\u308A 1 \u3064\u591A\u3044\u3002\u8FBA\
    \u304C\u306A\u304F\u3066\u3082\u59CB\u70B9 1 \u3064\u304C\u5165\u308B\u3002\u9589\
    \u8DEF\u306A\u3089 vertices.front() == vertices.back()\n * auto [cost, vertices,\
    \ edges] = *shortest_path(g, s, t); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\
    \u308C\u308B\n */\ntemplate <typename Cost>\nstruct Path {\n    Cost cost;   \
    \                                   //!< \u9577\u3055 (\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u548C)\n    std::vector<long long> vertices;                //!<\
    \ \u305F\u3069\u308B\u9802\u70B9 (\u59CB\u70B9\u304B\u3089\u9806\u306B)\n    std::vector<typename\
    \ Graph<Cost>::Edge> edges;  //!< \u305F\u3069\u308B\u8FBA (\u59CB\u70B9\u5074\
    \u304B\u3089\u9806\u306B)\n};\n\nnamespace internal_graph {\n/**\n * @brief \u59CB\
    \u70B9 s \u3068\u3001s \u304B\u3089\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u8FBA edges \u304B\u3089 Path \u3092\u4F5C\u308B\u3002cost \u306F\u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u548C\n */\ntemplate <typename Cost>\nPath<Cost> make_path(long\
    \ long s, std::vector<typename Graph<Cost>::Edge> edges) {\n    Path<Cost> res{Cost{},\
    \ {s}, std::move(edges)};\n    for (const auto& e : res.edges) {\n        assert(e.src\
    \ == res.vertices.back());\n        res.cost += e.cost;\n        res.vertices.push_back(e.dst);\n\
    \    }\n    return res;\n}\n}  // namespace internal_graph\n#line 17 \"src/graph/grid-graph.hpp\"\
    \n\n/**\n * @brief \u58C1\u4EE5\u5916\u306E\u30DE\u30B9\u3092\u9802\u70B9\u3068\
    \u3059\u308B\u30014 \u8FD1\u508D\u30FB\u91CD\u307F 1 \u306E\u7121\u5411\u30B0\u30E9\
    \u30D5\n * \u5143\u306E\u76E4\u9762\u3068\u5EA7\u6A19\u5BFE\u5FDC\u3092\u4FDD\u6301\
    \u3059\u308B\u3002\u9802\u70B9\u756A\u53F7\u306F\u901A\u884C\u53EF\u80FD\u306A\
    \u30DE\u30B9\u306B\u884C\u512A\u5148\u3067\u4ED8\u3051\u308B\u3002\n */\nclass\
    \ GridGraph {\n    std::vector<std::string> data;\n    long long h, w;\n    std::vector<long\
    \ long> ids;\n    std::vector<Grid::value_type> cells;\n    Graph<long long> g;\n\
    \n    class Matches {\n        const GridGraph* owner;\n        char c;\n\n  \
    \     public:\n        Matches(const GridGraph* owner, char c) : owner(owner),\
    \ c(c) {}\n\n        class iterator {\n            const GridGraph* owner = nullptr;\n\
    \            char c = 0;\n            long long v = -1;\n\n            void seek()\
    \ {\n                while (v < owner->size() && owner->label(v) != c) ++v;\n\
    \                if (v == owner->size()) v = -1;\n            }\n\n          \
    \ public:\n            using value_type = long long;\n            using difference_type\
    \ = std::ptrdiff_t;\n            using reference = value_type;\n            using\
    \ pointer = void;\n            using iterator_category = std::input_iterator_tag;\n\
    \            using iterator_concept = std::forward_iterator_tag;\n\n         \
    \   iterator() = default;\n            iterator(const GridGraph* owner, char c)\
    \ : owner(owner), c(c), v(0) { seek(); }\n            value_type operator*() const\
    \ { return v; }\n            iterator& operator++() {\n                ++v;\n\
    \                seek();\n                return *this;\n            }\n     \
    \       iterator operator++(int) {\n                auto previous = *this;\n \
    \               ++*this;\n                return previous;\n            }\n  \
    \          bool operator==(const iterator& other) const {\n                if\
    \ (v == -1 || other.v == -1) return v == other.v;\n                return owner\
    \ == other.owner && c == other.c && v == other.v;\n            }\n           \
    \ bool operator!=(const iterator& other) const { return !(*this == other); }\n\
    \        };\n\n        iterator begin() const { return iterator(owner, c); }\n\
    \        iterator end() const { return iterator(); }\n    };\n\n   public:\n \
    \   /**\n     * @brief \u76E4\u9762\u3092\u6240\u6709\u3057\u3001\u58C1\u4EE5\u5916\
    \u306E\u30DE\u30B9\u304B\u3089\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3059\u308B\
    \ O(HW)\n     * @pre \u5404\u884C\u306E\u9577\u3055\u304C\u7B49\u3057\u3044\u3053\
    \u3068\u3002\u7A7A\u306E\u76E4\u9762\u3084\u5E45 0 \u306E\u76E4\u9762\u3082\u3088\
    \u3044\u3002\n     */\n    explicit GridGraph(std::vector<std::string> board,\
    \ char wall = '#')\n        : data(std::move(board)), h(static_cast<long long>(data.size())),\
    \ w(data.empty() ? 0 : static_cast<long long>(data.front().size())) {\n      \
    \  for (const auto& row : data) assert(static_cast<long long>(row.size()) == w);\n\
    \        const Grid grid(h, w);\n        ids.assign(grid.size(), -1);\n      \
    \  for (auto [i, j] : grid) {\n            if (data[i][j] == wall) continue;\n\
    \            ids[grid.index(i, j)] = size();\n            cells.emplace_back(i,\
    \ j);\n        }\n        g = Graph<long long>(size());\n        for (long long\
    \ u = 0; u < size(); ++u) {\n            const auto [i, j] = cell(u);\n      \
    \      for (auto [ni, nj] : grid.neighbors4(i, j)) {\n                const long\
    \ long v = index(ni, nj);\n                // \u58C1 (-1) \u3092\u9664\u304D\u3001\
    \u5404\u7121\u5411\u8FBA\u3092 1 \u56DE\u3060\u3051\u8FFD\u52A0\u3059\u308B\u3002\
    \n                if (u < v) g.add_edge(u, v);\n            }\n        }\n   \
    \ }\n\n    const Graph<long long>& graph() const { return g; }\n    long long\
    \ size() const { return static_cast<long long>(cells.size()); }\n    long long\
    \ height() const { return h; }\n    long long width() const { return w; }\n  \
    \  const std::vector<Graph<long long>::Edge>& operator[](long long v) const {\
    \ return g[v]; }\n    const std::vector<std::string>& board() const { return data;\
    \ }\n\n    /** @brief \u5EA7\u6A19\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u756A\
    \u53F7\u3002\u58C1\u306A\u3089 -1\u3001\u7BC4\u56F2\u5916\u306A\u3089 assert */\n\
    \    long long index(long long i, long long j) const { return ids[Grid(h, w).index(i,\
    \ j)]; }\n    /** @brief \u9802\u70B9\u756A\u53F7\u306B\u5BFE\u5FDC\u3059\u308B\
    \u5EA7\u6A19 */\n    Grid::value_type cell(long long v) const {\n        assert(0\
    \ <= v && v < size());\n        return cells[v];\n    }\n    /** @brief \u9802\
    \u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u6587\u5B57 */\n    char label(long long\
    \ v) const {\n        const auto [i, j] = cell(v);\n        return data[i][j];\n\
    \    }\n    /** @brief \u6587\u5B57 c \u306B\u5BFE\u5FDC\u3059\u308B\u6700\u521D\
    \u306E\u9802\u70B9\u756A\u53F7\u3002\u306A\u3051\u308C\u3070 -1\u3002O(V) */\n\
    \    long long find(char c) const {\n        const auto matches = find_all(c);\n\
    \        const auto it = matches.begin();\n        return it == matches.end()\
    \ ? -1 : *it;\n    }\n    /**\n     * @brief \u6587\u5B57 c \u306B\u5BFE\u5FDC\
    \u3059\u308B\u9802\u70B9\u756A\u53F7\u3092\u884C\u512A\u5148\u3067\u9045\u5EF6\
    \u5217\u6319\u3059\u308B\u3002\u69CB\u7BC9 O(1)\u3001\u5168\u8D70\u67FB O(V)\n\
    \     * @pre \u8D70\u67FB\u4E2D\u306F\u5143\u306E GridGraph \u3092\u6709\u52B9\
    \u306A\u307E\u307E\u4FDD\u6301\u3057\u3001\u5909\u66F4\u3057\u306A\u3044\u3053\
    \u3068\u3002\n     */\n    Matches find_all(char c) const { return Matches(this,\
    \ c); }\n};\n#line 4 \"test/unittest/graph/grid-graph.test.cpp\"\n\n#include <algorithm>\n\
    #line 7 \"test/unittest/graph/grid-graph.test.cpp\"\n#include <cstdlib>\n#line\
    \ 9 \"test/unittest/graph/grid-graph.test.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <random>\n#include <set>\n#line 17 \"test/unittest/graph/grid-graph.test.cpp\"\
    \n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\n#line 2 \"src/graph/shortest-path.hpp\"\
    \n\n/**\n * @file shortest-path.hpp\n * @brief \u6700\u77ED\u8DEF\n */\n\n#line\
    \ 10 \"src/graph/shortest-path.hpp\"\n#include <deque>\n#include <functional>\n\
    #line 13 \"src/graph/shortest-path.hpp\"\n#include <optional>\n#line 17 \"src/graph/shortest-path.hpp\"\
    \n\n#line 19 \"src/graph/shortest-path.hpp\"\n\n/**\n * @brief 1 \u70B9\u304B\u3089\
    \u5168\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u306E\u7D50\u679C\n *\n * auto [dist,\
    \ prev] = shortest_path_dijkstra(g, s); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\
    \u308C\u308B\n */\ntemplate <typename Cost>\nstruct ShortestPath {\n    using\
    \ Edge = typename Graph<Cost>::Edge;\n    std::vector<Cost> dist;  //!< \u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\n    std::vector<Edge> prev;\
    \  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\
    \u306E\u8FBA (\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3067\u306F\
    \ src == -1)\n    /**\n     * @brief \u59CB\u70B9\u304B\u3089 t \u3078\u306E\u6700\
    \u77ED\u8DEF (\u9577\u3055\u3001\u305F\u3069\u308B\u9802\u70B9\u3001\u305F\u3069\
    \u308B\u8FBA)\n     * cost \u306F dist[t] (shortest_path_bfs \u3067\u306F\u8FBA\
    \u306E\u672C\u6570)\n     * @return std::optional<Path<Cost>> t \u304C\u59CB\u70B9\
    \u306A\u3089\u9577\u3055 0\u3001\u9802\u70B9\u306F t \u3060\u3051\u3001\u8FBA\u306F\
    \u7A7A\u3002\u672A\u5230\u9054\u306A\u3089 std::nullopt\n     * @note \u8CA0\u9589\
    \u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u9802\u70B9\u3067\u306F\u6700\
    \u77ED\u8DEF\u304C\u5B9A\u307E\u3089\u306A\u3044 (assert \u3067\u843D\u3061\u308B\
    )\n     */\n    std::optional<Path<Cost>> path(long long t) const {\n        //\
    \ \u76F4\u524D\u306E\u8FBA\u304C\u306A\u3044\u306E\u306F\u59CB\u70B9\u3068\u672A\
    \u5230\u9054\u306E\u9802\u70B9\u3002\u59CB\u70B9\u306E\u8DDD\u96E2\u306F 0 \u3067\
    \u3001\u672A\u5230\u9054\u306E\u8DDD\u96E2 inf \u306F\u6B63\u306A\u306E\u3067\u533A\
    \u5225\u3067\u304D\u308B\n        if (prev[t].src == -1 && dist[t] != Cost{})\
    \ return std::nullopt;\n        Path<Cost> res{dist[t], {t}, {}};\n        while\
    \ (prev[t].src != -1) {\n            res.edges.push_back(prev[t]);\n         \
    \   assert(res.edges.size() < prev.size() && \"path: negative cycle\");\n    \
    \        t = prev[t].src;\n            res.vertices.push_back(t);\n        }\n\
    \        std::reverse(res.vertices.begin(), res.vertices.end());\n        std::reverse(res.edges.begin(),\
    \ res.edges.end());\n        return res;\n    }\n};\n\nnamespace internal_shortest_path\
    \ {\n\ntemplate <typename Cost>\nShortestPath<Cost> bfs(const Graph<Cost>& graph,\
    \ long long s, Cost inf) {\n    std::vector<Cost> dist(graph.size(), inf);\n \
    \   std::vector<typename Graph<Cost>::Edge> prev(graph.size());\n    std::queue<long\
    \ long> que;\n    dist[s] = 0;\n    que.push(s);\n    while (!que.empty()) {\n\
    \        long long u = que.front();\n        que.pop();\n        for (auto& e\
    \ : graph[u]) {\n            if (dist[e.dst] == inf) {\n                dist[e.dst]\
    \ = dist[e.src] + 1;\n                prev[e.dst] = e;\n                que.push(e.dst);\n\
    \            }\n        }\n    }\n    return {dist, prev};\n}\n\n// target \u304C\
    \ -1 \u3067\u306A\u3051\u308C\u3070\u3001target \u306E\u8DDD\u96E2\u304C\u6C7A\
    \u307E\u3063\u305F\u6642\u70B9\u3067\u6253\u3061\u5207\u308B\ntemplate <typename\
    \ Cost>\nShortestPath<Cost> dijkstra(const Graph<Cost>& graph, long long s, Cost\
    \ inf, long long target = -1) {\n    for (long long v = 0; v < graph.size(); v++)\
    \ {\n        for (const auto& e : graph[v]) assert(!(e.cost < Cost{}) && \"negative\
    \ edge (use shortest_path_bellman_ford)\");\n    }\n    std::vector<Cost> dist(graph.size(),\
    \ inf);\n    std::vector<typename Graph<Cost>::Edge> prev(graph.size());\n   \
    \ using Node = std::pair<Cost, long long>;\n    std::priority_queue<Node, std::vector<Node>,\
    \ std::greater<Node>> que;\n    dist[s] = 0;\n    que.push({0, s});\n    while\
    \ (!que.empty()) {\n        auto [d, u] = que.top();\n        que.pop();\n   \
    \     if (d > dist[u])\n            continue;\n        if (u == target) break;\n\
    \        for (auto& e : graph[u]) {\n            if (dist[e.dst] == inf || dist[e.dst]\
    \ > dist[e.src] + e.cost) {\n                dist[e.dst] = dist[e.src] + e.cost;\n\
    \                prev[e.dst] = e;\n                que.push({dist[e.dst], e.dst});\n\
    \            }\n        }\n    }\n    return {dist, prev};\n}\n\n}  // namespace\
    \ internal_shortest_path\n\n/**\n * @brief s \u304B\u3089 t \u3078\u306E\u6700\
    \u77ED\u8DEF (Dijkstra\u3002t \u306E\u8DDD\u96E2\u304C\u6C7A\u307E\u3063\u305F\
    \u6642\u70B9\u3067\u6253\u3061\u5207\u308B) O(m log m)\n *\n * @return std::optional<Path<Cost>>\
    \ \u9577\u3055\u3001\u305F\u3069\u308B\u9802\u70B9\u3001\u305F\u3069\u308B\u8FBA\
    \u3002\u5C4A\u304B\u306A\u3051\u308C\u3070 std::nullopt\u3002s == t \u306A\u3089\
    \u9577\u3055 0\u3001\u9802\u70B9\u306F s \u3060\u3051\u3001\u8FBA\u306F\u7A7A\n\
    \ * @note \u8CA0\u306E\u8FBA\u304C\u3042\u308B\u3068 assert \u3067\u843D\u3061\
    \u308B (\u8CA0\u306E\u8FBA\u304C\u3042\u308B\u306A\u3089 shortest_path_bellman_ford)\n\
    \ */\ntemplate <typename Cost = long long>\nstd::optional<Path<Cost>> shortest_path(const\
    \ Graph<Cost>& graph, long long s, long long t) {\n    assert(0 <= s && s < graph.size());\n\
    \    assert(0 <= t && t < graph.size());\n    return internal_shortest_path::dijkstra(graph,\
    \ s, std::numeric_limits<Cost>::max() / 4, t).path(t);\n}\n\n/**\n * @brief \u3042\
    \u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \ (Dijkstra) O(m log m)\n *\n * @param s \u59CB\u70B9\n * @param inf \u672A\u5230\
    \u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\u3059\u308B\u3068\
    \ std::numeric_limits<Cost>::max() / 4\n * @return ShortestPath \u5404\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n * @note\
    \ \u8CA0\u306E\u8FBA\u304C\u3042\u308B\u3068 assert \u3067\u843D\u3061\u308B (\u8CA0\
    \u306E\u8FBA\u304C\u3042\u308B\u306A\u3089 shortest_path_bellman_ford)\n */\n\
    template <typename Cost = long long>\nShortestPath<Cost> shortest_path_dijkstra(const\
    \ Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.size());\n    return internal_shortest_path::dijkstra(graph,\
    \ s, inf);\n}\n\n/**\n * @brief \u8FBA\u306E\u91CD\u307F\u3092\u3059\u3079\u3066\
    \ 1 \u3068\u307F\u306A\u3057\u3066\u3001\u3042\u308B\u9802\u70B9\u304B\u3089\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF (BFS) O(n + m)\n *\n * @param s \u59CB\
    \u70B9\n * @param inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\
    \ \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n * @return\
    \ ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u8FBA\u306E\
    \u672C\u6570\u3001dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost\
    \ = long long>\nShortestPath<Cost> shortest_path_bfs(const Graph<Cost>& graph,\
    \ long long s, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    assert(0\
    \ <= s && s < graph.size());\n    return internal_shortest_path::bfs(graph, s,\
    \ inf);\n}\n\n/**\n * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF\n *\n * @param s \u59CB\u70B9\n * @param inf \u30B3\
    \u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\
    \u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068\
    \ std::numeric_limits<Cost>::max() / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\
    \u53D7\u3051\u308B\u70B9\u306F -inf\n * @return ShortestPath \u5404\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate\
    \ <typename Cost = long long>\nShortestPath<Cost> shortest_path_bellman_ford(const\
    \ Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.size());\n    const long long n = graph.size();\n\
    \    std::vector<Cost> dist(n, inf);\n    std::vector<typename Graph<Cost>::Edge>\
    \ prev(n);\n    dist[s] = Cost{};\n\n    for (long long i = 1; i < n; i++) {\n\
    \        bool changed = false;\n        for (long long j = 0; j < n; j++)\n  \
    \          for (const auto& e : graph[j]) {\n                if (dist[e.src] ==\
    \ inf)\n                    continue;\n                if (dist[e.dst] > dist[e.src]\
    \ + e.cost) {\n                    dist[e.dst] = dist[e.src] + e.cost;\n     \
    \               if (dist[e.dst] < -inf)\n                        dist[e.dst] =\
    \ -inf;\n                    prev[e.dst] = e;\n                    changed = true;\n\
    \                }\n            }\n        if (!changed)\n            break;\n\
    \    }\n    for (long long i = 0; i < n; i++) {\n        bool changed = false;\n\
    \        for (long long j = 0; j < n; j++)\n            for (const auto& e : graph[j])\
    \ {\n                if (dist[e.src] == inf)\n                    continue;\n\
    \                if (dist[e.dst] > dist[e.src] + e.cost) {\n                 \
    \   dist[e.dst] = -inf;\n                    prev[e.dst] = e;\n              \
    \      changed = true;\n                }\n            }\n        if (!changed)\n\
    \            break;\n    }\n    return {dist, prev};\n}\n\n/**\n * @brief \u8FBA\
    \u306E\u30B3\u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\
    \u3067\u3001\u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DEF (01-BFS) O(n + m)\n *\n * @param s \u59CB\u70B9\n * @param\
    \ inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\
    \u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n * @return ShortestPath\
    \ \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\
    \ (prev)\n */\ntemplate <typename Cost = long long>\nShortestPath<Cost> shortest_path_01bfs(const\
    \ Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.size());\n    std::vector<Cost> dist(graph.size(),\
    \ inf);\n    std::vector<typename Graph<Cost>::Edge> prev(graph.size());\n   \
    \ std::deque<long long> que;\n    dist[s] = 0;\n    que.push_back(s);\n    while\
    \ (!que.empty()) {\n        long long u = que.front();\n        que.pop_front();\n\
    \        for (auto& e : graph[u]) {\n            assert(e.cost == 0 || e.cost\
    \ == 1);\n            if (dist[e.dst] == inf || dist[e.dst] > dist[u] + e.cost)\
    \ {\n                dist[e.dst] = dist[u] + e.cost;\n                prev[e.dst]\
    \ = e;\n                if (e.cost == 0)\n                    que.push_front(e.dst);\n\
    \                else\n                    que.push_back(e.dst);\n           \
    \ }\n        }\n    }\n    return {dist, prev};\n}\n\n/**\n * @brief \u5168\u70B9\
    \u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577 (Floyd-Warshall) O(n^3)\n *\n * @param\
    \ inf \u672A\u5230\u9054\u3092\u8868\u3059\u5024 \u7701\u7565\u3059\u308B\u3068\
    \ std::numeric_limits<Cost>::max() / 4\n * @return std::vector<std::vector<Cost>>\
    \ dist[i][j] \u304C i \u304B\u3089 j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\
    \u9054\u3067\u304D\u306A\u3051\u308C\u3070 inf)\n * @note \u8CA0\u306E\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B i\
    \ \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n * \u8CA0\u9589\
    \u8DEF\u304C\u3042\u308B\u3068\u304D\u306E\u5024\u306F -inf \u4EE5\u4E0A\u306B\
    \u5207\u308A\u8A70\u3081\u308B\u306E\u3067\u3001\u3042\u3075\u308C\u306A\u3044\
    \ (\u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u7D44\u306E\u5024\
    \u306F\u6700\u77ED\u8DEF\u9577\u3067\u306F\u306A\u3044)\n */\ntemplate <typename\
    \ Cost = long long>\nstd::vector<std::vector<Cost>> shortest_path_floyd_warshall(const\
    \ Graph<Cost>& graph, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n   \
    \ const long long n = graph.size();\n    std::vector<std::vector<Cost>> dist(n,\
    \ std::vector<Cost>(n, inf));\n    for (long long i = 0; i < n; i++) dist[i][i]\
    \ = Cost{};\n    for (long long i = 0; i < n; i++) {\n        for (auto& e : graph[i])\
    \ dist[i][e.dst] = std::min(dist[i][e.dst], e.cost);\n    }\n    for (long long\
    \ k = 0; k < n; k++) {\n        for (long long i = 0; i < n; i++) {\n        \
    \    if (dist[i][k] == inf) continue;\n            for (long long j = 0; j < n;\
    \ j++) {\n                if (dist[k][j] == inf) continue;\n                //\
    \ dist \u306F -inf \u4EE5\u4E0A inf \u4EE5\u4E0B\u306A\u306E\u3067\u3001\u548C\
    \u306F -2 inf \u4EE5\u4E0A\u3067\u3042\u3075\u308C\u306A\u3044\n             \
    \   Cost d = dist[i][k] + dist[k][j];\n                if (d < -inf) d = -inf;\n\
    \                if (d < dist[i][j]) dist[i][j] = d;\n            }\n        }\n\
    \    }\n    return dist;\n}\n#line 22 \"test/unittest/graph/grid-graph.test.cpp\"\
    \n\nusing ll = long long;\nusing Cell = std::pair<ll, ll>;\n\nstatic_assert(std::is_same_v<decltype(std::declval<const\
    \ GridGraph&>().graph()), const Graph<ll>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<GridGraph&>().board()),\
    \ const std::vector<std::string>&>);\nstatic_assert(!std::is_assignable_v<decltype(std::declval<GridGraph&>().board()[0][0]),\
    \ char>);\nstatic_assert(!std::is_convertible_v<std::vector<std::string>, GridGraph>);\n\
    \nbool adjacent(Cell a, Cell b) {\n    return std::abs(a.first - b.first) + std::abs(a.second\
    \ - b.second) == 1;\n}\n\nvoid verify(const GridGraph& maze, const std::vector<std::string>&\
    \ board, char wall) {\n    const ll h = board.size(), w = board.empty() ? 0 :\
    \ static_cast<ll>(board.front().size());\n    assert(maze.board() == board &&\
    \ maze.height() == h && maze.width() == w);\n    std::vector<Cell> cells;\n  \
    \  for (ll i = 0; i < h; ++i) {\n        for (ll j = 0; j < w; ++j) {\n      \
    \      const ll expected = board[i][j] == wall ? -1 : static_cast<ll>(cells.size());\n\
    \            assert(maze.index(i, j) == expected);\n            if (expected !=\
    \ -1) cells.emplace_back(i, j);\n        }\n    }\n    const ll n = cells.size();\n\
    \    assert(maze.size() == n && maze.graph().size() == n);\n\n    std::set<std::pair<ll,\
    \ ll>> expected_edges, actual_edges;\n    for (ll u = 0; u < n; ++u) {\n     \
    \   assert(maze.cell(u) == cells[u]);\n        assert(maze.label(u) == board[cells[u].first][cells[u].second]);\n\
    \        std::set<ll> expected_neighbors, actual_neighbors;\n        for (ll v\
    \ = 0; v < n; ++v) {\n            if (adjacent(cells[u], cells[v])) {\n      \
    \          expected_neighbors.insert(v);\n                if (u < v) expected_edges.emplace(u,\
    \ v);\n            }\n        }\n        for (const auto& edge : maze[u]) {\n\
    \            assert(edge.src == u && edge.cost == 1 && 0 <= edge.dst && edge.dst\
    \ < n);\n            actual_neighbors.insert(edge.dst);\n        }\n        assert(actual_neighbors\
    \ == expected_neighbors && maze[u].size() == expected_neighbors.size());\n   \
    \     assert(&maze[u] == &maze.graph()[u]);\n    }\n    assert(maze.graph().edge_count()\
    \ == static_cast<ll>(expected_edges.size()));\n    std::vector<ll> edge_occurrences(maze.graph().edge_count());\n\
    \    for (ll u = 0; u < n; ++u) {\n        for (const auto& edge : maze[u]) {\n\
    \            assert(0 <= edge.id && edge.id < maze.graph().edge_count());\n  \
    \          ++edge_occurrences[edge.id];\n        }\n    }\n    for (ll count :\
    \ edge_occurrences) assert(count == 2);\n    for (const auto& edge : maze.graph().edges())\
    \ actual_edges.emplace(std::min(edge.src, edge.dst), std::max(edge.src, edge.dst));\n\
    \    assert(actual_edges == expected_edges);\n\n    for (char c : {'S', 'G', '.',\
    \ '#', 'a', 'X', '\\0'}) {\n        std::vector<ll> expected;\n        for (ll\
    \ v = 0; v < n; ++v) {\n            if (board[cells[v].first][cells[v].second]\
    \ == c) expected.push_back(v);\n        }\n        const auto matches = maze.find_all(c);\n\
    \        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);\n\
    \        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);\n\
    \        assert(maze.find(c) == (expected.empty() ? -1 : expected.front()));\n\
    \        // \u4E00\u6642\u7684\u306A\u691C\u7D22range\u304C\u306A\u304F\u306A\u3063\
    \u3066\u3082\u3001iterator\u306E\u8D70\u67FB\u72B6\u614B\u306F\u72EC\u7ACB\u3057\
    \u3066\u3044\u308B\u3002\n        auto it = maze.find_all(c).begin();\n      \
    \  for (ll v : expected) {\n            auto independent = it;\n            decltype(it)\
    \ assigned;\n            assigned = it;\n            assert(*it++ == v && *independent\
    \ == v && *assigned == v);\n            ++independent;\n            assert(independent\
    \ == it);\n        }\n        assert(it == matches.end());\n#if __cplusplus >=\
    \ 202002L\n        static_assert(std::ranges::forward_range<decltype(matches)>);\n\
    \        auto selected = maze.find_all(c) | std::views::take(1);\n        std::vector<ll>\
    \ first;\n        std::ranges::copy(selected, std::back_inserter(first));\n  \
    \      assert(first == (expected.empty() ? std::vector<ll>{} : std::vector<ll>{expected.front()}));\n\
    #endif\n    }\n\n    // Grid\u3092\u4F7F\u308F\u305A\u3001\u5EA7\u6A19\u306E\u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3060\u3051\u3067\u96A3\u63A5\u3092\
    \u5224\u5B9A\u3059\u308BBFS\u3068\u6BD4\u8F03\u3059\u308B\u3002\n    const ll\
    \ inf = std::numeric_limits<ll>::max() / 4;\n    for (ll s = 0; s < n; ++s) {\n\
    \        std::vector<ll> expected(n, inf);\n        std::queue<ll> queue;\n  \
    \      expected[s] = 0;\n        queue.push(s);\n        while (!queue.empty())\
    \ {\n            const ll u = queue.front();\n            queue.pop();\n     \
    \       for (ll v = 0; v < n; ++v) {\n                if (expected[v] != inf ||\
    \ !adjacent(cells[u], cells[v])) continue;\n                expected[v] = expected[u]\
    \ + 1;\n                queue.push(v);\n            }\n        }\n        const\
    \ auto result = shortest_path_bfs(maze.graph(), s);\n        assert(result.dist\
    \ == expected);\n        for (ll t = 0; t < n; ++t) {\n            const auto\
    \ path = result.path(t);\n            assert(path.has_value() == (expected[t]\
    \ != inf));\n            if (path) {\n                assert(path->vertices.front()\
    \ == s && path->vertices.back() == t);\n                assert(path->cost == expected[t]\
    \ && static_cast<ll>(path->edges.size()) == expected[t]);\n                for\
    \ (ll i = 1; i < static_cast<ll>(path->vertices.size()); ++i) {\n            \
    \        assert(adjacent(maze.cell(path->vertices[i - 1]), maze.cell(path->vertices[i])));\n\
    \                }\n            }\n        }\n    }\n}\n\nint main() {\n    for\
    \ (const auto& board : std::vector<std::vector<std::string>>{\n             {},\
    \ {\"\", \"\"}, {\"#\"}, {\".\"}, {\"S\"}, {\"###\", \"###\"}, {\"S#G\"}, {\"\
    S\", \"#\", \"G\"}, {\"S..#.\", \".#...\", \"...G.\"}, {\"aaa\", \"a#a\", \"aaa\"\
    }}) {\n        verify(GridGraph(board), board, '#');\n    }\n    verify(GridGraph({\"\
    S#XG\", \"aX.a\"}, 'X'), {\"S#XG\", \"aX.a\"}, 'X');\n    verify(GridGraph({\"\
    S.G\"}, 'S'), {\"S.G\"}, 'S');\n    const std::vector<std::string> binary = {std::string(\"\
    a\\0#\", 3)};\n    verify(GridGraph(binary), binary, '#');\n    {\n        const\
    \ std::vector<std::string> expected = {\"S..#.\", \".#...\", \"...G.\"};\n   \
    \     auto input = expected;\n        GridGraph maze(input);\n        input.clear();\n\
    \        verify(maze, expected, '#');\n        const GridGraph copy(maze);\n \
    \       verify(copy, expected, '#');\n        GridGraph moved(std::move(maze));\n\
    \        verify(moved, expected, '#');\n        assert(shortest_path_bfs(moved.graph(),\
    \ moved.find('S')).dist[moved.find('G')] == 5);\n    }\n    std::mt19937 rng(314);\n\
    \    for (int rep = 0; rep < 600; ++rep) {\n        const ll h = rng() % 8, w\
    \ = rng() % 8;\n        std::vector<std::string> board(h, std::string(w, '.'));\n\
    \        for (auto& row : board) {\n            for (char& c : row) c = std::string(\"\
    ##..aSGX\")[rng() % 8];\n        }\n        const char wall = rep % 2 == 0 ? '#'\
    \ : 'X';\n        verify(GridGraph(board, wall), board, wall);\n    }\n    std::cout\
    \ << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../../src/graph/grid-graph.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstdlib>\n#include <iostream>\n#include <limits>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <string>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n#if __cplusplus >= 202002L\n#include <ranges>\n\
    #endif\n\n#include \"../../../src/graph/shortest-path.hpp\"\n\nusing ll = long\
    \ long;\nusing Cell = std::pair<ll, ll>;\n\nstatic_assert(std::is_same_v<decltype(std::declval<const\
    \ GridGraph&>().graph()), const Graph<ll>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<GridGraph&>().board()),\
    \ const std::vector<std::string>&>);\nstatic_assert(!std::is_assignable_v<decltype(std::declval<GridGraph&>().board()[0][0]),\
    \ char>);\nstatic_assert(!std::is_convertible_v<std::vector<std::string>, GridGraph>);\n\
    \nbool adjacent(Cell a, Cell b) {\n    return std::abs(a.first - b.first) + std::abs(a.second\
    \ - b.second) == 1;\n}\n\nvoid verify(const GridGraph& maze, const std::vector<std::string>&\
    \ board, char wall) {\n    const ll h = board.size(), w = board.empty() ? 0 :\
    \ static_cast<ll>(board.front().size());\n    assert(maze.board() == board &&\
    \ maze.height() == h && maze.width() == w);\n    std::vector<Cell> cells;\n  \
    \  for (ll i = 0; i < h; ++i) {\n        for (ll j = 0; j < w; ++j) {\n      \
    \      const ll expected = board[i][j] == wall ? -1 : static_cast<ll>(cells.size());\n\
    \            assert(maze.index(i, j) == expected);\n            if (expected !=\
    \ -1) cells.emplace_back(i, j);\n        }\n    }\n    const ll n = cells.size();\n\
    \    assert(maze.size() == n && maze.graph().size() == n);\n\n    std::set<std::pair<ll,\
    \ ll>> expected_edges, actual_edges;\n    for (ll u = 0; u < n; ++u) {\n     \
    \   assert(maze.cell(u) == cells[u]);\n        assert(maze.label(u) == board[cells[u].first][cells[u].second]);\n\
    \        std::set<ll> expected_neighbors, actual_neighbors;\n        for (ll v\
    \ = 0; v < n; ++v) {\n            if (adjacent(cells[u], cells[v])) {\n      \
    \          expected_neighbors.insert(v);\n                if (u < v) expected_edges.emplace(u,\
    \ v);\n            }\n        }\n        for (const auto& edge : maze[u]) {\n\
    \            assert(edge.src == u && edge.cost == 1 && 0 <= edge.dst && edge.dst\
    \ < n);\n            actual_neighbors.insert(edge.dst);\n        }\n        assert(actual_neighbors\
    \ == expected_neighbors && maze[u].size() == expected_neighbors.size());\n   \
    \     assert(&maze[u] == &maze.graph()[u]);\n    }\n    assert(maze.graph().edge_count()\
    \ == static_cast<ll>(expected_edges.size()));\n    std::vector<ll> edge_occurrences(maze.graph().edge_count());\n\
    \    for (ll u = 0; u < n; ++u) {\n        for (const auto& edge : maze[u]) {\n\
    \            assert(0 <= edge.id && edge.id < maze.graph().edge_count());\n  \
    \          ++edge_occurrences[edge.id];\n        }\n    }\n    for (ll count :\
    \ edge_occurrences) assert(count == 2);\n    for (const auto& edge : maze.graph().edges())\
    \ actual_edges.emplace(std::min(edge.src, edge.dst), std::max(edge.src, edge.dst));\n\
    \    assert(actual_edges == expected_edges);\n\n    for (char c : {'S', 'G', '.',\
    \ '#', 'a', 'X', '\\0'}) {\n        std::vector<ll> expected;\n        for (ll\
    \ v = 0; v < n; ++v) {\n            if (board[cells[v].first][cells[v].second]\
    \ == c) expected.push_back(v);\n        }\n        const auto matches = maze.find_all(c);\n\
    \        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);\n\
    \        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);\n\
    \        assert(maze.find(c) == (expected.empty() ? -1 : expected.front()));\n\
    \        // \u4E00\u6642\u7684\u306A\u691C\u7D22range\u304C\u306A\u304F\u306A\u3063\
    \u3066\u3082\u3001iterator\u306E\u8D70\u67FB\u72B6\u614B\u306F\u72EC\u7ACB\u3057\
    \u3066\u3044\u308B\u3002\n        auto it = maze.find_all(c).begin();\n      \
    \  for (ll v : expected) {\n            auto independent = it;\n            decltype(it)\
    \ assigned;\n            assigned = it;\n            assert(*it++ == v && *independent\
    \ == v && *assigned == v);\n            ++independent;\n            assert(independent\
    \ == it);\n        }\n        assert(it == matches.end());\n#if __cplusplus >=\
    \ 202002L\n        static_assert(std::ranges::forward_range<decltype(matches)>);\n\
    \        auto selected = maze.find_all(c) | std::views::take(1);\n        std::vector<ll>\
    \ first;\n        std::ranges::copy(selected, std::back_inserter(first));\n  \
    \      assert(first == (expected.empty() ? std::vector<ll>{} : std::vector<ll>{expected.front()}));\n\
    #endif\n    }\n\n    // Grid\u3092\u4F7F\u308F\u305A\u3001\u5EA7\u6A19\u306E\u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3060\u3051\u3067\u96A3\u63A5\u3092\
    \u5224\u5B9A\u3059\u308BBFS\u3068\u6BD4\u8F03\u3059\u308B\u3002\n    const ll\
    \ inf = std::numeric_limits<ll>::max() / 4;\n    for (ll s = 0; s < n; ++s) {\n\
    \        std::vector<ll> expected(n, inf);\n        std::queue<ll> queue;\n  \
    \      expected[s] = 0;\n        queue.push(s);\n        while (!queue.empty())\
    \ {\n            const ll u = queue.front();\n            queue.pop();\n     \
    \       for (ll v = 0; v < n; ++v) {\n                if (expected[v] != inf ||\
    \ !adjacent(cells[u], cells[v])) continue;\n                expected[v] = expected[u]\
    \ + 1;\n                queue.push(v);\n            }\n        }\n        const\
    \ auto result = shortest_path_bfs(maze.graph(), s);\n        assert(result.dist\
    \ == expected);\n        for (ll t = 0; t < n; ++t) {\n            const auto\
    \ path = result.path(t);\n            assert(path.has_value() == (expected[t]\
    \ != inf));\n            if (path) {\n                assert(path->vertices.front()\
    \ == s && path->vertices.back() == t);\n                assert(path->cost == expected[t]\
    \ && static_cast<ll>(path->edges.size()) == expected[t]);\n                for\
    \ (ll i = 1; i < static_cast<ll>(path->vertices.size()); ++i) {\n            \
    \        assert(adjacent(maze.cell(path->vertices[i - 1]), maze.cell(path->vertices[i])));\n\
    \                }\n            }\n        }\n    }\n}\n\nint main() {\n    for\
    \ (const auto& board : std::vector<std::vector<std::string>>{\n             {},\
    \ {\"\", \"\"}, {\"#\"}, {\".\"}, {\"S\"}, {\"###\", \"###\"}, {\"S#G\"}, {\"\
    S\", \"#\", \"G\"}, {\"S..#.\", \".#...\", \"...G.\"}, {\"aaa\", \"a#a\", \"aaa\"\
    }}) {\n        verify(GridGraph(board), board, '#');\n    }\n    verify(GridGraph({\"\
    S#XG\", \"aX.a\"}, 'X'), {\"S#XG\", \"aX.a\"}, 'X');\n    verify(GridGraph({\"\
    S.G\"}, 'S'), {\"S.G\"}, 'S');\n    const std::vector<std::string> binary = {std::string(\"\
    a\\0#\", 3)};\n    verify(GridGraph(binary), binary, '#');\n    {\n        const\
    \ std::vector<std::string> expected = {\"S..#.\", \".#...\", \"...G.\"};\n   \
    \     auto input = expected;\n        GridGraph maze(input);\n        input.clear();\n\
    \        verify(maze, expected, '#');\n        const GridGraph copy(maze);\n \
    \       verify(copy, expected, '#');\n        GridGraph moved(std::move(maze));\n\
    \        verify(moved, expected, '#');\n        assert(shortest_path_bfs(moved.graph(),\
    \ moved.find('S')).dist[moved.find('G')] == 5);\n    }\n    std::mt19937 rng(314);\n\
    \    for (int rep = 0; rep < 600; ++rep) {\n        const ll h = rng() % 8, w\
    \ = rng() % 8;\n        std::vector<std::string> board(h, std::string(w, '.'));\n\
    \        for (auto& row : board) {\n            for (char& c : row) c = std::string(\"\
    ##..aSGX\")[rng() % 8];\n        }\n        const char wall = rep % 2 == 0 ? '#'\
    \ : 'X';\n        verify(GridGraph(board, wall), board, wall);\n    }\n    std::cout\
    \ << \"Hello World\\n\";\n}\n"
  dependsOn:
  - src/graph/grid-graph.hpp
  - src/utility/range.hpp
  - src/graph/graph.hpp
  - src/graph/shortest-path.hpp
  isVerificationFile: true
  path: test/unittest/graph/grid-graph.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 05:56:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/grid-graph.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/grid-graph.test.cpp
- /verify/test/unittest/graph/grid-graph.test.cpp.html
title: test/unittest/graph/grid-graph.test.cpp
---
