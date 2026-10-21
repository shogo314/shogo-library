---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Rect"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B
  bundledCode: "#line 1 \"test/aoj/itp1/itp1-7-b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B\"\
    \n\n#include <iostream>\n\n#line 2 \"src/utility/range.hpp\"\n\n/**\n * @file\
    \ range.hpp\n * @brief Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\
    \u5217\u3068\u3001\u305D\u306E\u76F4\u7A4D\u306E Rect\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <iterator>\n#include <string>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nstruct Range {\n   public:\n    using\
    \ value_type = long long;\n    using const_reference = const value_type&;\n  \
    \  using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const value_type start;\n    const value_type stop;\n    const value_type\
    \ step;\n\n   private:\n    const value_type norm_stop;\n\n    constexpr static\
    \ value_type normalize(value_type _start, value_type _stop, value_type _step)\
    \ {\n        assert(_step != 0);\n        if (_step > 0) {\n            if (_start\
    \ >= _stop) {\n                return _start;\n            } else {\n        \
    \        return _start + (_stop - _start + _step - 1) / _step * _step;\n     \
    \       }\n        } else {\n            if (_start <= _stop) {\n            \
    \    return _start;\n            } else {\n                return _start - (_start\
    \ - _stop - _step - 1) / _step * _step;\n            }\n        }\n    }\n\n \
    \   constexpr Range(value_type _start, value_type _stop, value_type _step, value_type\
    \ _norm_stop)\n        : start(_start), stop(_stop), step(_step), norm_stop(_norm_stop)\
    \ {\n    }\n\n   public:\n    /**\n     * @brief start \u304B\u3089 stop \u306E\
    \u624B\u524D\u307E\u3067 step \u305A\u3064\u9032\u3080\u6574\u6570\u5217\n   \
    \  * @pre step != 0\n     */\n    constexpr Range(value_type _start, value_type\
    \ _stop, value_type _step)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(normalize(_start, _stop, _step)) {\n    }\n    constexpr Range(value_type\
    \ _start, value_type _stop)\n        : start(_start), stop(_stop), step(1), norm_stop(normalize(_start,\
    \ _stop, 1)) {}\n    explicit constexpr Range(value_type _stop)\n        : start(0),\
    \ stop(_stop), step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n\
    \        : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = const\
    \ Range::value_type*;\n        using reference = const Range::value_type&;\n \
    \       using iterator_category = std::random_access_iterator_tag;\n\n       private:\n\
    \        const Range& range;\n        value_type value;\n\n        constexpr bool\
    \ same_range(const const_iterator& o) const noexcept {\n            return range.start\
    \ == o.range.start && range.stop == o.range.stop && range.step == o.range.step;\n\
    \        }\n\n       public:\n        constexpr const_iterator(const Range& _range,\
    \ value_type _value) noexcept\n            : range(_range), value(_value) {}\n\
    \        constexpr const_iterator(const const_iterator& o) noexcept\n        \
    \    : range(o.range), value(o.value) {}\n        constexpr reference base() const\
    \ noexcept {\n            return value;\n        }\n        constexpr const_iterator&\
    \ operator=(const const_iterator& o) {\n            assert(same_range(o));\n \
    \           value = o.value;\n            return *this;\n        };\n        constexpr\
    \ const_iterator& operator++() noexcept {\n            value += range.step;\n\
    \            return *this;\n        }\n        constexpr const_iterator operator++(int)\
    \ noexcept {\n            const_iterator ret(*this);\n            value += range.step;\n\
    \            return ret;\n        }\n        constexpr const_iterator& operator+=(difference_type\
    \ _n) noexcept {\n            value += _n * range.step;\n            return *this;\n\
    \        }\n        constexpr friend const_iterator operator+(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret += _n;\n            return ret;\n        }\n        constexpr friend\
    \ const_iterator operator+(difference_type _n, const const_iterator& i) noexcept\
    \ {\n            const_iterator ret(i);\n            ret += _n;\n            return\
    \ ret;\n        }\n        constexpr const_iterator& operator--() noexcept {\n\
    \            value -= range.step;\n            return *this;\n        }\n    \
    \    constexpr const_iterator operator--(int) noexcept {\n            const_iterator\
    \ ret(*this);\n            value -= range.step;\n            return ret;\n   \
    \     }\n        constexpr const_iterator& operator-=(difference_type _n) noexcept\
    \ {\n            value -= _n * range.step;\n            return *this;\n      \
    \  }\n        constexpr friend const_iterator operator-(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret -= _n;\n            return ret;\n        }\n        constexpr reference\
    \ operator*() const noexcept {\n            return value;\n        }\n       \
    \ constexpr friend bool operator!=(const const_iterator& a, const const_iterator&\
    \ b) noexcept {\n            return !a.same_range(b) || a.value != b.value;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return !(a != b);\n       \
    \ }\n        constexpr friend difference_type operator-(const const_iterator&\
    \ a, const const_iterator& b) {\n            assert(a.same_range(b));\n      \
    \      if (a.range.step > 0) {\n                return (a.value - b.value) / a.range.step;\n\
    \            } else {\n                return (b.value - a.value) / (-a.range.step);\n\
    \            }\n        }\n    };\n\n    constexpr const_iterator begin() const\
    \ noexcept {\n        return {*this, start};\n    }\n    constexpr const_iterator\
    \ end() const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n\
    \     * @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr size_type\
    \ count(value_type x) const noexcept {\n        // step \u304C\u30B3\u30F3\u30D1\
    \u30A4\u30EB\u6642\u306B\u5206\u304B\u3089\u306A\u3044\u3068\u304D\u3082\u3001\
    \u3088\u304F\u4F7F\u3046 step = 1 \u3067\u306F\u5272\u308A\u7B97\u3092\u3057\u306A\
    \u3044\n        if (step == 1) return start <= x && x < stop;\n        if (step\
    \ > 0) {\n            if (start <= x && x < stop) {\n                if ((x -\
    \ start) % step == 0) {\n                    return 1;\n                }\n  \
    \          }\n        } else {\n            if (stop < x && x <= start) {\n  \
    \              if ((start - x) % (-step) == 0) {\n                    return 1;\n\
    \                }\n            }\n        }\n        return 0;\n    }\n    /**\n\
    \     * @brief x \u304C\u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr\
    \ bool contains(value_type x) const noexcept {\n        return count(x) != 0;\n\
    \    }\n    /**\n     * @brief x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \     * x \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n\
    \    constexpr size_type index(value_type x) const {\n        assert(contains(x));\n\
    \        if (step == 1) return x - start;\n        return (x - start) / step;\n\
    \    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n     * x \u304C\u542B\u307E\u308C\u306A\u3044\u3068 end() \u3092\u8FD4\
    \u3059\n     */\n    constexpr const_iterator find(value_type x) const noexcept\
    \ {\n        if (contains(x)) {\n            return {*this, x};\n        } else\
    \ {\n            return {*this, norm_stop};\n        }\n    }\n    /**\n     *\
    \ @brief \u8981\u7D20\u304C x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n     * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\
    \u30FC\n     */\n    constexpr const_iterator lower_bound(value_type x) const\
    \ {\n        assert(step > 0);\n        if (norm_stop <= x) {\n            return\
    \ end();\n        } else if (x < start) {\n            return begin();\n     \
    \   } else {\n            return {*this, start + (x - start + step - 1) / step\
    \ * step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n   \
    \  * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ const_iterator upper_bound(value_type x) const {\n        assert(step > 0);\n\
    \        if (norm_stop <= x) {\n            return end();\n        } else if (x\
    \ < start) {\n            return begin();\n        } else {\n            return\
    \ {*this, start + (x - start + step) / step * step};\n        }\n    }\n    /**\n\
    \     * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u8981\u7D20\u6570\n     */\n   \
    \ constexpr size_type size() const noexcept {\n        if (step > 0) {\n     \
    \       return (norm_stop - start) / step;\n        } else {\n            return\
    \ (start - norm_stop) / (-step);\n        }\n    }\n    constexpr value_type at(size_type\
    \ i) const {\n        assert(0 <= i && i < size());\n        return start + i\
    \ * step;\n    }\n    constexpr value_type operator[](size_type i) const {\n \
    \       return at(i);\n    }\n    constexpr bool empty() const noexcept {\n  \
    \      return start == norm_stop;\n    }\n    constexpr value_type sum() const\
    \ noexcept {\n        return size() * (norm_stop - step + start) / 2;\n    }\n\
    \    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\
    \u30FC\n     */\n    constexpr value_type min() const {\n        assert(!empty());\n\
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
    \n */\nstruct Rect {\n   public:\n    using value_type = std::pair<long long,\
    \ long long>;\n    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const Range rows;\n    const Range cols;\n\n   private:\n    const long\
    \ long width;  // cols.size() (index \u3084 at \u3067\u6BCE\u56DE\u5272\u308A\u7B97\
    \u3057\u306A\u3044\u3088\u3046\u306B\u6301\u3063\u3066\u304A\u304F)\n\n   public:\n\
    \    /**\n     * @brief [0, h) \xD7 [0, w)\n     */\n    constexpr Rect(long long\
    \ h, long long w) : rows(h), cols(w), width(cols.size()) {}\n    constexpr Rect(const\
    \ Range& _rows, const Range& _cols) : rows(_rows), cols(_cols), width(cols.size())\
    \ {}\n    constexpr Rect(const Rect& o) = default;\n    Rect& operator=(const\
    \ Rect& o) = delete;\n\n    struct const_iterator {\n       public:\n        using\
    \ difference_type = Rect::difference_type;\n        using value_type = Rect::value_type;\n\
    \        using pointer = void;\n        using reference = value_type;\n      \
    \  using iterator_category = std::forward_iterator_tag;\n\n       private:\n \
    \       const Rect* rect = nullptr;\n        long long w = 0;   // cols.size()\n\
    \        long long ic = 0;  // rows \u306E\u4F55\u756A\u76EE\u304B\n        long\
    \ long jc = 0;  // cols \u306E\u4F55\u756A\u76EE\u304B\n\n       public:\n   \
    \     constexpr const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Rect* _rect, long long _w, long long _ic, long long _jc) noexcept\n        \
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
    \ (rows\u30FBcols \u306E\u4E2D\u3067\u306E\u4F4D\u7F6E\u306E\u5DEE) \u3092 Rect\
    \ \u306E\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5148\u982D 4 \u3064\u306F\
    \u4E0A\u4E0B\u5DE6\u53F3\u3060\u3051\u3092\u4E26\u3079\u305F\u5225\u306E\u8868\
    \n    // 4 \u8FD1\u508D\u3068 8 \u8FD1\u508D\u306E\u5883\u76EE\u304C\u5206\u304B\
    \u308B\u3088\u3046\u306B 2 \u884C\u306B\u5206\u3051\u3066\u3044\u308B\u306E\u3067\
    \u6574\u5F62\u3057\u306A\u3044\n    // clang-format off\n    static constexpr\
    \ int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0},\n            \
    \                                     {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,\
    \ 1}, {1, -1}, {1, 0}, {1, 1}};\n    // clang-format on\n\n   public:\n    /**\n\
    \     * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2\
    \ for \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Rect \u306B\u542B\
    \u307E\u308C\u308B\u65B9\u5411\u3092\u30D3\u30C3\u30C8\u3067\u6301\u3063\u3066\
    \u304A\u304D\u3001\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u9806\
    \u306B\u8FD4\u3059\n     */\n    struct Neighbors {\n        long long i, j, row_step,\
    \ col_step;\n        int first;      // neighbor_dirs[first + k] \u304C\u30D3\u30C3\
    \u30C8 k \u306E\u65B9\u5411\n        unsigned mask;  // Rect \u306B\u542B\u307E\
    \u308C\u308B\u65B9\u5411\n\n        struct iterator {\n            using difference_type\
    \ = std::ptrdiff_t;\n            using value_type = Rect::value_type;\n      \
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
    \u3046\u3061 Rect \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Rect \u306E\
    \u9806\u306B\u8FD4\u3059\n     * \u96A3\u306F rows\u30FBcols \u306E\u4E2D\u3067\
    \u96A3\u308A\u5408\u3046\u8981\u7D20 (i \xB1 rows.step \u306A\u3069)\u3002(i,\
    \ j) \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr Neighbors neighbors4(long long i, long long j) const {\n       \
    \ return neighbors(i, j, 0, 4);\n    }\n    constexpr Neighbors neighbors4(const\
    \ value_type& p) const {\n        return neighbors4(p.first, p.second);\n    }\n\
    \    /**\n     * @brief (i, j) \u3092\u56F2\u3080 8 \u3064\u306E\u3046\u3061 Rect\
    \ \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Rect \u306E\u9806\u306B\
    \u8FD4\u3059\n     */\n    constexpr Neighbors neighbors8(long long i, long long\
    \ j) const {\n        return neighbors(i, j, 4, 12);\n    }\n    constexpr Neighbors\
    \ neighbors8(const value_type& p) const {\n        return neighbors8(p.first,\
    \ p.second);\n    }\n\n    static std::string type_str() {\n        return \"\
    Rect\";\n    }\n    std::string initializer_str() const {\n        return \"{\"\
    \ + rows.initializer_str() + \", \" + cols.initializer_str() + \"}\";\n    }\n\
    \    std::string repr() const {\n        return \"Rect(\" + rows.repr() + \",\
    \ \" + cols.repr() + \")\";\n    }\n\n    constexpr friend bool operator==(const\
    \ Rect& a, const Rect& b) noexcept {\n        if (a.empty() && b.empty()) return\
    \ true;\n        return a.rows == b.rows && a.cols == b.cols;\n    }\n    constexpr\
    \ friend bool operator!=(const Rect& a, const Rect& b) noexcept {\n        return\
    \ !(a == b);\n    }\n};\n#line 6 \"test/aoj/itp1/itp1-7-b.test.cpp\"\n\nint main()\
    \ {\n    long long n, x;\n    while (std::cin >> n >> x && (n != 0 || x != 0))\
    \ {\n        int cnt = 0;\n        for (long long a : Range(1, n + 1)) {\n   \
    \         for (long long b : Range(a + 1, n + 1)) {\n                for (long\
    \ long c : Range(b + 1, n + 1)) {\n                    if (a + b + c == x) cnt++;\n\
    \                }\n            }\n        }\n        std::cout << cnt << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B\"\
    \n\n#include <iostream>\n\n#include \"../../../src/utility/range.hpp\"\n\nint\
    \ main() {\n    long long n, x;\n    while (std::cin >> n >> x && (n != 0 || x\
    \ != 0)) {\n        int cnt = 0;\n        for (long long a : Range(1, n + 1))\
    \ {\n            for (long long b : Range(a + 1, n + 1)) {\n                for\
    \ (long long c : Range(b + 1, n + 1)) {\n                    if (a + b + c ==\
    \ x) cnt++;\n                }\n            }\n        }\n        std::cout <<\
    \ cnt << '\\n';\n    }\n}\n"
  dependsOn:
  - src/utility/range.hpp
  isVerificationFile: true
  path: test/aoj/itp1/itp1-7-b.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:37:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp1/itp1-7-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp1/itp1-7-b.test.cpp
- /verify/test/aoj/itp1/itp1-7-b.test.cpp.html
title: test/aoj/itp1/itp1-7-b.test.cpp
---
