---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/math/rational.hpp
    title: "\u6709\u7406\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/stern-brocot.test.cpp
    title: test/unittest/math/stern-brocot.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/rational-approximation.test.cpp
    title: test/yosupo/number_theory/rational-approximation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/stern-brocot-tree.test.cpp
    title: test/yosupo/number_theory/stern-brocot-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570"
    links: []
  bundledCode: "#line 2 \"src/math/stern-brocot.hpp\"\n\n/**\n * @file stern-brocot.hpp\n\
    \ * @brief Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/math/rational.hpp\"\n\n/**\n * @file rational.hpp\n\
    \ * @brief \u6709\u7406\u6570\n */\n\n#line 9 \"src/math/rational.hpp\"\n#include\
    \ <cstddef>\n#include <istream>\n#include <ostream>\n#include <string>\n#line\
    \ 14 \"src/math/rational.hpp\"\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n\
    \ * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\
    \u3069)\n */\n\n#line 9 \"src/base/functions.hpp\"\n#include <cmath>\n#include\
    \ <iterator>\n#include <limits>\n#include <numeric>\n#if __cplusplus >= 202002L\n\
    #include <ranges>\n#endif\n#line 18 \"src/base/functions.hpp\"\n\ntemplate <typename\
    \ T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate\
    \ <typename T1, typename T2>\ninline constexpr bool chmax(T1& a, T2 b) {\n   \
    \ if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ninline constexpr long long max(const long long& t1, const long long& t2)\
    \ {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr long long\
    \ min(const long long& t1, const long long& t2) {\n    return std::min<long long>(t1,\
    \ t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing std::size;\n\
    \n#if __cplusplus >= 202002L\nusing std::midpoint;\n#else\n// C++20 \u306E std::midpoint\
    \ \u3068\u540C\u3058 (\u6574\u6570\u306F a \u306E\u5074\u306B\u4E38\u3081\u3001\
    \u3042\u3075\u308C\u306A\u3044)\ntemplate <typename T>\ninline constexpr std::enable_if_t<std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>, T> midpoint(T a, T b) noexcept {\n    using U =\
    \ std::make_unsigned_t<T>;\n    if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
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
    \ + 1)));\n        return is;\n    }\n};\n#line 16 \"src/math/stern-brocot.hpp\"\
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
    \ b, a);\n    return {k * u + v, u};\n}\n\n// \u5F15\u6570\u306E\u578B\u306E\u63A8\
    \u8AD6\u306B\u4F7F\u308F\u305B\u306A\u3044 (binary_search \u306E max_num \u306B\
    \ T \u306E\u5024\u3092\u305D\u306E\u307E\u307E\u6E21\u305B\u308B\u3088\u3046\u306B\
    \u3059\u308B)\n#if __cplusplus >= 202002L\ntemplate <typename T>\nusing non_deduced_t\
    \ = std::type_identity_t<T>;\n#else\ntemplate <typename T>\nstruct type_identity\
    \ {\n    using type = T;\n};\ntemplate <typename T>\nusing non_deduced_t = typename\
    \ type_identity<T>::type;\n#endif\n}  // namespace internal\n\n/**\n * @brief\
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
    \ T>> binary_search(T max_den, Pred pred, std::optional<internal::non_deduced_t<T>>\
    \ max_num = std::nullopt) {\n    assert(max_den >= 1);\n    assert(!max_num ||\
    \ *max_num >= 0);\n    assert(pred(Rational<T>(0)));\n    internal::Bounds<T>\
    \ b;\n    // \u5206\u5B50\u304C 0 \u4EE5\u4E0B\u306A\u3089 0 \u3057\u304B\u9078\
    \u3079\u306A\u3044 (\u4E0A\u7AEF +\u221E \u304B\u3089\u5DE6\u3078\u9032\u3093\u3067\
    \u3082\u5206\u5B50 1 \u306E\u307E\u307E\u306A\u306E\u3067\u3001\u4E0A\u9650\u3092\
    \u6E80\u305F\u305B\u306A\u3044)\n    if (max_num && *max_num == 0) return {{0,\
    \ 1}, {1, 0}};\n    // \u52D5\u304F\u65B9\u306E\u7AEF (num, den) \u306B k \u56DE\
    \u3082\u3046\u4E00\u65B9\u306E\u7AEF (add_num, add_den) \u3092\u8DB3\u305B\u308B\
    \u56DE\u6570\u306E\u4E0A\u9650 (\u306A\u3051\u308C\u3070 -1)\n    auto limit =\
    \ [&](T num, T den, T add_num, T add_den) -> T {\n        T res = -1;\n      \
    \  if (add_den > 0) res = (max_den - den) / add_den;\n        if (max_num && add_num\
    \ > 0) {\n            T r = (*max_num - num) / add_num;\n            res = res\
    \ == -1 ? r : std::min(res, r);\n        }\n        return res;\n    };\n    //\
    \ ok(k) \u304C k = 0 \u3067 true\u3001k \u304C\u5927\u304D\u3044\u3068 false \u306B\
    \u306A\u308B\u3068\u304D\u3001ok(k) \u304C true \u306E\u6700\u5927\u306E k (k\
    \ <= bound\u3001bound = -1 \u306A\u3089\u4E0A\u9650\u306A\u3057)\n    // \u500D\
    \u3005\u306B\u9032\u3081\u3066\u304B\u3089\u3001\u901A\u308A\u904E\u304E\u305F\
    \u5206\u3092\u4E8C\u5206\u63A2\u7D22\u3067\u623B\u3059\u3002ok \u3092\u547C\u3076\
    \u56DE\u6570\u306F O(log k)\n    auto search = [](T bound, auto ok) -> T {\n \
    \       T k = 0, s = 1;\n        while ((bound == -1 || s <= bound - k) && ok(k\
    \ + s)) k += s, s *= 2;\n        while (s > 1) {\n            s /= 2;\n      \
    \      if ((bound == -1 || s <= bound - k) && ok(k + s)) k += s;\n        }\n\
    \        return k;\n    };\n    while (true) {\n        bool moved = false;\n\
    \        // \u4E0B\u7AEF\u3092\u4E0A\u3052\u308B: \u4E0B\u7AEF + k \u4E0A\u7AEF\
    \ \u3067 pred \u304C true \u306E\u6700\u5927\u306E k\n        T k = search(limit(b.lo_num,\
    \ b.lo_den, b.hi_num, b.hi_den), [&](T k) {\n            return pred(Rational<T>(b.lo_num\
    \ + k * b.hi_num, b.lo_den + k * b.hi_den));\n        });\n        if (k > 0)\
    \ b.move('R', k), moved = true;\n        // \u4E0A\u7AEF\u3092\u4E0B\u3052\u308B\
    : \u4E0A\u7AEF + k \u4E0B\u7AEF \u3067 pred \u304C false \u306E\u6700\u5927\u306E\
    \ k\n        k = search(limit(b.hi_num, b.hi_den, b.lo_num, b.lo_den), [&](T k)\
    \ {\n            return !pred(Rational<T>(b.hi_num + k * b.lo_num, b.hi_den +\
    \ k * b.lo_den));\n        });\n        if (k > 0) b.move('L', k), moved = true;\n\
    \        if (!moved) break;\n    }\n    return {{b.lo_num, b.lo_den}, {b.hi_num,\
    \ b.hi_den}};\n}\n\n}  // namespace stern_brocot\n"
  code: "#pragma once\n\n/**\n * @file stern-brocot.hpp\n * @brief Stern\u2013Brocot\
    \ \u6728\u3068\u9023\u5206\u6570\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#include \"rational.hpp\"\n\n/**\n * @brief Stern\u2013Brocot \u6728\u3068\u9023\
    \u5206\u6570\n *\n * \u6B63\u306E\u6709\u7406\u6570\u3092 Stern\u2013Brocot \u6728\
    \ (\u6839\u306F 1/1) \u306E\u9802\u70B9\u3068\u540C\u4E00\u8996\u3059\u308B\n\
    \ * \u6839\u304B\u3089\u9802\u70B9\u3078\u306E\u9053\u306F\u3001\u5DE6\u306E\u5B50\
    \u3078\u9032\u3080 'L' \u3068\u53F3\u306E\u5B50\u3078\u9032\u3080 'R' \u3092\u9023\
    \u9577\u5727\u7E2E\u3057\u305F {\u6587\u5B57, \u56DE\u6570} \u306E\u5217\u3067\
    \u8868\u3059\n * \u4F8B:\n * stern_brocot::encode_path(Rational<>(3, 2));    \
    \                 // {{'R', 1}, {'L', 1}}\n * stern_brocot::simplest_between(Rational<>(1,\
    \ 3), Rational<>(1, 2));  // 2/5\n */\nnamespace stern_brocot {\n\n/**\n * @brief\
    \ \u9023\u5206\u6570\u5C55\u958B x = a0 + 1 / (a1 + 1 / (... + 1 / an))\n * a0\
    \ = floor(x)\u3001i >= 1 \u3067\u306F ai >= 1\u3002n >= 1 \u306A\u3089 an >= 2\
    \ (\u8868\u3057\u65B9\u304C 1 \u901A\u308A\u306B\u6C7A\u307E\u308B)\n */\ntemplate\
    \ <typename T>\nstd::vector<T> continued_fraction(const Rational<T>& x) {\n  \
    \  std::vector<T> res;\n    T p = x.num(), q = x.den();\n    T a = x.floor();\n\
    \    res.push_back(a);\n    p -= a * q;\n    while (p != 0) {\n        // \u5C0F\
    \u6570\u90E8\u5206 p / q \u306E\u9006\u6570 q / p \u306E\u6574\u6570\u90E8\u5206\
    \n        T t = q / p, r = q - t * p;\n        res.push_back(t);\n        q =\
    \ p, p = r;\n    }\n    return res;\n}\n\n/**\n * @brief \u9023\u5206\u6570 [a0;\
    \ a1, ..., an] \u304C\u8868\u3059\u6709\u7406\u6570\n * @pre a \u306F\u7A7A\u3067\
    \u306A\u304F\u3001i >= 1 \u3067\u306F ai >= 1\n */\ntemplate <typename T>\nRational<T>\
    \ from_continued_fraction(const std::vector<T>& a) {\n    assert(!a.empty());\n\
    \    // \u5F8C\u308D\u304B\u3089 p / q = ai + 1 / (p / q) \u3092\u305F\u3069\u308B\
    \n    T p = a.back(), q = 1;\n    for (int i = static_cast<int>(a.size()) - 2;\
    \ i >= 0; i--) {\n        assert(a[i + 1] >= 1);\n        T np = a[i] * p + q;\n\
    \        q = p, p = np;\n    }\n    return Rational<T>(p, q);\n}\n\n/**\n * @brief\
    \ \u6839 1/1 \u304B\u3089 x \u3078\u306E\u9053\n * @pre x > 0\n */\ntemplate <typename\
    \ T>\nstd::vector<std::pair<char, T>> encode_path(const Rational<T>& x) {\n  \
    \  assert(x > 0);\n    std::vector<T> a = continued_fraction(x);\n    // x = [a0;\
    \ a1, ..., an] \u3078\u306E\u9053\u306F R^a0 L^a1 R^a2 ... \u3067\u3001\u6700\u5F8C\
    \u306E\u9805\u3060\u3051 1 \u5C11\u306A\u3044\n    a.back() -= 1;\n    std::vector<std::pair<char,\
    \ T>> res;\n    for (int i = 0; i < static_cast<int>(a.size()); i++) {\n     \
    \   if (a[i] > 0) res.emplace_back(i % 2 == 0 ? 'R' : 'L', a[i]);\n    }\n   \
    \ return res;\n}\n\nnamespace internal {\n// \u9053\u3092\u305F\u3069\u3063\u305F\
    \u3042\u3068\u306E\u9802\u70B9\u306E\u3001\u5B50\u5B6B\u306E\u7BC4\u56F2\u306E\
    \u4E21\u7AEF (\u4E0B\u7AEF lo\u3001\u4E0A\u7AEF hi)\u3002\u5206\u6BCD\u304C 0\
    \ \u306A\u3089 +\u221E\ntemplate <typename T>\nstruct Bounds {\n    T lo_num =\
    \ 0, lo_den = 1, hi_num = 1, hi_den = 0;\n    // 'R' \u3078 n \u56DE: \u4E0B\u7AEF\
    \u304C\u4ECA\u306E\u9802\u70B9 (lo + hi) \u306B n \u56DE\u7F6E\u304D\u63DB\u308F\
    \u308B\n    void move(char c, T n) {\n        assert(c == 'L' || c == 'R');\n\
    \        if (c == 'R') {\n            lo_num += n * hi_num, lo_den += n * hi_den;\n\
    \        } else {\n            hi_num += n * lo_num, hi_den += n * lo_den;\n \
    \       }\n    }\n    Rational<T> node() const { return Rational<T>(lo_num + hi_num,\
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
    \ b, a);\n    return {k * u + v, u};\n}\n\n// \u5F15\u6570\u306E\u578B\u306E\u63A8\
    \u8AD6\u306B\u4F7F\u308F\u305B\u306A\u3044 (binary_search \u306E max_num \u306B\
    \ T \u306E\u5024\u3092\u305D\u306E\u307E\u307E\u6E21\u305B\u308B\u3088\u3046\u306B\
    \u3059\u308B)\n#if __cplusplus >= 202002L\ntemplate <typename T>\nusing non_deduced_t\
    \ = std::type_identity_t<T>;\n#else\ntemplate <typename T>\nstruct type_identity\
    \ {\n    using type = T;\n};\ntemplate <typename T>\nusing non_deduced_t = typename\
    \ type_identity<T>::type;\n#endif\n}  // namespace internal\n\n/**\n * @brief\
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
    \ T>> binary_search(T max_den, Pred pred, std::optional<internal::non_deduced_t<T>>\
    \ max_num = std::nullopt) {\n    assert(max_den >= 1);\n    assert(!max_num ||\
    \ *max_num >= 0);\n    assert(pred(Rational<T>(0)));\n    internal::Bounds<T>\
    \ b;\n    // \u5206\u5B50\u304C 0 \u4EE5\u4E0B\u306A\u3089 0 \u3057\u304B\u9078\
    \u3079\u306A\u3044 (\u4E0A\u7AEF +\u221E \u304B\u3089\u5DE6\u3078\u9032\u3093\u3067\
    \u3082\u5206\u5B50 1 \u306E\u307E\u307E\u306A\u306E\u3067\u3001\u4E0A\u9650\u3092\
    \u6E80\u305F\u305B\u306A\u3044)\n    if (max_num && *max_num == 0) return {{0,\
    \ 1}, {1, 0}};\n    // \u52D5\u304F\u65B9\u306E\u7AEF (num, den) \u306B k \u56DE\
    \u3082\u3046\u4E00\u65B9\u306E\u7AEF (add_num, add_den) \u3092\u8DB3\u305B\u308B\
    \u56DE\u6570\u306E\u4E0A\u9650 (\u306A\u3051\u308C\u3070 -1)\n    auto limit =\
    \ [&](T num, T den, T add_num, T add_den) -> T {\n        T res = -1;\n      \
    \  if (add_den > 0) res = (max_den - den) / add_den;\n        if (max_num && add_num\
    \ > 0) {\n            T r = (*max_num - num) / add_num;\n            res = res\
    \ == -1 ? r : std::min(res, r);\n        }\n        return res;\n    };\n    //\
    \ ok(k) \u304C k = 0 \u3067 true\u3001k \u304C\u5927\u304D\u3044\u3068 false \u306B\
    \u306A\u308B\u3068\u304D\u3001ok(k) \u304C true \u306E\u6700\u5927\u306E k (k\
    \ <= bound\u3001bound = -1 \u306A\u3089\u4E0A\u9650\u306A\u3057)\n    // \u500D\
    \u3005\u306B\u9032\u3081\u3066\u304B\u3089\u3001\u901A\u308A\u904E\u304E\u305F\
    \u5206\u3092\u4E8C\u5206\u63A2\u7D22\u3067\u623B\u3059\u3002ok \u3092\u547C\u3076\
    \u56DE\u6570\u306F O(log k)\n    auto search = [](T bound, auto ok) -> T {\n \
    \       T k = 0, s = 1;\n        while ((bound == -1 || s <= bound - k) && ok(k\
    \ + s)) k += s, s *= 2;\n        while (s > 1) {\n            s /= 2;\n      \
    \      if ((bound == -1 || s <= bound - k) && ok(k + s)) k += s;\n        }\n\
    \        return k;\n    };\n    while (true) {\n        bool moved = false;\n\
    \        // \u4E0B\u7AEF\u3092\u4E0A\u3052\u308B: \u4E0B\u7AEF + k \u4E0A\u7AEF\
    \ \u3067 pred \u304C true \u306E\u6700\u5927\u306E k\n        T k = search(limit(b.lo_num,\
    \ b.lo_den, b.hi_num, b.hi_den), [&](T k) {\n            return pred(Rational<T>(b.lo_num\
    \ + k * b.hi_num, b.lo_den + k * b.hi_den));\n        });\n        if (k > 0)\
    \ b.move('R', k), moved = true;\n        // \u4E0A\u7AEF\u3092\u4E0B\u3052\u308B\
    : \u4E0A\u7AEF + k \u4E0B\u7AEF \u3067 pred \u304C false \u306E\u6700\u5927\u306E\
    \ k\n        k = search(limit(b.hi_num, b.hi_den, b.lo_num, b.lo_den), [&](T k)\
    \ {\n            return !pred(Rational<T>(b.hi_num + k * b.lo_num, b.hi_den +\
    \ k * b.lo_den));\n        });\n        if (k > 0) b.move('L', k), moved = true;\n\
    \        if (!moved) break;\n    }\n    return {{b.lo_num, b.lo_den}, {b.hi_num,\
    \ b.hi_den}};\n}\n\n}  // namespace stern_brocot\n"
  dependsOn:
  - src/math/rational.hpp
  - src/base/functions.hpp
  isVerificationFile: false
  path: src/math/stern-brocot.hpp
  requiredBy: []
  timestamp: '2026-10-23 13:29:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/stern-brocot.test.cpp
  - test/yosupo/number_theory/stern-brocot-tree.test.cpp
  - test/yosupo/number_theory/rational-approximation.test.cpp
