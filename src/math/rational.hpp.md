---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/rational.test.cpp
    title: test/unittest/rational.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6709\u7406\u6570"
    links: []
  bundledCode: "#line 2 \"src/math/rational.hpp\"\n\n/**\n * @file rational.hpp\n\
    \ * @brief \u6709\u7406\u6570\n */\n\n#include <cassert>\n#include <cstddef>\n\
    #include <istream>\n#include <ostream>\n#include <string>\n#include <utility>\n\
    \n/**\n * @brief \u6709\u7406\u6570 (\u5206\u6570)\n *\n * \u5E38\u306B\u65E2\u7D04\
    \u3067\u3001\u5206\u6BCD\u306F\u6B63\u30020 \u306F 0/1\n * \u6F14\u7B97\u306E\u9014\
    \u4E2D\u3067\u3082\u3001\u65E2\u7D04\u306B\u3057\u3066\u304B\u3089\u639B\u3051\
    \u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306B\u304F\
    \u3044\u3002\u6BD4\u8F03\u306F T \u304C 64 bit \u4EE5\u4E0B\u306A\u3089 __int128\
    \ \u3067\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u9023\u5206\u6570\u5C55\
    \u958B\u3067\u884C\u3046\n * std::map \u3084 std::set \u306E\u30AD\u30FC\u306B\
    \u4F7F\u3048\u308B\n * \u4F8B:\n * Rational<> a(1, 3), b(1, 6);\n * a + b;   //\
    \ 1/2\n * a < b;   // false\n *\n * @tparam T \u6574\u6570\u578B (long long \u3084\
    \ __int128 \u306A\u3069)\n */\ntemplate <typename T = long long>\nclass Rational\
    \ {\n    T p, q;  // p / q (q > 0\u3001gcd(p, q) = 1)\n\n    static T abs_(T x)\
    \ { return x < 0 ? -x : x; }\n    static T gcd_(T a, T b) {\n        a = abs_(a),\
    \ b = abs_(b);\n        while (b != 0) {\n            T t = a % b;\n         \
    \   a = b;\n            b = t;\n        }\n        return a;\n    }\n    // \u5207\
    \u308A\u6368\u3066\u9664\u7B97 (b > 0)\n    static T floor_div(T a, T b) { return\
    \ a / b - (a % b < 0); }\n\n    struct Raw {};\n    // \u3059\u3067\u306B\u65E2\
    \u7D04\u3067 q > 0 \u3068\u308F\u304B\u3063\u3066\u3044\u308B\u5834\u5408\n  \
    \  Rational(T p, T q, Raw) : p(p), q(q) {}\n\n    // a / b \u3068 c / d (b, d\
    \ > 0) \u3092\u6BD4\u3079\u3001\u5C0F\u3055\u3051\u308C\u3070\u8CA0\u3001\u7B49\
    \u3057\u3051\u308C\u3070 0\u3001\u5927\u304D\u3051\u308C\u3070\u6B63\u3092\u8FD4\
    \u3059\n    static int compare(T a, T b, T c, T d) {\n        if constexpr (sizeof(T)\
    \ <= 8) {\n            __int128 x = (__int128)a * d, y = (__int128)c * b;\n  \
    \          return x < y ? -1 : x > y ? 1\n                                   \
    \   : 0;\n        } else {\n            // \u6574\u6570\u90E8\u5206\u3092\u6BD4\
    \u3079\u3001\u540C\u3058\u306A\u3089\u5C0F\u6570\u90E8\u5206\u306E\u9006\u6570\
    \u3092\u6BD4\u3079\u308B (\u5927\u5C0F\u304C\u9006\u306B\u306A\u308B)\n      \
    \      int sign = 1;\n            while (true) {\n                T x = floor_div(a,\
    \ b), y = floor_div(c, d);\n                if (x != y) return x < y ? -sign :\
    \ sign;\n                a -= x * b, c -= y * d;\n                if (a == 0 ||\
    \ c == 0) {\n                    if (a == 0 && c == 0) return 0;\n           \
    \         return a == 0 ? -sign : sign;\n                }\n                std::swap(a,\
    \ b);\n                std::swap(c, d);\n                sign = -sign;\n     \
    \       }\n        }\n    }\n\n   public:\n    /**\n     * @brief \u6574\u6570\
    \ n\n     */\n    Rational(T n = 0) : p(n), q(1) {}\n    /**\n     * @brief num\
    \ / den (den != 0)\n     */\n    Rational(T num, T den) : p(num), q(den) {\n \
    \       assert(den != 0 && \"Rational: division by zero\");\n        if (q < 0)\
    \ p = -p, q = -q;\n        T g = gcd_(p, q);\n        p /= g, q /= g;\n    }\n\
    \n    /**\n     * @brief \u5206\u5B50\n     */\n    T num() const { return p;\
    \ }\n    /**\n     * @brief \u5206\u6BCD (\u6B63)\n     */\n    T den() const\
    \ { return q; }\n\n    /**\n     * @brief \u4EE5\u4E0B\u3067\u6700\u5927\u306E\
    \u6574\u6570\n     */\n    T floor() const { return floor_div(p, q); }\n    /**\n\
    \     * @brief \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u6574\u6570\n     */\n   \
    \ T ceil() const { return -floor_div(-p, q); }\n    /**\n     * @brief \u6574\u6570\
    \u304B\n     */\n    bool is_integer() const { return q == 1; }\n    /**\n   \
    \  * @brief double \u306B\u76F4\u3057\u305F\u5024\n     */\n    double to_double()\
    \ const { return (double)p / (double)q; }\n    /**\n     * @brief long double\
    \ \u306B\u76F4\u3057\u305F\u5024\n     */\n    long double to_long_double() const\
    \ { return (long double)p / (long double)q; }\n    explicit operator double()\
    \ const { return to_double(); }\n\n    /**\n     * @brief \u9006\u6570 (0 \u3067\
    \u306A\u3044\u3053\u3068)\n     */\n    Rational inv() const {\n        assert(p\
    \ != 0 && \"Rational: division by zero\");\n        return p > 0 ? Rational(q,\
    \ p, Raw{}) : Rational(-q, -p, Raw{});\n    }\n    /**\n     * @brief \u7D76\u5BFE\
    \u5024\n     */\n    Rational abs() const { return Rational(abs_(p), q, Raw{});\
    \ }\n\n    Rational operator+() const { return *this; }\n    Rational operator-()\
    \ const { return Rational(-p, q, Raw{}); }\n\n    Rational& operator+=(const Rational&\
    \ r) {\n        // p / q + r.p / r.q \u3092\u3001\u5206\u6BCD\u306E gcd \u3067\
    \u5272\u3063\u3066\u304B\u3089\u901A\u5206\u3059\u308B\n        T g = gcd_(q,\
    \ r.q);\n        T qg = q / g;\n        T t = p * (r.q / g) + r.p * qg;\n    \
    \    T g2 = gcd_(t, g);\n        p = t / g2;\n        q = qg * (r.q / g2);\n \
    \       return *this;\n    }\n    Rational& operator-=(const Rational& r) { return\
    \ *this += -r; }\n    Rational& operator*=(const Rational& r) {\n        // \u639B\
    \u3051\u308B\u524D\u306B\u3001\u5206\u5B50\u3068\u76F8\u624B\u306E\u5206\u6BCD\
    \u306E gcd \u3067\u5272\u308B\n        T g1 = gcd_(p, r.q), g2 = gcd_(r.p, q);\n\
    \        p = (p / g1) * (r.p / g2);\n        q = (q / g2) * (r.q / g1);\n    \
    \    return *this;\n    }\n    Rational& operator/=(const Rational& r) { return\
    \ *this *= r.inv(); }\n\n    friend Rational operator+(Rational a, const Rational&\
    \ b) { return a += b; }\n    friend Rational operator-(Rational a, const Rational&\
    \ b) { return a -= b; }\n    friend Rational operator*(Rational a, const Rational&\
    \ b) { return a *= b; }\n    friend Rational operator/(Rational a, const Rational&\
    \ b) { return a /= b; }\n\n    friend bool operator==(const Rational& a, const\
    \ Rational& b) { return a.p == b.p && a.q == b.q; }\n    friend bool operator!=(const\
    \ Rational& a, const Rational& b) { return !(a == b); }\n    friend bool operator<(const\
    \ Rational& a, const Rational& b) { return compare(a.p, a.q, b.p, b.q) < 0; }\n\
    \    friend bool operator>(const Rational& a, const Rational& b) { return b <\
    \ a; }\n    friend bool operator<=(const Rational& a, const Rational& b) { return\
    \ !(b < a); }\n    friend bool operator>=(const Rational& a, const Rational& b)\
    \ { return !(a < b); }\n\n    /**\n     * @brief \"p/q\" \u306E\u5F62\u306E\u6587\
    \u5B57\u5217 (\u6574\u6570\u306A\u3089 \"p\")\n     */\n    std::string to_string()\
    \ const {\n        auto str = [](T x) {\n            if (x == 0) return std::string(\"\
    0\");\n            bool neg = x < 0;\n            std::string s;\n           \
    \ // \u8CA0\u306E\u307E\u307E 1 \u6841\u305A\u3064\u53D6\u308A\u51FA\u3059 (\u6700\
    \u5C0F\u5024\u3067\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044)\n            while (x != 0) {\n                T d = x % 10;\n       \
    \         s += char('0' + (d < 0 ? -d : d));\n                x /= 10;\n     \
    \       }\n            if (neg) s += '-';\n            return std::string(s.rbegin(),\
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
    \ + 1)));\n        return is;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file rational.hpp\n * @brief \u6709\u7406\u6570\n\
    \ */\n\n#include <cassert>\n#include <cstddef>\n#include <istream>\n#include <ostream>\n\
    #include <string>\n#include <utility>\n\n/**\n * @brief \u6709\u7406\u6570 (\u5206\
    \u6570)\n *\n * \u5E38\u306B\u65E2\u7D04\u3067\u3001\u5206\u6BCD\u306F\u6B63\u3002\
    0 \u306F 0/1\n * \u6F14\u7B97\u306E\u9014\u4E2D\u3067\u3082\u3001\u65E2\u7D04\u306B\
    \u3057\u3066\u304B\u3089\u639B\u3051\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306B\u304F\u3044\u3002\u6BD4\u8F03\u306F T \u304C 64\
    \ bit \u4EE5\u4E0B\u306A\u3089 __int128 \u3067\u3001\u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070\u9023\u5206\u6570\u5C55\u958B\u3067\u884C\u3046\n * std::map \u3084\
    \ std::set \u306E\u30AD\u30FC\u306B\u4F7F\u3048\u308B\n * \u4F8B:\n * Rational<>\
    \ a(1, 3), b(1, 6);\n * a + b;   // 1/2\n * a < b;   // false\n *\n * @tparam\
    \ T \u6574\u6570\u578B (long long \u3084 __int128 \u306A\u3069)\n */\ntemplate\
    \ <typename T = long long>\nclass Rational {\n    T p, q;  // p / q (q > 0\u3001\
    gcd(p, q) = 1)\n\n    static T abs_(T x) { return x < 0 ? -x : x; }\n    static\
    \ T gcd_(T a, T b) {\n        a = abs_(a), b = abs_(b);\n        while (b != 0)\
    \ {\n            T t = a % b;\n            a = b;\n            b = t;\n      \
    \  }\n        return a;\n    }\n    // \u5207\u308A\u6368\u3066\u9664\u7B97 (b\
    \ > 0)\n    static T floor_div(T a, T b) { return a / b - (a % b < 0); }\n\n \
    \   struct Raw {};\n    // \u3059\u3067\u306B\u65E2\u7D04\u3067 q > 0 \u3068\u308F\
    \u304B\u3063\u3066\u3044\u308B\u5834\u5408\n    Rational(T p, T q, Raw) : p(p),\
    \ q(q) {}\n\n    // a / b \u3068 c / d (b, d > 0) \u3092\u6BD4\u3079\u3001\u5C0F\
    \u3055\u3051\u308C\u3070\u8CA0\u3001\u7B49\u3057\u3051\u308C\u3070 0\u3001\u5927\
    \u304D\u3051\u308C\u3070\u6B63\u3092\u8FD4\u3059\n    static int compare(T a,\
    \ T b, T c, T d) {\n        if constexpr (sizeof(T) <= 8) {\n            __int128\
    \ x = (__int128)a * d, y = (__int128)c * b;\n            return x < y ? -1 : x\
    \ > y ? 1\n                                      : 0;\n        } else {\n    \
    \        // \u6574\u6570\u90E8\u5206\u3092\u6BD4\u3079\u3001\u540C\u3058\u306A\
    \u3089\u5C0F\u6570\u90E8\u5206\u306E\u9006\u6570\u3092\u6BD4\u3079\u308B (\u5927\
    \u5C0F\u304C\u9006\u306B\u306A\u308B)\n            int sign = 1;\n           \
    \ while (true) {\n                T x = floor_div(a, b), y = floor_div(c, d);\n\
    \                if (x != y) return x < y ? -sign : sign;\n                a -=\
    \ x * b, c -= y * d;\n                if (a == 0 || c == 0) {\n              \
    \      if (a == 0 && c == 0) return 0;\n                    return a == 0 ? -sign\
    \ : sign;\n                }\n                std::swap(a, b);\n             \
    \   std::swap(c, d);\n                sign = -sign;\n            }\n        }\n\
    \    }\n\n   public:\n    /**\n     * @brief \u6574\u6570 n\n     */\n    Rational(T\
    \ n = 0) : p(n), q(1) {}\n    /**\n     * @brief num / den (den != 0)\n     */\n\
    \    Rational(T num, T den) : p(num), q(den) {\n        assert(den != 0 && \"\
    Rational: division by zero\");\n        if (q < 0) p = -p, q = -q;\n        T\
    \ g = gcd_(p, q);\n        p /= g, q /= g;\n    }\n\n    /**\n     * @brief \u5206\
    \u5B50\n     */\n    T num() const { return p; }\n    /**\n     * @brief \u5206\
    \u6BCD (\u6B63)\n     */\n    T den() const { return q; }\n\n    /**\n     * @brief\
    \ \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u6574\u6570\n     */\n    T floor() const\
    \ { return floor_div(p, q); }\n    /**\n     * @brief \u4EE5\u4E0A\u3067\u6700\
    \u5C0F\u306E\u6574\u6570\n     */\n    T ceil() const { return -floor_div(-p,\
    \ q); }\n    /**\n     * @brief \u6574\u6570\u304B\n     */\n    bool is_integer()\
    \ const { return q == 1; }\n    /**\n     * @brief double \u306B\u76F4\u3057\u305F\
    \u5024\n     */\n    double to_double() const { return (double)p / (double)q;\
    \ }\n    /**\n     * @brief long double \u306B\u76F4\u3057\u305F\u5024\n     */\n\
    \    long double to_long_double() const { return (long double)p / (long double)q;\
    \ }\n    explicit operator double() const { return to_double(); }\n\n    /**\n\
    \     * @brief \u9006\u6570 (0 \u3067\u306A\u3044\u3053\u3068)\n     */\n    Rational\
    \ inv() const {\n        assert(p != 0 && \"Rational: division by zero\");\n \
    \       return p > 0 ? Rational(q, p, Raw{}) : Rational(-q, -p, Raw{});\n    }\n\
    \    /**\n     * @brief \u7D76\u5BFE\u5024\n     */\n    Rational abs() const\
    \ { return Rational(abs_(p), q, Raw{}); }\n\n    Rational operator+() const {\
    \ return *this; }\n    Rational operator-() const { return Rational(-p, q, Raw{});\
    \ }\n\n    Rational& operator+=(const Rational& r) {\n        // p / q + r.p /\
    \ r.q \u3092\u3001\u5206\u6BCD\u306E gcd \u3067\u5272\u3063\u3066\u304B\u3089\u901A\
    \u5206\u3059\u308B\n        T g = gcd_(q, r.q);\n        T qg = q / g;\n     \
    \   T t = p * (r.q / g) + r.p * qg;\n        T g2 = gcd_(t, g);\n        p = t\
    \ / g2;\n        q = qg * (r.q / g2);\n        return *this;\n    }\n    Rational&\
    \ operator-=(const Rational& r) { return *this += -r; }\n    Rational& operator*=(const\
    \ Rational& r) {\n        // \u639B\u3051\u308B\u524D\u306B\u3001\u5206\u5B50\u3068\
    \u76F8\u624B\u306E\u5206\u6BCD\u306E gcd \u3067\u5272\u308B\n        T g1 = gcd_(p,\
    \ r.q), g2 = gcd_(r.p, q);\n        p = (p / g1) * (r.p / g2);\n        q = (q\
    \ / g2) * (r.q / g1);\n        return *this;\n    }\n    Rational& operator/=(const\
    \ Rational& r) { return *this *= r.inv(); }\n\n    friend Rational operator+(Rational\
    \ a, const Rational& b) { return a += b; }\n    friend Rational operator-(Rational\
    \ a, const Rational& b) { return a -= b; }\n    friend Rational operator*(Rational\
    \ a, const Rational& b) { return a *= b; }\n    friend Rational operator/(Rational\
    \ a, const Rational& b) { return a /= b; }\n\n    friend bool operator==(const\
    \ Rational& a, const Rational& b) { return a.p == b.p && a.q == b.q; }\n    friend\
    \ bool operator!=(const Rational& a, const Rational& b) { return !(a == b); }\n\
    \    friend bool operator<(const Rational& a, const Rational& b) { return compare(a.p,\
    \ a.q, b.p, b.q) < 0; }\n    friend bool operator>(const Rational& a, const Rational&\
    \ b) { return b < a; }\n    friend bool operator<=(const Rational& a, const Rational&\
    \ b) { return !(b < a); }\n    friend bool operator>=(const Rational& a, const\
    \ Rational& b) { return !(a < b); }\n\n    /**\n     * @brief \"p/q\" \u306E\u5F62\
    \u306E\u6587\u5B57\u5217 (\u6574\u6570\u306A\u3089 \"p\")\n     */\n    std::string\
    \ to_string() const {\n        auto str = [](T x) {\n            if (x == 0) return\
    \ std::string(\"0\");\n            bool neg = x < 0;\n            std::string\
    \ s;\n            // \u8CA0\u306E\u307E\u307E 1 \u6841\u305A\u3064\u53D6\u308A\
    \u51FA\u3059 (\u6700\u5C0F\u5024\u3067\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044)\n            while (x != 0) {\n                T d =\
    \ x % 10;\n                s += char('0' + (d < 0 ? -d : d));\n              \
    \  x /= 10;\n            }\n            if (neg) s += '-';\n            return\
    \ std::string(s.rbegin(), s.rend());\n        };\n        return q == 1 ? str(p)\
    \ : str(p) + \"/\" + str(q);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Rational& r) { return os << r.to_string(); }\n    /**\n     * @brief\
    \ \"p/q\" \u307E\u305F\u306F \"p\" \u306E\u5F62\u3067\u8AAD\u3080\n     */\n \
    \   friend std::istream& operator>>(std::istream& is, Rational& r) {\n       \
    \ std::string s;\n        if (!(is >> s)) return is;\n        auto parse = [](const\
    \ std::string& t) {\n            T x = 0;\n            bool neg = false;\n   \
    \         std::size_t i = 0;\n            if (i < t.size() && (t[i] == '-' ||\
    \ t[i] == '+')) neg = t[i++] == '-';\n            for (; i < t.size(); i++) x\
    \ = x * 10 + (t[i] - '0');\n            return neg ? -x : x;\n        };\n   \
    \     auto pos = s.find('/');\n        if (pos == std::string::npos)\n       \
    \     r = Rational(parse(s));\n        else\n            r = Rational(parse(s.substr(0,\
    \ pos)), parse(s.substr(pos + 1)));\n        return is;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/rational.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rational.test.cpp
documentation_of: src/math/rational.hpp
layout: document
title: "\u6709\u7406\u6570"
---

有理数 (分数) を誤差なく扱う `Rational<T>` です。`T` は整数型で、既定は `long long` です。値は常に既約で、分母は正です (0 は 0/1)。傾きや比を誤差なく比べたり、`std::map` や `std::set` のキーにしたりするのに使います。

```cpp
using Q = Rational<>;
Q a(1, 3), b(1, 6);
Q c = a + b;               // 1/2
bool lt = a < b;           // false
Q d(2, -4);                // -1/2 (既約にして、分母を正にする)
std::set<Q> slopes;        // 傾きの種類を数える
slopes.insert(Q(dy, dx));  // dx != 0
std::cout << c << '\n';    // 1/2
```

## メンバ関数

計算量の $p$、$q$ は分子・分母の絶対値です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Rational(n = 0)` | 整数 `n` | $O(1)$ |
| `Rational(num, den)` | `num / den` (`den != 0`)。既約にして分母を正にする | $O(\log \max(\lvert p \rvert, q))$ |
| `num()` / `den()` | 分子 / 分母 (正) | $O(1)$ |
| `+`、`-` (単項・二項)、`*`、`/`、`+=`、`-=`、`*=`、`/=` | 四則演算 (0 での割り算は assert で落ちる) | $O(\log \max(\lvert p \rvert, q))$ (単項 `-` は $O(1)$) |
| `==`、`!=`、`<`、`<=`、`>`、`>=` | 比較。整数とも比べられる (`q < 1` など) | $O(1)$ (`T = __int128` の大小比較は $O(\log \max(\lvert p \rvert, q))$) |
| `floor()` / `ceil()` | 以下で最大の整数 / 以上で最小の整数 | $O(1)$ |
| `is_integer()` | 整数か | $O(1)$ |
| `inv()` / `abs()` | 逆数 (0 でないこと) / 絶対値 | $O(1)$ |
| `to_double()` / `to_long_double()` / `(double)q` | 浮動小数点数に直した値 | $O(1)$ |
| `to_string()` | `"p/q"` の形の文字列 (整数なら `"p"`) | 桁数に比例 |
| `os << q` / `is >> q` | `to_string()` の形で出力 / `"p/q"` か `"p"` の形で入力 | 桁数に比例 (入力は既約にするので + $O(\log \max(\lvert p \rvert, q))$) |

## オーバーフローについて

- 足し算では分母の gcd で割ってから通分し、掛け算では分子と相手の分母の gcd で割ってから掛けます。そのため、途中の値は答えの分子・分母の数倍程度に収まります。
- 比較は、`T` が 64 bit 以下なら `__int128` で $a d$ と $c b$ を比べます。`T = __int128` なら、連分数展開 (整数部分を比べ、同じなら小数部分の逆数を比べる) で、掛け算を使わずに比べます。
- 分子・分母の絶対値が $10^9$ 程度までなら、`long long` で足し算・掛け算を 1 回してもあふれません。それより大きくなるときは `Rational<__int128>` を使ってください。

## 関連

- 偏角でソートするだけなら [偏角](../geometry/angle.hpp) の `Angle`
