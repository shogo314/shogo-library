---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Grid"
  - icon: ':question:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
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
  bundledCode: "#line 1 \"test/unittest/string/rolling-hash.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ RHString \u3092 std::string \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\
    \u7D50\u679C\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u7AEF\
    \u306E\u524A\u9664 (remove_prefix\u30FBremove_suffix) \u3082\u3001\u6B8B\u308A\
    \u306E\u6587\u5B57\u5217\u304B\u3089\u4F5C\u3063\u305F RHString \u3068\u6BD4\u3079\
    \u308B\n// RollingHash2D \u3068 pattern_match_2d \u3092\u3001\u9577\u65B9\u5F62\
    \u3092\u76F4\u63A5\u6BD4\u3079\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B (std::vector<std::vector<int>>\
    \ \u3067\u3082\u4F5C\u308B)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/string/rolling-hash.hpp\"\n\n/**\n *\
    \ @file rolling-hash.hpp\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\n */\n\n#include <cassert>\n#include <iterator>\n#include <random>\n\
    #include <string>\n#include <string_view>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/utility/range.hpp\"\n\n/**\n * @file range.hpp\n\
    \ * @brief Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\
    \u3001\u305D\u306E\u76F4\u7A4D\u306E Grid\n */\n\n#line 9 \"src/utility/range.hpp\"\
    \n#include <cstddef>\n#line 15 \"src/utility/range.hpp\"\n\nstruct Range {\n \
    \  public:\n    using value_type = long long;\n    using const_reference = const\
    \ value_type&;\n    using size_type = long long;\n    using difference_type =\
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
    \ !(a == b);\n    }\n};\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include\
    \ <functional>\n#line 11 \"src/utility/traits.hpp\"\n#include <set>\n#line 14\
    \ \"src/utility/traits.hpp\"\n\nnamespace internal_traits {\nusing std::begin,\
    \ std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 19 \"src/string/rolling-hash.hpp\"\n\nstruct RHString;\nclass RollingHash2D;\n\
    \n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n\
    \ * \u30D3\u30C3\u30C8\u6F14\u7B97\u306B\u3088\u308B\u9AD8\u901F\u5316\u306E\u305F\
    \u3081\u30CF\u30C3\u30B7\u30E5\u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\
    \u308B\n *\n * 10^8\u500B\u304F\u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\u3067\
    \u885D\u7A81\u3059\u308B\u7D44\u304C\u5B58\u5728\u3057\u306A\u3044\n */\nclass\
    \ RollingHash {\n    constexpr static unsigned long long MASK30 = (1ULL << 30)\
    \ - 1;\n    constexpr static unsigned long long MASK31 = (1ULL << 31) - 1;\n \
    \   constexpr static unsigned long long MOD = (1ULL << 61) - 1;\n\n    // a <\
    \ MOD, b < MOD\u5FC5\u9808\n    constexpr static unsigned long long add(unsigned\
    \ long long a, unsigned long long b) {\n        if ((a += b) >= MOD) a -= MOD;\n\
    \        return a;\n    }\n\n    // a < MOD, b < MOD\u5FC5\u9808\n    constexpr\
    \ static unsigned long long mul(unsigned long long a, unsigned long long b) {\n\
    \        __uint128_t c = static_cast<__uint128_t>(a) * b;\n        return add(static_cast<unsigned\
    \ long long>(c >> 61), static_cast<unsigned long long>(c & MOD));\n    }\n\n \
    \   void expand(long long n) {\n        while (static_cast<long long>(power.size())\
    \ <= n) power.push_back(mul(power.back(), base));\n    }\n    // base \u306E\u9006\
    \u5143\u306E\u7D2F\u4E57\u3092 n \u4E57\u307E\u3067\u7528\u610F\u3059\u308B (RHString\
    \ \u306E\u7AEF\u3092\u524A\u308B\u3068\u304D\u3060\u3051\u4F7F\u3046)\n    void\
    \ expand_inv(long long n) {\n        if (inv_power.empty()) {\n            //\
    \ MOD \u306F\u7D20\u6570\u306A\u306E\u3067 base^(MOD - 2) \u304C\u9006\u5143\n\
    \            unsigned long long inv = 1, b = base, e = MOD - 2;\n            for\
    \ (; e > 0; e >>= 1, b = mul(b, b))\n                if (e & 1) inv = mul(inv,\
    \ b);\n            inv_base = inv;\n            inv_power = {1};\n        }\n\
    \        while (static_cast<long long>(inv_power.size()) <= n) inv_power.push_back(mul(inv_power.back(),\
    \ inv_base));\n    }\n    unsigned long long inv_base = 0;\n    std::vector<unsigned\
    \ long long> inv_power;  // base \u306E\u9006\u5143\u306E\u7D2F\u4E57\n\n   public:\n\
    \    /**\n     * @brief \u8981\u7D20\u3092[0, MOD)\u306E\u5024\u306B\u5909\u63DB\
    \u3059\u308B\n     * @note char\u306F\u7B26\u53F7\u306B\u95A2\u308F\u3089\u305A\
    0~255\u3068\u3057\u3066\u6271\u3046 \u8CA0\u306E\u6574\u6570\u306FMOD\u3067\u6B63\
    \u898F\u5316\u3059\u308B\n     */\n    template <typename T>\n    constexpr static\
    \ unsigned long long to_value(const T& x) {\n        using U = std::decay_t<T>;\n\
    \        if constexpr (std::is_same_v<U, char> || std::is_same_v<U, signed char>)\
    \ {\n            return static_cast<unsigned char>(x);\n        } else if constexpr\
    \ (std::is_integral_v<U> && std::is_signed_v<U>) {\n            long long v =\
    \ static_cast<long long>(x) % static_cast<long long>(MOD);\n            return\
    \ v < 0 ? v + MOD : v;\n        } else {\n            return static_cast<unsigned\
    \ long long>(x) % MOD;\n        }\n    }\n\n    unsigned int base;           \
    \           //!< \u30CF\u30C3\u30B7\u30E5\u306E\u57FA\u6570\n    std::vector<unsigned\
    \ long long> power;  //!< base\u306E\u7D2F\u4E57\n\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param base \u30CF\u30C3\u30B7\
    \u30E5\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\
    \n     */\n    explicit RollingHash(unsigned int base = 0) : base(base) {\n  \
    \      if (base == 0) {\n            std::mt19937 mt(std::random_device{}());\n\
    \            this->base = std::uniform_int_distribution<unsigned int>(129, ~0U)(mt);\n\
    \        }\n        power = {1};\n    }\n\n    /**\n     * @brief \u914D\u5217\
    /\u6587\u5B57\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u9593\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n     *\n     * @tparam It \u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @param first \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @param last \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @return std::vector<unsigned long long> \u5148\u982D\u304B\
    \u3089\u5404\u8981\u7D20\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n\
    \    template <typename It>\n    std::vector<unsigned long long> build(It first,\
    \ It last) {\n        std::vector<unsigned long long> res;\n        if constexpr\
    \ (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category,\
    \ std::random_access_iterator_tag>) {\n            res.reserve(last - first +\
    \ 1);\n        }\n        res.push_back(0);\n        for (; first != last; ++first)\
    \ {\n            res.push_back(add(mul(res.back(), base), to_value(*first)));\n\
    \        }\n        return res;\n    }\n\n    /**\n     * @brief \u914D\u5217\
    /\u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97\
    (O(N))\n     *\n     * @param s \u914D\u5217/\u6587\u5B57\u5217\n     * @return\
    \ std::vector<unsigned long long> \u5148\u982D\u304B\u3089\u5404\u6587\u5B57\u6570\
    \u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    template <typename R>\n   \
    \ std::vector<unsigned long long> build(R&& s) {\n        using std::begin, std::end;\n\
    \        return build(begin(s), end(s));\n    }\n\n    /**\n     * @brief [l,r)\u306E\
    \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(1))\n     *\n     * @param hash \u5148\
    \u982D\u304B\u3089\u306E\u30CF\u30C3\u30B7\u30E5\n     * @param l \u533A\u9593\
    \u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ unsigned long long [l,r)\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    unsigned\
    \ long long query(const std::vector<unsigned long long>& hash, long long l, long\
    \ long r) {\n        assert(0 <= l && l <= r && r < static_cast<long long>(hash.size()));\n\
    \        expand(r - l);\n        return add(hash[r], MOD - mul(hash[l], power[r\
    \ - l]));\n    }\n\n    friend RHString;\n    friend RollingHash2D;\n};\n\n/**\n\
    \ * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306B\u3088\u3063\
    \u3066\u7BA1\u7406\u3055\u308C\u308B\u6587\u5B57\u5217\u578B\n */\nstruct RHString\
    \ {\n    RollingHash& rh;\n    long long sz;              //!< \u9577\u3055\n\
    \    unsigned long long hash1;  //!< \u6B63\u9806\n    unsigned long long hash2;\
    \  //!< \u9006\u9806\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     * \u4E88\u3081RollingHash\u3092\u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\
    \u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\n     */\n    explicit\
    \ RHString(RollingHash& rh) : rh(rh), sz(0), hash1(0), hash2(0) {}\n    RHString(RollingHash&\
    \ rh, long long sz, unsigned long long hash1, unsigned long long hash2) : rh(rh),\
    \ sz(sz), hash1(hash1), hash2(hash2) {}\n    RHString(const RHString& o) : rh(o.rh),\
    \ sz(o.sz), hash1(o.hash1), hash2(o.hash2) {}\n    /**\n     * @brief vector\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>)>\n    RHString(RollingHash&\
    \ rh, R&& v) : rh(rh) {\n        using std::begin, std::end, std::rbegin, std::rend;\n\
    \        sz = static_cast<long long>(std::distance(begin(v), end(v)));\n     \
    \   hash1 = rh.build(begin(v), end(v)).back();\n        hash2 = rh.build(rbegin(v),\
    \ rend(v)).back();\n    }\n    /**\n     * @brief char\u3084unsigned long long\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString(RollingHash&\
    \ rh, T&& x) : rh(rh) {\n        sz = 1;\n        hash1 = RollingHash::to_value(x);\n\
    \        hash2 = hash1;\n    }\n    /**\n     * @brief \u6587\u5B57\u5217(string,\
    \ const char*, string_view)\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n   \
    \ RHString(RollingHash& rh, std::string_view s) : rh(rh) {\n        sz = static_cast<long\
    \ long>(s.size());\n        hash1 = rh.build(s.begin(), s.end()).back();\n   \
    \     hash2 = rh.build(s.rbegin(), s.rend()).back();\n    }\n\n    /**\n     *\
    \ @brief \u56DE\u6587\u304B\u5426\u304B\n     */\n    bool is_palindrome() const\
    \ {\n        return hash1 == hash2;\n    }\n    long long size() const {\n   \
    \     return sz;\n    }\n    void clear() {\n        sz = 0;\n        hash1 =\
    \ 0;\n        hash2 = 0;\n    }\n    bool empty() const {\n        return sz ==\
    \ 0;\n    }\n    /**\n     * @brief \u5148\u982D\u306E t \u3092\u53D6\u308A\u9664\
    \u304F (\u5148\u982D\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\u30C3\u30B7\
    \u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\u306E\u3067\
    \u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\u4E57\u306E\
    \u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t \u306F RHString\
    \ \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\n     */\n\
    \    void remove_prefix(const RHString& t) {\n        assert(&rh == &t.rh && t.sz\
    \ <= sz);\n        // s = t + u \u304B\u3089 u: hash1(u) = hash1(s) - hash1(t)\
    \ B^|u|\u3001hash2(u) = (hash2(s) - hash2(t)) B^-|t|\n        const long long\
    \ u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n      \
    \  hash1 = rh.add(hash1, RollingHash::MOD - rh.mul(t.hash1, rh.power[u]));\n \
    \       hash2 = rh.mul(rh.add(hash2, RollingHash::MOD - t.hash2), rh.inv_power[t.sz]);\n\
    \        sz = u;\n    }\n    /**\n     * @brief \u672B\u5C3E\u306E t \u3092\u53D6\
    \u308A\u9664\u304F (\u672B\u5C3E\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\
    \u30C3\u30B7\u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\
    \u306E\u3067\u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\
    \u4E57\u306E\u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t\
    \ \u306F RHString \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\
    \u306E (\u6587\u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\
    \n     */\n    void remove_suffix(const RHString& t) {\n        assert(&rh ==\
    \ &t.rh && t.sz <= sz);\n        // s = u + t \u304B\u3089 u: hash1(u) = (hash1(s)\
    \ - hash1(t)) B^-|t|\u3001hash2(u) = hash2(s) - hash2(t) B^|u|\n        const\
    \ long long u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n\
    \        hash1 = rh.mul(rh.add(hash1, RollingHash::MOD - t.hash1), rh.inv_power[t.sz]);\n\
    \        hash2 = rh.add(hash2, RollingHash::MOD - rh.mul(t.hash2, rh.power[u]));\n\
    \        sz = u;\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_prefix(T&& x) {\n        remove_prefix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_suffix(T&& x) {\n        remove_suffix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    RHString& operator+=(const RHString& o) {\n\
    \        assert(&rh == &o.rh);\n        rh.expand(sz);\n        rh.expand(o.sz);\n\
    \        hash1 = rh.add(rh.mul(hash1, rh.power[o.sz]), o.hash1);\n        hash2\
    \ = rh.add(hash2, rh.mul(o.hash2, rh.power[sz]));\n        sz += o.sz;\n     \
    \   return *this;\n    }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\
    \n     * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n     */\n    void assign(const RHString& o) {\n        assert(&rh\
    \ == &o.rh);\n        sz = o.sz;\n        hash1 = o.hash1;\n        hash2 = o.hash2;\n\
    \    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\
    \u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R> && !std::is_convertible_v<R,\
    \ std::string_view>)>\n    void assign(R&& v) {\n        using std::begin, std::end,\
    \ std::rbegin, std::rend;\n        sz = static_cast<long long>(std::distance(begin(v),\
    \ end(v)));\n        hash1 = rh.build(begin(v), end(v)).back();\n        hash2\
    \ = rh.build(rbegin(v), rend(v)).back();\n    }\n    /**\n     * @brief char\u3084\
    unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n\
    \    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned long long>\
    \ && !std::is_convertible_v<T, std::string_view>)>\n    void assign(T&& x) {\n\
    \        sz = 1;\n        hash1 = RollingHash::to_value(x);\n        hash2 = hash1;\n\
    \    }\n    /**\n     * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3092\
    \u518D\u4EE3\u5165\u3059\u308B\n     */\n    void assign(std::string_view s) {\n\
    \        sz = static_cast<long long>(s.size());\n        hash1 = rh.build(s.begin(),\
    \ s.end()).back();\n        hash2 = rh.build(s.rbegin(), s.rend()).back();\n \
    \   }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\n     * RollingHash\u306F\
    \u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \  */\n    RHString& operator=(const RHString& o) {\n        assign(o);\n    \
    \    return *this;\n    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\
    \u4EE3\u5165\u3059\u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>)>\n    RHString& operator=(R&&\
    \ v) {\n        assign(v);\n        return *this;\n    }\n    /**\n     * @brief\
    \ char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\
    \n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned\
    \ long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString& operator=(T&&\
    \ x) {\n        assign(x);\n        return *this;\n    }\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\
    \u3059\u308B\n     */\n    RHString& operator=(std::string_view s) {\n       \
    \ assign(s);\n        return *this;\n    }\n    friend RHString operator+(const\
    \ RHString& t1, const RHString& t2) {\n        RHString ret = t1;\n        ret\
    \ += t2;\n        return ret;\n    }\n    friend bool operator==(const RHString&\
    \ t1, const RHString& t2) {\n        assert(&t1.rh == &t2.rh);\n        return\
    \ t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n    }\n   \
    \ friend bool operator!=(const RHString& t1, const RHString& t2) { return !(t1\
    \ == t2); }\n};\n\n/**\n * @brief 2 \u6B21\u5143\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u884C\u65B9\u5411\u3068\u5217\u65B9\u5411\
    \u3067\u5225\u306E\u57FA\u6570\u3092\u4F7F\u3044\u3001\u8868\u306E\u5DE6\u4E0A\
    \u304B\u3089\u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5\u3067\u9577\u65B9\u5F62\
    \u306E\u30CF\u30C3\u30B7\u30E5\u3092 O(1) \u3067\u6C42\u3081\u308B\n * H[i][j]\
    \ = \u03A3_{a < i, b < j} v[a][b] base1^(i-1-a) base2^(j-1-b)\n */\nclass RollingHash2D\
    \ {\n    using ull = unsigned long long;\n    RollingHash rh1, rh2;  // \u884C\
    \u65B9\u5411 (\u4E0A\u4E0B) \u3068\u5217\u65B9\u5411 (\u5DE6\u53F3)\n\n    static\
    \ ull add(ull a, ull b) { return RollingHash::add(a, b); }\n    static ull sub(ull\
    \ a, ull b) { return RollingHash::add(a, RollingHash::MOD - b); }\n    static\
    \ ull mul(ull a, ull b) { return RollingHash::mul(a, b); }\n\n   public:\n   \
    \ /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n    \
    \ * @param base1 \u884C\u65B9\u5411\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\
    \u3068\u30E9\u30F3\u30C0\u30E0\n     * @param base2 \u5217\u65B9\u5411\u306E\u57FA\
    \u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\n     */\n    explicit\
    \ RollingHash2D(unsigned int base1 = 0, unsigned int base2 = 0) : rh1(base1),\
    \ rh2(base2) {}\n\n    /**\n     * @brief \u8868 (std::vector<std::string> \u3084\
    \ std::vector<std::vector<T>>) \u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5 O(HW)\n\
    \     *\n     * @return std::vector<std::vector<unsigned long long>> (H + 1) \u884C\
    \ (W + 1) \u5217\u306E\u8868\u3002[i][j] \u306F\u5DE6\u4E0A i \u884C j \u5217\u306E\
    \u30CF\u30C3\u30B7\u30E5\n     */\n    template <typename Grid>\n    std::vector<std::vector<ull>>\
    \ build(const Grid& grid) {\n        using std::size;\n        const long long\
    \ h = size(grid), w = h == 0 ? 0 : size(grid[0]);\n        std::vector<std::vector<ull>>\
    \ res(h + 1, std::vector<ull>(w + 1, 0));\n        const ull b1 = rh1.base, b2\
    \ = rh2.base, b12 = mul(b1, b2);\n        for (long long i = 0; i < h; i++) {\n\
    \            assert(static_cast<long long>(size(grid[i])) == w);\n           \
    \ for (long long j = 0; j < w; j++) {\n                ull v = add(mul(res[i][j\
    \ + 1], b1), mul(res[i + 1][j], b2));\n                res[i + 1][j + 1] = add(sub(v,\
    \ mul(res[i][j], b12)), RollingHash::to_value(grid[i][j]));\n            }\n \
    \       }\n        return res;\n    }\n\n    /**\n     * @brief region \u306E\u30CF\
    \u30C3\u30B7\u30E5 O(1) (\u521D\u56DE\u306F\u9577\u3055\u5206)\u3002\u884C\u30FB\
    \u5217\u306E step \u306F 1\n     */\n    ull query(const std::vector<std::vector<ull>>&\
    \ hash, const Grid& region) {\n        assert(region.rows.step == 1 && region.cols.step\
    \ == 1);\n        const long long i1 = region.rows.start, i2 = region.rows.stop;\n\
    \        const long long j1 = region.cols.start, j2 = region.cols.stop;\n    \
    \    assert(0 <= i1 && i1 <= i2 && i2 < static_cast<long long>(hash.size()));\n\
    \        assert(0 <= j1 && j1 <= j2 && j2 < static_cast<long long>(hash[0].size()));\n\
    \        rh1.expand(i2 - i1);\n        rh2.expand(j2 - j1);\n        ull p1 =\
    \ rh1.power[i2 - i1], p2 = rh2.power[j2 - j1];\n        ull res = sub(hash[i2][j2],\
    \ mul(hash[i1][j2], p1));\n        res = sub(res, mul(hash[i2][j1], p2));\n  \
    \      return add(res, mul(mul(hash[i1][j1], p1), p2));\n    }\n};\n\n/**\n *\
    \ @brief \u8868 text \u306E\u4E2D\u3067\u3001\u8868 pattern \u3068\u4E00\u81F4\
    \u3059\u308B\u90E8\u5206\u306E\u5DE6\u4E0A\u306E\u4F4D\u7F6E (\u884C, \u5217)\
    \ \u3092\u3059\u3079\u3066\u6C42\u3081\u308B O(HW + hw)\n *\n * 2 \u6B21\u5143\
    \u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3067\u6BD4\u3079\
    \u308B\u3002\u884C\u306E\u6607\u9806\u3001\u540C\u3058\u884C\u306A\u3089\u5217\
    \u306E\u6607\u9806\u306B\u4E26\u3079\u308B\n * pattern \u306F 1 \u884C 1 \u5217\
    \u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\n */\ntemplate <typename Grid1, typename\
    \ Grid2>\nstd::vector<std::pair<long long, long long>> pattern_match_2d(const\
    \ Grid1& text, const Grid2& pattern) {\n    using std::size;\n    const long long\
    \ h = size(text), w = h == 0 ? 0 : size(text[0]);\n    const long long ph = size(pattern),\
    \ pw = ph == 0 ? 0 : size(pattern[0]);\n    assert(ph > 0 && pw > 0);\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    if (ph > h || pw > w) return res;\n    RollingHash2D\
    \ rh;\n    auto th = rh.build(text), pht = rh.build(pattern);\n    unsigned long\
    \ long target = rh.query(pht, Grid(ph, pw));\n    for (auto [i, j] : Grid(h -\
    \ ph + 1, w - pw + 1)) {\n        if (rh.query(th, Grid({i, i + ph}, {j, j + pw}))\
    \ == target) res.emplace_back(i, j);\n    }\n    return res;\n}\n#line 9 \"test/unittest/string/rolling-hash.test.cpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#line 17 \"test/unittest/string/rolling-hash.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    RollingHash rh(1000003);\n\
    \    bool ok = true;\n    auto check = [&](bool cond, const char* what) {\n  \
    \      if (!cond) {\n            if (ok) std::cerr << \"failed: \" << what <<\
    \ std::endl;\n            ok = false;\n        }\n    };\n    auto random_string\
    \ = [&](int max_len) {\n        std::string s(rng() % (max_len + 1), 'a');\n \
    \       for (char& c : s) c = 'a' + rng() % 3;  // \u56DE\u6587\u3084\u4E00\u81F4\
    \u304C\u8D77\u304D\u3084\u3059\u3044\u3088\u3046\u6587\u5B57\u3092\u7D5E\u308B\
    \n        return s;\n    };\n    auto is_palindrome = [](const std::string& s)\
    \ { return std::equal(s.begin(), s.end(), s.rbegin()); };\n    // RHString \u306E\
    \u4E2D\u8EAB\u304C s \u3068\u4E00\u81F4\u3059\u308B\u304B (\u9577\u3055\u30FB\u6B63\
    \u9806\u306E\u30CF\u30C3\u30B7\u30E5\u30FB\u9006\u9806\u306E\u30CF\u30C3\u30B7\
    \u30E5)\n    auto same = [&](const RHString& t, const std::string& s) {\n    \
    \    std::string r(s.rbegin(), s.rend());\n        return t.size() == static_cast<long\
    \ long>(s.size()) && t.hash1 == rh.build(s).back() && t.hash2 == rh.build(r).back();\n\
    \    };\n\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        std::string\
    \ s = random_string(8), t = random_string(8);\n\n        // \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF: \u6587\u5B57\u5217 (std::string / const char* / string_view)\u30FB\
    vector\u30FB1 \u6587\u5B57\u30FB\u7A7A\u30FB\u30B3\u30D4\u30FC\u30FB\u30CF\u30C3\
    \u30B7\u30E5\u5024\u304B\u3089\n        RHString a(rh, s), b(rh, t);\n       \
    \ check(same(a, s) && same(b, t), \"string constructor\");\n        check(same(RHString(rh,\
    \ s.c_str()), s), \"const char* constructor\");\n        check(same(RHString(rh,\
    \ std::string_view(s)), s), \"string_view constructor\");\n        std::vector<char>\
    \ sv(s.begin(), s.end());\n        check(same(RHString(rh, sv), s), \"vector constructor\"\
    );\n        RHString empty(rh);\n        check(empty.empty() && empty.size() ==\
    \ 0 && same(empty, \"\"), \"empty constructor\");\n        if (!s.empty()) check(same(RHString(rh,\
    \ s[0]), s.substr(0, 1)), \"char constructor\");\n        RHString copy(a);\n\
    \        check(copy == a && same(copy, s), \"copy constructor\");\n        RHString\
    \ raw(rh, a.size(), a.hash1, a.hash2);\n        check(raw == a, \"hash constructor\"\
    );\n\n        // \u9023\u7D50: +, +=\n        check(same(a + b, s + t), \"operator+\"\
    );\n        RHString c = a;\n        c += b;\n        check(same(c, s + t), \"\
    operator+=\");\n        RHString d(rh);\n        for (char ch : s) d += RHString(rh,\
    \ ch);\n        check(same(d, s) && d == a, \"operator+= char by char\");\n\n\
    \        // \u6BD4\u8F03: \u6587\u5B57\u5217\u304C\u7B49\u3057\u3044\u3068\u304D\
    \u3060\u3051\u7B49\u3057\u3044\n        check((a == b) == (s == t), \"operator==\"\
    );\n        check((a != b) == (s != t), \"operator!=\");\n        check(a + b\
    \ == RHString(rh, s + t), \"concat equals whole\");\n\n        // \u56DE\u6587\
    \u5224\u5B9A\n        check(a.is_palindrome() == is_palindrome(s), \"is_palindrome\"\
    );\n        check((a + b).is_palindrome() == is_palindrome(s + t), \"is_palindrome\
    \ concat\");\n\n        // size, empty, clear\n        check(a.size() == static_cast<long\
    \ long>(s.size()) && a.empty() == s.empty(), \"size/empty\");\n        RHString\
    \ e = a;\n        e.clear();\n        check(e.empty() && e.size() == 0 && e ==\
    \ empty, \"clear\");\n\n        // assign \u3068 operator= \u306E\u5404\u7248\n\
    \        RHString f(rh);\n        f.assign(a);\n        check(f == a, \"assign(RHString)\"\
    );\n        f.assign(t);\n        check(same(f, t), \"assign(string)\");\n   \
    \     f.assign(std::string_view(s));\n        check(same(f, s), \"assign(string_view)\"\
    );\n        std::vector<char> tv(t.begin(), t.end());\n        f.assign(tv);\n\
    \        check(same(f, t), \"assign(vector)\");\n        f.assign('b');\n    \
    \    check(same(f, \"b\"), \"assign(char)\");\n        f = b;\n        check(f\
    \ == b, \"operator=(RHString)\");\n        f = s;\n        check(same(f, s), \"\
    operator=(string)\");\n        f = std::string_view(t);\n        check(same(f,\
    \ t), \"operator=(string_view)\");\n        f = sv;\n        check(same(f, s),\
    \ \"operator=(vector)\");\n        f = 'c';\n        check(same(f, \"c\"), \"\
    operator=(char)\");\n    }\n\n    // \u6574\u6570\u306E\u5217 (\u8CA0\u306E\u5024\
    \u3092\u542B\u3080) \u3067\u3082\u3001\u9023\u7D50\u3068\u6BD4\u8F03\u304C\u5217\
    \u3068\u3057\u3066\u306E\u4E00\u81F4\u3068\u5BFE\u5FDC\u3059\u308B\n    for (int\
    \ rep = 0; rep < 1000 && ok; rep++) {\n        std::vector<long long> x(rng()\
    \ % 6), y(rng() % 6);\n        for (auto& v : x) v = static_cast<long long>(rng()\
    \ % 5) - 2;\n        for (auto& v : y) v = static_cast<long long>(rng() % 5) -\
    \ 2;\n        std::vector<long long> xy = x;\n        xy.insert(xy.end(), y.begin(),\
    \ y.end());\n        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);\n        check(hx\
    \ + hy == hxy, \"vector<long long> concat\");\n        check((hx == hy) == (x\
    \ == y), \"vector<long long> equality\");\n        check(hx.is_palindrome() ==\
    \ std::equal(x.begin(), x.end(), x.rbegin()), \"vector<long long> palindrome\"\
    );\n    }\n\n    // remove_prefix / remove_suffix: s = t + u \u3084 s = u + t\
    \ \u304B\u3089 t \u3092\u53D6\u308A\u9664\u304F\u3068\u3001u \u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    // \u56DE\u6587\u306E\
    \u5224\u5B9A (\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5) \u3082\u4E00\u81F4\u3057\
    \u3001\u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570\u3067\u3082\u6210\u308A\u7ACB\
    \u3064\n    RollingHash random_rh;\n    for (RollingHash* r : {&rh, &random_rh})\
    \ {\n        for (int rep = 0; rep < 3000 && ok; rep++) {\n            std::string\
    \ t = random_string(8), u = random_string(8);\n            RHString a(*r, t +\
    \ u), b(*r, u + t);\n            a.remove_prefix(RHString(*r, t));\n         \
    \   b.remove_suffix(t);  // RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u5217) \u3092\u76F4\u63A5\u6E21\u3059\n            RHString hu(*r, u);\n\
    \            check(a == hu && a.size() == static_cast<long long>(u.size()), \"\
    remove_prefix\");\n            check(b == hu && b.size() == static_cast<long long>(u.size()),\
    \ \"remove_suffix\");\n            check(a.is_palindrome() == is_palindrome(u)\
    \ && b.is_palindrome() == is_palindrome(u), \"remove \u5F8C\u306E is_palindrome\"\
    );\n            // \u53D6\u308A\u9664\u3044\u305F\u3042\u3068\u306B\u9023\u7D50\
    \u3057\u3066\u3082\u6B63\u3057\u3044\n            check(a + RHString(*r, t) ==\
    \ RHString(*r, u + t), \"remove \u5F8C\u306E\u9023\u7D50\");\n        }\n    }\n\
    \    // 1 \u6587\u5B57\u305A\u3064 push_back \u3068 pop_front \u3092\u3057\u3066\
    \u3001\u9577\u3055 k \u306E\u7A93\u3092\u52D5\u304B\u3059\n    {\n        std::string\
    \ s = random_string(200);\n        const int k = 5;\n        RHString w(rh);\n\
    \        for (int i = 0; i < static_cast<int>(s.size()); i++) {\n            w\
    \ += RHString(rh, s[i]);\n            if (i >= k) w.remove_prefix(s[i - k]); \
    \ // \u6587\u5B57\u3092\u76F4\u63A5\u6E21\u3059\n            int l = std::max(0,\
    \ i - k + 1);\n            check(w == RHString(rh, s.substr(l, i - l + 1)), \"\
    \u7A93\");\n        }\n    }\n\n    // 2 \u6B21\u5143\n    for (int rep = 0; rep\
    \ < 2000 && ok; rep++) {\n        int h = rng() % 6, w = rng() % 6, ph = rng()\
    \ % 3 + 1, pw = rng() % 3 + 1, k = rng() % 2 + 1;\n        std::vector<std::string>\
    \ text(h, std::string(w, 'a')), pattern(ph, std::string(pw, 'a'));\n        for\
    \ (auto& row : text)\n            for (auto& ch : row) ch = 'a' + rng() % k;\n\
    \        for (auto& row : pattern)\n            for (auto& ch : row) ch = 'a'\
    \ + rng() % k;\n        // \u9577\u65B9\u5F62\u3069\u3046\u3057\u306E\u30CF\u30C3\
    \u30B7\u30E5\u304C\u3001\u4E2D\u8EAB\u304C\u540C\u3058\u3068\u304D\u306B\u9650\
    \u308A\u4E00\u81F4\u3059\u308B\n        RollingHash2D rh2;\n        auto th =\
    \ rh2.build(text);\n        for (int t = 0; t < 20 && h > 0 && w > 0; t++) {\n\
    \            int i1 = rng() % (h + 1), i2 = rng() % (h + 1), j1 = rng() % (w +\
    \ 1), j2 = rng() % (w + 1);\n            if (i1 > i2) std::swap(i1, i2);\n   \
    \         if (j1 > j2) std::swap(j1, j2);\n            int a = rng() % (h - (i2\
    \ - i1) + 1), b = rng() % (w - (j2 - j1) + 1);\n            bool same = true;\n\
    \            for (int i = 0; i < i2 - i1; i++)\n                for (int j = 0;\
    \ j < j2 - j1; j++) same &= text[i1 + i][j1 + j] == text[a + i][b + j];\n    \
    \        bool eq = rh2.query(th, Grid({i1, i2}, {j1, j2})) == rh2.query(th, Grid({a,\
    \ a + i2 - i1}, {b, b + j2 - j1}));\n            if (eq != same) ok = false;\n\
    \        }\n        std::vector<std::pair<long long, long long>> expected;\n \
    \       for (int i = 0; i + ph <= h; i++) {\n            for (int j = 0; j + pw\
    \ <= w; j++) {\n                bool match = true;\n                for (int a\
    \ = 0; a < ph; a++)\n                    for (int b = 0; b < pw; b++) match &=\
    \ text[i + a][j + b] == pattern[a][b];\n                if (match) expected.emplace_back(i,\
    \ j);\n            }\n        }\n        if (pattern_match_2d(text, pattern) !=\
    \ expected) ok = false;\n        std::vector<std::vector<int>> ti(h, std::vector<int>(w)),\
    \ pi(ph, std::vector<int>(pw));\n        for (int i = 0; i < h; i++)\n       \
    \     for (int j = 0; j < w; j++) ti[i][j] = text[i][j] - 'a' - 1;\n        for\
    \ (int i = 0; i < ph; i++)\n            for (int j = 0; j < pw; j++) pi[i][j]\
    \ = pattern[i][j] - 'a' - 1;\n        if (pattern_match_2d(ti, pi) != expected)\
    \ ok = false;\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// RHString \u3092 std::string \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\
    \u7D50\u679C\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u7AEF\
    \u306E\u524A\u9664 (remove_prefix\u30FBremove_suffix) \u3082\u3001\u6B8B\u308A\
    \u306E\u6587\u5B57\u5217\u304B\u3089\u4F5C\u3063\u305F RHString \u3068\u6BD4\u3079\
    \u308B\n// RollingHash2D \u3068 pattern_match_2d \u3092\u3001\u9577\u65B9\u5F62\
    \u3092\u76F4\u63A5\u6BD4\u3079\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B (std::vector<std::vector<int>>\
    \ \u3067\u3082\u4F5C\u308B)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/rolling-hash.hpp\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #include <string_view>\n#include <utility>\n#include <vector>\n\nint main() {\n\
    \    std::mt19937_64 rng(314);\n    RollingHash rh(1000003);\n    bool ok = true;\n\
    \    auto check = [&](bool cond, const char* what) {\n        if (!cond) {\n \
    \           if (ok) std::cerr << \"failed: \" << what << std::endl;\n        \
    \    ok = false;\n        }\n    };\n    auto random_string = [&](int max_len)\
    \ {\n        std::string s(rng() % (max_len + 1), 'a');\n        for (char& c\
    \ : s) c = 'a' + rng() % 3;  // \u56DE\u6587\u3084\u4E00\u81F4\u304C\u8D77\u304D\
    \u3084\u3059\u3044\u3088\u3046\u6587\u5B57\u3092\u7D5E\u308B\n        return s;\n\
    \    };\n    auto is_palindrome = [](const std::string& s) { return std::equal(s.begin(),\
    \ s.end(), s.rbegin()); };\n    // RHString \u306E\u4E2D\u8EAB\u304C s \u3068\u4E00\
    \u81F4\u3059\u308B\u304B (\u9577\u3055\u30FB\u6B63\u9806\u306E\u30CF\u30C3\u30B7\
    \u30E5\u30FB\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5)\n    auto same = [&](const\
    \ RHString& t, const std::string& s) {\n        std::string r(s.rbegin(), s.rend());\n\
    \        return t.size() == static_cast<long long>(s.size()) && t.hash1 == rh.build(s).back()\
    \ && t.hash2 == rh.build(r).back();\n    };\n\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        std::string s = random_string(8), t = random_string(8);\n\
    \n        // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF: \u6587\u5B57\u5217 (std::string\
    \ / const char* / string_view)\u30FBvector\u30FB1 \u6587\u5B57\u30FB\u7A7A\u30FB\
    \u30B3\u30D4\u30FC\u30FB\u30CF\u30C3\u30B7\u30E5\u5024\u304B\u3089\n        RHString\
    \ a(rh, s), b(rh, t);\n        check(same(a, s) && same(b, t), \"string constructor\"\
    );\n        check(same(RHString(rh, s.c_str()), s), \"const char* constructor\"\
    );\n        check(same(RHString(rh, std::string_view(s)), s), \"string_view constructor\"\
    );\n        std::vector<char> sv(s.begin(), s.end());\n        check(same(RHString(rh,\
    \ sv), s), \"vector constructor\");\n        RHString empty(rh);\n        check(empty.empty()\
    \ && empty.size() == 0 && same(empty, \"\"), \"empty constructor\");\n       \
    \ if (!s.empty()) check(same(RHString(rh, s[0]), s.substr(0, 1)), \"char constructor\"\
    );\n        RHString copy(a);\n        check(copy == a && same(copy, s), \"copy\
    \ constructor\");\n        RHString raw(rh, a.size(), a.hash1, a.hash2);\n   \
    \     check(raw == a, \"hash constructor\");\n\n        // \u9023\u7D50: +, +=\n\
    \        check(same(a + b, s + t), \"operator+\");\n        RHString c = a;\n\
    \        c += b;\n        check(same(c, s + t), \"operator+=\");\n        RHString\
    \ d(rh);\n        for (char ch : s) d += RHString(rh, ch);\n        check(same(d,\
    \ s) && d == a, \"operator+= char by char\");\n\n        // \u6BD4\u8F03: \u6587\
    \u5B57\u5217\u304C\u7B49\u3057\u3044\u3068\u304D\u3060\u3051\u7B49\u3057\u3044\
    \n        check((a == b) == (s == t), \"operator==\");\n        check((a != b)\
    \ == (s != t), \"operator!=\");\n        check(a + b == RHString(rh, s + t), \"\
    concat equals whole\");\n\n        // \u56DE\u6587\u5224\u5B9A\n        check(a.is_palindrome()\
    \ == is_palindrome(s), \"is_palindrome\");\n        check((a + b).is_palindrome()\
    \ == is_palindrome(s + t), \"is_palindrome concat\");\n\n        // size, empty,\
    \ clear\n        check(a.size() == static_cast<long long>(s.size()) && a.empty()\
    \ == s.empty(), \"size/empty\");\n        RHString e = a;\n        e.clear();\n\
    \        check(e.empty() && e.size() == 0 && e == empty, \"clear\");\n\n     \
    \   // assign \u3068 operator= \u306E\u5404\u7248\n        RHString f(rh);\n \
    \       f.assign(a);\n        check(f == a, \"assign(RHString)\");\n        f.assign(t);\n\
    \        check(same(f, t), \"assign(string)\");\n        f.assign(std::string_view(s));\n\
    \        check(same(f, s), \"assign(string_view)\");\n        std::vector<char>\
    \ tv(t.begin(), t.end());\n        f.assign(tv);\n        check(same(f, t), \"\
    assign(vector)\");\n        f.assign('b');\n        check(same(f, \"b\"), \"assign(char)\"\
    );\n        f = b;\n        check(f == b, \"operator=(RHString)\");\n        f\
    \ = s;\n        check(same(f, s), \"operator=(string)\");\n        f = std::string_view(t);\n\
    \        check(same(f, t), \"operator=(string_view)\");\n        f = sv;\n   \
    \     check(same(f, s), \"operator=(vector)\");\n        f = 'c';\n        check(same(f,\
    \ \"c\"), \"operator=(char)\");\n    }\n\n    // \u6574\u6570\u306E\u5217 (\u8CA0\
    \u306E\u5024\u3092\u542B\u3080) \u3067\u3082\u3001\u9023\u7D50\u3068\u6BD4\u8F03\
    \u304C\u5217\u3068\u3057\u3066\u306E\u4E00\u81F4\u3068\u5BFE\u5FDC\u3059\u308B\
    \n    for (int rep = 0; rep < 1000 && ok; rep++) {\n        std::vector<long long>\
    \ x(rng() % 6), y(rng() % 6);\n        for (auto& v : x) v = static_cast<long\
    \ long>(rng() % 5) - 2;\n        for (auto& v : y) v = static_cast<long long>(rng()\
    \ % 5) - 2;\n        std::vector<long long> xy = x;\n        xy.insert(xy.end(),\
    \ y.begin(), y.end());\n        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);\n\
    \        check(hx + hy == hxy, \"vector<long long> concat\");\n        check((hx\
    \ == hy) == (x == y), \"vector<long long> equality\");\n        check(hx.is_palindrome()\
    \ == std::equal(x.begin(), x.end(), x.rbegin()), \"vector<long long> palindrome\"\
    );\n    }\n\n    // remove_prefix / remove_suffix: s = t + u \u3084 s = u + t\
    \ \u304B\u3089 t \u3092\u53D6\u308A\u9664\u304F\u3068\u3001u \u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    // \u56DE\u6587\u306E\
    \u5224\u5B9A (\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5) \u3082\u4E00\u81F4\u3057\
    \u3001\u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570\u3067\u3082\u6210\u308A\u7ACB\
    \u3064\n    RollingHash random_rh;\n    for (RollingHash* r : {&rh, &random_rh})\
    \ {\n        for (int rep = 0; rep < 3000 && ok; rep++) {\n            std::string\
    \ t = random_string(8), u = random_string(8);\n            RHString a(*r, t +\
    \ u), b(*r, u + t);\n            a.remove_prefix(RHString(*r, t));\n         \
    \   b.remove_suffix(t);  // RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u5217) \u3092\u76F4\u63A5\u6E21\u3059\n            RHString hu(*r, u);\n\
    \            check(a == hu && a.size() == static_cast<long long>(u.size()), \"\
    remove_prefix\");\n            check(b == hu && b.size() == static_cast<long long>(u.size()),\
    \ \"remove_suffix\");\n            check(a.is_palindrome() == is_palindrome(u)\
    \ && b.is_palindrome() == is_palindrome(u), \"remove \u5F8C\u306E is_palindrome\"\
    );\n            // \u53D6\u308A\u9664\u3044\u305F\u3042\u3068\u306B\u9023\u7D50\
    \u3057\u3066\u3082\u6B63\u3057\u3044\n            check(a + RHString(*r, t) ==\
    \ RHString(*r, u + t), \"remove \u5F8C\u306E\u9023\u7D50\");\n        }\n    }\n\
    \    // 1 \u6587\u5B57\u305A\u3064 push_back \u3068 pop_front \u3092\u3057\u3066\
    \u3001\u9577\u3055 k \u306E\u7A93\u3092\u52D5\u304B\u3059\n    {\n        std::string\
    \ s = random_string(200);\n        const int k = 5;\n        RHString w(rh);\n\
    \        for (int i = 0; i < static_cast<int>(s.size()); i++) {\n            w\
    \ += RHString(rh, s[i]);\n            if (i >= k) w.remove_prefix(s[i - k]); \
    \ // \u6587\u5B57\u3092\u76F4\u63A5\u6E21\u3059\n            int l = std::max(0,\
    \ i - k + 1);\n            check(w == RHString(rh, s.substr(l, i - l + 1)), \"\
    \u7A93\");\n        }\n    }\n\n    // 2 \u6B21\u5143\n    for (int rep = 0; rep\
    \ < 2000 && ok; rep++) {\n        int h = rng() % 6, w = rng() % 6, ph = rng()\
    \ % 3 + 1, pw = rng() % 3 + 1, k = rng() % 2 + 1;\n        std::vector<std::string>\
    \ text(h, std::string(w, 'a')), pattern(ph, std::string(pw, 'a'));\n        for\
    \ (auto& row : text)\n            for (auto& ch : row) ch = 'a' + rng() % k;\n\
    \        for (auto& row : pattern)\n            for (auto& ch : row) ch = 'a'\
    \ + rng() % k;\n        // \u9577\u65B9\u5F62\u3069\u3046\u3057\u306E\u30CF\u30C3\
    \u30B7\u30E5\u304C\u3001\u4E2D\u8EAB\u304C\u540C\u3058\u3068\u304D\u306B\u9650\
    \u308A\u4E00\u81F4\u3059\u308B\n        RollingHash2D rh2;\n        auto th =\
    \ rh2.build(text);\n        for (int t = 0; t < 20 && h > 0 && w > 0; t++) {\n\
    \            int i1 = rng() % (h + 1), i2 = rng() % (h + 1), j1 = rng() % (w +\
    \ 1), j2 = rng() % (w + 1);\n            if (i1 > i2) std::swap(i1, i2);\n   \
    \         if (j1 > j2) std::swap(j1, j2);\n            int a = rng() % (h - (i2\
    \ - i1) + 1), b = rng() % (w - (j2 - j1) + 1);\n            bool same = true;\n\
    \            for (int i = 0; i < i2 - i1; i++)\n                for (int j = 0;\
    \ j < j2 - j1; j++) same &= text[i1 + i][j1 + j] == text[a + i][b + j];\n    \
    \        bool eq = rh2.query(th, Grid({i1, i2}, {j1, j2})) == rh2.query(th, Grid({a,\
    \ a + i2 - i1}, {b, b + j2 - j1}));\n            if (eq != same) ok = false;\n\
    \        }\n        std::vector<std::pair<long long, long long>> expected;\n \
    \       for (int i = 0; i + ph <= h; i++) {\n            for (int j = 0; j + pw\
    \ <= w; j++) {\n                bool match = true;\n                for (int a\
    \ = 0; a < ph; a++)\n                    for (int b = 0; b < pw; b++) match &=\
    \ text[i + a][j + b] == pattern[a][b];\n                if (match) expected.emplace_back(i,\
    \ j);\n            }\n        }\n        if (pattern_match_2d(text, pattern) !=\
    \ expected) ok = false;\n        std::vector<std::vector<int>> ti(h, std::vector<int>(w)),\
    \ pi(ph, std::vector<int>(pw));\n        for (int i = 0; i < h; i++)\n       \
    \     for (int j = 0; j < w; j++) ti[i][j] = text[i][j] - 'a' - 1;\n        for\
    \ (int i = 0; i < ph; i++)\n            for (int j = 0; j < pw; j++) pi[i][j]\
    \ = pattern[i][j] - 'a' - 1;\n        if (pattern_match_2d(ti, pi) != expected)\
    \ ok = false;\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/string/rolling-hash.hpp
  - src/utility/range.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/string/rolling-hash.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 17:10:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/rolling-hash.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/rolling-hash.test.cpp
- /verify/test/unittest/string/rolling-hash.test.cpp.html
title: test/unittest/string/rolling-hash.test.cpp
---