documentation_of: src/math/stern-brocot.hpp
layout: document
title: "Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570"
---

正の有理数を Stern–Brocot 木の頂点とみなして、木の上の道・最小共通祖先・祖先・子孫の範囲を求めます。区間に入る最も単純な分数 (分母が最小の分数) や、分母に上限がある中での最良近似、連分数展開も求められます。すべて `namespace stern_brocot` の関数で、有理数は [有理数](rational.hpp) の `Rational<T>` で受け渡します。

```cpp
using Q = Rational<long long>;
auto path = stern_brocot::encode_path(Q(3, 2));                // { {'R', 1}, {'L', 1}} (1/1 → 2/1 → 3/2)
Q x = stern_brocot::decode_path(path);                         // 3/2
Q m = stern_brocot::lca(Q(3, 2), Q(5, 3));                     // 3/2
Q s = stern_brocot::simplest_between(Q(60, 191), Q(11, 35));   // 71/226 (分母が最小の分数)
auto [lo, hi] = stern_brocot::best_approximation(Q(314159, 100000), 10LL);  // 25/8 と 22/7
auto a = stern_brocot::continued_fraction(Q(415, 93));         // {4, 2, 6, 7}

// 分母 10^9 以下の分数で √2 を挟む 2 つ (pred は小さい側で true の単調な関数)
auto [l, h] = stern_brocot::binary_search(1000000000LL, [](const Q& y) { return y.num() * y.num() <= 2 * y.den() * y.den(); });
// l = {1086679440, 768398401}, h = {768398401, 543339720} ({分子, 分母} の組)
```

