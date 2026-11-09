---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/math/quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
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
  bundledCode: "#line 1 \"test/unittest/math/quotients.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ enumerate_quotients \u3068 for_each_quotient \u3092\u3001i \u3054\u3068\u306B\
    \u5546\u3092\u8A08\u7B97\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\
    \u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\
    \u308B\n\n#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n\
    \ * @brief \u5546\u306E\u5217\u6319 (floor(n / i)\u30FBfloor((a x + b) / m) \u304C\
    \u4E00\u5B9A\u306E\u533A\u9593)\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cstddef>\n#include <iterator>\n#include <limits>\n\n#line 2 \"src/base/functions.hpp\"\
    \n\n/**\n * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax\
    \ \u306A\u3069)\n */\n\n#line 9 \"src/base/functions.hpp\"\n#include <cmath>\n\
    #line 12 \"src/base/functions.hpp\"\n#include <numeric>\n#if __cplusplus >= 202002L\n\
    #include <ranges>\n#endif\n#include <type_traits>\n#include <utility>\n\ntemplate\
    \ <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1& a, T2\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ninline constexpr long long max(const long long& t1, const long\
    \ long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
    \ long long min(const long long& t1, const long long& t2) {\n    return std::min<long\
    \ long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing\
    \ std::size;\n\n#if __cplusplus >= 202002L\nusing std::midpoint;\n#else\n// C++20\
    \ \u306E std::midpoint \u3068\u540C\u3058 (\u6574\u6570\u306F a \u306E\u5074\u306B\
    \u4E38\u3081\u3001\u3042\u3075\u308C\u306A\u3044)\ntemplate <typename T>\ninline\
    \ constexpr std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>,\
    \ T> midpoint(T a, T b) noexcept {\n    using U = std::make_unsigned_t<T>;\n \
    \   if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
    \ - static_cast<U>(a)) >> 1));\n    return static_cast<T>(a - static_cast<T>(static_cast<U>(static_cast<U>(a)\
    \ - static_cast<U>(b)) >> 1));\n}\ntemplate <typename T>\ninline constexpr std::enable_if_t<std::is_floating_point_v<T>,\
    \ T> midpoint(T a, T b) noexcept {\n    constexpr T lo = std::numeric_limits<T>::min()\
    \ * 2;\n    constexpr T hi = std::numeric_limits<T>::max() / 2;\n    const T abs_a\
    \ = a < 0 ? -a : a, abs_b = b < 0 ? -b : b;\n    if (abs_a <= hi && abs_b <= hi)\
    \ return (a + b) / 2;\n    if (abs_a < lo) return a + b / 2;\n    if (abs_b <\
    \ lo) return a / 2 + b;\n    return a / 2 + b / 2;\n}\ntemplate <typename T>\n\
    inline constexpr std::enable_if_t<std::is_object_v<T>, T*> midpoint(T* a, T* b)\
    \ noexcept {\n    return a + (b - a) / 2;\n}\n#endif\n\n/**\n * \u8981\u7D20\u6570\
    \u3092 long long \u3067\u8FD4\u3059 (std::ssize \u306E long long \u7248)\n * size()\
    \ \u3092\u6301\u3064\u578B\u306A\u3089\u3001begin() \u3068 end() \u3092\u6301\u305F\
    \u306A\u3044\u81EA\u4F5C\u306E\u578B\u306B\u3082\u4F7F\u3048\u308B\n */\n#if __cplusplus\
    \ >= 202002L\ntemplate <typename R>\n    requires requires(R& r) { std::ranges::size(r);\
    \ }\ninline constexpr long long len(R&& r) {\n    return static_cast<long long>(std::ranges::size(r));\n\
    }\n#else\ntemplate <typename C>\ninline constexpr auto len(const C& c) -> decltype(static_cast<long\
    \ long>(std::size(c))) {\n    return static_cast<long long>(std::size(c));\n}\n\
    #endif\n\ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T& b, T&\
    \ x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y,\
    \ x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n\
    \    }\n    return d;\n}\n\n/**\n * floor(a / b) (b != 0\u3001\u8CA0\u306E\u6570\
    \u3082\u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> floordiv(T1 a, T2 b) {\n    return a / b - (a % b != 0 && (a < 0) != (b\
    \ < 0));\n}\n/**\n * ceil(a / b) (b != 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n\
    \ */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> ceildiv(T1 a, T2 b) {\n    return a / b + (a % b != 0 && (a < 0) == (b <\
    \ 0));\n}\n/**\n * {floor(a / b), a - b * floor(a / b)} (b != 0\u3001\u8CA0\u306E\
    \u6570\u3082\u53EF)\n * \u4F59\u308A\u306F 0 \u307E\u305F\u306F b \u3068\u540C\
    \u3058\u7B26\u53F7\u306B\u306A\u308B\n */\ntemplate <typename T1, typename T2>\n\
    inline constexpr std::pair<std::common_type_t<T1, T2>, std::common_type_t<T1,\
    \ T2>> divmod(T1 a, T2 b) {\n    std::common_type_t<T1, T2> q = floordiv(a, b);\n\
    \    return {q, a - q * b};\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr bool\
    \ inrange(long long x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n *\
    \ a <= x < b\n */\ninline constexpr bool inrange(long long x, long long a, long\
    \ long b) {\n    return a <= x && x < b;\n}\n/**\n * 0 <= x < a and 0 <= y < b\n\
    \ */\ninline constexpr bool inrect(long long x, long long y, long long a, long\
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n#line 15 \"src/math/quotients.hpp\"\
    \n\n/**\n * @brief \u5546 q \u3068\u3001\u305D\u308C\u3092\u3068\u308B\u6DFB\u5B57\
    \u306E\u533A\u9593 [l, r)\n */\nstruct QuotientRange {\n    long long q;  //!<\
    \ \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080\
    )\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u307E\u306A\u3044\
    )\n};\n\nnamespace internal_quotients {\nstruct Quotients {\n    long long n =\
    \ 0;\n    QuotientRange current{0, 1, 1};\n    bool done = true;\n\n    void advance()\
    \ {\n        const long long l = current.r;\n        done = l > n;\n        if\
    \ (!done) {\n            const long long q = n / l;\n            current = {q,\
    \ l, n / q + 1};\n        }\n    }\n};\n\nstruct QuotientsLinear {\n    long long\
    \ n = 0, m = 1, a = 0, b = 0;\n    QuotientRange current{0, 0, 0};\n    bool done\
    \ = true;\n\n    void advance() {\n        const long long l = current.r;\n  \
    \      done = l == n;\n        if (done) return;\n        if (a == 1) {\n    \
    \        long long q, length;\n            if (l == 0) {\n                auto\
    \ [initial_q, rem] = divmod(static_cast<__int128_t>(b), static_cast<__int128_t>(m));\n\
    \                q = static_cast<long long>(initial_q);\n                length\
    \ = m - static_cast<long long>(rem);\n            } else {\n                assert(current.q\
    \ < std::numeric_limits<long long>::max());\n                q = current.q + 1;\n\
    \                length = m;\n            }\n            current = {q, l, l +\
    \ std::min(length, n - l)};\n            return;\n        }\n        advance_general(l);\n\
    \    }\n\n    // \u52A0\u7B97\u3060\u3051\u3067\u9032\u3080 a == 1 \u306E\u66F4\
    \u65B0\u3092\u30A4\u30F3\u30E9\u30A4\u30F3\u5316\u3057\u3084\u3059\u3044\u3088\
    \u3046\u3001\u6C4E\u7528\u8A08\u7B97\u3092\u5206\u3051\u308B\u3002\n    void advance_general(long\
    \ long l) {\n        const __int128_t slope = a;\n        auto [q, rem] = divmod(slope\
    \ * l + b, static_cast<__int128_t>(m));\n        assert(std::numeric_limits<long\
    \ long>::min() <= q && q <= std::numeric_limits<long long>::max());\n        __int128_t\
    \ length = n - l;\n        // \u6B63\u306E\u50BE\u304D\u3067\u306F\u6B21\u306E\
    \u5546\u306B\u5C4A\u304F\u307E\u3067\u3001\u8CA0\u306E\u50BE\u304D\u3067\u306F\
    \u4F59\u308A\u304C\u8CA0\u306B\u306A\u308B\u307E\u3067\u9032\u3080\n        if\
    \ (a > 0) chmin(length, ceildiv(m - rem, slope));\n        if (a < 0) chmin(length,\
    \ rem / (-slope) + 1);\n        current = {static_cast<long long>(q), l, l + static_cast<long\
    \ long>(length)};\n    }\n};\n\n// \u30A4\u30C6\u30EC\u30FC\u30BF\u304C\u72B6\u614B\
    \u3092\u6240\u6709\u3059\u308B\u305F\u3081\u3001range \u306E\u5BFF\u547D\u3084\
    \u5225\u306E\u8D70\u67FB\u306B\u4F9D\u5B58\u3057\u306A\u3044\u3002\ntemplate <class\
    \ State>\nclass Enumeration {\n    State initial;\n\n   public:\n    explicit\
    \ Enumeration(State initial) : initial(initial) {}\n\n    class iterator {\n \
    \       State state;\n\n       public:\n        using value_type = QuotientRange;\n\
    \        using difference_type = std::ptrdiff_t;\n        using reference = value_type;\n\
    \        using pointer = void;\n        using iterator_category = std::input_iterator_tag;\n\
    \n        iterator() = default;\n        explicit iterator(State state) : state(state)\
    \ { this->state.advance(); }\n        value_type operator*() const { return state.current;\
    \ }\n        iterator& operator++() {\n            state.advance();\n        \
    \    return *this;\n        }\n        iterator operator++(int) {\n          \
    \  auto previous = *this;\n            ++*this;\n            return previous;\n\
    \        }\n        bool operator==(const iterator& other) const {\n         \
    \   if (state.done || other.state.done) return state.done == other.state.done;\n\
    \            return state.current.l == other.state.current.l;\n        }\n   \
    \     bool operator!=(const iterator& other) const { return !(*this == other);\
    \ }\n    };\n\n    iterator begin() const { return iterator(initial); }\n    iterator\
    \ end() const { return iterator(); }\n};\n}  // namespace internal_quotients\n\
    \n/**\n * @brief floor(n / i) \u304C\u4E00\u5B9A\u306E\u533A\u9593\u3092\u6DFB\
    \u5B57\u306E\u6607\u9806 (\u5546\u306E\u964D\u9806) \u306B\u9045\u5EF6\u5217\u6319\
    \u3059\u308B\u3002\u5168\u4F53 O(sqrt(n))\u3001\u8FFD\u52A0\u9818\u57DF O(1)\n\
    \ * @pre 0 <= n < std::numeric_limits<long long>::max()\n */\ninline auto enumerate_quotients(long\
    \ long n) {\n    assert(0 <= n && n < std::numeric_limits<long long>::max());\n\
    \    return internal_quotients::Enumeration(internal_quotients::Quotients{n});\n\
    }\n\n/**\n * @brief x = 0, ..., n - 1 \u3092 floor((a x + b) / m) \u306E\u5024\
    \u3067\u533A\u9593\u306B\u5206\u3051\u3001x \u306E\u6607\u9806\u306B\u9045\u5EF6\
    \u5217\u6319\u3059\u308B\u3002\u5168\u4F53 O(\u533A\u9593\u6570)\u3001\u8FFD\u52A0\
    \u9818\u57DF O(1)\n * @pre n >= 0\u3001m >= 1\u3001\u5404\u5546\u304C long long\
    \ \u306B\u53CE\u307E\u308B\u3053\u3068\u3002a, b \u306F\u8CA0\u3067\u3082\u3088\
    \u3044\n */\ninline auto enumerate_quotients_linear(long long n, long long m,\
    \ long long a, long long b) {\n    assert(n >= 0 && m >= 1);\n    return internal_quotients::Enumeration(internal_quotients::QuotientsLinear{n,\
    \ m, a, b});\n}\n\n/**\n * @brief floor(n / i) \u304C\u4E00\u5B9A\u306E\u533A\u9593\
    \u3054\u3068\u306B f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n */\ntemplate <typename\
    \ F>\nvoid for_each_quotient(long long n, F f) {\n    for (auto [q, l, r] : enumerate_quotients(n))\
    \ f(q, l, r);\n}\n\n/**\n * @brief floor((a x + b) / m) \u304C\u4E00\u5B9A\u306E\
    \u533A\u9593\u3054\u3068\u306B f(q, l, r) \u3092\u547C\u3076 O(\u533A\u9593\u6570\
    )\n */\ntemplate <typename F>\nvoid for_each_quotient_linear(long long n, long\
    \ long m, long long a, long long b, F f) {\n    for (auto [q, l, r] : enumerate_quotients_linear(n,\
    \ m, a, b)) f(q, l, r);\n}\n#line 7 \"test/unittest/math/quotients.test.cpp\"\n\
    \n#line 9 \"test/unittest/math/quotients.test.cpp\"\n#include <iostream>\n#line\
    \ 12 \"test/unittest/math/quotients.test.cpp\"\n#include <vector>\n#if __cplusplus\
    \ >= 202002L\n#include <ranges>\n#endif\n\n#if __cplusplus >= 202002L\nstatic_assert(std::ranges::input_range<decltype(enumerate_quotients(10))>);\n\
    #endif\n\nint main() {\n    bool ok = true;\n    for (long long n = 0; n <= 3000\
    \ && ok; n++) {\n        auto range = enumerate_quotients(n);\n        std::vector<QuotientRange>\
    \ qs(range.begin(), range.end());\n        // \u533A\u9593\u304C 1 \u304B\u3089\
    \ n \u307E\u3067\u3092\u9699\u9593\u306A\u304F\u8986\u3044\u3001\u533A\u9593\u306E\
    \u4E2D\u3067\u5546\u304C q \u306B\u7B49\u3057\u304F\u3001\u96A3\u306E\u533A\u9593\
    \u3068\u306F\u5546\u304C\u7570\u306A\u308B\n        long long next = 1;\n    \
    \    for (int k = 0; k < static_cast<int>(qs.size()); k++) {\n            auto\
    \ [q, l, r] = qs[k];\n            if (l != next || l >= r) ok = false;\n     \
    \       if (n / l != q || n / (r - 1) != q) ok = false;\n            if (k > 0\
    \ && qs[k - 1].q <= q) ok = false;\n            next = r;\n        }\n       \
    \ if (next != n + 1) ok = false;\n        // \u533A\u9593\u306E\u500B\u6570\u306F\
    \ 2 sqrt(n) \u4EE5\u4E0B\n        long long k = qs.size();\n        if (k * k\
    \ > 4 * n) ok = false;\n        // \u7D04\u6570\u306E\u500B\u6570\u306E\u548C\
    \ sum_{k <= n} d(k) = sum_{i <= n} floor(n / i)\n        long long expected =\
    \ 0, sum = 0;\n        for (long long i = 1; i <= n; i++) expected += n / i;\n\
    \        for_each_quotient(n, [&](long long q, long long l, long long r) { sum\
    \ += q * (r - l); });\n        ok = ok && sum == expected;\n    }\n\n    // \u4F8B\
    \n    auto qs = enumerate_quotients(10);\n    std::vector<long long> q, l, r;\n\
    \    for (auto x : qs) q.push_back(x.q), l.push_back(x.l), r.push_back(x.r);\n\
    \    ok = ok && q == std::vector<long long>{10, 5, 3, 2, 1} && l == std::vector<long\
    \ long>{1, 2, 3, 4, 6};\n    ok = ok && r == std::vector<long long>{2, 3, 4, 6,\
    \ 11};\n    // \u5927\u304D\u3044 n \u3067\u3082\u533A\u9593\u306E\u500B\u6570\
    \u306F 2 sqrt(n) \u7A0B\u5EA6\n    auto large = enumerate_quotients(1000000000000LL);\n\
    \    ok = ok && std::distance(large.begin(), large.end()) == 1999999;\n    const\
    \ auto huge = enumerate_quotients(std::numeric_limits<long long>::max() - 1);\n\
    \    auto first = huge.begin(), copy = first;\n    assert((*first++).l == 1 &&\
    \ (*first).l == 2 && (*copy).l == 1);\n    assert((*huge.begin()).l == 1);\n\n\
    \    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n \
    \       std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// enumerate_quotients \u3068 for_each_quotient \u3092\u3001i \u3054\u3068\
    \u306B\u5546\u3092\u8A08\u7B97\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#include \"../../../src/math/quotients.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <vector>\n\
    #if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\n#if __cplusplus >= 202002L\n\
    static_assert(std::ranges::input_range<decltype(enumerate_quotients(10))>);\n\
    #endif\n\nint main() {\n    bool ok = true;\n    for (long long n = 0; n <= 3000\
    \ && ok; n++) {\n        auto range = enumerate_quotients(n);\n        std::vector<QuotientRange>\
    \ qs(range.begin(), range.end());\n        // \u533A\u9593\u304C 1 \u304B\u3089\
    \ n \u307E\u3067\u3092\u9699\u9593\u306A\u304F\u8986\u3044\u3001\u533A\u9593\u306E\
    \u4E2D\u3067\u5546\u304C q \u306B\u7B49\u3057\u304F\u3001\u96A3\u306E\u533A\u9593\
    \u3068\u306F\u5546\u304C\u7570\u306A\u308B\n        long long next = 1;\n    \
    \    for (int k = 0; k < static_cast<int>(qs.size()); k++) {\n            auto\
    \ [q, l, r] = qs[k];\n            if (l != next || l >= r) ok = false;\n     \
    \       if (n / l != q || n / (r - 1) != q) ok = false;\n            if (k > 0\
    \ && qs[k - 1].q <= q) ok = false;\n            next = r;\n        }\n       \
    \ if (next != n + 1) ok = false;\n        // \u533A\u9593\u306E\u500B\u6570\u306F\
    \ 2 sqrt(n) \u4EE5\u4E0B\n        long long k = qs.size();\n        if (k * k\
    \ > 4 * n) ok = false;\n        // \u7D04\u6570\u306E\u500B\u6570\u306E\u548C\
    \ sum_{k <= n} d(k) = sum_{i <= n} floor(n / i)\n        long long expected =\
    \ 0, sum = 0;\n        for (long long i = 1; i <= n; i++) expected += n / i;\n\
    \        for_each_quotient(n, [&](long long q, long long l, long long r) { sum\
    \ += q * (r - l); });\n        ok = ok && sum == expected;\n    }\n\n    // \u4F8B\
    \n    auto qs = enumerate_quotients(10);\n    std::vector<long long> q, l, r;\n\
    \    for (auto x : qs) q.push_back(x.q), l.push_back(x.l), r.push_back(x.r);\n\
    \    ok = ok && q == std::vector<long long>{10, 5, 3, 2, 1} && l == std::vector<long\
    \ long>{1, 2, 3, 4, 6};\n    ok = ok && r == std::vector<long long>{2, 3, 4, 6,\
    \ 11};\n    // \u5927\u304D\u3044 n \u3067\u3082\u533A\u9593\u306E\u500B\u6570\
    \u306F 2 sqrt(n) \u7A0B\u5EA6\n    auto large = enumerate_quotients(1000000000000LL);\n\
    \    ok = ok && std::distance(large.begin(), large.end()) == 1999999;\n    const\
    \ auto huge = enumerate_quotients(std::numeric_limits<long long>::max() - 1);\n\
    \    auto first = huge.begin(), copy = first;\n    assert((*first++).l == 1 &&\
    \ (*first).l == 2 && (*copy).l == 1);\n    assert((*huge.begin()).l == 1);\n\n\
    \    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n \
    \       std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/math/quotients.hpp
  - src/base/functions.hpp
  isVerificationFile: true
  path: test/unittest/math/quotients.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/quotients.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/quotients.test.cpp
- /verify/test/unittest/math/quotients.test.cpp.html
title: test/unittest/math/quotients.test.cpp
---
