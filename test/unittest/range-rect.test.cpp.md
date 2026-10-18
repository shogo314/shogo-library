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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/range-rect.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// Rect\
    \ (2 \u3064\u306E Range \u306E\u76F4\u7A4D) \u3092\u30012 \u91CD\u30EB\u30FC\u30D7\
    \u3067\u611A\u76F4\u306B\u4F5C\u3063\u305F (i, j) \u306E\u5217\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// neighbors4 / neighbors8 \u306F\u3001\
    \u4F4D\u7F6E\u306E\u5DEE\u3067\u611A\u76F4\u306B\u9078\u3093\u3060\u3082\u306E\
    \u3068\u6BD4\u3079\u308B\n// Range::contains \u306E step = 1 \u306E\u8FD1\u9053\
    \u3082\u3001\u611A\u76F4\u306A\u5224\u5B9A\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/range.hpp\"\
    \n\n/**\n * @file range.hpp\n * @brief Python \u306E range \u306E\u3088\u3046\u306A\
    \u6574\u6570\u5217\u3068\u3001\u305D\u306E\u76F4\u7A4D\u306E Rect\n */\n\n#include\
    \ <cassert>\n#include <cstddef>\n#include <iterator>\n#include <string>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\nstruct Range {\n   public:\n\
    \    using value_type = long long;\n    using const_reference = const value_type&;\n\
    \    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
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
    \n    static constexpr int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1,\
    \ 0},\n                                                 {-1, -1}, {-1, 0}, {-1,\
    \ 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};\n\n   public:\n    /**\n    \
    \ * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2 for\
    \ \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Rect \u306B\u542B\
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
    \ !(a == b);\n    }\n};\n#line 9 \"test/unittest/range-rect.test.cpp\"\n\n#include\
    \ <cstdlib>\n#include <iostream>\n#line 13 \"test/unittest/range-rect.test.cpp\"\
    \n#include <random>\n#line 16 \"test/unittest/range-rect.test.cpp\"\n#if __cplusplus\
    \ >= 202002L\n#include <ranges>\n#endif\n\nusing ll = long long;\nusing P = std::pair<ll,\
    \ ll>;\n\nstd::vector<ll> naive_range(ll start, ll stop, ll step) {\n    std::vector<ll>\
    \ v;\n    if (step > 0) {\n        for (ll x = start; x < stop; x += step) v.push_back(x);\n\
    \    } else {\n        for (ll x = start; x > stop; x += step) v.push_back(x);\n\
    \    }\n    return v;\n}\n\n// \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u3082\
    \u4F7F\u3048\u308B\nstatic_assert(Rect(3, 4).size() == 12);\nstatic_assert(Rect(3,\
    \ 4).index(2, 1) == 9);\nstatic_assert(Rect(3, 4)[9] == P(2, 1));\nstatic_assert(Rect(3,\
    \ 4).contains(2, 3) && !Rect(3, 4).contains(3, 0) && !Rect(3, 4).contains(0, -1));\n\
    static_assert(Rect({1, 4}, {10, 0, -5}).size() == 6);\nconstexpr ll sum_in_constexpr()\
    \ {\n    ll s = 0;\n    for (auto [i, j] : Rect(3, 4)) s += i * 10 + j;\n    return\
    \ s;\n}\nstatic_assert(Rect(3, 4).neighbors4(0, 0).size() == 2 && Rect(3, 4).neighbors8(1,\
    \ 1).size() == 8);\nstatic_assert(*++Rect(3, 4).neighbors4(2, 3).begin() == P(2,\
    \ 2));\nstatic_assert(sum_in_constexpr() == 4 * (0 + 10 + 20) + 3 * (0 + 1 + 2\
    \ + 3));\nstatic_assert(std::is_same_v<std::iterator_traits<Rect::const_iterator>::iterator_category,\
    \ std::forward_iterator_tag>);\n#if __cplusplus >= 202002L\nstatic_assert(std::forward_iterator<Rect::const_iterator>);\n\
    static_assert(std::ranges::forward_range<Rect> && std::ranges::sized_range<Rect>);\n\
    #endif\n\nint main() {\n    std::mt19937_64 rng(314);\n    auto rnd = [&](ll lo,\
    \ ll hi) { return lo + (ll)(rng() % (unsigned long long)(hi - lo + 1)); };\n \
    \   bool ok = true;\n    auto check = [&](bool cond, const char* what) {\n   \
    \     if (!cond) {\n            if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \            ok = false;\n        }\n    };\n    auto random_range = [&]() {\n\
    \        ll start = rnd(-6, 6), stop = rnd(-6, 6), step = rnd(-3, 3);\n      \
    \  if (step == 0) step = 1;\n        if (rng() % 3 == 0) step = 1;\n        return\
    \ Range(start, stop, step);\n    };\n\n    for (int rep = 0; rep < 3000 && ok;\
    \ rep++) {\n        const Range r = random_range(), c = random_range();\n    \
    \    const Rect rect(r, c);\n        std::vector<ll> rv = naive_range(r.start,\
    \ r.stop, r.step), cv = naive_range(c.start, c.stop, c.step);\n        std::vector<P>\
    \ expected;\n        for (ll i : rv)\n            for (ll j : cv) expected.emplace_back(i,\
    \ j);\n\n        // \u884C\u512A\u5148\u306B\u5217\u6319\u3059\u308B\n       \
    \ std::vector<P> got;\n        for (auto [i, j] : rect) got.emplace_back(i, j);\n\
    \        check(got == expected, \"\u5217\u6319\");\n        check(std::vector<P>(rect.begin(),\
    \ rect.end()) == expected, \"\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u304B\
    \u3089 vector \u3092\u4F5C\u308B\");\n        check(std::distance(rect.begin(),\
    \ rect.end()) == (ll)expected.size(), \"distance\");\n        check(rect.size()\
    \ == (ll)expected.size() && rect.empty() == expected.empty(), \"size / empty\"\
    );\n        {\n            auto it = rect.begin();\n            auto old = it++;\n\
    \            check(expected.empty() || (*old == expected[0] && (expected.size()\
    \ == 1 ? it == rect.end() : *it == expected[1])), \"\u5F8C\u7F6E ++\");\n    \
    \    }\n\n        // at / index \u306F\u4E92\u3044\u306B\u9006\n        for (ll\
    \ k = 0; k < (ll)expected.size(); k++) {\n            check(rect[k] == expected[k]\
    \ && rect.at(k) == expected[k], \"at\");\n            check(rect.index(expected[k].first,\
    \ expected[k].second) == k && rect.index(expected[k]) == k, \"index\");\n    \
    \    }\n\n        // contains: \u5217\u6319\u3057\u305F\u4E2D\u306B\u3042\u308B\
    \u304B\n        for (int t = 0; t < 30; t++) {\n            ll i = rnd(-8, 8),\
    \ j = rnd(-8, 8);\n            bool in = false;\n            for (auto& p : expected)\
    \ in |= p == P(i, j);\n            check(rect.contains(i, j) == in && rect.contains(P(i,\
    \ j)) == in, \"contains\");\n        }\n\n        // neighbors4 / neighbors8:\
    \ \u4F4D\u7F6E (rows\u30FBcols \u306E\u4F55\u756A\u76EE\u304B) \u306E\u5DEE\u304C\
    \ 1 \u4EE5\u5185\u306E\u3082\u306E\u3092 Rect \u306E\u9806\u306B\n        for\
    \ (ll k = 0; k < (ll)expected.size(); k++) {\n            const ll w = (ll)cv.size(),\
    \ ki = k / w, kj = k % w;\n            std::vector<P> e4, e8;\n            for\
    \ (ll t = 0; t < (ll)expected.size(); t++) {\n                const ll di = std::abs(t\
    \ / w - ki), dj = std::abs(t % w - kj);\n                if (t == k || di > 1\
    \ || dj > 1) continue;\n                e8.push_back(expected[t]);\n         \
    \       if (di + dj == 1) e4.push_back(expected[t]);\n            }\n        \
    \    auto [i, j] = expected[k];\n            auto n4 = rect.neighbors4(i, j),\
    \ n8 = rect.neighbors8(expected[k]);\n            check(std::vector<P>(n4.begin(),\
    \ n4.end()) == e4 && n4.size() == (ll)e4.size(), \"neighbors4\");\n          \
    \  check(std::vector<P>(n8.begin(), n8.end()) == e8 && n8.size() == (ll)e8.size()\
    \ && n8.empty() == e8.empty(), \"neighbors8\");\n        }\n\n        // ==: \u8981\
    \u7D20\u306E\u5217\u3068\u3057\u3066\u7B49\u3057\u3044\u304B\n        const Rect\
    \ same(Range(r.start, r.stop, r.step), Range(c.start, c.stop, c.step));\n    \
    \    check(rect == same && !(rect != same), \"== \u540C\u3058\u3082\u306E\");\n\
    \        const Rect other(random_range(), random_range());\n        std::vector<P>\
    \ ov(other.begin(), other.end());\n        check((rect == other) == (ov == expected),\
    \ \"== \u30E9\u30F3\u30C0\u30E0\");\n    }\n\n    // Range::contains \u306E step\
    \ = 1 \u306E\u8FD1\u9053 (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B step \u304C\
    \u5206\u304B\u3089\u306A\u3044\u5834\u5408)\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        const Range r(rnd(-10, 10), rnd(-10, 10), rng() % 2\
    \ ? 1 : rnd(-3, 3) | 1);\n        std::vector<ll> v = naive_range(r.start, r.stop,\
    \ r.step);\n        for (ll x = -12; x <= 12; x++) {\n            bool in = false;\n\
    \            for (ll y : v) in |= y == x;\n            check(r.contains(x) ==\
    \ in && r.count(x) == (ll)in, \"Range::contains\");\n        }\n    }\n\n    //\
    \ \u6C7A\u307E\u3063\u305F\u5024\n    {\n        Rect g(2, 3);\n        std::vector<P>\
    \ v(g.begin(), g.end());\n        check(v == std::vector<P>{{0, 0}, {0, 1}, {0,\
    \ 2}, {1, 0}, {1, 1}, {1, 2}}, \"Rect(2, 3)\");\n        check(Rect(0, 5).empty()\
    \ && Rect(5, 0).empty() && Rect(-1, 3).empty() && Rect(0, 5).begin() == Rect(0,\
    \ 5).end(), \"\u7A7A\");\n        check(Rect(0, 5) == Rect(3, 0), \"\u7A7A\u3069\
    \u3046\u3057\u306F\u7B49\u3057\u3044\");\n        check(g.repr() == \"Rect(Range(0,\
    \ 2, 1), Range(0, 3, 1))\" && g.initializer_str() == \"{{0, 2, 1}, {0, 3, 1}}\"\
    \ && Rect::type_str() == \"Rect\", \"repr\");\n        std::vector<P> n4, n8;\n\
    \        for (auto [i, j] : g.neighbors4(1, 1)) n4.emplace_back(i, j);\n     \
    \   for (auto [i, j] : g.neighbors8({0, 0})) n8.emplace_back(i, j);\n        check(n4\
    \ == std::vector<P>{{0, 1}, {1, 0}, {1, 2}} && n8 == std::vector<P>{{0, 1}, {1,\
    \ 0}, {1, 1}}, \"neighbors \u6C7A\u307E\u3063\u305F\u5024\");\n        check(Rect(1,\
    \ 1).neighbors8(0, 0).empty(), \"neighbors 1 \u30DE\u30B9\");\n        Rect h(g);\
    \  // \u30B3\u30D4\u30FC\n        check(h == g, \"copy\");\n    }\n#if __cplusplus\
    \ >= 202002L\n    {\n        // C++20 \u306E range \u3068\u3057\u3066 views \u3068\
    \u7D44\u307F\u5408\u308F\u305B\u3089\u308C\u308B (\u4EE3\u5165\u3067\u304D\u306A\
    \u3044\u306E\u3067\u3001\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3067\
    \u306F\u306A\u304F\u5909\u6570\u3092\u6E21\u3059)\n        ll cnt = 0;\n     \
    \   const Rect g(4, 4);\n        for (auto [i, j] : g | std::views::filter([](P\
    \ p) { return p.first == p.second; })) cnt += i + j;\n        check(cnt == 12\
    \ && std::ranges::size(Rect(3, 5)) == 15, \"views\");\n    }\n#endif\n\n    if\
    \ (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Rect (2 \u3064\u306E Range \u306E\u76F4\u7A4D) \u3092\u30012 \u91CD\u30EB\
    \u30FC\u30D7\u3067\u611A\u76F4\u306B\u4F5C\u3063\u305F (i, j) \u306E\u5217\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// neighbors4 / neighbors8\
    \ \u306F\u3001\u4F4D\u7F6E\u306E\u5DEE\u3067\u611A\u76F4\u306B\u9078\u3093\u3060\
    \u3082\u306E\u3068\u6BD4\u3079\u308B\n// Range::contains \u306E step = 1 \u306E\
    \u8FD1\u9053\u3082\u3001\u611A\u76F4\u306A\u5224\u5B9A\u3068\u6BD4\u3079\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../src/utility/range.hpp\"\n\n#include <cstdlib>\n#include <iostream>\n\
    #include <iterator>\n#include <random>\n#include <utility>\n#include <vector>\n\
    #if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nusing ll = long long;\n\
    using P = std::pair<ll, ll>;\n\nstd::vector<ll> naive_range(ll start, ll stop,\
    \ ll step) {\n    std::vector<ll> v;\n    if (step > 0) {\n        for (ll x =\
    \ start; x < stop; x += step) v.push_back(x);\n    } else {\n        for (ll x\
    \ = start; x > stop; x += step) v.push_back(x);\n    }\n    return v;\n}\n\n//\
    \ \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u3082\u4F7F\u3048\u308B\nstatic_assert(Rect(3,\
    \ 4).size() == 12);\nstatic_assert(Rect(3, 4).index(2, 1) == 9);\nstatic_assert(Rect(3,\
    \ 4)[9] == P(2, 1));\nstatic_assert(Rect(3, 4).contains(2, 3) && !Rect(3, 4).contains(3,\
    \ 0) && !Rect(3, 4).contains(0, -1));\nstatic_assert(Rect({1, 4}, {10, 0, -5}).size()\
    \ == 6);\nconstexpr ll sum_in_constexpr() {\n    ll s = 0;\n    for (auto [i,\
    \ j] : Rect(3, 4)) s += i * 10 + j;\n    return s;\n}\nstatic_assert(Rect(3, 4).neighbors4(0,\
    \ 0).size() == 2 && Rect(3, 4).neighbors8(1, 1).size() == 8);\nstatic_assert(*++Rect(3,\
    \ 4).neighbors4(2, 3).begin() == P(2, 2));\nstatic_assert(sum_in_constexpr() ==\
    \ 4 * (0 + 10 + 20) + 3 * (0 + 1 + 2 + 3));\nstatic_assert(std::is_same_v<std::iterator_traits<Rect::const_iterator>::iterator_category,\
    \ std::forward_iterator_tag>);\n#if __cplusplus >= 202002L\nstatic_assert(std::forward_iterator<Rect::const_iterator>);\n\
    static_assert(std::ranges::forward_range<Rect> && std::ranges::sized_range<Rect>);\n\
    #endif\n\nint main() {\n    std::mt19937_64 rng(314);\n    auto rnd = [&](ll lo,\
    \ ll hi) { return lo + (ll)(rng() % (unsigned long long)(hi - lo + 1)); };\n \
    \   bool ok = true;\n    auto check = [&](bool cond, const char* what) {\n   \
    \     if (!cond) {\n            if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \            ok = false;\n        }\n    };\n    auto random_range = [&]() {\n\
    \        ll start = rnd(-6, 6), stop = rnd(-6, 6), step = rnd(-3, 3);\n      \
    \  if (step == 0) step = 1;\n        if (rng() % 3 == 0) step = 1;\n        return\
    \ Range(start, stop, step);\n    };\n\n    for (int rep = 0; rep < 3000 && ok;\
    \ rep++) {\n        const Range r = random_range(), c = random_range();\n    \
    \    const Rect rect(r, c);\n        std::vector<ll> rv = naive_range(r.start,\
    \ r.stop, r.step), cv = naive_range(c.start, c.stop, c.step);\n        std::vector<P>\
    \ expected;\n        for (ll i : rv)\n            for (ll j : cv) expected.emplace_back(i,\
    \ j);\n\n        // \u884C\u512A\u5148\u306B\u5217\u6319\u3059\u308B\n       \
    \ std::vector<P> got;\n        for (auto [i, j] : rect) got.emplace_back(i, j);\n\
    \        check(got == expected, \"\u5217\u6319\");\n        check(std::vector<P>(rect.begin(),\
    \ rect.end()) == expected, \"\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u304B\
    \u3089 vector \u3092\u4F5C\u308B\");\n        check(std::distance(rect.begin(),\
    \ rect.end()) == (ll)expected.size(), \"distance\");\n        check(rect.size()\
    \ == (ll)expected.size() && rect.empty() == expected.empty(), \"size / empty\"\
    );\n        {\n            auto it = rect.begin();\n            auto old = it++;\n\
    \            check(expected.empty() || (*old == expected[0] && (expected.size()\
    \ == 1 ? it == rect.end() : *it == expected[1])), \"\u5F8C\u7F6E ++\");\n    \
    \    }\n\n        // at / index \u306F\u4E92\u3044\u306B\u9006\n        for (ll\
    \ k = 0; k < (ll)expected.size(); k++) {\n            check(rect[k] == expected[k]\
    \ && rect.at(k) == expected[k], \"at\");\n            check(rect.index(expected[k].first,\
    \ expected[k].second) == k && rect.index(expected[k]) == k, \"index\");\n    \
    \    }\n\n        // contains: \u5217\u6319\u3057\u305F\u4E2D\u306B\u3042\u308B\
    \u304B\n        for (int t = 0; t < 30; t++) {\n            ll i = rnd(-8, 8),\
    \ j = rnd(-8, 8);\n            bool in = false;\n            for (auto& p : expected)\
    \ in |= p == P(i, j);\n            check(rect.contains(i, j) == in && rect.contains(P(i,\
    \ j)) == in, \"contains\");\n        }\n\n        // neighbors4 / neighbors8:\
    \ \u4F4D\u7F6E (rows\u30FBcols \u306E\u4F55\u756A\u76EE\u304B) \u306E\u5DEE\u304C\
    \ 1 \u4EE5\u5185\u306E\u3082\u306E\u3092 Rect \u306E\u9806\u306B\n        for\
    \ (ll k = 0; k < (ll)expected.size(); k++) {\n            const ll w = (ll)cv.size(),\
    \ ki = k / w, kj = k % w;\n            std::vector<P> e4, e8;\n            for\
    \ (ll t = 0; t < (ll)expected.size(); t++) {\n                const ll di = std::abs(t\
    \ / w - ki), dj = std::abs(t % w - kj);\n                if (t == k || di > 1\
    \ || dj > 1) continue;\n                e8.push_back(expected[t]);\n         \
    \       if (di + dj == 1) e4.push_back(expected[t]);\n            }\n        \
    \    auto [i, j] = expected[k];\n            auto n4 = rect.neighbors4(i, j),\
    \ n8 = rect.neighbors8(expected[k]);\n            check(std::vector<P>(n4.begin(),\
    \ n4.end()) == e4 && n4.size() == (ll)e4.size(), \"neighbors4\");\n          \
    \  check(std::vector<P>(n8.begin(), n8.end()) == e8 && n8.size() == (ll)e8.size()\
    \ && n8.empty() == e8.empty(), \"neighbors8\");\n        }\n\n        // ==: \u8981\
    \u7D20\u306E\u5217\u3068\u3057\u3066\u7B49\u3057\u3044\u304B\n        const Rect\
    \ same(Range(r.start, r.stop, r.step), Range(c.start, c.stop, c.step));\n    \
    \    check(rect == same && !(rect != same), \"== \u540C\u3058\u3082\u306E\");\n\
    \        const Rect other(random_range(), random_range());\n        std::vector<P>\
    \ ov(other.begin(), other.end());\n        check((rect == other) == (ov == expected),\
    \ \"== \u30E9\u30F3\u30C0\u30E0\");\n    }\n\n    // Range::contains \u306E step\
    \ = 1 \u306E\u8FD1\u9053 (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B step \u304C\
    \u5206\u304B\u3089\u306A\u3044\u5834\u5408)\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        const Range r(rnd(-10, 10), rnd(-10, 10), rng() % 2\
    \ ? 1 : rnd(-3, 3) | 1);\n        std::vector<ll> v = naive_range(r.start, r.stop,\
    \ r.step);\n        for (ll x = -12; x <= 12; x++) {\n            bool in = false;\n\
    \            for (ll y : v) in |= y == x;\n            check(r.contains(x) ==\
    \ in && r.count(x) == (ll)in, \"Range::contains\");\n        }\n    }\n\n    //\
    \ \u6C7A\u307E\u3063\u305F\u5024\n    {\n        Rect g(2, 3);\n        std::vector<P>\
    \ v(g.begin(), g.end());\n        check(v == std::vector<P>{{0, 0}, {0, 1}, {0,\
    \ 2}, {1, 0}, {1, 1}, {1, 2}}, \"Rect(2, 3)\");\n        check(Rect(0, 5).empty()\
    \ && Rect(5, 0).empty() && Rect(-1, 3).empty() && Rect(0, 5).begin() == Rect(0,\
    \ 5).end(), \"\u7A7A\");\n        check(Rect(0, 5) == Rect(3, 0), \"\u7A7A\u3069\
    \u3046\u3057\u306F\u7B49\u3057\u3044\");\n        check(g.repr() == \"Rect(Range(0,\
    \ 2, 1), Range(0, 3, 1))\" && g.initializer_str() == \"{{0, 2, 1}, {0, 3, 1}}\"\
    \ && Rect::type_str() == \"Rect\", \"repr\");\n        std::vector<P> n4, n8;\n\
    \        for (auto [i, j] : g.neighbors4(1, 1)) n4.emplace_back(i, j);\n     \
    \   for (auto [i, j] : g.neighbors8({0, 0})) n8.emplace_back(i, j);\n        check(n4\
    \ == std::vector<P>{{0, 1}, {1, 0}, {1, 2}} && n8 == std::vector<P>{{0, 1}, {1,\
    \ 0}, {1, 1}}, \"neighbors \u6C7A\u307E\u3063\u305F\u5024\");\n        check(Rect(1,\
    \ 1).neighbors8(0, 0).empty(), \"neighbors 1 \u30DE\u30B9\");\n        Rect h(g);\
    \  // \u30B3\u30D4\u30FC\n        check(h == g, \"copy\");\n    }\n#if __cplusplus\
    \ >= 202002L\n    {\n        // C++20 \u306E range \u3068\u3057\u3066 views \u3068\
    \u7D44\u307F\u5408\u308F\u305B\u3089\u308C\u308B (\u4EE3\u5165\u3067\u304D\u306A\
    \u3044\u306E\u3067\u3001\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3067\
    \u306F\u306A\u304F\u5909\u6570\u3092\u6E21\u3059)\n        ll cnt = 0;\n     \
    \   const Rect g(4, 4);\n        for (auto [i, j] : g | std::views::filter([](P\
    \ p) { return p.first == p.second; })) cnt += i + j;\n        check(cnt == 12\
    \ && std::ranges::size(Rect(3, 5)) == 15, \"views\");\n    }\n#endif\n\n    if\
    \ (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/range.hpp
  isVerificationFile: true
  path: test/unittest/range-rect.test.cpp
  requiredBy: []
  timestamp: '2026-10-18 18:58:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/range-rect.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/range-rect.test.cpp
- /verify/test/unittest/range-rect.test.cpp.html
title: test/unittest/range-rect.test.cpp
---