Stern–Brocot 木は、根が $1/1$ で、頂点 $x$ の子孫がある開区間 $(l, h)$ を覆う二分木です ($l$、$h$ は $0/1$ や $1/0 = +\infty$ を含む分数)。頂点はその区間の両端の分子どうし・分母どうしを足した分数 (中間数) で、左の子は区間 $(l, x)$、右の子は区間 $(x, h)$ の頂点です。正の有理数はすべて、既約分数としてちょうど 1 回ずつ現れます。

## 関数

`x` などの有理数は `Rational<T>` です。道は、左の子へ進む `'L'` と右の子へ進む `'R'` を連長圧縮した `std::vector<std::pair<char, T>>` で表します。計算量の $N$ は分子・分母の最大値です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `continued_fraction(x)` | 連分数展開 $[a_0; a_1, \dots, a_n]$ ($x = a_0 + 1/(a_1 + 1/(\dots + 1/a_n))$)。$a_0 = \lfloor x \rfloor$ (負でもよい)、$i \ge 1$ では $a_i \ge 1$、$n \ge 1$ なら $a_n \ge 2$ | $O(\log N)$ |
| `from_continued_fraction(a)` | 連分数 $[a_0; a_1, \dots, a_n]$ が表す有理数。最後の項は 1 でもよい | $O(n + \log N)$ |
| `encode_path(x)` | 根 $1/1$ から $x$ への道 ($x > 0$)。同じ文字は続かず、回数は正 | $O(\log N)$ |
| `decode_path(path)` | 根から道 `path` をたどった頂点。同じ文字が続いても、回数が 0 でもよい | $O(\lvert path \rvert + \log N)$ |
| `depth(x)` | $x$ の深さ (根は 0)。値は道の文字数で、$N$ 程度になることもある | $O(\log N)$ |
| `lca(x, y)` | $x$ と $y$ の最小共通祖先 | $O(\log N)$ |
| `ancestor(x, k)` | $x$ の祖先で深さ $k$ の頂点。$k$ が $x$ の深さより大きいと `std::nullopt` | $O(\log N)$ |
| `range(x)` | $x$ の子孫 ($x$ 自身を含む) が覆う開区間 `{ {下端の分子, 分母}, {上端の分子, 分母}}`。下端が 0 なら `{0, 1}`、上端が $+\infty$ なら `{1, 0}` | $O(\log N)$ |
| `simplest_between(lo, hi, include_lo = false, include_hi = false)` | 区間に入る分数のうち、分母が最小で、その中で分子の絶対値が最小のもの。既定は開区間 $(lo, hi)$ で、`include_lo`・`include_hi` を `true` にするとその端を含める。負の区間や 0 をまたぐ区間でもよい | $O(\log N)$ |
| `best_approximation(x, n)` | 分母が $n$ 以下の分数のうち、$x$ 以下で最大のものと $x$ 以上で最小のもの `{lower, upper}`。$x$ の分母が $n$ 以下なら `{x, x}` | $O(\log N)$ |
| `binary_search(max_den, pred, max_num = nullopt)` | 分母が `max_den` 以下 (`max_num` を渡すと分子も `max_num` 以下) の 0 以上の分数の中での、単調な `pred` の境目。`{ {true の最大の分子, 分母}, {false の最小の分子, 分母} }` を返し、false の側がなければ後ろは `{1, 0}` ($+\infty$) | `pred` を $O(\log N)$ 回 |

