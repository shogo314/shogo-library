---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: src/utility/repr.hpp
    title: "\u51FA\u529B\u3092\u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\
      \u30AF\u30BF\u306B\u4F7F\u3048\u308B\u6587\u5B57\u5217\u5316 (repr)"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/unittest/repr.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// repr.hpp \u306E\u6587\u5B57\u5217\u5316\u3092\u691C\u8A3C\u3059\u308B\n\
    // CHECK_REPR(\u5024, \u5F0F) \u306F repr(\u5024) \u304C\u300C\u5F0F\u300D\u306E\
    \u6587\u5B57\u5217\u3068\u4E00\u81F4\u3057\u3001\u3055\u3089\u306B\u305D\u306E\
    \u5F0F\u3092\u8A55\u4FA1\u3059\u308B\u3068\u5024\u3068\u7B49\u3057\u304F\u306A\
    \u308B\u3053\u3068\u3092\u78BA\u304B\u3081\u308B\n// (\u5F0F\u306F\u3053\u306E\
    \u30D5\u30A1\u30A4\u30EB\u3067 C++ \u3068\u3057\u3066\u30B3\u30F3\u30D1\u30A4\u30EB\
    \u3055\u308C\u308B\u306E\u3067\u3001repr \u306E\u51FA\u529B\u304C C++ \u306E\u5F0F\
    \u3068\u3057\u3066\u6B63\u3057\u3044\u3053\u3068\u3082\u78BA\u304B\u3081\u3089\
    \u308C\u308B)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#include <array>\n#include <iostream>\n#include <map>\n#include\
    \ <random>\n#include <set>\n#include <sstream>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/utility/range.hpp\"\n\n/**\n * @file range.hpp\n\
    \ * @brief Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\n */\n\
    \n#include <cassert>\n#include <cstddef>\n#include <iterator>\n#line 12 \"src/utility/range.hpp\"\
    \n#include <type_traits>\n#line 15 \"src/utility/range.hpp\"\n\nstruct Range {\n\
    \   public:\n    using value_type = long long;\n    using const_reference = const\
    \ value_type&;\n    using size_type = std::size_t;\n    using difference_type\
    \ = std::ptrdiff_t;\n\n    const value_type start;\n    const value_type stop;\n\
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
    \ _stop, 1)) {}\n    constexpr Range(value_type _stop)\n        : start(0), stop(_stop),\
    \ step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n     \
    \   : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = const\
    \ Range::value_type*;\n        using reference = const Range::value_type&;\n \
    \       using iterator_category = std::random_access_iterator_tag;\n\n       private:\n\
    \        const Range& range;\n        value_type value;\n\n        constexpr bool\
    \ same_range(const const_iterator& o) const noexcept {\n            return range.start\
    \ == o.range.start and range.stop == o.range.stop and range.step == o.range.step;\n\
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
    \ b) noexcept {\n            return !a.same_range(b) or a.value != b.value;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return !(a != b);\n       \
    \ }\n        constexpr friend difference_type operator-(const const_iterator&\
    \ a, const const_iterator& b) {\n            assert(a.same_range(b));\n      \
    \      if (a.range.step > 0) {\n                return (a.value - b.value) / a.range.step;\n\
    \            } else {\n                return (b.value - a.value) / (-a.range.step);\n\
    \            }\n        }\n    };\n\n    constexpr const_iterator begin() const\
    \ noexcept {\n        return {*this, start};\n    }\n    constexpr const_iterator\
    \ end() const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n\
    \     * @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr difference_type\
    \ count(value_type x) const noexcept {\n        if (step > 0) {\n            if\
    \ (start <= x and x < stop) {\n                if ((x - start) % step == 0) {\n\
    \                    return 1;\n                }\n            }\n        } else\
    \ {\n            if (stop < x and x <= start) {\n                if ((start -\
    \ x) % (-step) == 0) {\n                    return 1;\n                }\n   \
    \         }\n        }\n        return 0;\n    }\n    /**\n     * @brief x \u304C\
    \u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(value_type\
    \ x) const noexcept {\n        return count(x) != 0;\n    }\n    /**\n     * @brief\
    \ x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * x \u304C\u542B\u307E\u308C\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(value_type\
    \ x) const {\n        assert(contains(x));\n        return (x - start) / step;\n\
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
    \ i) const {\n        assert(i < size());\n        return start + i * step;\n\
    \    }\n    constexpr value_type operator[](size_type i) const {\n        return\
    \ at(i);\n    }\n    constexpr bool empty() const noexcept {\n        return start\
    \ == norm_stop;\n    }\n    constexpr value_type sum() const noexcept {\n    \
    \    return static_cast<Range::value_type>(size()) * (norm_stop - step + start)\
    \ / 2;\n    }\n    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\
    \u30A8\u30E9\u30FC\n     */\n    constexpr value_type min() const {\n        assert(not\
    \ empty());\n        if (step > 0) {\n            return start;\n        } else\
    \ {\n            return norm_stop - step;\n        }\n    }\n    /**\n     * @brief\
    \ \u6700\u5927\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr value_type max() const {\n        assert(not empty());\n       \
    \ if (step > 0) {\n            return norm_stop - step;\n        } else {\n  \
    \          return start;\n        }\n    }\n    /**\n     * @brief \u7DCF xor\n\
    \     * \u8CA0\u3092\u542B\u3080\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ value_type product_xor() const noexcept {\n        if (empty()) return 0;\n\
    \        assert(min() >= 0);\n        Range sorted_range(sorted());\n        value_type\
    \ res = 0;\n        std::make_unsigned_t<value_type> t = 1;\n        while (t\
    \ <= static_cast<std::make_unsigned_t<value_type>>(max())) {\n            std::make_unsigned_t<value_type>\
    \ tmp = 0, n = size(), m = t, a = sorted_range.step, b = sorted_range.start;\n\
    \            while (true) {\n                if (a >= m) {\n                 \
    \   tmp += n * (n - 1) / 2 * (a / m);\n                    a %= m;\n         \
    \       }\n                if (b >= m) {\n                    tmp += n * (b /\
    \ m);\n                    b %= m;\n                }\n                std::make_unsigned_t<value_type>\
    \ y_max = a * n + b;\n                if (y_max < m) break;\n                n\
    \ = y_max / m;\n                b = y_max % m;\n                std::swap(m, a);\n\
    \            }\n            if (tmp % 2 == 1) {\n                res += t;\n \
    \           }\n            t <<= 1;\n        }\n        return res;\n    }\n \
    \   /**\n     * @brief \u9006\u9806\u306B\u3057\u305F\u3082\u306E\n     */\n \
    \   constexpr Range reversed() const noexcept {\n        return {norm_stop - step,\
    \ start - step, -step, start - step};\n    }\n    /**\n     * @brief step > 0\
    \ \u3060\u3068\u305D\u306E\u307E\u307E step < 0 \u3060\u3068\u9006\u9806\u306B\
    \u3057\u305F\u3082\u306E\n     */\n    constexpr Range sorted() const noexcept\
    \ {\n        if (step > 0) {\n            return {start, norm_stop, step, norm_stop};\n\
    \        } else {\n            return {norm_stop - step, start - step, -step,\
    \ start - step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C\
    \ [l, r) \u3067\u3042\u308B\u7BC4\u56F2\u3092\u8FD4\u3059\n     */\n    constexpr\
    \ Range clipped(value_type l, value_type r) const {\n        if (l >= r) return\
    \ {};\n        r--;  // \u4EE5\u4E0B\u3067\u306F r \u3092\u542B\u3080 [l, r] \u3068\
    \u3057\u3066\u6271\u3046\n        if (step > 0) {\n            value_type _start\
    \ = [&] {\n                if (norm_stop <= l) {\n                    return norm_stop;\n\
    \                } else if (l < start) {\n                    return start;\n\
    \                } else {\n                    return start + (l - start + step\
    \ - 1) / step * step;\n                }\n            }();\n            value_type\
    \ _stop = [&] {\n                if (norm_stop <= r) {\n                    return\
    \ norm_stop;\n                } else if (r < start) {\n                    return\
    \ start;\n                } else {\n                    return start + (r - start\
    \ + step) / step * step;\n                }\n            }();\n            return\
    \ {_start, _stop, step, _stop};\n        } else {\n            value_type _start\
    \ = [&] {\n                if (start - step <= r) {\n                    return\
    \ start;\n                } else if (r < norm_stop - step) {\n               \
    \     return norm_stop;\n                } else {\n                    return\
    \ norm_stop + (r - norm_stop) / step * step;\n                }\n            }();\n\
    \            value_type _stop = [&] {\n                if (start - step <= l)\
    \ {\n                    return start;\n                } else if (l < norm_stop\
    \ - step) {\n                    return norm_stop;\n                } else {\n\
    \                    return norm_stop + (l - norm_stop - 1) / step * step;\n \
    \               }\n            }();\n            return {_start, _stop, step,\
    \ _stop};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u3092 Range \u3067\
    \u6307\u5B9A\u3057\u305F\u30B3\u30F3\u30C6\u30CA\n     */\n    constexpr Range\
    \ slice(const Range& r) const {\n        if (r.empty()) return {};\n        if\
    \ (r.max() < 0) return {};\n        if (r.min() >= static_cast<Range::value_type>(size()))\
    \ return {};\n        Range trimmed_range(r.clipped(0, static_cast<Range::value_type>(size())));\n\
    \        if (trimmed_range.empty()) return {};\n        value_type _step = step\
    \ * trimmed_range.step;\n        value_type _start = at(trimmed_range.start);\n\
    \        value_type _stop = _start + _step * static_cast<Range::value_type>(trimmed_range.size());\n\
    \        return {_start, _stop, _step, _stop};\n    }\n\n    static std::string\
    \ type_str() {\n        return \"Range\";\n    }\n    std::string initializer_str()\
    \ const {\n        return \"{\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \"}\";\n    }\n    std::string repr() const\
    \ {\n        return \"Range(\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \")\";\n    }\n\n    std::vector<value_type>\
    \ to_vector() const {\n        std::vector<value_type> ret;\n        ret.reserve(size());\n\
    \        if (step > 0) {\n            for (value_type x = start; x < stop; x +=\
    \ step) {\n                ret.push_back(x);\n            }\n        } else {\n\
    \            for (value_type x = start; x > stop; x += step) {\n             \
    \   ret.push_back(x);\n            }\n        }\n        return ret;\n    }\n\
    \    constexpr friend bool operator==(const Range& a, const Range& b) noexcept\
    \ {\n        if (a.empty() and b.empty()) return true;\n        if (a.size() !=\
    \ b.size()) return false;\n        if (a.start != b.start) return false;\n   \
    \     if (a.size() == 1) return true;\n        if (a.step != b.step) return false;\n\
    \        return true;\n    }\n    constexpr friend bool operator!=(const Range&\
    \ a, const Range& b) noexcept {\n        return !(a == b);\n    }\n};\n#line 2\
    \ \"src/utility/repr.hpp\"\n\n/**\n * @file repr.hpp\n * @brief \u51FA\u529B\u3092\
    \u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u4F7F\
    \u3048\u308B\u6587\u5B57\u5217\u5316 (repr)\n */\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 13 \"\
    src/utility/traits.hpp\"\n\nnamespace detail {\nusing std::begin, std::end;\n\n\
    template <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace detail\n\n\
    template <class T>\nstruct is_range : detail::is_range_impl<T>::type {};\ntemplate\
    \ <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define\
    \ HAS_METHOD(func_name)                                                      \
    \        \\\n    namespace detail {                                          \
    \                           \\\n    template <class T, class = void>         \
    \                                              \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : detail::has_##func_name##_impl<T>::type {};                   \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace detail {              \
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
    \                                          \\\n    struct has_##func_name : detail::has_##func_name##_impl<T,\
    \ U>::type {};                                    \\\n    template <class T, typename\
    \ U>                                                                         \
    \    \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ detail {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace detail\ntemplate <class T>\nstruct is_sorted_container\
    \ : detail::is_sorted_container_impl<T>::type {};\ntemplate <class T>\ninline\
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n#line\
    \ 18 \"src/utility/repr.hpp\"\n\nnamespace detail {\n\n///////////////////////////////////////////////////////////////////\n\
    /////////////////////////// declaration ///////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ninline std::string type_str(const char*);\ninline std::string initializer_str(const\
    \ char*);\ninline std::string repr(const char*);\n\ninline std::string type_str(const\
    \ char&);\ninline std::string initializer_str(const char&);\ninline std::string\
    \ repr(const char&);\n\ninline std::string type_str(const int&);\ninline std::string\
    \ initializer_str(const int&);\ninline std::string repr(const int&);\n\ninline\
    \ std::string type_str(const long&);\ninline std::string initializer_str(const\
    \ long&);\ninline std::string repr(const long&);\n\ninline std::string type_str(const\
    \ long long&);\ninline std::string initializer_str(const long long&);\ninline\
    \ std::string repr(const long long&);\n\ninline std::string type_str(const unsigned\
    \ int&);\ninline std::string initializer_str(const unsigned int&);\ninline std::string\
    \ repr(const unsigned int&);\n\ninline std::string type_str(const unsigned long&);\n\
    inline std::string initializer_str(const unsigned long&);\ninline std::string\
    \ repr(const unsigned long&);\n\ninline std::string type_str(const unsigned long\
    \ long&);\ninline std::string initializer_str(const unsigned long long&);\ninline\
    \ std::string repr(const unsigned long long&);\n\ninline std::string type_str(const\
    \ std::string&);\ninline std::string initializer_str(const std::string&);\ninline\
    \ std::string repr(const std::string&);\n\ninline std::string type_str(const float&);\n\
    inline std::string initializer_str(const float&);\ninline std::string repr(const\
    \ float&);\n\ninline std::string type_str(const double&);\ninline std::string\
    \ initializer_str(const double&);\ninline std::string repr(const double&);\n\n\
    inline std::string type_str(const long double&);\ninline std::string initializer_str(const\
    \ long double&);\ninline std::string repr(const long double&);\n\ntemplate <typename\
    \ T>\ninline std::string type_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string repr(const std::vector<T>&);\n\ntemplate <typename T>\n\
    inline std::string type_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string initializer_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string repr(const std::set<T>&);\n\ntemplate <typename T1, typename T2>\n\
    inline std::string type_str(const std::pair<T1, T2>&);\ntemplate <typename T1,\
    \ typename T2>\ninline std::string initializer_str(const std::pair<T1, T2>&);\n\
    template <typename T1, typename T2>\ninline std::string repr(const std::pair<T1,\
    \ T2>&);\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const\
    \ std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\ninline std::string\
    \ initializer_str(const std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\n\
    inline std::string repr(const std::map<T1, T2>&);\n\ntemplate <typename T, std::size_t\
    \ N>\ninline std::string type_str(const std::array<T, N>&);\ntemplate <typename\
    \ T, std::size_t N>\ninline std::string initializer_str(const std::array<T, N>&);\n\
    template <typename T, std::size_t N>\ninline std::string repr(const std::array<T,\
    \ N>&);\n\n///////////////////////////////////////////////////////////////////\n\
    /////////////////////////// definition ////////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ntemplate <typename T, std::enable_if_t<not has_type_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string type_str(const T& t) {\n    return \"T\";\n}\n\
    template <typename T, std::enable_if_t<has_type_str_v<T>, std::nullptr_t> = nullptr>\n\
    inline std::string type_str(const T& t) {\n    return t.type_str();\n}\ntemplate\
    \ <typename T, std::enable_if_t<not has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return \"\
    {}\";\n}\ntemplate <typename T, std::enable_if_t<has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return t.initializer_str();\n\
    }\ntemplate <typename T, std::enable_if_t<not has_repr_v<T>, std::nullptr_t> =\
    \ nullptr>\ninline std::string repr(const T& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\ntemplate <typename T, std::enable_if_t<has_repr_v<T>,\
    \ std::nullptr_t> = nullptr>\ninline std::string repr(const T& t) {\n    return\
    \ t.repr();\n}\n\ninline std::string type_str(const char*) {\n    return \"char*\"\
    ;\n}\ninline std::string initializer_str(const char* t) {\n    return \"\\\"\"\
    \ + std::string(t) + \"\\\"\";\n}\ninline std::string repr(const char* t) {\n\
    \    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ char&) {\n    return \"char\";\n}\ninline std::string initializer_str(const\
    \ char& t) {\n    // char \u304C\u7B26\u53F7\u4ED8\u304D\u3067\u3082\u6DFB\u5B57\
    \u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u3088\u3046\u306B unsigned char \u3067\
    \u6271\u3046 (UTF-8 \u306E\u30D0\u30A4\u30C8\u306A\u3069)\n    const unsigned\
    \ char u = static_cast<unsigned char>(t);\n    std::vector<std::string> v(128,\
    \ \"\");\n    v['\\0'] = \"\\\\0\";\n    v['\\a'] = \"\\\\a\";\n    v['\\b'] =\
    \ \"\\\\b\";\n    v['\\f'] = \"\\\\f\";\n    v['\\r'] = \"\\\\r\";\n    v['\\\
    n'] = \"\\\\n\";\n    v['\\v'] = \"\\\\v\";\n    v['\\''] = \"\\\\'\";\n    v['\\\
    \\'] = \"\\\\\\\\\";\n    if (u < 128 and !v[u].empty())\n        return \"'\"\
    \ + v[u] + \"'\";\n    if (32 <= u and u <= 126)\n        return \"'\" + std::string{t}\
    \ + \"'\";\n    return \"'\\\\\" + std::to_string(u / 64) + std::to_string(u /\
    \ 8 % 8) + std::to_string(u % 8) + \"'\";\n}\ninline std::string repr(const char&\
    \ t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ int&) {\n    return \"int\";\n}\ninline std::string initializer_str(const int&\
    \ t) {\n    return std::to_string(t);\n}\ninline std::string repr(const int& t)\
    \ {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ long&) {\n    return \"long\";\n}\ninline std::string initializer_str(const\
    \ long& t) {\n    return std::to_string(t) + \"l\";\n}\ninline std::string repr(const\
    \ long& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const long long&) {\n    return \"long long\";\n}\ninline std::string\
    \ initializer_str(const long long& t) {\n    return std::to_string(t) + \"ll\"\
    ;\n}\ninline std::string repr(const long long& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const unsigned int&) {\n    return \"unsigned\
    \ int\";\n}\ninline std::string initializer_str(const unsigned int& t) {\n   \
    \ return std::to_string(t) + \"u\";\n}\ninline std::string repr(const unsigned\
    \ int& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ unsigned long&) {\n    return \"unsigned long\";\n}\ninline std::string initializer_str(const\
    \ unsigned long& t) {\n    return std::to_string(t) + \"ul\";\n}\ninline std::string\
    \ repr(const unsigned long& t) {\n    return detail::initializer_str(t);\n}\n\n\
    inline std::string type_str(const unsigned long long&) {\n    return \"unsigned\
    \ long long\";\n}\ninline std::string initializer_str(const unsigned long long&\
    \ t) {\n    return std::to_string(t) + \"ull\";\n}\ninline std::string repr(const\
    \ unsigned long long& t) {\n    return detail::initializer_str(t);\n}\n\ninline\
    \ std::string type_str(const std::string&) {\n    return \"std::string\";\n}\n\
    inline std::string initializer_str(const std::string& t) {\n    return \"\\\"\"\
    \ + t + \"\\\"\";\n}\ninline std::string repr(const std::string& t) {\n    return\
    \ detail::type_str(t) + \"{\" + detail::initializer_str(t) + \"}\";\n}\n\ninline\
    \ std::string type_str(const float&) {\n    return \"float\";\n}\ninline std::string\
    \ initializer_str(const float& t) {\n    return std::to_string(t) + \"f\";\n}\n\
    inline std::string repr(const float& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const double&) {\n    return \"double\";\n}\n\
    inline std::string initializer_str(const double& t) {\n    return std::to_string(t);\n\
    }\ninline std::string repr(const double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long double&) {\n    return \"long double\"\
    ;\n}\ninline std::string initializer_str(const long double& t) {\n    return std::to_string(t)\
    \ + \"l\";\n}\ninline std::string repr(const long double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ntemplate <typename T>\ninline std::string type_str(const std::vector<T>&)\
    \ {\n    T t;\n    return \"std::vector<\" + detail::type_str(t) + \">\";\n}\n\
    template <typename T>\ninline std::string initializer_str(const std::vector<T>&\
    \ t) {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin();\
    \ itr != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n   \
    \     ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T>\ninline std::string repr(const std::vector<T>&\
    \ t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\ntemplate\
    \ <typename T>\ninline std::string type_str(const std::set<T>&) {\n    T t;\n\
    \    return \"std::set<\" + detail::type_str(t) + \">\";\n}\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::set<T>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += detail::initializer_str(*itr);\n\
    \    }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T>\ninline std::string\
    \ repr(const std::set<T>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::pair<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::pair<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::pair<T1, T2>& t) {\n    return\
    \ \"{\" + detail::initializer_str(t.first) + \", \" + detail::initializer_str(t.second)\
    \ + \"}\";\n}\ntemplate <typename T1, typename T2>\ninline std::string repr(const\
    \ std::pair<T1, T2>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::map<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::map<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::map<T1, T2>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += \"{\";\n   \
    \     ret += detail::initializer_str(itr->first);\n        ret += \", \";\n  \
    \      ret += detail::initializer_str(itr->second);\n        ret += \"}\";\n \
    \   }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string repr(const std::map<T1, T2>& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\n\ntemplate <typename T, std::size_t N>\ninline\
    \ std::string type_str(const std::array<T, N>&) {\n    T t;\n    return \"std::array<\"\
    \ + detail::type_str(t) + \", \" + std::to_string(N) + \">\";\n}\ntemplate <typename\
    \ T, std::size_t N>\ninline std::string initializer_str(const std::array<T, N>&\
    \ t) {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin();\
    \ itr != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n   \
    \     ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T, std::size_t N>\ninline std::string repr(const\
    \ std::array<T, N>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\n}  // namespace detail\n\ntemplate <typename T>\ninline std::string type_str(const\
    \ T& t) {\n    return detail::type_str(t);\n}\ntemplate <typename T>\ninline std::string\
    \ initializer_str(const T& t) {\n    return detail::initializer_str(t);\n}\ntemplate\
    \ <typename T>\ninline std::string repr(const T& t) {\n    return detail::repr(t);\n\
    }\n\n#define DEBUG(x) { std::cerr << #x << \" = \" << repr(x) << std::endl; }\n\
    #line 20 \"test/unittest/repr.test.cpp\"\n\nbool ok = true;\nvoid check(bool cond,\
    \ const std::string& what) {\n    if (!cond) {\n        if (ok) std::cerr << \"\
    failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\n#define CHECK_REPR(value,\
    \ ...)                                                         \\\n    do {  \
    \                                                                            \
    \ \\\n        const auto& value_ = (value);                                  \
    \                \\\n        check(repr(value_) == #__VA_ARGS__, \"repr(\" #value\
    \ \") == \" #__VA_ARGS__ \" (got \" + repr(value_) + \")\"); \\\n        check(value_\
    \ == (__VA_ARGS__), \"evaluating \" #__VA_ARGS__);                    \\\n   \
    \ } while (0)\n\n// repr \u306A\u3069\u306E\u30E1\u30F3\u30D0\u95A2\u6570\u3092\
    \u6301\u305F\u306A\u3044\u578B\nstruct Plain {};\n// initializer_str \u3060\u3051\
    \u3092\u6301\u3064\u578B\nstruct OnlyInit {\n    int x;\n    std::string initializer_str()\
    \ const { return \"{\" + std::to_string(x) + \"}\"; }\n};\n\n// char \u306E\u671F\
    \u5F85\u5024 (\u611A\u76F4\u306B\u4F5C\u308B)\nstd::string naive_char_repr(char\
    \ c) {\n    unsigned char u = static_cast<unsigned char>(c);\n    switch (c) {\n\
    \        case '\\0': return \"'\\\\0'\";\n        case '\\a': return \"'\\\\a'\"\
    ;\n        case '\\b': return \"'\\\\b'\";\n        case '\\f': return \"'\\\\\
    f'\";\n        case '\\r': return \"'\\\\r'\";\n        case '\\n': return \"\
    '\\\\n'\";\n        case '\\v': return \"'\\\\v'\";\n        case '\\'': return\
    \ \"'\\\\''\";\n        case '\\\\': return \"'\\\\\\\\'\";\n    }\n    if (32\
    \ <= u && u <= 126) return std::string(\"'\") + c + \"'\";\n    return \"'\\\\\
    \" + std::to_string(u / 64) + std::to_string(u / 8 % 8) + std::to_string(u % 8)\
    \ + \"'\";\n}\n\nint main() {\n    std::mt19937 rng(314);\n\n    // \u6574\u6570\
    \u30FB\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\n    CHECK_REPR(5, 5);\n    CHECK_REPR(-3,\
    \ -3);\n    CHECK_REPR(5L, 5l);\n    CHECK_REPR(-7LL, -7ll);\n    CHECK_REPR(5U,\
    \ 5u);\n    CHECK_REPR(5UL, 5ul);\n    CHECK_REPR(18446744073709551615ULL, 18446744073709551615ull);\n\
    \    CHECK_REPR(1.5f, 1.500000f);\n    CHECK_REPR(-0.25, -0.250000);\n    CHECK_REPR(2.5L,\
    \ 2.500000l);\n    check(type_str(5) == \"int\" && type_str(5L) == \"long\" &&\
    \ type_str(5LL) == \"long long\", \"type_str (signed)\");\n    check(type_str(5U)\
    \ == \"unsigned int\" && type_str(5UL) == \"unsigned long\" && type_str(5ULL)\
    \ == \"unsigned long long\", \"type_str (unsigned)\");\n    check(type_str(1.0f)\
    \ == \"float\" && type_str(1.0) == \"double\" && type_str(1.0L) == \"long double\"\
    , \"type_str (floating)\");\n    check(initializer_str(5LL) == \"5ll\" && initializer_str(1.5f)\
    \ == \"1.500000f\", \"initializer_str (number)\");\n\n    // char\n    CHECK_REPR('a',\
    \ 'a');\n    CHECK_REPR('\\n', '\\n');\n    CHECK_REPR('\\0', '\\0');\n    CHECK_REPR('\\\
    '', '\\'');\n    CHECK_REPR('\\\\', '\\\\');\n    CHECK_REPR(char(1), '\\001');\n\
    \    CHECK_REPR(char(127), '\\177');\n    CHECK_REPR(char(-61), '\\303');  //\
    \ UTF-8 \u306E\u6587\u5B57\u306E\u30D0\u30A4\u30C8\u306A\u3069\u3001\u8CA0\u306E\
    \u5024\u306E char\n    check(type_str('a') == \"char\" && initializer_str('a')\
    \ == \"'a'\", \"type_str / initializer_str (char)\");\n    for (int i = -128;\
    \ i <= 127; i++) {\n        char c = static_cast<char>(i);\n        check(repr(c)\
    \ == naive_char_repr(c), \"repr(char) for all values\");\n    }\n\n    // \u6587\
    \u5B57\u5217\n    {\n        const char* s = \"abc\";\n        check(repr(s) ==\
    \ \"\\\"abc\\\"\" && type_str(s) == \"char*\" && initializer_str(s) == \"\\\"\
    abc\\\"\", \"const char*\");\n    }\n    CHECK_REPR(std::string(\"abc\"), std::string{\"\
    abc\"});\n    CHECK_REPR(std::string(), std::string{\"\"});\n    check(type_str(std::string())\
    \ == \"std::string\" && initializer_str(std::string(\"x\")) == \"\\\"x\\\"\",\
    \ \"type_str / initializer_str (string)\");\n\n    // \u30B3\u30F3\u30C6\u30CA\
    \n    CHECK_REPR((std::vector<int>{1, 2, 3}), std::vector<int>{1, 2, 3});\n  \
    \  CHECK_REPR(std::vector<int>(), std::vector<int>{});\n    CHECK_REPR((std::vector<std::vector<long\
    \ long>>{{1, 2}, {}}), std::vector<std::vector<long long>>{{1ll, 2ll}, {}});\n\
    \    CHECK_REPR((std::set<int>{3, 1, 2}), std::set<int>{1, 2, 3});\n    CHECK_REPR((std::pair<int,\
    \ std::string>{1, \"a\"}), std::pair<int, std::string>{1, \"a\"});\n    CHECK_REPR((std::pair<char,\
    \ double>{'x', 0.5}), std::pair<char, double>{'x', 0.500000});\n    CHECK_REPR((std::map<int,\
    \ char>{{2, 'b'}, {1, 'a'}}), std::map<int, char>{{1, 'a'}, {2, 'b'}});\n    CHECK_REPR((std::map<std::string,\
    \ std::vector<int>>{{\"k\", {1}}}), std::map<std::string, std::vector<int>>{{\"\
    k\", {1}}});\n    CHECK_REPR((std::array<int, 3>{1, 2, 3}), std::array<int, 3>{1,\
    \ 2, 3});\n    CHECK_REPR((std::vector<std::pair<int, unsigned>>{{1, 2u}}), std::vector<std::pair<int,\
    \ unsigned int>>{{1, 2u}});\n    check(type_str(std::vector<std::set<long long>>())\
    \ == \"std::vector<std::set<long long>>\", \"type_str (nested)\");\n    check(initializer_str(std::vector<int>{1,\
    \ 2}) == \"{1, 2}\", \"initializer_str (vector)\");\n\n    // repr / type_str\
    \ / initializer_str \u3092\u30E1\u30F3\u30D0\u95A2\u6570\u306B\u6301\u3064\u578B\
    \ (Range)\n    CHECK_REPR(Range(0, 10, 2), Range(0, 10, 2));\n    CHECK_REPR((std::vector<Range>{Range(0,\
    \ 3, 1)}), std::vector<Range>{{0, 3, 1}});\n    check(type_str(Range(5)) == \"\
    Range\" && initializer_str(Range(1, 5, 2)) == \"{1, 5, 2}\", \"Range\");\n\n \
    \   // \u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u305F\u306A\u3044\u578B\u306F\
    \ \"T\" \u3068 \"{}\"\n    check(type_str(Plain{}) == \"T\" && initializer_str(Plain{})\
    \ == \"{}\" && repr(Plain{}) == \"T{}\", \"Plain\");\n    // initializer_str \u3060\
    \u3051\u3092\u6301\u3064\u578B\n    check(repr(OnlyInit{7}) == \"T{7}\" && initializer_str(std::vector<OnlyInit>{{1},\
    \ {2}}) == \"{{1}, {2}}\", \"OnlyInit\");\n\n    // \u30E9\u30F3\u30C0\u30E0:\
    \ \u6574\u6570\u306E vector\n    for (int rep = 0; rep < 1000 && ok; rep++) {\n\
    \        int n = rng() % 5;\n        std::vector<long long> v(n);\n        std::string\
    \ expect = \"std::vector<long long>{\";\n        for (int i = 0; i < n; i++) {\n\
    \            v[i] = (long long)(rng() % 2001) - 1000;\n            expect += (i\
    \ ? \", \" : \"\") + std::to_string(v[i]) + \"ll\";\n        }\n        expect\
    \ += \"}\";\n        check(repr(v) == expect, \"repr(vector<long long>) (random)\"\
    );\n    }\n\n    // DEBUG(x) \u306F std::cerr \u306B \"x = repr(x)\" \u3092\u51FA\
    \u529B\u3059\u308B\n    {\n        std::ostringstream buf;\n        std::streambuf*\
    \ old = std::cerr.rdbuf(buf.rdbuf());\n        std::vector<int> xs{1, 2};\n  \
    \      DEBUG(xs);\n        std::cerr.rdbuf(old);\n        check(buf.str() == \"\
    xs = std::vector<int>{1, 2}\\n\", \"DEBUG\");\n    }\n\n    if (ok) std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// repr.hpp \u306E\u6587\u5B57\u5217\u5316\u3092\u691C\u8A3C\u3059\u308B\n\
    // CHECK_REPR(\u5024, \u5F0F) \u306F repr(\u5024) \u304C\u300C\u5F0F\u300D\u306E\
    \u6587\u5B57\u5217\u3068\u4E00\u81F4\u3057\u3001\u3055\u3089\u306B\u305D\u306E\
    \u5F0F\u3092\u8A55\u4FA1\u3059\u308B\u3068\u5024\u3068\u7B49\u3057\u304F\u306A\
    \u308B\u3053\u3068\u3092\u78BA\u304B\u3081\u308B\n// (\u5F0F\u306F\u3053\u306E\
    \u30D5\u30A1\u30A4\u30EB\u3067 C++ \u3068\u3057\u3066\u30B3\u30F3\u30D1\u30A4\u30EB\
    \u3055\u308C\u308B\u306E\u3067\u3001repr \u306E\u51FA\u529B\u304C C++ \u306E\u5F0F\
    \u3068\u3057\u3066\u6B63\u3057\u3044\u3053\u3068\u3082\u78BA\u304B\u3081\u3089\
    \u308C\u308B)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#include <array>\n#include <iostream>\n#include <map>\n#include\
    \ <random>\n#include <set>\n#include <sstream>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../src/utility/range.hpp\"\n#include \"../../src/utility/repr.hpp\"\
    \n\nbool ok = true;\nvoid check(bool cond, const std::string& what) {\n    if\
    \ (!cond) {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \        ok = false;\n    }\n}\n\n#define CHECK_REPR(value, ...)             \
    \                                            \\\n    do {                    \
    \                                                           \\\n        const\
    \ auto& value_ = (value);                                                  \\\n\
    \        check(repr(value_) == #__VA_ARGS__, \"repr(\" #value \") == \" #__VA_ARGS__\
    \ \" (got \" + repr(value_) + \")\"); \\\n        check(value_ == (__VA_ARGS__),\
    \ \"evaluating \" #__VA_ARGS__);                    \\\n    } while (0)\n\n//\
    \ repr \u306A\u3069\u306E\u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u305F\u306A\
    \u3044\u578B\nstruct Plain {};\n// initializer_str \u3060\u3051\u3092\u6301\u3064\
    \u578B\nstruct OnlyInit {\n    int x;\n    std::string initializer_str() const\
    \ { return \"{\" + std::to_string(x) + \"}\"; }\n};\n\n// char \u306E\u671F\u5F85\
    \u5024 (\u611A\u76F4\u306B\u4F5C\u308B)\nstd::string naive_char_repr(char c) {\n\
    \    unsigned char u = static_cast<unsigned char>(c);\n    switch (c) {\n    \
    \    case '\\0': return \"'\\\\0'\";\n        case '\\a': return \"'\\\\a'\";\n\
    \        case '\\b': return \"'\\\\b'\";\n        case '\\f': return \"'\\\\f'\"\
    ;\n        case '\\r': return \"'\\\\r'\";\n        case '\\n': return \"'\\\\\
    n'\";\n        case '\\v': return \"'\\\\v'\";\n        case '\\'': return \"\
    '\\\\''\";\n        case '\\\\': return \"'\\\\\\\\'\";\n    }\n    if (32 <=\
    \ u && u <= 126) return std::string(\"'\") + c + \"'\";\n    return \"'\\\\\"\
    \ + std::to_string(u / 64) + std::to_string(u / 8 % 8) + std::to_string(u % 8)\
    \ + \"'\";\n}\n\nint main() {\n    std::mt19937 rng(314);\n\n    // \u6574\u6570\
    \u30FB\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\n    CHECK_REPR(5, 5);\n    CHECK_REPR(-3,\
    \ -3);\n    CHECK_REPR(5L, 5l);\n    CHECK_REPR(-7LL, -7ll);\n    CHECK_REPR(5U,\
    \ 5u);\n    CHECK_REPR(5UL, 5ul);\n    CHECK_REPR(18446744073709551615ULL, 18446744073709551615ull);\n\
    \    CHECK_REPR(1.5f, 1.500000f);\n    CHECK_REPR(-0.25, -0.250000);\n    CHECK_REPR(2.5L,\
    \ 2.500000l);\n    check(type_str(5) == \"int\" && type_str(5L) == \"long\" &&\
    \ type_str(5LL) == \"long long\", \"type_str (signed)\");\n    check(type_str(5U)\
    \ == \"unsigned int\" && type_str(5UL) == \"unsigned long\" && type_str(5ULL)\
    \ == \"unsigned long long\", \"type_str (unsigned)\");\n    check(type_str(1.0f)\
    \ == \"float\" && type_str(1.0) == \"double\" && type_str(1.0L) == \"long double\"\
    , \"type_str (floating)\");\n    check(initializer_str(5LL) == \"5ll\" && initializer_str(1.5f)\
    \ == \"1.500000f\", \"initializer_str (number)\");\n\n    // char\n    CHECK_REPR('a',\
    \ 'a');\n    CHECK_REPR('\\n', '\\n');\n    CHECK_REPR('\\0', '\\0');\n    CHECK_REPR('\\\
    '', '\\'');\n    CHECK_REPR('\\\\', '\\\\');\n    CHECK_REPR(char(1), '\\001');\n\
    \    CHECK_REPR(char(127), '\\177');\n    CHECK_REPR(char(-61), '\\303');  //\
    \ UTF-8 \u306E\u6587\u5B57\u306E\u30D0\u30A4\u30C8\u306A\u3069\u3001\u8CA0\u306E\
    \u5024\u306E char\n    check(type_str('a') == \"char\" && initializer_str('a')\
    \ == \"'a'\", \"type_str / initializer_str (char)\");\n    for (int i = -128;\
    \ i <= 127; i++) {\n        char c = static_cast<char>(i);\n        check(repr(c)\
    \ == naive_char_repr(c), \"repr(char) for all values\");\n    }\n\n    // \u6587\
    \u5B57\u5217\n    {\n        const char* s = \"abc\";\n        check(repr(s) ==\
    \ \"\\\"abc\\\"\" && type_str(s) == \"char*\" && initializer_str(s) == \"\\\"\
    abc\\\"\", \"const char*\");\n    }\n    CHECK_REPR(std::string(\"abc\"), std::string{\"\
    abc\"});\n    CHECK_REPR(std::string(), std::string{\"\"});\n    check(type_str(std::string())\
    \ == \"std::string\" && initializer_str(std::string(\"x\")) == \"\\\"x\\\"\",\
    \ \"type_str / initializer_str (string)\");\n\n    // \u30B3\u30F3\u30C6\u30CA\
    \n    CHECK_REPR((std::vector<int>{1, 2, 3}), std::vector<int>{1, 2, 3});\n  \
    \  CHECK_REPR(std::vector<int>(), std::vector<int>{});\n    CHECK_REPR((std::vector<std::vector<long\
    \ long>>{{1, 2}, {}}), std::vector<std::vector<long long>>{{1ll, 2ll}, {}});\n\
    \    CHECK_REPR((std::set<int>{3, 1, 2}), std::set<int>{1, 2, 3});\n    CHECK_REPR((std::pair<int,\
    \ std::string>{1, \"a\"}), std::pair<int, std::string>{1, \"a\"});\n    CHECK_REPR((std::pair<char,\
    \ double>{'x', 0.5}), std::pair<char, double>{'x', 0.500000});\n    CHECK_REPR((std::map<int,\
    \ char>{{2, 'b'}, {1, 'a'}}), std::map<int, char>{{1, 'a'}, {2, 'b'}});\n    CHECK_REPR((std::map<std::string,\
    \ std::vector<int>>{{\"k\", {1}}}), std::map<std::string, std::vector<int>>{{\"\
    k\", {1}}});\n    CHECK_REPR((std::array<int, 3>{1, 2, 3}), std::array<int, 3>{1,\
    \ 2, 3});\n    CHECK_REPR((std::vector<std::pair<int, unsigned>>{{1, 2u}}), std::vector<std::pair<int,\
    \ unsigned int>>{{1, 2u}});\n    check(type_str(std::vector<std::set<long long>>())\
    \ == \"std::vector<std::set<long long>>\", \"type_str (nested)\");\n    check(initializer_str(std::vector<int>{1,\
    \ 2}) == \"{1, 2}\", \"initializer_str (vector)\");\n\n    // repr / type_str\
    \ / initializer_str \u3092\u30E1\u30F3\u30D0\u95A2\u6570\u306B\u6301\u3064\u578B\
    \ (Range)\n    CHECK_REPR(Range(0, 10, 2), Range(0, 10, 2));\n    CHECK_REPR((std::vector<Range>{Range(0,\
    \ 3, 1)}), std::vector<Range>{{0, 3, 1}});\n    check(type_str(Range(5)) == \"\
    Range\" && initializer_str(Range(1, 5, 2)) == \"{1, 5, 2}\", \"Range\");\n\n \
    \   // \u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u305F\u306A\u3044\u578B\u306F\
    \ \"T\" \u3068 \"{}\"\n    check(type_str(Plain{}) == \"T\" && initializer_str(Plain{})\
    \ == \"{}\" && repr(Plain{}) == \"T{}\", \"Plain\");\n    // initializer_str \u3060\
    \u3051\u3092\u6301\u3064\u578B\n    check(repr(OnlyInit{7}) == \"T{7}\" && initializer_str(std::vector<OnlyInit>{{1},\
    \ {2}}) == \"{{1}, {2}}\", \"OnlyInit\");\n\n    // \u30E9\u30F3\u30C0\u30E0:\
    \ \u6574\u6570\u306E vector\n    for (int rep = 0; rep < 1000 && ok; rep++) {\n\
    \        int n = rng() % 5;\n        std::vector<long long> v(n);\n        std::string\
    \ expect = \"std::vector<long long>{\";\n        for (int i = 0; i < n; i++) {\n\
    \            v[i] = (long long)(rng() % 2001) - 1000;\n            expect += (i\
    \ ? \", \" : \"\") + std::to_string(v[i]) + \"ll\";\n        }\n        expect\
    \ += \"}\";\n        check(repr(v) == expect, \"repr(vector<long long>) (random)\"\
    );\n    }\n\n    // DEBUG(x) \u306F std::cerr \u306B \"x = repr(x)\" \u3092\u51FA\
    \u529B\u3059\u308B\n    {\n        std::ostringstream buf;\n        std::streambuf*\
    \ old = std::cerr.rdbuf(buf.rdbuf());\n        std::vector<int> xs{1, 2};\n  \
    \      DEBUG(xs);\n        std::cerr.rdbuf(old);\n        check(buf.str() == \"\
    xs = std::vector<int>{1, 2}\\n\", \"DEBUG\");\n    }\n\n    if (ok) std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/range.hpp
  - src/utility/repr.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/repr.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 07:03:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/repr.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/repr.test.cpp
- /verify/test/unittest/repr.test.cpp.html
title: test/unittest/repr.test.cpp
---
