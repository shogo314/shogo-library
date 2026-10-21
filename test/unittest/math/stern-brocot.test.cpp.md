---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/math/rational.hpp
    title: "\u6709\u7406\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/stern-brocot.hpp
    title: "Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570"
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
  bundledCode: "#line 1 \"test/unittest/math/stern-brocot.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ stern-brocot.hpp \u306E\u95A2\u6570\u3092\u3001\u6728\u3092 1 \u6B69\u305A\u3064\
    \u305F\u3069\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3084\u5168\u63A2\u7D22\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/math/stern-brocot.hpp\"\
    \n\n/**\n * @file stern-brocot.hpp\n * @brief Stern\u2013Brocot \u6728\u3068\u9023\
    \u5206\u6570\n */\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/math/rational.hpp\"\n\n\
    /**\n * @file rational.hpp\n * @brief \u6709\u7406\u6570\n */\n\n#line 9 \"src/math/rational.hpp\"\
    \n#include <cstddef>\n#include <istream>\n#include <ostream>\n#include <string>\n\
    #line 14 \"src/math/rational.hpp\"\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n\
    \ * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\
    \u3069)\n */\n\n#line 9 \"src/base/functions.hpp\"\n#include <cmath>\n#include\
    \ <iterator>\n#include <limits>\n#include <numeric>\n#if __cplusplus >= 202002L\n\
    #include <ranges>\n#endif\n#include <type_traits>\n#line 18 \"src/base/functions.hpp\"\
    \n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2\
    \ b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1&\
    \ a, T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ninline constexpr long long max(const long long& t1, const\
    \ long long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
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
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n#line 16 \"src/math/rational.hpp\"\
    \n\n/**\n * @brief \u6709\u7406\u6570 (\u5206\u6570)\n *\n * \u5E38\u306B\u65E2\
    \u7D04\u3067\u3001\u5206\u6BCD\u306F\u6B63\u30020 \u306F 0/1\n * \u6F14\u7B97\u306E\
    \u9014\u4E2D\u3067\u3082\u3001\u65E2\u7D04\u306B\u3057\u3066\u304B\u3089\u639B\
    \u3051\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306B\
    \u304F\u3044\u3002\u6BD4\u8F03\u306F T \u304C 64 bit \u4EE5\u4E0B\u306A\u3089\
    \ __int128 \u3067\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u9023\u5206\u6570\
    \u5C55\u958B\u3067\u884C\u3046\n * std::map \u3084 std::set \u306E\u30AD\u30FC\
    \u306B\u4F7F\u3048\u308B\n * \u4F8B:\n * Rational<> a(1, 3), b(1, 6);\n * a +\
    \ b;   // 1/2\n * a < b;   // false\n *\n * @tparam T \u6574\u6570\u578B (long\
    \ long \u3084 __int128 \u306A\u3069)\n */\ntemplate <typename T = long long>\n\
    class Rational {\n    T p, q;  // p / q (q > 0\u3001gcd(p, q) = 1)\n\n    static\
    \ constexpr T abs_(T x) { return x < 0 ? -x : x; }\n    static constexpr T gcd_(T\
    \ a, T b) {\n        a = abs_(a), b = abs_(b);\n        while (b != 0) {\n   \
    \         T t = a % b;\n            a = b;\n            b = t;\n        }\n  \
    \      return a;\n    }\n    struct Raw {};\n    // \u3059\u3067\u306B\u65E2\u7D04\
    \u3067 q > 0 \u3068\u308F\u304B\u3063\u3066\u3044\u308B\u5834\u5408\n    constexpr\
    \ Rational(T p, T q, Raw) : p(p), q(q) {}\n\n    // a / b \u3068 c / d (b, d >\
    \ 0) \u3092\u6BD4\u3079\u3001\u5C0F\u3055\u3051\u308C\u3070\u8CA0\u3001\u7B49\u3057\
    \u3051\u308C\u3070 0\u3001\u5927\u304D\u3051\u308C\u3070\u6B63\u3092\u8FD4\u3059\
    \n    static constexpr int compare(T a, T b, T c, T d) {\n        if constexpr\
    \ (sizeof(T) <= 8) {\n            __int128 x = static_cast<__int128>(a) * d, y\
    \ = static_cast<__int128>(c) * b;\n            return x < y ? -1 : x > y ? 1\n\
    \                                      : 0;\n        } else {\n            //\
    \ \u6574\u6570\u90E8\u5206\u3092\u6BD4\u3079\u3001\u540C\u3058\u306A\u3089\u5C0F\
    \u6570\u90E8\u5206\u306E\u9006\u6570\u3092\u6BD4\u3079\u308B (\u5927\u5C0F\u304C\
    \u9006\u306B\u306A\u308B)\n            int sign = 1;\n            while (true)\
    \ {\n                T x = floordiv(a, b), y = floordiv(c, d);\n             \
    \   if (x != y) return x < y ? -sign : sign;\n                a -= x * b, c -=\
    \ y * d;\n                if (a == 0 || c == 0) {\n                    if (a ==\
    \ 0 && c == 0) return 0;\n                    return a == 0 ? -sign : sign;\n\
    \                }\n                T t = a;\n                a = b, b = t;\n\
    \                t = c;\n                c = d, d = t;\n                sign =\
    \ -sign;\n            }\n        }\n    }\n\n   public:\n    /**\n     * @brief\
    \ \u6574\u6570 n\n     */\n    constexpr Rational(T n = 0) : p(n), q(1) {}\n \
    \   /**\n     * @brief num / den (den != 0)\n     */\n    constexpr Rational(T\
    \ num, T den) : p(num), q(den) {\n        assert(den != 0 && \"Rational: division\
    \ by zero\");\n        if (q < 0) p = -p, q = -q;\n        T g = gcd_(p, q);\n\
    \        p /= g, q /= g;\n    }\n\n    /**\n     * @brief \u5206\u5B50\n     */\n\
    \    constexpr T num() const { return p; }\n    /**\n     * @brief \u5206\u6BCD\
    \ (\u6B63)\n     */\n    constexpr T den() const { return q; }\n\n    /**\n  \
    \   * @brief \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u6574\u6570\n     */\n    constexpr\
    \ T floor() const { return floordiv(p, q); }\n    /**\n     * @brief \u4EE5\u4E0A\
    \u3067\u6700\u5C0F\u306E\u6574\u6570\n     */\n    constexpr T ceil() const {\
    \ return ceildiv(p, q); }\n    /**\n     * @brief \u6574\u6570\u304B\n     */\n\
    \    constexpr bool is_integer() const { return q == 1; }\n    /**\n     * @brief\
    \ double \u306B\u76F4\u3057\u305F\u5024\n     */\n    constexpr double to_double()\
    \ const { return static_cast<double>(p) / static_cast<double>(q); }\n    /**\n\
    \     * @brief long double \u306B\u76F4\u3057\u305F\u5024\n     */\n    constexpr\
    \ long double to_long_double() const { return static_cast<long double>(p) / static_cast<long\
    \ double>(q); }\n    explicit constexpr operator double() const { return to_double();\
    \ }\n\n    /**\n     * @brief \u9006\u6570 (0 \u3067\u306A\u3044\u3053\u3068)\n\
    \     */\n    constexpr Rational inv() const {\n        assert(p != 0 && \"Rational:\
    \ division by zero\");\n        return p > 0 ? Rational(q, p, Raw{}) : Rational(-q,\
    \ -p, Raw{});\n    }\n    /**\n     * @brief \u7D76\u5BFE\u5024\n     */\n   \
    \ constexpr Rational abs() const { return Rational(abs_(p), q, Raw{}); }\n\n \
    \   constexpr Rational operator+() const { return *this; }\n    constexpr Rational\
    \ operator-() const { return Rational(-p, q, Raw{}); }\n\n    constexpr Rational&\
    \ operator+=(const Rational& r) {\n        // p / q + r.p / r.q \u3092\u3001\u5206\
    \u6BCD\u306E gcd \u3067\u5272\u3063\u3066\u304B\u3089\u901A\u5206\u3059\u308B\n\
    \        T g = gcd_(q, r.q);\n        T qg = q / g;\n        T t = p * (r.q /\
    \ g) + r.p * qg;\n        T g2 = gcd_(t, g);\n        p = t / g2;\n        q =\
    \ qg * (r.q / g2);\n        return *this;\n    }\n    constexpr Rational& operator-=(const\
    \ Rational& r) { return *this += -r; }\n    constexpr Rational& operator*=(const\
    \ Rational& r) {\n        // \u639B\u3051\u308B\u524D\u306B\u3001\u5206\u5B50\u3068\
    \u76F8\u624B\u306E\u5206\u6BCD\u306E gcd \u3067\u5272\u308B\n        T g1 = gcd_(p,\
    \ r.q), g2 = gcd_(r.p, q);\n        p = (p / g1) * (r.p / g2);\n        q = (q\
    \ / g2) * (r.q / g1);\n        return *this;\n    }\n    constexpr Rational& operator/=(const\
    \ Rational& r) { return *this *= r.inv(); }\n\n    friend constexpr Rational operator+(Rational\
    \ a, const Rational& b) { return a += b; }\n    friend constexpr Rational operator-(Rational\
    \ a, const Rational& b) { return a -= b; }\n    friend constexpr Rational operator*(Rational\
    \ a, const Rational& b) { return a *= b; }\n    friend constexpr Rational operator/(Rational\
    \ a, const Rational& b) { return a /= b; }\n\n    friend constexpr bool operator==(const\
    \ Rational& a, const Rational& b) { return a.p == b.p && a.q == b.q; }\n    friend\
    \ constexpr bool operator!=(const Rational& a, const Rational& b) { return !(a\
    \ == b); }\n    friend constexpr bool operator<(const Rational& a, const Rational&\
    \ b) { return compare(a.p, a.q, b.p, b.q) < 0; }\n    friend constexpr bool operator>(const\
    \ Rational& a, const Rational& b) { return b < a; }\n    friend constexpr bool\
    \ operator<=(const Rational& a, const Rational& b) { return !(b < a); }\n    friend\
    \ constexpr bool operator>=(const Rational& a, const Rational& b) { return !(a\
    \ < b); }\n\n    /**\n     * @brief \"p/q\" \u306E\u5F62\u306E\u6587\u5B57\u5217\
    \ (\u6574\u6570\u306A\u3089 \"p\")\n     */\n    std::string to_string() const\
    \ {\n        auto str = [](T x) {\n            if (x == 0) return std::string(\"\
    0\");\n            bool neg = x < 0;\n            std::string s;\n           \
    \ // \u8CA0\u306E\u307E\u307E 1 \u6841\u305A\u3064\u53D6\u308A\u51FA\u3059 (\u6700\
    \u5C0F\u5024\u3067\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044)\n            while (x != 0) {\n                T d = x % 10;\n       \
    \         s += static_cast<char>('0' + (d < 0 ? -d : d));\n                x /=\
    \ 10;\n            }\n            if (neg) s += '-';\n            return std::string(s.rbegin(),\
    \ s.rend());\n        };\n        return q == 1 ? str(p) : str(p) + \"/\" + str(q);\n\
    \    }\n\n    friend std::ostream& operator<<(std::ostream& os, const Rational&\
    \ r) { return os << r.to_string(); }\n    /**\n     * @brief \"p/q\" \u307E\u305F\
    \u306F \"p\" \u306E\u5F62\u3067\u8AAD\u3080\n     */\n    friend std::istream&\
    \ operator>>(std::istream& is, Rational& r) {\n        std::string s;\n      \
    \  if (!(is >> s)) return is;\n        auto parse = [](const std::string& t) {\n\
    \            T x = 0;\n            bool neg = false;\n            std::size_t\
    \ i = 0;\n            if (i < t.size() && (t[i] == '-' || t[i] == '+')) neg =\
    \ t[i++] == '-';\n            for (; i < t.size(); i++) x = x * 10 + (t[i] - '0');\n\
    \            return neg ? -x : x;\n        };\n        auto pos = s.find('/');\n\
    \        if (pos == std::string::npos)\n            r = Rational(parse(s));\n\
    \        else\n            r = Rational(parse(s.substr(0, pos)), parse(s.substr(pos\
    \ + 1)));\n        return is;\n    }\n};\n#line 15 \"src/math/stern-brocot.hpp\"\
    \n\n/**\n * @brief Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570\n *\n * \u6B63\
    \u306E\u6709\u7406\u6570\u3092 Stern\u2013Brocot \u6728 (\u6839\u306F 1/1) \u306E\
    \u9802\u70B9\u3068\u540C\u4E00\u8996\u3059\u308B\n * \u6839\u304B\u3089\u9802\u70B9\
    \u3078\u306E\u9053\u306F\u3001\u5DE6\u306E\u5B50\u3078\u9032\u3080 'L' \u3068\u53F3\
    \u306E\u5B50\u3078\u9032\u3080 'R' \u3092\u9023\u9577\u5727\u7E2E\u3057\u305F\
    \ {\u6587\u5B57, \u56DE\u6570} \u306E\u5217\u3067\u8868\u3059\n * \u4F8B:\n *\
    \ stern_brocot::encode_path(Rational<>(3, 2));                     // {{'R', 1},\
    \ {'L', 1}}\n * stern_brocot::simplest_between(Rational<>(1, 3), Rational<>(1,\
    \ 2));  // 2/5\n */\nnamespace stern_brocot {\n\n/**\n * @brief \u9023\u5206\u6570\
    \u5C55\u958B x = a0 + 1 / (a1 + 1 / (... + 1 / an))\n * a0 = floor(x)\u3001i >=\
    \ 1 \u3067\u306F ai >= 1\u3002n >= 1 \u306A\u3089 an >= 2 (\u8868\u3057\u65B9\u304C\
    \ 1 \u901A\u308A\u306B\u6C7A\u307E\u308B)\n */\ntemplate <typename T>\nstd::vector<T>\
    \ continued_fraction(const Rational<T>& x) {\n    std::vector<T> res;\n    T p\
    \ = x.num(), q = x.den();\n    T a = x.floor();\n    res.push_back(a);\n    p\
    \ -= a * q;\n    while (p != 0) {\n        // \u5C0F\u6570\u90E8\u5206 p / q \u306E\
    \u9006\u6570 q / p \u306E\u6574\u6570\u90E8\u5206\n        T t = q / p, r = q\
    \ - t * p;\n        res.push_back(t);\n        q = p, p = r;\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief \u9023\u5206\u6570 [a0; a1, ..., an] \u304C\u8868\u3059\
    \u6709\u7406\u6570\n * @pre a \u306F\u7A7A\u3067\u306A\u304F\u3001i >= 1 \u3067\
    \u306F ai >= 1\n */\ntemplate <typename T>\nRational<T> from_continued_fraction(const\
    \ std::vector<T>& a) {\n    assert(!a.empty());\n    // \u5F8C\u308D\u304B\u3089\
    \ p / q = ai + 1 / (p / q) \u3092\u305F\u3069\u308B\n    T p = a.back(), q = 1;\n\
    \    for (int i = static_cast<int>(a.size()) - 2; i >= 0; i--) {\n        assert(a[i\
    \ + 1] >= 1);\n        T np = a[i] * p + q;\n        q = p, p = np;\n    }\n \
    \   return Rational<T>(p, q);\n}\n\n/**\n * @brief \u6839 1/1 \u304B\u3089 x \u3078\
    \u306E\u9053\n * @pre x > 0\n */\ntemplate <typename T>\nstd::vector<std::pair<char,\
    \ T>> encode_path(const Rational<T>& x) {\n    assert(x > 0);\n    std::vector<T>\
    \ a = continued_fraction(x);\n    // x = [a0; a1, ..., an] \u3078\u306E\u9053\u306F\
    \ R^a0 L^a1 R^a2 ... \u3067\u3001\u6700\u5F8C\u306E\u9805\u3060\u3051 1 \u5C11\
    \u306A\u3044\n    a.back() -= 1;\n    std::vector<std::pair<char, T>> res;\n \
    \   for (int i = 0; i < static_cast<int>(a.size()); i++) {\n        if (a[i] >\
    \ 0) res.emplace_back(i % 2 == 0 ? 'R' : 'L', a[i]);\n    }\n    return res;\n\
    }\n\nnamespace internal {\n// \u9053\u3092\u305F\u3069\u3063\u305F\u3042\u3068\
    \u306E\u9802\u70B9\u306E\u3001\u5B50\u5B6B\u306E\u7BC4\u56F2\u306E\u4E21\u7AEF\
    \ (\u4E0B\u7AEF lo\u3001\u4E0A\u7AEF hi)\u3002\u5206\u6BCD\u304C 0 \u306A\u3089\
    \ +\u221E\ntemplate <typename T>\nstruct Bounds {\n    T lo_num = 0, lo_den =\
    \ 1, hi_num = 1, hi_den = 0;\n    // 'R' \u3078 n \u56DE: \u4E0B\u7AEF\u304C\u4ECA\
    \u306E\u9802\u70B9 (lo + hi) \u306B n \u56DE\u7F6E\u304D\u63DB\u308F\u308B\n \
    \   void move(char c, T n) {\n        assert(c == 'L' || c == 'R');\n        if\
    \ (c == 'R') {\n            lo_num += n * hi_num, lo_den += n * hi_den;\n    \
    \    } else {\n            hi_num += n * lo_num, hi_den += n * lo_den;\n     \
    \   }\n    }\n    Rational<T> node() const { return Rational<T>(lo_num + hi_num,\
    \ lo_den + hi_den); }\n};\ntemplate <typename T>\nBounds<T> walk(const std::vector<std::pair<char,\
    \ T>>& path) {\n    Bounds<T> b;\n    for (auto [c, n] : path) {\n        assert(n\
    \ >= 0);\n        b.move(c, n);\n    }\n    return b;\n}\n}  // namespace internal\n\
    \n/**\n * @brief \u6839 1/1 \u304B\u3089\u9053 path \u3092\u305F\u3069\u3063\u305F\
    \u9802\u70B9\n * \u540C\u3058\u6587\u5B57\u304C\u7D9A\u3044\u3066\u3082\u3088\u304F\
    \u3001\u56DE\u6570\u306F 0 \u4EE5\u4E0A\n */\ntemplate <typename T>\nRational<T>\
    \ decode_path(const std::vector<std::pair<char, T>>& path) {\n    return internal::walk(path).node();\n\
    }\n\n/**\n * @brief x \u306E\u6DF1\u3055 (\u6839 1/1 \u306F 0)\n * @pre x > 0\n\
    \ */\ntemplate <typename T>\nT depth(const Rational<T>& x) {\n    T d = 0;\n \
    \   for (auto [c, n] : encode_path(x)) d += n;\n    return d;\n}\n\n/**\n * @brief\
    \ x \u3068 y \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\n * @pre x > 0\u3001y\
    \ > 0\n */\ntemplate <typename T>\nRational<T> lca(const Rational<T>& x, const\
    \ Rational<T>& y) {\n    std::vector<std::pair<char, T>> px = encode_path(x),\
    \ py = encode_path(y), common;\n    for (int i = 0; i < static_cast<int>(std::min(px.size(),\
    \ py.size())); i++) {\n        if (px[i].first != py[i].first) break;\n      \
    \  common.emplace_back(px[i].first, std::min(px[i].second, py[i].second));\n \
    \       if (px[i].second != py[i].second) break;\n    }\n    return decode_path(common);\n\
    }\n\n/**\n * @brief x \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C k \u306E\u9802\
    \u70B9 (k > depth(x) \u306A\u3089 std::nullopt)\n * @pre x > 0\u3001k >= 0\n */\n\
    template <typename T>\nstd::optional<Rational<T>> ancestor(const Rational<T>&\
    \ x, T k) {\n    assert(k >= 0);\n    std::vector<std::pair<char, T>> path;\n\
    \    for (auto [c, n] : encode_path(x)) {\n        if (k == 0) break;\n      \
    \  T m = std::min(n, k);\n        path.emplace_back(c, m);\n        k -= m;\n\
    \    }\n    if (k > 0) return std::nullopt;\n    return decode_path(path);\n}\n\
    \n/**\n * @brief x \u306E\u5B50\u5B6B (x \u81EA\u8EAB\u3092\u542B\u3080) \u304C\
    \u8986\u3046\u958B\u533A\u9593\u306E {{\u4E0B\u7AEF\u306E\u5206\u5B50, \u5206\u6BCD\
    }, {\u4E0A\u7AEF\u306E\u5206\u5B50, \u5206\u6BCD}}\n * \u4E0B\u7AEF\u306F 0 \u306A\
    \u3089 {0, 1}\u3001\u4E0A\u7AEF\u306F +\u221E \u306A\u3089 {1, 0}\n * @pre x >\
    \ 0\n */\ntemplate <typename T>\nstd::pair<std::pair<T, T>, std::pair<T, T>> range(const\
    \ Rational<T>& x) {\n    internal::Bounds<T> b = internal::walk(encode_path(x));\n\
    \    return {{b.lo_num, b.lo_den}, {b.hi_num, b.hi_den}};\n}\n\nnamespace internal\
    \ {\n// 0 <= a / b < c / d (b, d > 0) \u306E\u3068\u304D\u3001\u958B\u533A\u9593\
    \ (a / b, c / d) \u3067\u5206\u6BCD\u304C\u6700\u5C0F\u306E\u5206\u6570 {\u5206\
    \u5B50, \u5206\u6BCD}\n// \u5206\u6BCD\u304C\u6700\u5C0F\u306E\u3082\u306E\u306F\
    \ 1 \u3064\u306B\u6C7A\u307E\u308A\u3001\u5206\u5B50\u3082\u6700\u5C0F\u306B\u306A\
    \u308B\u3002\u639B\u3051\u7B97\u3092\u3057\u306A\u3044\u306E\u3067 a, b, c, d\
    \ \u306E\u7BC4\u56F2\u3067\u3042\u3075\u308C\u306A\u3044\ntemplate <typename T>\n\
    std::pair<T, T> simplest_open(T a, T b, T c, T d) {\n    T k = a / b;\n    //\
    \ k + 1 < c / d \u306A\u3089 k + 1\n    if (k + 1 <= (c - 1) / d) return {k +\
    \ 1, 1};\n    // \u6574\u6570\u90E8\u5206 k \u3092\u5F15\u304F\u30020 <= a / b\
    \ < 1\u30010 < c / d <= 1\n    a -= k * b, c -= k * d;\n    if (a == 0) {\n  \
    \      // 0 < 1 / q < c / d \u3068\u306A\u308B\u6700\u5C0F\u306E q\n        T\
    \ q = d / c + 1;\n        return {k * q + 1, q};\n    }\n    // \u9006\u6570\u3092\
    \u3068\u308B\u3068 d / c < q / p < b / a\n    auto [u, v] = simplest_open(d, c,\
    \ b, a);\n    return {k * u + v, u};\n}\n}  // namespace internal\n\n/**\n * @brief\
    \ lo \u3068 hi \u306E\u9593\u3067\u6700\u3082\u5358\u7D14\u306A (\u5206\u6BCD\u304C\
    \u6700\u5C0F\u3067\u3001\u305D\u306E\u4E2D\u3067\u5206\u5B50\u306E\u7D76\u5BFE\
    \u5024\u304C\u6700\u5C0F\u306E) \u5206\u6570\n * \u65E2\u5B9A\u306F\u958B\u533A\
    \u9593 (lo, hi)\u3002include_lo, include_hi \u304C true \u306A\u3089\u3001\u305D\
    \u306E\u7AEF\u3082\u542B\u3081\u308B\n * \u5206\u6BCD\u304C\u6700\u5C0F\u306E\u3082\
    \u306E\u306F 1 \u3064\u306B\u6C7A\u307E\u308B\n * @pre lo < hi (\u4E21\u7AEF\u3092\
    \u542B\u3080\u306A\u3089 lo <= hi)\n */\ntemplate <typename T>\nRational<T> simplest_between(const\
    \ Rational<T>& lo, const Rational<T>& hi, bool include_lo = false, bool include_hi\
    \ = false) {\n    if (lo == hi) {\n        assert(include_lo && include_hi);\n\
    \        return lo;\n    }\n    assert(lo < hi);\n    // 0 \u3092\u542B\u3080\u306A\
    \u3089 0\n    if ((lo < 0 || (lo == 0 && include_lo)) && (0 < hi || (hi == 0 &&\
    \ include_hi))) return Rational<T>(0);\n    // \u8CA0\u306E\u533A\u9593\u306F\u7B26\
    \u53F7\u3092\u53CD\u8EE2\u3057\u3066\u6C42\u3081\u308B\n    if (hi <= 0) return\
    \ -simplest_between(-hi, -lo, include_hi, include_lo);\n    auto [p, q] = internal::simplest_open(lo.num(),\
    \ lo.den(), hi.num(), hi.den());\n    Rational<T> res(p, q);\n    // \u542B\u3081\
    \u308B\u7AEF\u306E\u65B9\u304C\u5358\u7D14\u306A\u3089\u3001\u305D\u3061\u3089\
    \u3092\u9078\u3076\n    auto simpler = [](const Rational<T>& x, const Rational<T>&\
    \ y) {\n        return x.den() != y.den() ? x.den() < y.den() : x.num() < y.num();\n\
    \    };\n    if (include_lo && simpler(lo, res)) res = lo;\n    if (include_hi\
    \ && simpler(hi, res)) res = hi;\n    return res;\n}\n\n/**\n * @brief \u5206\u6BCD\
    \u304C n \u4EE5\u4E0B\u306E\u5206\u6570\u306E\u3046\u3061\u3001x \u4EE5\u4E0B\u3067\
    \u6700\u5927\u306E\u3082\u306E\u3068 x \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u3082\
    \u306E {lower, upper}\n * x \u306E\u5206\u6BCD\u304C n \u4EE5\u4E0B\u306A\u3089\
    \ {x, x}\n * @pre n >= 1\n */\ntemplate <typename T>\nstd::pair<Rational<T>, Rational<T>>\
    \ best_approximation(const Rational<T>& x, T n) {\n    assert(n >= 1);\n    if\
    \ (x.den() <= n) return {x, x};\n    // \u6574\u6570\u90E8\u5206\u3092\u5F15\u3044\
    \u305F 0 < x - k < 1 \u3067\u6728\u3092\u305F\u3069\u308B (\u5206\u6BCD\u306F\u5909\
    \u308F\u3089\u306A\u3044)\n    T k = x.floor();\n    internal::Bounds<T> b;\n\
    \    for (auto [c, m] : encode_path(x - k)) {\n        // \u9032\u3080\u3068\u52D5\
    \u304F\u65B9\u306E\u7AEF\u306E\u5206\u6BCD\u304C n \u3092\u8D85\u3048\u306A\u3044\
    \u56DE\u6570\u3060\u3051\u9032\u3080 (\u8DB3\u3059\u65B9\u306E\u7AEF\u304C +\u221E\
    \ \u306A\u3089\u5206\u6BCD\u306F\u5909\u308F\u3089\u306A\u3044)\n        T add_den\
    \ = c == 'R' ? b.hi_den : b.lo_den, cur_den = c == 'R' ? b.lo_den : b.hi_den;\n\
    \        T step = add_den == 0 ? m : (n - cur_den) / add_den;\n        b.move(c,\
    \ std::min(m, step));\n        if (step < m) break;\n    }\n    return {Rational<T>(b.lo_num,\
    \ b.lo_den) + k, Rational<T>(b.hi_num, b.hi_den) + k};\n}\n\n/**\n * @brief \u5206\
    \u6BCD\u304C max_den \u4EE5\u4E0B (max_num \u3092\u6E21\u3059\u3068\u5206\u5B50\
    \u3082 max_num \u4EE5\u4E0B) \u306E 0 \u4EE5\u4E0A\u306E\u5206\u6570\u306E\u4E2D\
    \u3067\u3001\u5358\u8ABF\u306A pred \u306E\u5883\u76EE\u3092\u6C42\u3081\u308B\
    \n * pred(x) \u306F\u5C0F\u3055\u3044 x \u3067 true\u3001\u5927\u304D\u3044 x\
    \ \u3067 false \u3068\u306A\u308B\u5358\u8ABF\u306A\u95A2\u6570\u3067\u3001pred(0)\
    \ \u306F true \u3067\u3042\u308B\u3053\u3068\n * \u623B\u308A\u5024\u306F {{pred\
    \ \u304C true \u306E\u6700\u5927\u306E\u5206\u6570\u306E\u5206\u5B50, \u5206\u6BCD\
    }, {pred \u304C false \u306E\u6700\u5C0F\u306E\u5206\u6570\u306E\u5206\u5B50,\
    \ \u5206\u6BCD}}\u3002false \u306E\u5074\u304C\u306A\u3051\u308C\u3070 {1, 0}\
    \ (+\u221E)\n * max_num \u3092\u6E21\u3055\u306A\u3044\u306A\u3089\u3001pred \u306F\
    \u3069\u3053\u304B\u3067 false \u306B\u306A\u308B\u3053\u3068 (\u305D\u3046\u3067\
    \u306A\u3044\u3068\u7D42\u308F\u3089\u306A\u3044)\n * pred \u3092\u547C\u3076\u56DE\
    \u6570\u306F O(log max_den) \u7A0B\u5EA6 (max_num \u3092\u6E21\u3055\u306A\u3044\
    \u306A\u3089 O(log (max_den + \u5883\u76EE\u306E\u5024)))\n * @pre max_den >=\
    \ 1\n */\ntemplate <typename T, typename Pred>\nstd::pair<std::pair<T, T>, std::pair<T,\
    \ T>> binary_search(T max_den, Pred pred, std::optional<T> max_num = std::nullopt)\
    \ {\n    assert(max_den >= 1);\n    assert(!max_num || *max_num >= 0);\n    assert(pred(Rational<T>(0)));\n\
    \    internal::Bounds<T> b;\n    // \u5206\u5B50\u304C 0 \u4EE5\u4E0B\u306A\u3089\
    \ 0 \u3057\u304B\u9078\u3079\u306A\u3044 (\u4E0A\u7AEF +\u221E \u304B\u3089\u5DE6\
    \u3078\u9032\u3093\u3067\u3082\u5206\u5B50 1 \u306E\u307E\u307E\u306A\u306E\u3067\
    \u3001\u4E0A\u9650\u3092\u6E80\u305F\u305B\u306A\u3044)\n    if (max_num && *max_num\
    \ == 0) return {{0, 1}, {1, 0}};\n    // \u52D5\u304F\u65B9\u306E\u7AEF (num,\
    \ den) \u306B k \u56DE\u3082\u3046\u4E00\u65B9\u306E\u7AEF (add_num, add_den)\
    \ \u3092\u8DB3\u305B\u308B\u56DE\u6570\u306E\u4E0A\u9650 (\u306A\u3051\u308C\u3070\
    \ -1)\n    auto limit = [&](T num, T den, T add_num, T add_den) -> T {\n     \
    \   T res = -1;\n        if (add_den > 0) res = (max_den - den) / add_den;\n \
    \       if (max_num && add_num > 0) {\n            T r = (*max_num - num) / add_num;\n\
    \            res = res == -1 ? r : std::min(res, r);\n        }\n        return\
    \ res;\n    };\n    // ok(k) \u304C k = 0 \u3067 true\u3001k \u304C\u5927\u304D\
    \u3044\u3068 false \u306B\u306A\u308B\u3068\u304D\u3001ok(k) \u304C true \u306E\
    \u6700\u5927\u306E k (k <= bound\u3001bound = -1 \u306A\u3089\u4E0A\u9650\u306A\
    \u3057)\n    // \u500D\u3005\u306B\u9032\u3081\u3066\u304B\u3089\u3001\u901A\u308A\
    \u904E\u304E\u305F\u5206\u3092\u4E8C\u5206\u63A2\u7D22\u3067\u623B\u3059\u3002\
    ok \u3092\u547C\u3076\u56DE\u6570\u306F O(log k)\n    auto search = [](T bound,\
    \ auto ok) -> T {\n        T k = 0, s = 1;\n        while ((bound == -1 || s <=\
    \ bound - k) && ok(k + s)) k += s, s *= 2;\n        while (s > 1) {\n        \
    \    s /= 2;\n            if ((bound == -1 || s <= bound - k) && ok(k + s)) k\
    \ += s;\n        }\n        return k;\n    };\n    while (true) {\n        bool\
    \ moved = false;\n        // \u4E0B\u7AEF\u3092\u4E0A\u3052\u308B: \u4E0B\u7AEF\
    \ + k \u4E0A\u7AEF \u3067 pred \u304C true \u306E\u6700\u5927\u306E k\n      \
    \  T k = search(limit(b.lo_num, b.lo_den, b.hi_num, b.hi_den), [&](T k) {\n  \
    \          return pred(Rational<T>(b.lo_num + k * b.hi_num, b.lo_den + k * b.hi_den));\n\
    \        });\n        if (k > 0) b.move('R', k), moved = true;\n        // \u4E0A\
    \u7AEF\u3092\u4E0B\u3052\u308B: \u4E0A\u7AEF + k \u4E0B\u7AEF \u3067 pred \u304C\
    \ false \u306E\u6700\u5927\u306E k\n        k = search(limit(b.hi_num, b.hi_den,\
    \ b.lo_num, b.lo_den), [&](T k) {\n            return !pred(Rational<T>(b.hi_num\
    \ + k * b.lo_num, b.hi_den + k * b.lo_den));\n        });\n        if (k > 0)\
    \ b.move('L', k), moved = true;\n        if (!moved) break;\n    }\n    return\
    \ {{b.lo_num, b.lo_den}, {b.hi_num, b.hi_den}};\n}\n\n}  // namespace stern_brocot\n\
    #line 7 \"test/unittest/math/stern-brocot.test.cpp\"\n\n#include <iostream>\n\
    #line 11 \"test/unittest/math/stern-brocot.test.cpp\"\n#include <random>\n#line\
    \ 15 \"test/unittest/math/stern-brocot.test.cpp\"\n\nusing Q = Rational<long long>;\n\
    \nbool ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond &&\
    \ ok) std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok = false;\n\
    }\n\n// \u6839 1/1 \u304B\u3089 x \u307E\u3067 1 \u6B69\u305A\u3064\u305F\u3069\
    \u3063\u305F\u9053 (\"RRL\" \u306A\u3069) \u3068\u3001\u305D\u306E\u3068\u304D\
    \u306E\u5B50\u5B6B\u306E\u7BC4\u56F2\nstruct NaiveWalk {\n    std::string path;\n\
    \    long long lo_num = 0, lo_den = 1, hi_num = 1, hi_den = 0;\n};\nNaiveWalk\
    \ naive_walk(const Q& x) {\n    NaiveWalk w;\n    while (true) {\n        Q m(w.lo_num\
    \ + w.hi_num, w.lo_den + w.hi_den);\n        if (m == x) return w;\n        if\
    \ (m < x) {\n            w.path += 'R';\n            w.lo_num = m.num(), w.lo_den\
    \ = m.den();\n        } else {\n            w.path += 'L';\n            w.hi_num\
    \ = m.num(), w.hi_den = m.den();\n        }\n    }\n}\nQ naive_decode(const std::string&\
    \ path) {\n    long long a = 0, b = 1, c = 1, d = 0;\n    for (char ch : path)\
    \ {\n        if (ch == 'R') {\n            a += c, b += d;\n        } else {\n\
    \            c += a, d += b;\n        }\n    }\n    return Q(a + c, b + d);\n\
    }\nstd::string expand(const std::vector<std::pair<char, long long>>& path) {\n\
    \    std::string s;\n    for (auto [c, n] : path) s += std::string(n, c);\n  \
    \  return s;\n}\n\n// \u5206\u6BCD\u3092 1 \u304B\u3089\u9806\u306B\u8A66\u3057\
    \u3066\u3001\u533A\u9593\u306B\u5165\u308B\u5206\u6570\u306E\u3046\u3061\u6700\
    \u3082\u5358\u7D14\u306A\u3082\u306E\nQ naive_simplest(const Q& lo, const Q& hi,\
    \ bool include_lo, bool include_hi) {\n    auto in = [&](const Q& x) { return\
    \ (lo < x || (include_lo && lo == x)) && (x < hi || (include_hi && x == hi));\
    \ };\n    for (long long q = 1;; q++) {\n        // \u5206\u5B50\u306E\u7D76\u5BFE\
    \u5024\u304C\u5C0F\u3055\u3044\u9806\u306B\u8A66\u3059\n        for (long long\
    \ a = 0; a <= 100 * q; a++) {\n            for (long long p : {a, -a}) {\n   \
    \             Q x(p, q);\n                if (x.den() == q && in(x)) return x;\n\
    \            }\n        }\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    auto gen_pos = [&](long long m) { return Q(static_cast<long long>(rng() %\
    \ m) + 1, static_cast<long long>(rng() % m) + 1); };\n    auto gen = [&](long\
    \ long m) { return Q(static_cast<long long>(rng() % (2 * m + 1)) - m, static_cast<long\
    \ long>(rng() % m) + 1); };\n\n    // \u9023\u5206\u6570: \u5C55\u958B\u3057\u3066\
    \u623B\u3059\u3068\u5143\u306B\u623B\u308B\u3002\u6700\u5F8C\u306E\u9805\u306F\
    \ 2 \u4EE5\u4E0A (\u9805\u304C 1 \u3064\u306A\u3089\u4F55\u3067\u3082\u3088\u3044\
    )\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Q x = rep < 1500\
    \ ? gen(30) : gen(1000000000000000000LL);\n        auto a = stern_brocot::continued_fraction(x);\n\
    \        check(a[0] == x.floor(), \"continued_fraction a0\");\n        for (int\
    \ i = 1; i < static_cast<int>(a.size()); i++) check(a[i] >= 1, \"continued_fraction\
    \ ai >= 1\");\n        if (a.size() >= 2) check(a.back() >= 2, \"continued_fraction\
    \ an >= 2\");\n        check(stern_brocot::from_continued_fraction(a) == x, \"\
    from_continued_fraction\");\n    }\n    check((stern_brocot::continued_fraction(Q(415,\
    \ 93)) == std::vector<long long>{4, 2, 6, 7}), \"continued_fraction 415/93\");\n\
    \    check((stern_brocot::continued_fraction(Q(-7, 3)) == std::vector<long long>{-3,\
    \ 1, 2}), \"continued_fraction -7/3\");\n    // \u6700\u5F8C\u306E\u9805\u304C\
    \ 1 \u306E\u8868\u3057\u65B9 [0; 1, 1] = 1/2 \u3082\u53D7\u3051\u4ED8\u3051\u308B\
    \n    check((stern_brocot::from_continued_fraction(std::vector<long long>{0, 1,\
    \ 1}) == Q(1, 2)), \"from_continued_fraction [0; 1, 1]\");\n\n    // encode_path\
    \ / decode_path / depth / range: 1 \u6B69\u305A\u3064\u305F\u3069\u308B\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 3000 &&\
    \ ok; rep++) {\n        Q x = gen_pos(60);\n        auto path = stern_brocot::encode_path(x);\n\
    \        NaiveWalk w = naive_walk(x);\n        check(expand(path) == w.path, \"\
    encode_path\");\n        for (int i = 0; i + 1 < static_cast<int>(path.size());\
    \ i++) check(path[i].first != path[i + 1].first && path[i].second > 0, \"encode_path\
    \ \u306F\u9023\u9577\u5727\u7E2E\");\n        check(stern_brocot::decode_path(path)\
    \ == x, \"decode_path\");\n        check(stern_brocot::depth(x) == static_cast<long\
    \ long>(w.path.size()), \"depth\");\n        auto [lo, hi] = stern_brocot::range(x);\n\
    \        check(lo == std::make_pair(w.lo_num, w.lo_den) && hi == std::make_pair(w.hi_num,\
    \ w.hi_den), \"range\");\n    }\n    check(stern_brocot::encode_path(Q(1)).empty(),\
    \ \"encode_path 1/1\");\n    check((stern_brocot::range(Q(1)) == std::pair<std::pair<long\
    \ long, long long>, std::pair<long long, long long>>{{0, 1}, {1, 0}}), \"range\
    \ 1/1\");\n    // \u540C\u3058\u6587\u5B57\u304C\u7D9A\u304F\u9053\u3084\u56DE\
    \u6570 0 \u3082\u53D7\u3051\u4ED8\u3051\u308B\n    check((stern_brocot::decode_path(std::vector<std::pair<char,\
    \ long long>>{{'R', 1}, {'R', 0}, {'R', 1}, {'L', 2}}) == naive_decode(\"RRLL\"\
    )), \"decode_path \u7D9A\u304F\u6587\u5B57\");\n\n    // lca / ancestor: \u9053\
    \u306E\u6587\u5B57\u5217\u306E\u5171\u901A\u90E8\u5206\u30FB\u5148\u982D\u90E8\
    \u5206\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 3000 && ok; rep++)\
    \ {\n        Q x = gen_pos(40), y = gen_pos(40);\n        std::string px = naive_walk(x).path,\
    \ py = naive_walk(y).path;\n        size_t k = 0;\n        while (k < px.size()\
    \ && k < py.size() && px[k] == py[k]) k++;\n        check(stern_brocot::lca(x,\
    \ y) == naive_decode(px.substr(0, k)), \"lca\");\n        for (long long d = 0;\
    \ d <= static_cast<long long>(px.size()) + 2; d++) {\n            auto a = stern_brocot::ancestor(x,\
    \ d);\n            if (d <= static_cast<long long>(px.size())) {\n           \
    \     check(a && *a == naive_decode(px.substr(0, d)), \"ancestor\");\n       \
    \     } else {\n                check(!a, \"ancestor \u306A\u3057\");\n      \
    \      }\n        }\n    }\n\n    // simplest_between: \u958B\u533A\u9593\u30FB\
    \u9589\u533A\u9593\u30FB\u534A\u958B\u533A\u9593\u3001\u8CA0\u306E\u533A\u9593\
    \u3084 0 \u3092\u307E\u305F\u3050\u533A\u9593\u3067\u5168\u63A2\u7D22\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Q lo =\
    \ gen(12), hi = gen(12);\n        if (hi < lo) std::swap(lo, hi);\n        for\
    \ (int mask = 0; mask < 4; mask++) {\n            bool il = mask & 1, ih = mask\
    \ >> 1 & 1;\n            if (lo == hi && !(il && ih)) continue;\n            check(stern_brocot::simplest_between(lo,\
    \ hi, il, ih) == naive_simplest(lo, hi, il, ih), \"simplest_between\");\n    \
    \    }\n    }\n\n    // best_approximation: \u5206\u6BCD n \u4EE5\u4E0B\u306E\u5206\
    \u6570\u3092\u5168\u63A2\u7D22\u3057\u3066\u3001x \u4EE5\u4E0B\u3067\u6700\u5927\
    \u30FBx \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u3082\u306E\u3068\u6BD4\u3079\u308B\
    \n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        Q x = gen(50);\n \
    \       long long n = static_cast<long long>(rng() % 20) + 1;\n        Q lower(std::numeric_limits<long\
    \ long>::lowest() / 4), upper(std::numeric_limits<long long>::max() / 4);\n  \
    \      for (long long q = 1; q <= n; q++) {\n            // x \u3092\u631F\u3080\
    \u5206\u6BCD q \u306E\u5206\u6570\u306F floor(x q) / q \u3068 ceil(x q) / q\n\
    \            Q f((x * Q(q)).floor(), q), c((x * Q(q)).ceil(), q);\n          \
    \  if (lower < f) lower = f;\n            if (c < upper) upper = c;\n        }\n\
    \        auto [l, u] = stern_brocot::best_approximation(x, n);\n        check(l\
    \ == lower && u == upper, \"best_approximation\");\n    }\n\n    // \u5024\u304C\
    \ 10^18 \u7A0B\u5EA6\u3067\u3082\u3042\u3075\u308C\u306A\u3044 (UBSan \u3067\u78BA\
    \u304B\u3081\u308B)\n    {\n        const long long big = 1000000000000000000LL;\n\
    \        check(stern_brocot::simplest_between(Q(big - 1, big), Q(1)) == Q(big,\
    \ big + 1), \"simplest_between 10^18\");\n        check(stern_brocot::simplest_between(Q(1,\
    \ big), Q(1, big - 1)) == Q(2, 2 * big - 1), \"simplest_between 1/10^18\");\n\
    \        check(stern_brocot::simplest_between(Q(big - 1), Q(big)) == Q(2 * big\
    \ - 1, 2), \"simplest_between \u5927\u304D\u3044\u6574\u6570\");\n        for\
    \ (int rep = 0; rep < 20000 && ok; rep++) {\n            Q lo = gen_pos(big),\
    \ hi = gen_pos(big);\n            if (lo == hi) continue;\n            if (hi\
    \ < lo) std::swap(lo, hi);\n            Q s = stern_brocot::simplest_between(lo,\
    \ hi);\n            check(lo < s && s < hi, \"simplest_between \u5927\u304D\u3044\
    \u5024\u3067\u533A\u9593\u306B\u5165\u308B\");\n            // s \u3088\u308A\u5206\
    \u6BCD\u304C\u5C0F\u3055\u3044\u5206\u6570\u306F\u533A\u9593\u306B\u5165\u3089\
    \u306A\u3044: \u5206\u6BCD\u304C s.den() - 1 \u4EE5\u4E0B\u3067 lo \u306B\u6700\
    \u3082\u8FD1\u3044\u4E0A\u5074\u306E\u5206\u6570\u304C hi \u4EE5\u4E0A\n     \
    \       // (lo \u81EA\u8EAB\u306E\u5206\u6BCD\u304C s.den() - 1 \u4EE5\u4E0B\u3060\
    \u3068\u4E0A\u5074\u306E\u5206\u6570\u304C lo \u306B\u306A\u3063\u3066\u3057\u307E\
    \u3046\u306E\u3067\u3001\u305D\u306E\u3068\u304D\u306F\u78BA\u304B\u3081\u306A\
    \u3044)\n            if (s.den() >= 2 && lo.den() > s.den() - 1) {\n         \
    \       auto [l, u] = stern_brocot::best_approximation(lo, s.den() - 1);\n   \
    \             check(!(lo < u && u < hi) && !(lo < l && l < hi), \"simplest_between\
    \ \u5927\u304D\u3044\u5024\u3067\u6700\u5C0F\");\n            }\n        }\n \
    \       // \u6DF1\u3055\u304C 10^18 \u7A0B\u5EA6\u306E\u9802\u70B9\n        Q\
    \ x(big, 1);\n        check(stern_brocot::depth(x) == big - 1, \"depth 10^18\"\
    );\n        check(*stern_brocot::ancestor(x, big - 2) == Q(big - 1, 1), \"ancestor\
    \ 10^18\");\n        check(!stern_brocot::ancestor(x, big), \"ancestor 10^18 \u306A\
    \u3057\");\n        check(stern_brocot::lca(Q(big, 1), Q(big - 1, 2)) == Q(big\
    \ / 2, 1), \"lca 10^18\");\n    }\n\n    // binary_search: \u5206\u6BCD\u30FB\u5206\
    \u5B50\u306E\u4E0A\u9650\u5185\u306E\u5206\u6570\u3092\u5168\u63A2\u7D22\u3057\
    \u3066\u3001pred \u304C true \u306E\u6700\u5927\u3068 false \u306E\u6700\u5C0F\
    \u3092\u6C42\u3081\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\
    \n    {\n        using P = std::pair<long long, long long>;\n        auto naive\
    \ = [&](long long max_den, long long max_num, auto pred) {\n            Q lo(0),\
    \ hi(0);\n            bool has_hi = false;\n            for (long long q = 1;\
    \ q <= max_den; q++) {\n                for (long long p = 0; p <= max_num; p++)\
    \ {\n                    Q x(p, q);\n                    if (pred(x)) {\n    \
    \                    if (lo < x) lo = x;\n                    } else if (!has_hi\
    \ || x < hi) {\n                        hi = x, has_hi = true;\n             \
    \       }\n                }\n            }\n            return std::make_pair(P{lo.num(),\
    \ lo.den()}, has_hi ? P{hi.num(), hi.den()} : P{1, 0});\n        };\n        for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n            long long max_den = rng()\
    \ % 12 + 1, max_num = rng() % 12;\n            Q x = gen_pos(15);\n          \
    \  bool strict = rng() % 2;\n            auto pred = [&](const Q& y) { return\
    \ strict ? y < x || y == Q(0) : y <= x; };\n            auto expect = naive(max_den,\
    \ max_num, pred);\n            check(stern_brocot::binary_search(max_den, pred,\
    \ std::optional<long long>(max_num)) == expect, \"binary_search \u5206\u5B50\u306E\
    \u4E0A\u9650\u3042\u308A\");\n            // \u5206\u5B50\u306E\u4E0A\u9650\u306A\
    \u3057: \u5206\u5B50\u304C\u5341\u5206\u5927\u304D\u3044\u7BC4\u56F2\u306E\u5168\
    \u63A2\u7D22\u3068\u540C\u3058\n            check(stern_brocot::binary_search(max_den,\
    \ pred) == naive(max_den, 16 * max_den, pred), \"binary_search \u5206\u5B50\u306E\
    \u4E0A\u9650\u306A\u3057\");\n        }\n        // pred \u304C\u305A\u3063\u3068\
    \ true \u306A\u3089\u4E0A\u5074\u306F +\u221E\n        auto all = stern_brocot::binary_search(5LL,\
    \ [](const Q&) { return true; }, std::optional<long long>(7));\n        check(all.first\
    \ == P{7, 1} && all.second == P{1, 0}, \"binary_search +\u221E\");\n        //\
    \ \u221A2 \u306E\u4E21\u5074: \u5206\u6BCD 10^9 \u4EE5\u4E0B\u3067\u6700\u3082\
    \u8FD1\u3044\u5206\u6570\u3002pred \u3092\u547C\u3076\u56DE\u6570\u3082\u6570\u3048\
    \u308B\n        const long long n = 1000000000;\n        int calls = 0;\n    \
    \    auto [lo, hi] = stern_brocot::binary_search(n, [&](const Q& y) {\n      \
    \      calls++;\n            return y.num() * y.num() <= 2 * y.den() * y.den();\n\
    \        });\n        Q l(lo.first, lo.second), h(hi.first, hi.second);\n    \
    \    // \u96A3\u308A\u5408\u3046\u5206\u6570 (\u9593\u306B\u5206\u6BCD n \u4EE5\
    \u4E0B\u306E\u5206\u6570\u304C\u306A\u3044) \u3067\u3001\u221A2 \u3092\u631F\u3080\
    \n        check(lo.second <= n && hi.second <= n && lo.second + hi.second > n,\
    \ \"binary_search \u221A2 \u5206\u6BCD\");\n        check(hi.first * lo.second\
    \ - lo.first * hi.second == 1, \"binary_search \u221A2 \u96A3\u308A\u5408\u3046\
    \");\n        check(l * l < Q(2) && Q(2) < h * h, \"binary_search \u221A2 \u631F\
    \u3080\");\n        check(calls <= 200, \"binary_search \u221A2 \u547C\u3076\u56DE\
    \u6570\");\n        // best_approximation \u3068\u4E00\u81F4\u3059\u308B\n   \
    \     for (int rep = 0; rep < 1000 && ok; rep++) {\n            Q x = gen_pos(1000000);\n\
    \            long long m = rng() % 1000 + 1;\n            auto [bl, bu] = stern_brocot::best_approximation(x,\
    \ m);\n            auto [sl, su] = stern_brocot::binary_search(m, [&](const Q&\
    \ y) { return y <= x; });\n            // x \u81EA\u8EAB\u306E\u5206\u6BCD\u304C\
    \ m \u4EE5\u4E0B\u306A\u3089\u3001\u4E0B\u5074\u306F x\u3001\u4E0A\u5074\u306F\
    \ x \u306E\u6B21\u306E\u5206\u6570\u306B\u306A\u308B\n            check(Q(sl.first,\
    \ sl.second) == bl && (bl == bu || Q(su.first, su.second) == bu), \"binary_search\
    \ \u3068 best_approximation\");\n        }\n    }\n\n    // ABC408 G \u306E\u5165\
    \u51FA\u529B\u4F8B: A/B < p/q < C/D \u3068\u306A\u308B\u6700\u5C0F\u306E q\n \
    \   {\n        long long in[5][4] = {{3, 2, 2, 1}, {5, 2, 8, 3}, {1, 2, 2, 1},\
    \ {60, 191, 11, 35}, {40, 191, 71, 226}};\n        long long out[5] = {3, 5, 1,\
    \ 226, 4};\n        for (int i = 0; i < 5; i++) check(stern_brocot::simplest_between(Q(in[i][0],\
    \ in[i][1]), Q(in[i][2], in[i][3])).den() == out[i], \"ABC408 G\");\n    }\n\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// stern-brocot.hpp \u306E\u95A2\u6570\u3092\u3001\u6728\u3092 1 \u6B69\u305A\
    \u3064\u305F\u3069\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3084\u5168\u63A2\u7D22\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/math/stern-brocot.hpp\"\
    \n\n#include <iostream>\n#include <limits>\n#include <optional>\n#include <random>\n\
    #include <string>\n#include <utility>\n#include <vector>\n\nusing Q = Rational<long\
    \ long>;\n\nbool ok = true;\nvoid check(bool cond, const char* what) {\n    if\
    \ (!cond && ok) std::cerr << \"failed: \" << what << std::endl;\n    if (!cond)\
    \ ok = false;\n}\n\n// \u6839 1/1 \u304B\u3089 x \u307E\u3067 1 \u6B69\u305A\u3064\
    \u305F\u3069\u3063\u305F\u9053 (\"RRL\" \u306A\u3069) \u3068\u3001\u305D\u306E\
    \u3068\u304D\u306E\u5B50\u5B6B\u306E\u7BC4\u56F2\nstruct NaiveWalk {\n    std::string\
    \ path;\n    long long lo_num = 0, lo_den = 1, hi_num = 1, hi_den = 0;\n};\nNaiveWalk\
    \ naive_walk(const Q& x) {\n    NaiveWalk w;\n    while (true) {\n        Q m(w.lo_num\
    \ + w.hi_num, w.lo_den + w.hi_den);\n        if (m == x) return w;\n        if\
    \ (m < x) {\n            w.path += 'R';\n            w.lo_num = m.num(), w.lo_den\
    \ = m.den();\n        } else {\n            w.path += 'L';\n            w.hi_num\
    \ = m.num(), w.hi_den = m.den();\n        }\n    }\n}\nQ naive_decode(const std::string&\
    \ path) {\n    long long a = 0, b = 1, c = 1, d = 0;\n    for (char ch : path)\
    \ {\n        if (ch == 'R') {\n            a += c, b += d;\n        } else {\n\
    \            c += a, d += b;\n        }\n    }\n    return Q(a + c, b + d);\n\
    }\nstd::string expand(const std::vector<std::pair<char, long long>>& path) {\n\
    \    std::string s;\n    for (auto [c, n] : path) s += std::string(n, c);\n  \
    \  return s;\n}\n\n// \u5206\u6BCD\u3092 1 \u304B\u3089\u9806\u306B\u8A66\u3057\
    \u3066\u3001\u533A\u9593\u306B\u5165\u308B\u5206\u6570\u306E\u3046\u3061\u6700\
    \u3082\u5358\u7D14\u306A\u3082\u306E\nQ naive_simplest(const Q& lo, const Q& hi,\
    \ bool include_lo, bool include_hi) {\n    auto in = [&](const Q& x) { return\
    \ (lo < x || (include_lo && lo == x)) && (x < hi || (include_hi && x == hi));\
    \ };\n    for (long long q = 1;; q++) {\n        // \u5206\u5B50\u306E\u7D76\u5BFE\
    \u5024\u304C\u5C0F\u3055\u3044\u9806\u306B\u8A66\u3059\n        for (long long\
    \ a = 0; a <= 100 * q; a++) {\n            for (long long p : {a, -a}) {\n   \
    \             Q x(p, q);\n                if (x.den() == q && in(x)) return x;\n\
    \            }\n        }\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    auto gen_pos = [&](long long m) { return Q(static_cast<long long>(rng() %\
    \ m) + 1, static_cast<long long>(rng() % m) + 1); };\n    auto gen = [&](long\
    \ long m) { return Q(static_cast<long long>(rng() % (2 * m + 1)) - m, static_cast<long\
    \ long>(rng() % m) + 1); };\n\n    // \u9023\u5206\u6570: \u5C55\u958B\u3057\u3066\
    \u623B\u3059\u3068\u5143\u306B\u623B\u308B\u3002\u6700\u5F8C\u306E\u9805\u306F\
    \ 2 \u4EE5\u4E0A (\u9805\u304C 1 \u3064\u306A\u3089\u4F55\u3067\u3082\u3088\u3044\
    )\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Q x = rep < 1500\
    \ ? gen(30) : gen(1000000000000000000LL);\n        auto a = stern_brocot::continued_fraction(x);\n\
    \        check(a[0] == x.floor(), \"continued_fraction a0\");\n        for (int\
    \ i = 1; i < static_cast<int>(a.size()); i++) check(a[i] >= 1, \"continued_fraction\
    \ ai >= 1\");\n        if (a.size() >= 2) check(a.back() >= 2, \"continued_fraction\
    \ an >= 2\");\n        check(stern_brocot::from_continued_fraction(a) == x, \"\
    from_continued_fraction\");\n    }\n    check((stern_brocot::continued_fraction(Q(415,\
    \ 93)) == std::vector<long long>{4, 2, 6, 7}), \"continued_fraction 415/93\");\n\
    \    check((stern_brocot::continued_fraction(Q(-7, 3)) == std::vector<long long>{-3,\
    \ 1, 2}), \"continued_fraction -7/3\");\n    // \u6700\u5F8C\u306E\u9805\u304C\
    \ 1 \u306E\u8868\u3057\u65B9 [0; 1, 1] = 1/2 \u3082\u53D7\u3051\u4ED8\u3051\u308B\
    \n    check((stern_brocot::from_continued_fraction(std::vector<long long>{0, 1,\
    \ 1}) == Q(1, 2)), \"from_continued_fraction [0; 1, 1]\");\n\n    // encode_path\
    \ / decode_path / depth / range: 1 \u6B69\u305A\u3064\u305F\u3069\u308B\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 3000 &&\
    \ ok; rep++) {\n        Q x = gen_pos(60);\n        auto path = stern_brocot::encode_path(x);\n\
    \        NaiveWalk w = naive_walk(x);\n        check(expand(path) == w.path, \"\
    encode_path\");\n        for (int i = 0; i + 1 < static_cast<int>(path.size());\
    \ i++) check(path[i].first != path[i + 1].first && path[i].second > 0, \"encode_path\
    \ \u306F\u9023\u9577\u5727\u7E2E\");\n        check(stern_brocot::decode_path(path)\
    \ == x, \"decode_path\");\n        check(stern_brocot::depth(x) == static_cast<long\
    \ long>(w.path.size()), \"depth\");\n        auto [lo, hi] = stern_brocot::range(x);\n\
    \        check(lo == std::make_pair(w.lo_num, w.lo_den) && hi == std::make_pair(w.hi_num,\
    \ w.hi_den), \"range\");\n    }\n    check(stern_brocot::encode_path(Q(1)).empty(),\
    \ \"encode_path 1/1\");\n    check((stern_brocot::range(Q(1)) == std::pair<std::pair<long\
    \ long, long long>, std::pair<long long, long long>>{{0, 1}, {1, 0}}), \"range\
    \ 1/1\");\n    // \u540C\u3058\u6587\u5B57\u304C\u7D9A\u304F\u9053\u3084\u56DE\
    \u6570 0 \u3082\u53D7\u3051\u4ED8\u3051\u308B\n    check((stern_brocot::decode_path(std::vector<std::pair<char,\
    \ long long>>{{'R', 1}, {'R', 0}, {'R', 1}, {'L', 2}}) == naive_decode(\"RRLL\"\
    )), \"decode_path \u7D9A\u304F\u6587\u5B57\");\n\n    // lca / ancestor: \u9053\
    \u306E\u6587\u5B57\u5217\u306E\u5171\u901A\u90E8\u5206\u30FB\u5148\u982D\u90E8\
    \u5206\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 3000 && ok; rep++)\
    \ {\n        Q x = gen_pos(40), y = gen_pos(40);\n        std::string px = naive_walk(x).path,\
    \ py = naive_walk(y).path;\n        size_t k = 0;\n        while (k < px.size()\
    \ && k < py.size() && px[k] == py[k]) k++;\n        check(stern_brocot::lca(x,\
    \ y) == naive_decode(px.substr(0, k)), \"lca\");\n        for (long long d = 0;\
    \ d <= static_cast<long long>(px.size()) + 2; d++) {\n            auto a = stern_brocot::ancestor(x,\
    \ d);\n            if (d <= static_cast<long long>(px.size())) {\n           \
    \     check(a && *a == naive_decode(px.substr(0, d)), \"ancestor\");\n       \
    \     } else {\n                check(!a, \"ancestor \u306A\u3057\");\n      \
    \      }\n        }\n    }\n\n    // simplest_between: \u958B\u533A\u9593\u30FB\
    \u9589\u533A\u9593\u30FB\u534A\u958B\u533A\u9593\u3001\u8CA0\u306E\u533A\u9593\
    \u3084 0 \u3092\u307E\u305F\u3050\u533A\u9593\u3067\u5168\u63A2\u7D22\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Q lo =\
    \ gen(12), hi = gen(12);\n        if (hi < lo) std::swap(lo, hi);\n        for\
    \ (int mask = 0; mask < 4; mask++) {\n            bool il = mask & 1, ih = mask\
    \ >> 1 & 1;\n            if (lo == hi && !(il && ih)) continue;\n            check(stern_brocot::simplest_between(lo,\
    \ hi, il, ih) == naive_simplest(lo, hi, il, ih), \"simplest_between\");\n    \
    \    }\n    }\n\n    // best_approximation: \u5206\u6BCD n \u4EE5\u4E0B\u306E\u5206\
    \u6570\u3092\u5168\u63A2\u7D22\u3057\u3066\u3001x \u4EE5\u4E0B\u3067\u6700\u5927\
    \u30FBx \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u3082\u306E\u3068\u6BD4\u3079\u308B\
    \n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        Q x = gen(50);\n \
    \       long long n = static_cast<long long>(rng() % 20) + 1;\n        Q lower(std::numeric_limits<long\
    \ long>::lowest() / 4), upper(std::numeric_limits<long long>::max() / 4);\n  \
    \      for (long long q = 1; q <= n; q++) {\n            // x \u3092\u631F\u3080\
    \u5206\u6BCD q \u306E\u5206\u6570\u306F floor(x q) / q \u3068 ceil(x q) / q\n\
    \            Q f((x * Q(q)).floor(), q), c((x * Q(q)).ceil(), q);\n          \
    \  if (lower < f) lower = f;\n            if (c < upper) upper = c;\n        }\n\
    \        auto [l, u] = stern_brocot::best_approximation(x, n);\n        check(l\
    \ == lower && u == upper, \"best_approximation\");\n    }\n\n    // \u5024\u304C\
    \ 10^18 \u7A0B\u5EA6\u3067\u3082\u3042\u3075\u308C\u306A\u3044 (UBSan \u3067\u78BA\
    \u304B\u3081\u308B)\n    {\n        const long long big = 1000000000000000000LL;\n\
    \        check(stern_brocot::simplest_between(Q(big - 1, big), Q(1)) == Q(big,\
    \ big + 1), \"simplest_between 10^18\");\n        check(stern_brocot::simplest_between(Q(1,\
    \ big), Q(1, big - 1)) == Q(2, 2 * big - 1), \"simplest_between 1/10^18\");\n\
    \        check(stern_brocot::simplest_between(Q(big - 1), Q(big)) == Q(2 * big\
    \ - 1, 2), \"simplest_between \u5927\u304D\u3044\u6574\u6570\");\n        for\
    \ (int rep = 0; rep < 20000 && ok; rep++) {\n            Q lo = gen_pos(big),\
    \ hi = gen_pos(big);\n            if (lo == hi) continue;\n            if (hi\
    \ < lo) std::swap(lo, hi);\n            Q s = stern_brocot::simplest_between(lo,\
    \ hi);\n            check(lo < s && s < hi, \"simplest_between \u5927\u304D\u3044\
    \u5024\u3067\u533A\u9593\u306B\u5165\u308B\");\n            // s \u3088\u308A\u5206\
    \u6BCD\u304C\u5C0F\u3055\u3044\u5206\u6570\u306F\u533A\u9593\u306B\u5165\u3089\
    \u306A\u3044: \u5206\u6BCD\u304C s.den() - 1 \u4EE5\u4E0B\u3067 lo \u306B\u6700\
    \u3082\u8FD1\u3044\u4E0A\u5074\u306E\u5206\u6570\u304C hi \u4EE5\u4E0A\n     \
    \       // (lo \u81EA\u8EAB\u306E\u5206\u6BCD\u304C s.den() - 1 \u4EE5\u4E0B\u3060\
    \u3068\u4E0A\u5074\u306E\u5206\u6570\u304C lo \u306B\u306A\u3063\u3066\u3057\u307E\
    \u3046\u306E\u3067\u3001\u305D\u306E\u3068\u304D\u306F\u78BA\u304B\u3081\u306A\
    \u3044)\n            if (s.den() >= 2 && lo.den() > s.den() - 1) {\n         \
    \       auto [l, u] = stern_brocot::best_approximation(lo, s.den() - 1);\n   \
    \             check(!(lo < u && u < hi) && !(lo < l && l < hi), \"simplest_between\
    \ \u5927\u304D\u3044\u5024\u3067\u6700\u5C0F\");\n            }\n        }\n \
    \       // \u6DF1\u3055\u304C 10^18 \u7A0B\u5EA6\u306E\u9802\u70B9\n        Q\
    \ x(big, 1);\n        check(stern_brocot::depth(x) == big - 1, \"depth 10^18\"\
    );\n        check(*stern_brocot::ancestor(x, big - 2) == Q(big - 1, 1), \"ancestor\
    \ 10^18\");\n        check(!stern_brocot::ancestor(x, big), \"ancestor 10^18 \u306A\
    \u3057\");\n        check(stern_brocot::lca(Q(big, 1), Q(big - 1, 2)) == Q(big\
    \ / 2, 1), \"lca 10^18\");\n    }\n\n    // binary_search: \u5206\u6BCD\u30FB\u5206\
    \u5B50\u306E\u4E0A\u9650\u5185\u306E\u5206\u6570\u3092\u5168\u63A2\u7D22\u3057\
    \u3066\u3001pred \u304C true \u306E\u6700\u5927\u3068 false \u306E\u6700\u5C0F\
    \u3092\u6C42\u3081\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\
    \n    {\n        using P = std::pair<long long, long long>;\n        auto naive\
    \ = [&](long long max_den, long long max_num, auto pred) {\n            Q lo(0),\
    \ hi(0);\n            bool has_hi = false;\n            for (long long q = 1;\
    \ q <= max_den; q++) {\n                for (long long p = 0; p <= max_num; p++)\
    \ {\n                    Q x(p, q);\n                    if (pred(x)) {\n    \
    \                    if (lo < x) lo = x;\n                    } else if (!has_hi\
    \ || x < hi) {\n                        hi = x, has_hi = true;\n             \
    \       }\n                }\n            }\n            return std::make_pair(P{lo.num(),\
    \ lo.den()}, has_hi ? P{hi.num(), hi.den()} : P{1, 0});\n        };\n        for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n            long long max_den = rng()\
    \ % 12 + 1, max_num = rng() % 12;\n            Q x = gen_pos(15);\n          \
    \  bool strict = rng() % 2;\n            auto pred = [&](const Q& y) { return\
    \ strict ? y < x || y == Q(0) : y <= x; };\n            auto expect = naive(max_den,\
    \ max_num, pred);\n            check(stern_brocot::binary_search(max_den, pred,\
    \ std::optional<long long>(max_num)) == expect, \"binary_search \u5206\u5B50\u306E\
    \u4E0A\u9650\u3042\u308A\");\n            // \u5206\u5B50\u306E\u4E0A\u9650\u306A\
    \u3057: \u5206\u5B50\u304C\u5341\u5206\u5927\u304D\u3044\u7BC4\u56F2\u306E\u5168\
    \u63A2\u7D22\u3068\u540C\u3058\n            check(stern_brocot::binary_search(max_den,\
    \ pred) == naive(max_den, 16 * max_den, pred), \"binary_search \u5206\u5B50\u306E\
    \u4E0A\u9650\u306A\u3057\");\n        }\n        // pred \u304C\u305A\u3063\u3068\
    \ true \u306A\u3089\u4E0A\u5074\u306F +\u221E\n        auto all = stern_brocot::binary_search(5LL,\
    \ [](const Q&) { return true; }, std::optional<long long>(7));\n        check(all.first\
    \ == P{7, 1} && all.second == P{1, 0}, \"binary_search +\u221E\");\n        //\
    \ \u221A2 \u306E\u4E21\u5074: \u5206\u6BCD 10^9 \u4EE5\u4E0B\u3067\u6700\u3082\
    \u8FD1\u3044\u5206\u6570\u3002pred \u3092\u547C\u3076\u56DE\u6570\u3082\u6570\u3048\
    \u308B\n        const long long n = 1000000000;\n        int calls = 0;\n    \
    \    auto [lo, hi] = stern_brocot::binary_search(n, [&](const Q& y) {\n      \
    \      calls++;\n            return y.num() * y.num() <= 2 * y.den() * y.den();\n\
    \        });\n        Q l(lo.first, lo.second), h(hi.first, hi.second);\n    \
    \    // \u96A3\u308A\u5408\u3046\u5206\u6570 (\u9593\u306B\u5206\u6BCD n \u4EE5\
    \u4E0B\u306E\u5206\u6570\u304C\u306A\u3044) \u3067\u3001\u221A2 \u3092\u631F\u3080\
    \n        check(lo.second <= n && hi.second <= n && lo.second + hi.second > n,\
    \ \"binary_search \u221A2 \u5206\u6BCD\");\n        check(hi.first * lo.second\
    \ - lo.first * hi.second == 1, \"binary_search \u221A2 \u96A3\u308A\u5408\u3046\
    \");\n        check(l * l < Q(2) && Q(2) < h * h, \"binary_search \u221A2 \u631F\
    \u3080\");\n        check(calls <= 200, \"binary_search \u221A2 \u547C\u3076\u56DE\
    \u6570\");\n        // best_approximation \u3068\u4E00\u81F4\u3059\u308B\n   \
    \     for (int rep = 0; rep < 1000 && ok; rep++) {\n            Q x = gen_pos(1000000);\n\
    \            long long m = rng() % 1000 + 1;\n            auto [bl, bu] = stern_brocot::best_approximation(x,\
    \ m);\n            auto [sl, su] = stern_brocot::binary_search(m, [&](const Q&\
    \ y) { return y <= x; });\n            // x \u81EA\u8EAB\u306E\u5206\u6BCD\u304C\
    \ m \u4EE5\u4E0B\u306A\u3089\u3001\u4E0B\u5074\u306F x\u3001\u4E0A\u5074\u306F\
    \ x \u306E\u6B21\u306E\u5206\u6570\u306B\u306A\u308B\n            check(Q(sl.first,\
    \ sl.second) == bl && (bl == bu || Q(su.first, su.second) == bu), \"binary_search\
    \ \u3068 best_approximation\");\n        }\n    }\n\n    // ABC408 G \u306E\u5165\
    \u51FA\u529B\u4F8B: A/B < p/q < C/D \u3068\u306A\u308B\u6700\u5C0F\u306E q\n \
    \   {\n        long long in[5][4] = {{3, 2, 2, 1}, {5, 2, 8, 3}, {1, 2, 2, 1},\
    \ {60, 191, 11, 35}, {40, 191, 71, 226}};\n        long long out[5] = {3, 5, 1,\
    \ 226, 4};\n        for (int i = 0; i < 5; i++) check(stern_brocot::simplest_between(Q(in[i][0],\
    \ in[i][1]), Q(in[i][2], in[i][3])).den() == out[i], \"ABC408 G\");\n    }\n\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/stern-brocot.hpp
  - src/math/rational.hpp
  - src/base/functions.hpp
  isVerificationFile: true
  path: test/unittest/math/stern-brocot.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/stern-brocot.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/stern-brocot.test.cpp
- /verify/test/unittest/math/stern-brocot.test.cpp.html
title: test/unittest/math/stern-brocot.test.cpp
---