- `ancestor` と `best_approximation` の `k`、`n` は `T` 型です。`10LL` のように型を合わせて渡します。
- 区間で分母が最小の分数は 1 つに決まり、その分子も最小になります (Stern–Brocot 木で区間に入る頂点のうち最も浅いもの)。
- `simplest_between` は、ユークリッドの互除法のように整数部分を引いて逆数をとることを繰り返します。掛け算を使わないので、入力の分子・分母が $10^{18}$ 程度でもあふれません。答えの分子・分母も `T` に収まる必要があります。
- `binary_search` の `pred` は `Rational<T>` を受け取り、小さい値で `true`、大きい値で `false` となる単調な関数です。`pred(0)` は `true` である必要があります。`max_num` を渡さないなら、`pred` はどこかで `false` になる必要があります (そうでないと上側へ進み続けて終わりません)。Stern–Brocot 木を根から下り、同じ向きに何歩進めるかを、倍々に進めてから二分探索して決めます。浮動小数点の二分探索と違い、誤差なく境目の分数が求まります。`best_approximation(x, n)` は `pred(y) = (y <= x)` の場合にあたります。
- 道は連分数展開から作ります。$x = [a_0; a_1, \dots, a_n]$ への道は $R^{a_0} L^{a_1} R^{a_2} \cdots$ で、最後の項だけ 1 少なくなります。

## 関連

- 有理数の型は [有理数](rational.hpp)
- 床関数の和は [floor sum](floor-sum.hpp)
