---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/imos.hpp
    title: "imos\u6CD5\u3067\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/lazy-segtree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-f.test.cpp
    title: test/aoj/dsl-2-f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-g.test.cpp
    title: test/aoj/dsl-2-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-h.1.test.cpp
    title: test/aoj/dsl-2-h.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-h.2.test.cpp
    title: test/aoj/dsl-2-h.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-i.test.cpp
    title: test/aoj/dsl-2-i.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-5-a.test.cpp
    title: test/aoj/dsl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/acted-monoid.test.cpp
    title: test/unittest/acted-monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/imos.test.cpp
    title: test/unittest/imos.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/segtree-beats.test.cpp
    title: test/unittest/segtree-beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/area-of-union-of-rectangles.1.test.cpp
    title: test/yosupo/area-of-union-of-rectangles.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/area-of-union-of-rectangles.2.test.cpp
    title: test/yosupo/area-of-union-of-rectangles.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point-add-range-sum.1.test.cpp
    title: test/yosupo/point-add-range-sum.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point-set-range-composite.4.test.cpp
    title: test/yosupo/point-set-range-composite.4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-affine-point-get.test.cpp
    title: test/yosupo/range-affine-point-get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-affine-range-sum.1.test.cpp
    title: test/yosupo/range-affine-range-sum.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-affine-range-sum.2.test.cpp
    title: test/yosupo/range-affine-range-sum.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-affine-range-sum.3.test.cpp
    title: test/yosupo/range-affine-range-sum.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
    title: test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
    title: test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-set-range-composite.test.cpp
    title: test/yosupo/range-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2292.test.cpp
    title: test/yukicoder/2292.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\
      \u7FA9"
    links: []
  bundledCode: "#line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file acted-monoid.hpp\n\
    \ * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306F\u30E2\u30CE\
    \u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\
    \u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\
    \u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n * - S mapping(const F&\
    \ f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528 f(x)\n *   \u533A\u9593\
    \u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\u306F mapping(f, x, sz)\
    \ (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084 mapping(f, x, l, r) (\u533A\
    \u9593 [l, r)) \u3067\u3082\u3088\u3044\n * - F composition(const F& f, const\
    \ F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210 f\u2218g (g\u3092\u9069\u7528\u3057\
    \u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\u308B)\n * - F id(): \u6052\u7B49\u5199\
    \u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\u3092\u306A\u3059\u5834\u5408 (imos.hpp\
    \ \u3067\u4F7F\u3046) \u306F\n * - F inv(const F& f): \u9006\u4F5C\u7528\u7D20\
    \n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n#include\
    \ <limits>\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
    #line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\
    \u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\
    \n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\
    \n#include <istream>\n#line 19 \"src/algebra/monoid.hpp\"\n#include <numeric>\n\
    #include <ostream>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084\
    \ acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B\
    : Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\
    \u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n\
    \    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr\
    \ T operator()(const T& x) const { return a * x + b; }\n    friend constexpr bool\
    \ operator==(const Affine& f, const Affine& g) { return f.a == g.a && f.b == g.b;\
    \ }\n    friend constexpr bool operator!=(const Affine& f, const Affine& g) {\
    \ return !(f == g); }\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Affine& f) {\n  \
    \      return is >> f.a >> f.b;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Affine& f) {\n        return os << f.a << CharT(' ') << f.b;\n\
    \    }\n};\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename\
    \ T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S\
    \ = T;\n    static constexpr S op(const S& a, const S& b) { return a * b; }\n\
    \    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename\
    \ T>\nstruct Max {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return std::min(a, b); }\n\
    \    static constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n\
    \ */\ntemplate <typename T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n\
    \    static constexpr S op(const S& a, const S& b) { return {std::min(a.first,\
    \ b.first), std::max(a.second, b.second)}; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()}; }\n};\n\n\
    /**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename T>\n\
    struct Xor {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a ^ b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct And {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a & b; }\n\
    \    static constexpr S e() { return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Or {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a | b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\u516C\u7D04\u6570\
    \ \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0,\
    \ 1, ..., N-1} \u304B\u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\
    \u5408\u6210 (\u5909\u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F\
    \ f[x] \u304C x \u306E\u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n * \u4F8B: SegTree<monoid::Mapping<3>>\
    \ seg(n); seg.set(i, {0, 2, 1});\n * swap(i, j) \u3067 i \u3068 j \u3092\u5165\
    \u308C\u66FF\u3048\u308B\u5199\u50CF\u3092\u4F5C\u308C\u308B\n *\n * @tparam N\
    \ \u5199\u50CF\u306E\u5B9A\u7FA9\u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\
    \n */\ntemplate <std::size_t N>\nstruct Mapping {\n    using S = std::array<int,\
    \ N>;\n    static constexpr S op(const S& f, const S& g) {\n        S h{};\n \
    \       for (std::size_t x = 0; x < N; x++) h[x] = g[f[x]];\n        return h;\n\
    \    }\n    static constexpr S e() {\n        S h{};\n        for (std::size_t\
    \ x = 0; x < N; x++) h[x] = static_cast<int>(x);\n        return h;\n    }\n \
    \   // i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u3001\u307B\u304B\u306F\u52D5\
    \u304B\u3055\u306A\u3044\u5199\u50CF (\u4E92\u63DB)\n    static constexpr S swap(int\
    \ i, int j) {\n        S h = e();\n        h[i] = j;\n        h[j] = i;\n    \
    \    return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\
    \u8868\u3059\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {g.a * f.a, g.a *\
    \ f.b + g.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close; // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u306E\u500B\u6570\n        long long open;  // \u5BFE\u5FDC\u306E\u53D6\
    \u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr S(char\
    \ c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long long close,\
    \ long long open) : close(close), open(open) {}\n        /**\n         * @brief\
    \ \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n        constexpr bool\
    \ is_valid() const { return close == 0 && open == 0; }\n    };\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if(a.open >= b.close) return S(a.close,\
    \ a.open - b.close + b.open);\n        return S(a.close + b.close - a.open, b.open);\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = int>\nstruct MinWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return b.first < a.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\
    \u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\n\
    struct MaxWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a.first < b.first ? b : a; }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ a;\n        if(b.first < a.first) return b;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return b;\n        if(b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n} // namespace\
    \ monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\
    \u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B\
    : SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));\n *\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n    S identity;\n\
    \    Monoid() = default;\n    constexpr Monoid(Op op, const S& e) : op_object(std::move(op)),\
    \ identity(e) {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a,\
    \ b); }\n    constexpr S e() const { return identity; }\n};\ntemplate <typename\
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 25 \"src/algebra/acted-monoid.hpp\"\
    \n\nnamespace acted_monoid {\n\nnamespace detail {\ntemplate <typename A, typename\
    \ = void>\nstruct has_mapping_lr : std::false_type {};\ntemplate <typename A>\n\
    struct has_mapping_lr<A, std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const\
    \ typename A::F&>(), std::declval<const typename A::S&>(), 0, 0))>> : std::true_type\
    \ {};\ntemplate <typename A, typename = void>\nstruct has_mapping_sz : std::false_type\
    \ {};\ntemplate <typename A>\nstruct has_mapping_sz<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0))>> : std::true_type {};\n} // namespace detail\n\n/**\n * @brief\
    \ \u533A\u9593 [l, r) \u3092\u8868\u3059\u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\
    \u9069\u7528\u3059\u308B\n * mapping \u306E\u5F15\u6570\u306E\u5F62\u306E\u9055\
    \u3044\u3092\u5438\u53CE\u3059\u308B\n */\ntemplate <typename A>\nconstexpr auto\
    \ apply_mapping(const A& a, const typename A::F& f, const typename A::S& x, int\
    \ l, int r) {\n    if constexpr(detail::has_mapping_lr<A>::value) {\n        return\
    \ a.mapping(f, x, l, r);\n    } else if constexpr(detail::has_mapping_sz<A>::value)\
    \ {\n        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
    \ x);\n    }\n}\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\
    \n */\ntemplate <typename T>\nstruct AddSum : monoid::Sum<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) { return x + f * S(sz); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n    static constexpr F inv(const F& f) { return -f; }\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u4E57\u7B97\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\n\
    struct MulSum : monoid::Sum<T> {\n    using S = T;\n    using F = T;\n    static\
    \ constexpr S mapping(const F& f, const S& x) { return f * x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f * g; }\n    static constexpr\
    \ F id() { return F(1); }\n    static constexpr F inv(const F& f) { return F(1)\
    \ / f; }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\n */\ntemplate <typename T>\nstruct AddMin : monoid::Min<T> {\n \
    \   using S = T;\n    using F = T;\n    static constexpr S mapping(const F& f,\
    \ const S& x) { return x + f; }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return f + g; }\n    static constexpr F id() { return F(0); }\n\
    };\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct AddMax : monoid::Max<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return x + f; }\n    static constexpr F composition(const F& f, const F& g)\
    \ { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u548C\n */\ntemplate <typename\
    \ T>\nstruct UpdateSum : monoid::Sum<T> {\n    using S = T;\n    using F = std::optional<T>;\n\
    \    static constexpr S mapping(const F& f, const S& x, int sz) { return f ? *f\
    \ * S(sz) : x; }\n    static constexpr F composition(const F& f, const F& g) {\
    \ return f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n\
    };\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u6700\u5C0F\u5024\
    \n */\ntemplate <typename T>\nstruct UpdateMin : monoid::Min<T> {\n    using S\
    \ = T;\n    using F = std::optional<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f ? *f : x; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f ? f : g; }\n    static constexpr F id() { return\
    \ std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct UpdateMax : monoid::Max<T>\
    \ {\n    using S = T;\n    using F = std::optional<T>;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return f ? *f : x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f ? f : g; }\n    static constexpr\
    \ F id() { return std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593chmin\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nstruct ChminMin :\
    \ monoid::Min<T> {\n    using S = T;\n    using F = T;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return std::min(f, x); }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return std::min(f, g); }\n    static\
    \ constexpr F id() { return std::numeric_limits<F>::max(); }\n};\n\n/**\n * @brief\
    \ \u533A\u9593chmax\u3001\u533A\u9593\u6700\u5927\u5024\n */\ntemplate <typename\
    \ T>\nstruct ChmaxMax : monoid::Max<T> {\n    using S = T;\n    using F = T;\n\
    \    static constexpr S mapping(const F& f, const S& x) { return std::max(f, x);\
    \ }\n    static constexpr F composition(const F& f, const F& g) { return std::max(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<F>::lowest();\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <-\
    \ a * x + b (Affine)\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\nstruct\
    \ AffineSum : monoid::Sum<T> {\n    using S = T;\n    using F = Affine<T>;\n \
    \   static constexpr S mapping(const F& f, const S& x, int sz) { return f.a *\
    \ x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id() { return\
    \ {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u30011\u6B21\u95A2\
    \u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename T>\nstruct\
    \ UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n    using\
    \ F = std::optional<S>;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) {\n        if(!f) return x;\n        // f \u3092 sz \u56DE\u5408\u6210\
    \u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n        for(;\
    \ sz > 0; sz >>= 1) {\n            if(sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using\
    \ S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return {x.first + f, x.second}; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MinCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMinCount : monoid::MinCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MaxCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMaxCount : monoid::MaxCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u306E0\u4E57\u548C\u304B\u3089K\u4E57\u548C\n *\n * S(x) \u3067\
    \u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
    S::operator[](i) \u3067 i \u4E57\u548C\u3092\u53D6\u5F97\u3059\u308B\n */\ntemplate\
    \ <typename T, int K>\nstruct AddPowerSum {\n    struct S {\n        std::array<T,\
    \ K + 1> val;\n        S() : val{} {}\n        S(const T& x) {\n            val[0]\
    \ = T(1);\n            for(int i = 1; i <= K; i++) val[i] = val[i - 1] * x;\n\
    \        }\n        const T& operator[](std::size_t i) const { return val[i];\
    \ }\n    };\n    using F = T;\n    static S op(const S& a, const S& b) {\n   \
    \     S ret;\n        for(int i = 0; i <= K; i++) ret.val[i] = a.val[i] + b.val[i];\n\
    \        return ret;\n    }\n    static S e() { return S(); }\n    static S mapping(const\
    \ F& f, const S& x) {\n        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)\n\
    \        static const auto binom = [] {\n            std::array<std::array<T,\
    \ K + 1>, K + 1> c{};\n            for(int i = 0; i <= K; i++) {\n           \
    \     c[i][0] = c[i][i] = T(1);\n                for(int j = 1; j < i; j++) c[i][j]\
    \ = c[i - 1][j - 1] + c[i - 1][j];\n            }\n            return c;\n   \
    \     }();\n        std::array<T, K + 1> pw{};\n        pw[0] = T(1);\n      \
    \  for(int i = 1; i <= K; i++) pw[i] = pw[i - 1] * f;\n        S ret;\n      \
    \  for(int i = 0; i <= K; i++) {\n            for(int j = 0; j <= i; j++) ret.val[i]\
    \ += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        return ret;\n   \
    \ }\n    static F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ F id() { return F(0); }\n};\n\n} // namespace acted_monoid\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam U \u4F5C\u7528\u7D20\u306E\u578B\n * @tparam Mapping\
    \ \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\u306F (f, x), (f, x, sz), (f, x, l,\
    \ r) \u306E\u3044\u305A\u308C\u304B\n * @tparam Composition \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename U, typename Mapping,\
    \ typename Composition>\nstruct ActedMonoid {\n    using S = T;\n    using F =\
    \ U;\n    Op op_object;\n    S identity;\n    Mapping mapping_object;\n    Composition\
    \ composition_object;\n    F lazy_identity;\n    ActedMonoid() = default;\n  \
    \  constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition,\
    \ const F& id)\n        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)),\
    \ composition_object(std::move(composition)), lazy_identity(id) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n    constexpr auto mapping(const F& f, const\
    \ S& x, int l, int r) const {\n        if constexpr(std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, int, int>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr(std::is_invocable_v<const Mapping&, const\
    \ F&, const S&, int>) {\n            return mapping_object(f, x, r - l);\n   \
    \     } else {\n            return mapping_object(f, x);\n        }\n    }\n \
    \   constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n"
  code: "#pragma once\n\n/**\n * @file acted-monoid.hpp\n * @brief \u4F5C\u7528\u7D20\
    \u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u4F5C\u7528\u7D20\
    \u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using F: \u4F5C\u7528\
    \u7D20\u306E\u578B\n * - S mapping(const F& f, const S& x): \u4F5C\u7528\u7D20\
    \u306E\u9069\u7528 f(x)\n *   \u533A\u9593\u306E\u60C5\u5831\u304C\u5FC5\u8981\
    \u306A\u5834\u5408\u306F mapping(f, x, sz) (sz \u306F\u533A\u9593\u306E\u9577\u3055\
    ) \u3084 mapping(f, x, l, r) (\u533A\u9593 [l, r)) \u3067\u3082\u3088\u3044\n\
    \ * - F composition(const F& f, const F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210\
    \ f\u2218g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\
    \u308B)\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\
    \u3092\u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046) \u306F\n * - F inv(const\
    \ F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <cstddef>\n#include <limits>\n#include <optional>\n#include <type_traits>\n\
    #include <utility>\n#include \"monoid.hpp\"\n\nnamespace acted_monoid {\n\nnamespace\
    \ detail {\ntemplate <typename A, typename = void>\nstruct has_mapping_lr : std::false_type\
    \ {};\ntemplate <typename A>\nstruct has_mapping_lr<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0, 0))>> : std::true_type {};\ntemplate <typename A, typename = void>\n\
    struct has_mapping_sz : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_sz<A,\
    \ std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename\
    \ A::F&>(), std::declval<const typename A::S&>(), 0))>> : std::true_type {};\n\
    } // namespace detail\n\n/**\n * @brief \u533A\u9593 [l, r) \u3092\u8868\u3059\
    \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\n * mapping\
    \ \u306E\u5F15\u6570\u306E\u5F62\u306E\u9055\u3044\u3092\u5438\u53CE\u3059\u308B\
    \n */\ntemplate <typename A>\nconstexpr auto apply_mapping(const A& a, const typename\
    \ A::F& f, const typename A::S& x, int l, int r) {\n    if constexpr(detail::has_mapping_lr<A>::value)\
    \ {\n        return a.mapping(f, x, l, r);\n    } else if constexpr(detail::has_mapping_sz<A>::value)\
    \ {\n        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
    \ x);\n    }\n}\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\
    \n */\ntemplate <typename T>\nstruct AddSum : monoid::Sum<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) { return x + f * S(sz); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n    static constexpr F inv(const F& f) { return -f; }\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u4E57\u7B97\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\n\
    struct MulSum : monoid::Sum<T> {\n    using S = T;\n    using F = T;\n    static\
    \ constexpr S mapping(const F& f, const S& x) { return f * x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f * g; }\n    static constexpr\
    \ F id() { return F(1); }\n    static constexpr F inv(const F& f) { return F(1)\
    \ / f; }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\n */\ntemplate <typename T>\nstruct AddMin : monoid::Min<T> {\n \
    \   using S = T;\n    using F = T;\n    static constexpr S mapping(const F& f,\
    \ const S& x) { return x + f; }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return f + g; }\n    static constexpr F id() { return F(0); }\n\
    };\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct AddMax : monoid::Max<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return x + f; }\n    static constexpr F composition(const F& f, const F& g)\
    \ { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u548C\n */\ntemplate <typename\
    \ T>\nstruct UpdateSum : monoid::Sum<T> {\n    using S = T;\n    using F = std::optional<T>;\n\
    \    static constexpr S mapping(const F& f, const S& x, int sz) { return f ? *f\
    \ * S(sz) : x; }\n    static constexpr F composition(const F& f, const F& g) {\
    \ return f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n\
    };\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u6700\u5C0F\u5024\
    \n */\ntemplate <typename T>\nstruct UpdateMin : monoid::Min<T> {\n    using S\
    \ = T;\n    using F = std::optional<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f ? *f : x; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f ? f : g; }\n    static constexpr F id() { return\
    \ std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct UpdateMax : monoid::Max<T>\
    \ {\n    using S = T;\n    using F = std::optional<T>;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return f ? *f : x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f ? f : g; }\n    static constexpr\
    \ F id() { return std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593chmin\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nstruct ChminMin :\
    \ monoid::Min<T> {\n    using S = T;\n    using F = T;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return std::min(f, x); }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return std::min(f, g); }\n    static\
    \ constexpr F id() { return std::numeric_limits<F>::max(); }\n};\n\n/**\n * @brief\
    \ \u533A\u9593chmax\u3001\u533A\u9593\u6700\u5927\u5024\n */\ntemplate <typename\
    \ T>\nstruct ChmaxMax : monoid::Max<T> {\n    using S = T;\n    using F = T;\n\
    \    static constexpr S mapping(const F& f, const S& x) { return std::max(f, x);\
    \ }\n    static constexpr F composition(const F& f, const F& g) { return std::max(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<F>::lowest();\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <-\
    \ a * x + b (Affine)\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\nstruct\
    \ AffineSum : monoid::Sum<T> {\n    using S = T;\n    using F = Affine<T>;\n \
    \   static constexpr S mapping(const F& f, const S& x, int sz) { return f.a *\
    \ x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id() { return\
    \ {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u30011\u6B21\u95A2\
    \u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename T>\nstruct\
    \ UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n    using\
    \ F = std::optional<S>;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) {\n        if(!f) return x;\n        // f \u3092 sz \u56DE\u5408\u6210\
    \u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n        for(;\
    \ sz > 0; sz >>= 1) {\n            if(sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using\
    \ S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return {x.first + f, x.second}; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MinCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMinCount : monoid::MinCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MaxCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMaxCount : monoid::MaxCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u306E0\u4E57\u548C\u304B\u3089K\u4E57\u548C\n *\n * S(x) \u3067\
    \u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
    S::operator[](i) \u3067 i \u4E57\u548C\u3092\u53D6\u5F97\u3059\u308B\n */\ntemplate\
    \ <typename T, int K>\nstruct AddPowerSum {\n    struct S {\n        std::array<T,\
    \ K + 1> val;\n        S() : val{} {}\n        S(const T& x) {\n            val[0]\
    \ = T(1);\n            for(int i = 1; i <= K; i++) val[i] = val[i - 1] * x;\n\
    \        }\n        const T& operator[](std::size_t i) const { return val[i];\
    \ }\n    };\n    using F = T;\n    static S op(const S& a, const S& b) {\n   \
    \     S ret;\n        for(int i = 0; i <= K; i++) ret.val[i] = a.val[i] + b.val[i];\n\
    \        return ret;\n    }\n    static S e() { return S(); }\n    static S mapping(const\
    \ F& f, const S& x) {\n        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)\n\
    \        static const auto binom = [] {\n            std::array<std::array<T,\
    \ K + 1>, K + 1> c{};\n            for(int i = 0; i <= K; i++) {\n           \
    \     c[i][0] = c[i][i] = T(1);\n                for(int j = 1; j < i; j++) c[i][j]\
    \ = c[i - 1][j - 1] + c[i - 1][j];\n            }\n            return c;\n   \
    \     }();\n        std::array<T, K + 1> pw{};\n        pw[0] = T(1);\n      \
    \  for(int i = 1; i <= K; i++) pw[i] = pw[i - 1] * f;\n        S ret;\n      \
    \  for(int i = 0; i <= K; i++) {\n            for(int j = 0; j <= i; j++) ret.val[i]\
    \ += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        return ret;\n   \
    \ }\n    static F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ F id() { return F(0); }\n};\n\n} // namespace acted_monoid\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam U \u4F5C\u7528\u7D20\u306E\u578B\n * @tparam Mapping\
    \ \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\u306F (f, x), (f, x, sz), (f, x, l,\
    \ r) \u306E\u3044\u305A\u308C\u304B\n * @tparam Composition \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename U, typename Mapping,\
    \ typename Composition>\nstruct ActedMonoid {\n    using S = T;\n    using F =\
    \ U;\n    Op op_object;\n    S identity;\n    Mapping mapping_object;\n    Composition\
    \ composition_object;\n    F lazy_identity;\n    ActedMonoid() = default;\n  \
    \  constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition,\
    \ const F& id)\n        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)),\
    \ composition_object(std::move(composition)), lazy_identity(id) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n    constexpr auto mapping(const F& f, const\
    \ S& x, int l, int r) const {\n        if constexpr(std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, int, int>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr(std::is_invocable_v<const Mapping&, const\
    \ F&, const S&, int>) {\n            return mapping_object(f, x, r - l);\n   \
    \     } else {\n            return mapping_object(f, x);\n        }\n    }\n \
    \   constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/algebra/acted-monoid.hpp
  requiredBy:
  - src/data_structures/lazy-segtree.hpp
  - src/data_structures/segtree-beats.hpp
  - src/data_structures/imos.hpp
  timestamp: '2026-10-13 12:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/imos.test.cpp
  - test/unittest/segtree-beats.test.cpp
  - test/unittest/acted-monoid.test.cpp
  - test/aoj/dsl-2-h.1.test.cpp
  - test/aoj/dsl-2-i.test.cpp
  - test/aoj/dsl-2-g.test.cpp
  - test/aoj/dsl-5-a.test.cpp
  - test/aoj/dsl-2-f.test.cpp
  - test/aoj/dsl-2-h.2.test.cpp
  - test/yosupo/point-add-range-sum.1.test.cpp
  - test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
  - test/yosupo/point-set-range-composite.4.test.cpp
  - test/yosupo/range-affine-range-sum.2.test.cpp
  - test/yosupo/range-affine-range-sum.3.test.cpp
  - test/yosupo/area-of-union-of-rectangles.2.test.cpp
  - test/yosupo/range-set-range-composite.test.cpp
  - test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
  - test/yosupo/range-affine-point-get.test.cpp
  - test/yosupo/area-of-union-of-rectangles.1.test.cpp
  - test/yosupo/range-affine-range-sum.1.test.cpp
  - test/yukicoder/2292.test.cpp
documentation_of: src/algebra/acted-monoid.hpp
layout: document
title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
---

[遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp) などに渡す作用素付きモノイドです。

作用素付きモノイドは、[モノイド](monoid.hpp) のメンバに加えて次のメンバを持つ型として表します。

- `using F`: 作用素の型
- `S mapping(const F& f, const S& x)`: 作用素の適用 $f(x)$。区間の情報が必要な場合は `mapping(f, x, sz)` (`sz` は区間の長さ) や `mapping(f, x, l, r)` (区間 $[l, r)$) でもよい
- `F composition(const F& f, const F& g)`: 作用素の合成 $f \circ g$ ($g$ を適用した後に $f$ を適用する)
- `F id()`: 恒等写像
- `F inv(const F& f)`: 逆作用素 ([imos法](../data_structures/imos.hpp) で使う場合のみ)

## 一覧 (`namespace acted_monoid`)

| 作用素付きモノイド | 作用 | 取得 | 作用素の型 `F` | `inv` |
|---|---|---|---|---|
| `AddSum<T>` | 区間加算 | 区間和 | `T` | ✓ |
| `MulSum<T>` | 区間乗算 | 区間和 | `T` | ✓ |
| `AddMin<T>` | 区間加算 | 区間最小値 | `T` | |
| `AddMax<T>` | 区間加算 | 区間最大値 | `T` | |
| `UpdateSum<T>` | 区間代入 | 区間和 | `optional<T>` | |
| `UpdateMin<T>` | 区間代入 | 区間最小値 | `optional<T>` | |
| `UpdateMax<T>` | 区間代入 | 区間最大値 | `optional<T>` | |
| `ChminMin<T>` | 区間 chmin | 区間最小値 | `T` | |
| `ChmaxMax<T>` | 区間 chmax | 区間最大値 | `T` | |
| `AffineSum<T>` | 区間アフィン変換 $x \leftarrow ax + b$ | 区間和 | [`Affine<T>`](monoid.hpp) | |
| `UpdateComposite<T>` | 区間代入 | 1次関数の合成 (`monoid::Composite`) | `optional<Affine<T>>` | |
| `AddMinWith<T, U = int>` | 区間加算 | 区間最小値とその位置 | `T` | |
| `AddMaxWith<T, U = int>` | 区間加算 | 区間最大値とその位置 | `T` | |
| `AddMinCount<T, U = long long>` | 区間加算 | 区間最小値とその個数 | `T` | |
| `AddMaxCount<T, U = long long>` | 区間加算 | 区間最大値とその個数 | `T` | |
| `AddPowerSum<T, K>` | 区間加算 | 区間の 0 乗和から K 乗和 | `T` | |

`AddPowerSum` の要素は `S(x)` で値 `x` の1要素から作り、`s[i]` で `i` 乗和を取得します。

## ラムダ式から作る

`ActedMonoid(op, e, mapping, composition, id)` で、関数オブジェクトから作用素付きモノイドを作れます。`mapping` の引数は `(f, x)`、`(f, x, sz)`、`(f, x, l, r)` のいずれでもかまいません。
