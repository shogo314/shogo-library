---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/counter.hpp
    title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
      \ (Counter)"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/counter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Counter \u3092 std::map \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/counter.hpp\"\
    \n\n/**\n * @file counter.hpp\n * @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\
    \u308B\u591A\u91CD\u96C6\u5408 (Counter)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstddef>\n#include <initializer_list>\n#include <iterator>\n\
    #include <map>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <functional>\n\
    #line 11 \"src/utility/traits.hpp\"\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\
    \n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    #line 19 \"src/data_structures/counter.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Counter {\n    using key_type = T;\n    using mapped_type = long long;\n   \
    \ using value_type = std::pair<key_type, mapped_type>;\n    std::map<key_type,\
    \ mapped_type> data;\n\n    void inc(const key_type& key, const mapped_type& t)\
    \ {\n        data[key] += t;\n        auto itr = data.find(key);\n        assert(itr->second\
    \ >= 0);\n        if (itr->second == 0) {\n            data.erase(itr);\n    \
    \    }\n    }\n    Counter() = default;\n    explicit Counter(const key_type&\
    \ x) : data{{x, 1}} {}\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\u7D20\u3092\
    \u6570\u3048\u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string \u306A\
    \u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\u3089\
    \u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n    explicit Counter(C&& v) {\n        for (const\
    \ key_type& a : v) {\n            data[a]++;\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            data[i] += c;\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\
    \u304F\u3068\u3001\u8D70\u67FB\u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc\
    \ \u304C\u6D88\u3057\u3066\u3057\u307E\u3046\n        if (this == &o) {\n    \
    \        data.clear();\n            return *this;\n        }\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, -c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator-(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res -= b;\n    }\n    auto begin()\
    \ const { return data.begin(); }\n    auto end() const { return data.end(); }\n\
    \    /**\n     * @brief \u7570\u306A\u308B\u5024\u306E\u500B\u6570 (\u91CD\u8907\
    \u306F\u6570\u3048\u306A\u3044)\n     */\n    long long size() const {\n     \
    \   return static_cast<long long>(data.size());\n    }\n    /**\n     * @brief\
    \ \u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\
    \u548C)\n     * @note Python \u306E collections.Counter.total() \u3068\u540C\u3058\
    \u3002O(\u7570\u306A\u308B\u5024\u306E\u500B\u6570)\n     */\n    mapped_type\
    \ total() const {\n        mapped_type ret = 0;\n        for (const auto& [key,\
    \ cnt] : data) ret += cnt;\n        return ret;\n    }\n    mapped_type get(const\
    \ key_type& key) const {\n        auto itr = data.find(key);\n        if (itr\
    \ == data.end()) return 0;\n        return itr->second;\n    }\n    void set(const\
    \ key_type& key, const mapped_type& t) {\n        assert(t >= 0);\n        if\
    \ (t > 0) {\n            data[key] = t;\n        } else {\n            auto itr\
    \ = data.find(key);\n            if (itr != data.end()) {\n                data.erase(itr);\n\
    \            }\n        }\n    }\n    std::vector<value_type> most_common() const\
    \ {\n        std::vector<value_type> ret;\n        ret.reserve(data.size());\n\
    \        for (const auto& [i, c] : data) {\n            ret.push_back({i, c});\n\
    \        }\n        std::sort(ret.begin(), ret.end(), [](const value_type& a,\
    \ const value_type& b) { return a.second > b.second || (a.second == b.second &&\
    \ a.first < b.first); });\n        return ret;\n    }\n    class CounterReference\
    \ {\n        Counter& base;\n        key_type key;\n\n       public:\n       \
    \ CounterReference(Counter& base, key_type key) : base(base), key(key) {}\n  \
    \      CounterReference& operator=(const mapped_type& x) {\n            base.set(key,\
    \ x);\n            return *this;\n        }\n        CounterReference& operator+=(const\
    \ mapped_type& x) {\n            base.inc(key, x);\n            return *this;\n\
    \        }\n        CounterReference& operator-=(const mapped_type& x) {\n   \
    \         base.inc(key, -x);\n            return *this;\n        }\n        operator\
    \ mapped_type() const {\n            return base.get(key);\n        }\n    };\n\
    \    mapped_type operator[](const key_type& key) const {\n        return get(key);\n\
    \    }\n    CounterReference operator[](const key_type& key) {\n        return\
    \ CounterReference(*this, key);\n    }\n};\n#line 7 \"test/unittest/data_structures/counter.test.cpp\"\
    \n\n#line 9 \"test/unittest/data_structures/counter.test.cpp\"\n#include <iostream>\n\
    #line 11 \"test/unittest/data_structures/counter.test.cpp\"\n#include <random>\n\
    #include <string>\n#line 14 \"test/unittest/data_structures/counter.test.cpp\"\
    \n\nusing Model = std::map<int, long long>;\n\n// \u500B\u6570 0 \u306E\u5024\u3092\
    \u53D6\u308A\u9664\u3044\u305F map \u306B\u3059\u308B\nModel normalize(Model m)\
    \ {\n    for (auto itr = m.begin(); itr != m.end();) {\n        if (itr->second\
    \ == 0)\n            itr = m.erase(itr);\n        else\n            ++itr;\n \
    \   }\n    return m;\n}\n\nbool same(const Counter<int>& c, const Model& m) {\n\
    \    Model mm = normalize(m);\n    if (c.size() != static_cast<int>(mm.size()))\
    \ return false;\n    // total \u306F\u91CD\u8907\u3092\u542B\u3081\u305F\u8981\
    \u7D20\u6570 (\u500B\u6570\u306E\u7DCF\u548C)\n    long long sum = 0;\n    for\
    \ (auto [x, cnt] : mm) sum += cnt;\n    if (c.total() != sum) return false;\n\
    \    // begin / end \u3067\u8D70\u67FB\u3057\u305F\u7D50\u679C\u304C\u5024\u306E\
    \u6607\u9806\u306B\u4E00\u81F4\u3059\u308B\n    std::vector<std::pair<int, long\
    \ long>> a(c.begin(), c.end()), b(mm.begin(), mm.end());\n    if (a != b) return\
    \ false;\n    // const \u306A [] \u3068 get\n    for (int x = -1; x <= 10; x++)\
    \ {\n        long long expect = mm.count(x) ? mm.at(x) : 0;\n        if (c[x]\
    \ != expect || c.get(x) != expect) return false;\n    }\n    return true;\n}\n\
    \nModel random_model(std::mt19937& rng) {\n    Model m;\n    int k = rng() % 6;\n\
    \    for (int i = 0; i < k; i++) m[rng() % 10] += rng() % 4;\n    return m;\n\
    }\n\nCounter<int> from_model(const Model& m) {\n    Counter<int> c;\n    for (auto\
    \ [x, cnt] : m) c[x] = cnt;\n    return c;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    auto check = [&](bool cond, const char*\
    \ what) {\n        if (!cond && ok) {\n            std::cerr << \"failed: \" <<\
    \ what << std::endl;\n            ok = false;\n        }\n    };\n\n    // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    {\n        Counter<int> empty;\n   \
    \     check(same(empty, {}), \"default constructor\");\n        Counter<int> one(5);\n\
    \        check(same(one, {{5, 1}}), \"Counter(x)\");\n        std::vector<int>\
    \ v = {3, 1, 3, 2, 3};\n        Counter<int> from_vec(v);\n        check(same(from_vec,\
    \ {{1, 1}, {2, 1}, {3, 3}}), \"Counter(range)\");\n        Counter<int> from_il{{1,\
    \ 2}, {4, 0}, {7, 3}, {1, 1}};\n        check(same(from_il, {{1, 3}, {7, 3}}),\
    \ \"Counter(initializer_list)\");\n        // const \u3067\u306A\u3044\u5DE6\u8FBA\
    \u5024\u304B\u3089\u306E\u30B3\u30D4\u30FC\u304C\u7BC4\u56F2\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6A2A\u53D6\u308A\u3055\u308C\u306A\u3044\
    \n        Counter<int> copy(from_vec);\n        check(same(copy, {{1, 1}, {2,\
    \ 1}, {3, 3}}), \"copy constructor\");\n        // key_type \u304C\u7BC4\u56F2\
    \u3067\u3082\u3042\u308B\u5834\u5408\u306F\u5024 1 \u500B\u3068\u3057\u3066\u6570\
    \u3048\u308B\n        Counter<std::string> s(std::string(\"ab\"));\n        check(s.size()\
    \ == 1 && s[\"ab\"] == 1, \"Counter<std::string>(x)\");\n        Counter<char>\
    \ chars(std::string(\"aab\"));\n        check(chars['a'] == 2 && chars['b'] ==\
    \ 1 && chars.size() == 2, \"Counter<char>(string)\");\n        // size \u306F\u7570\
    \u306A\u308B\u5024\u306E\u500B\u6570\u3001total \u306F\u91CD\u8907\u3092\u542B\
    \u3081\u305F\u8981\u7D20\u6570\n        Counter<int> dup(std::vector<int>{3, 3,\
    \ 3, 5});\n        check(dup.size() == 2 && dup.total() == 4, \"size / total\"\
    );\n        check(Counter<int>().total() == 0, \"total of empty\");\n    }\n\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Model ma = random_model(rng),\
    \ mb = random_model(rng);\n        Counter<int> a = from_model(ma), b = from_model(mb);\n\
    \        check(same(a, ma), \"operator[] =\");\n\n        // + \u3068 +=\n   \
    \     Model sum = ma;\n        for (auto [x, cnt] : mb) sum[x] += cnt;\n     \
    \   check(same(a + b, sum), \"operator+\");\n        Counter<int> c = a;\n   \
    \     c += b;\n        check(same(c, sum), \"operator+=\");\n\n        // - \u3068\
    \ -= (\u500B\u6570\u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u7BC4\u56F2\u3067\
    )\n        Model sub = sum;\n        for (auto [x, cnt] : mb) sub[x] -= cnt;\n\
    \        check(same(c - b, sub), \"operator-\");\n        c -= b;\n        check(same(c,\
    \ sub), \"operator-=\");\n\n        // [] \u306B\u3088\u308B += / -= / =\n   \
    \     Counter<int> d = from_model(ma);\n        Model md = ma;\n        for (int\
    \ t = 0; t < 20; t++) {\n            int x = rng() % 10;\n            int op =\
    \ rng() % 3;\n            if (op == 0) {\n                long long k = rng()\
    \ % 3;\n                d[x] += k;\n                md[x] += k;\n            }\
    \ else if (op == 1) {\n                long long have = md.count(x) ? md[x] :\
    \ 0;\n                long long k = have == 0 ? 0 : rng() % (have + 1);\n    \
    \            d[x] -= k;\n                md[x] -= k;\n            } else {\n \
    \               long long k = rng() % 3;\n                d[x] = k;\n        \
    \        md[x] = k;\n            }\n            // \u53C2\u7167\u304B\u3089\u306E\
    \u8AAD\u307F\u53D6\u308A\n            long long expect = normalize(md).count(x)\
    \ ? normalize(md).at(x) : 0;\n            check(static_cast<long long>(d[x]) ==\
    \ expect, \"CounterReference -> mapped_type\");\n        }\n        check(same(d,\
    \ md), \"operator[] += / -= / =\");\n\n        // most_common: \u500B\u6570\u306E\
    \u964D\u9806\u3001\u540C\u6570\u306A\u3089\u5024\u306E\u6607\u9806\n        Model\
    \ nm = normalize(md);\n        std::vector<std::pair<int, long long>> expect(nm.begin(),\
    \ nm.end());\n        std::stable_sort(expect.begin(), expect.end(), [](const\
    \ auto& p, const auto& q) { return p.second > q.second; });\n        check(d.most_common()\
    \ == expect, \"most_common\");\n    }\n\n    // \u81EA\u5206\u81EA\u8EAB\u3092\
    \u5F15\u304F\u3068\u7A7A\u306B\u306A\u308B (\u8D70\u67FB\u4E2D\u306E\u8981\u7D20\
    \u3092\u6D88\u3057\u3066\u3082\u58CA\u308C\u306A\u3044)\n    if (ok) {\n     \
    \   Counter<int> c{{1, 2}, {3, 1}, {5, 4}};\n        c -= c;\n        check(same(c,\
    \ {}), \"self operator-=\");\n        Counter<int> d{{1, 2}, {3, 1}};\n      \
    \  d += d;\n        check(same(d, {{1, 4}, {3, 2}}), \"self operator+=\");\n \
    \   }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Counter \u3092 std::map \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/data_structures/counter.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <random>\n\
    #include <string>\n#include <vector>\n\nusing Model = std::map<int, long long>;\n\
    \n// \u500B\u6570 0 \u306E\u5024\u3092\u53D6\u308A\u9664\u3044\u305F map \u306B\
    \u3059\u308B\nModel normalize(Model m) {\n    for (auto itr = m.begin(); itr !=\
    \ m.end();) {\n        if (itr->second == 0)\n            itr = m.erase(itr);\n\
    \        else\n            ++itr;\n    }\n    return m;\n}\n\nbool same(const\
    \ Counter<int>& c, const Model& m) {\n    Model mm = normalize(m);\n    if (c.size()\
    \ != static_cast<int>(mm.size())) return false;\n    // total \u306F\u91CD\u8907\
    \u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\u548C)\n\
    \    long long sum = 0;\n    for (auto [x, cnt] : mm) sum += cnt;\n    if (c.total()\
    \ != sum) return false;\n    // begin / end \u3067\u8D70\u67FB\u3057\u305F\u7D50\
    \u679C\u304C\u5024\u306E\u6607\u9806\u306B\u4E00\u81F4\u3059\u308B\n    std::vector<std::pair<int,\
    \ long long>> a(c.begin(), c.end()), b(mm.begin(), mm.end());\n    if (a != b)\
    \ return false;\n    // const \u306A [] \u3068 get\n    for (int x = -1; x <=\
    \ 10; x++) {\n        long long expect = mm.count(x) ? mm.at(x) : 0;\n       \
    \ if (c[x] != expect || c.get(x) != expect) return false;\n    }\n    return true;\n\
    }\n\nModel random_model(std::mt19937& rng) {\n    Model m;\n    int k = rng()\
    \ % 6;\n    for (int i = 0; i < k; i++) m[rng() % 10] += rng() % 4;\n    return\
    \ m;\n}\n\nCounter<int> from_model(const Model& m) {\n    Counter<int> c;\n  \
    \  for (auto [x, cnt] : m) c[x] = cnt;\n    return c;\n}\n\nint main() {\n   \
    \ std::mt19937 rng(314);\n    bool ok = true;\n    auto check = [&](bool cond,\
    \ const char* what) {\n        if (!cond && ok) {\n            std::cerr << \"\
    failed: \" << what << std::endl;\n            ok = false;\n        }\n    };\n\
    \n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    {\n        Counter<int>\
    \ empty;\n        check(same(empty, {}), \"default constructor\");\n        Counter<int>\
    \ one(5);\n        check(same(one, {{5, 1}}), \"Counter(x)\");\n        std::vector<int>\
    \ v = {3, 1, 3, 2, 3};\n        Counter<int> from_vec(v);\n        check(same(from_vec,\
    \ {{1, 1}, {2, 1}, {3, 3}}), \"Counter(range)\");\n        Counter<int> from_il{{1,\
    \ 2}, {4, 0}, {7, 3}, {1, 1}};\n        check(same(from_il, {{1, 3}, {7, 3}}),\
    \ \"Counter(initializer_list)\");\n        // const \u3067\u306A\u3044\u5DE6\u8FBA\
    \u5024\u304B\u3089\u306E\u30B3\u30D4\u30FC\u304C\u7BC4\u56F2\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6A2A\u53D6\u308A\u3055\u308C\u306A\u3044\
    \n        Counter<int> copy(from_vec);\n        check(same(copy, {{1, 1}, {2,\
    \ 1}, {3, 3}}), \"copy constructor\");\n        // key_type \u304C\u7BC4\u56F2\
    \u3067\u3082\u3042\u308B\u5834\u5408\u306F\u5024 1 \u500B\u3068\u3057\u3066\u6570\
    \u3048\u308B\n        Counter<std::string> s(std::string(\"ab\"));\n        check(s.size()\
    \ == 1 && s[\"ab\"] == 1, \"Counter<std::string>(x)\");\n        Counter<char>\
    \ chars(std::string(\"aab\"));\n        check(chars['a'] == 2 && chars['b'] ==\
    \ 1 && chars.size() == 2, \"Counter<char>(string)\");\n        // size \u306F\u7570\
    \u306A\u308B\u5024\u306E\u500B\u6570\u3001total \u306F\u91CD\u8907\u3092\u542B\
    \u3081\u305F\u8981\u7D20\u6570\n        Counter<int> dup(std::vector<int>{3, 3,\
    \ 3, 5});\n        check(dup.size() == 2 && dup.total() == 4, \"size / total\"\
    );\n        check(Counter<int>().total() == 0, \"total of empty\");\n    }\n\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Model ma = random_model(rng),\
    \ mb = random_model(rng);\n        Counter<int> a = from_model(ma), b = from_model(mb);\n\
    \        check(same(a, ma), \"operator[] =\");\n\n        // + \u3068 +=\n   \
    \     Model sum = ma;\n        for (auto [x, cnt] : mb) sum[x] += cnt;\n     \
    \   check(same(a + b, sum), \"operator+\");\n        Counter<int> c = a;\n   \
    \     c += b;\n        check(same(c, sum), \"operator+=\");\n\n        // - \u3068\
    \ -= (\u500B\u6570\u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u7BC4\u56F2\u3067\
    )\n        Model sub = sum;\n        for (auto [x, cnt] : mb) sub[x] -= cnt;\n\
    \        check(same(c - b, sub), \"operator-\");\n        c -= b;\n        check(same(c,\
    \ sub), \"operator-=\");\n\n        // [] \u306B\u3088\u308B += / -= / =\n   \
    \     Counter<int> d = from_model(ma);\n        Model md = ma;\n        for (int\
    \ t = 0; t < 20; t++) {\n            int x = rng() % 10;\n            int op =\
    \ rng() % 3;\n            if (op == 0) {\n                long long k = rng()\
    \ % 3;\n                d[x] += k;\n                md[x] += k;\n            }\
    \ else if (op == 1) {\n                long long have = md.count(x) ? md[x] :\
    \ 0;\n                long long k = have == 0 ? 0 : rng() % (have + 1);\n    \
    \            d[x] -= k;\n                md[x] -= k;\n            } else {\n \
    \               long long k = rng() % 3;\n                d[x] = k;\n        \
    \        md[x] = k;\n            }\n            // \u53C2\u7167\u304B\u3089\u306E\
    \u8AAD\u307F\u53D6\u308A\n            long long expect = normalize(md).count(x)\
    \ ? normalize(md).at(x) : 0;\n            check(static_cast<long long>(d[x]) ==\
    \ expect, \"CounterReference -> mapped_type\");\n        }\n        check(same(d,\
    \ md), \"operator[] += / -= / =\");\n\n        // most_common: \u500B\u6570\u306E\
    \u964D\u9806\u3001\u540C\u6570\u306A\u3089\u5024\u306E\u6607\u9806\n        Model\
    \ nm = normalize(md);\n        std::vector<std::pair<int, long long>> expect(nm.begin(),\
    \ nm.end());\n        std::stable_sort(expect.begin(), expect.end(), [](const\
    \ auto& p, const auto& q) { return p.second > q.second; });\n        check(d.most_common()\
    \ == expect, \"most_common\");\n    }\n\n    // \u81EA\u5206\u81EA\u8EAB\u3092\
    \u5F15\u304F\u3068\u7A7A\u306B\u306A\u308B (\u8D70\u67FB\u4E2D\u306E\u8981\u7D20\
    \u3092\u6D88\u3057\u3066\u3082\u58CA\u308C\u306A\u3044)\n    if (ok) {\n     \
    \   Counter<int> c{{1, 2}, {3, 1}, {5, 4}};\n        c -= c;\n        check(same(c,\
    \ {}), \"self operator-=\");\n        Counter<int> d{{1, 2}, {3, 1}};\n      \
    \  d += d;\n        check(same(d, {{1, 4}, {3, 2}}), \"self operator+=\");\n \
    \   }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/counter.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/counter.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 05:46:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/counter.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/counter.test.cpp
- /verify/test/unittest/data_structures/counter.test.cpp.html
title: test/unittest/data_structures/counter.test.cpp
---
