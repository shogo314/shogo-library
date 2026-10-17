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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/rational.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Rational \u3092\u3001__int128 \u3067\u901A\u5206\u3057\u3066\u8A08\u7B97\
    \u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/math/rational.hpp\"\n\n/**\n * @file rational.hpp\n\
    \ * @brief \u6709\u7406\u6570\n */\n\n#include <cassert>\n#include <cstddef>\n\
    #include <istream>\n#include <ostream>\n#include <string>\n#include <utility>\n\
    \n#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n * @brief\
    \ \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include <algorithm>\n\
    #include <cmath>\n#include <iterator>\n#include <numeric>\n#include <type_traits>\n\
    \ntemplate <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1&\
    \ a, T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ninline constexpr long long max(const long long& t1, const\
    \ long long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
    \ long long min(const long long& t1, const long long& t2) {\n    return std::min<long\
    \ long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing\
    \ std::size;\n\ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T&\
    \ b, T& x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a %\
    \ b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n       \
    \ y = 0;\n    }\n    return d;\n}\n\n/**\n * floor(a / b) (b != 0\u3001\u8CA0\u306E\
    \u6570\u3082\u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ std::common_type_t<T1, T2> floordiv(T1 a, T2 b) {\n    return a / b - (a % b\
    \ != 0 && (a < 0) != (b < 0));\n}\n/**\n * ceil(a / b) (b != 0\u3001\u8CA0\u306E\
    \u6570\u3082\u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ std::common_type_t<T1, T2> ceildiv(T1 a, T2 b) {\n    return a / b + (a % b\
    \ != 0 && (a < 0) == (b < 0));\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr\
    \ bool inrange(long long x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n\
    \ * a <= x < b\n */\ninline constexpr bool inrange(long long x, long long a, long\
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
    \ (sizeof(T) <= 8) {\n            __int128 x = (__int128)a * d, y = (__int128)c\
    \ * b;\n            return x < y ? -1 : x > y ? 1\n                          \
    \            : 0;\n        } else {\n            // \u6574\u6570\u90E8\u5206\u3092\
    \u6BD4\u3079\u3001\u540C\u3058\u306A\u3089\u5C0F\u6570\u90E8\u5206\u306E\u9006\
    \u6570\u3092\u6BD4\u3079\u308B (\u5927\u5C0F\u304C\u9006\u306B\u306A\u308B)\n\
    \            int sign = 1;\n            while (true) {\n                T x =\
    \ floordiv(a, b), y = floordiv(c, d);\n                if (x != y) return x <\
    \ y ? -sign : sign;\n                a -= x * b, c -= y * d;\n               \
    \ if (a == 0 || c == 0) {\n                    if (a == 0 && c == 0) return 0;\n\
    \                    return a == 0 ? -sign : sign;\n                }\n      \
    \          T t = a;\n                a = b, b = t;\n                t = c;\n \
    \               c = d, d = t;\n                sign = -sign;\n            }\n\
    \        }\n    }\n\n   public:\n    /**\n     * @brief \u6574\u6570 n\n     */\n\
    \    constexpr Rational(T n = 0) : p(n), q(1) {}\n    /**\n     * @brief num /\
    \ den (den != 0)\n     */\n    constexpr Rational(T num, T den) : p(num), q(den)\
    \ {\n        assert(den != 0 && \"Rational: division by zero\");\n        if (q\
    \ < 0) p = -p, q = -q;\n        T g = gcd_(p, q);\n        p /= g, q /= g;\n \
    \   }\n\n    /**\n     * @brief \u5206\u5B50\n     */\n    constexpr T num() const\
    \ { return p; }\n    /**\n     * @brief \u5206\u6BCD (\u6B63)\n     */\n    constexpr\
    \ T den() const { return q; }\n\n    /**\n     * @brief \u4EE5\u4E0B\u3067\u6700\
    \u5927\u306E\u6574\u6570\n     */\n    constexpr T floor() const { return floordiv(p,\
    \ q); }\n    /**\n     * @brief \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u6574\u6570\
    \n     */\n    constexpr T ceil() const { return ceildiv(p, q); }\n    /**\n \
    \    * @brief \u6574\u6570\u304B\n     */\n    constexpr bool is_integer() const\
    \ { return q == 1; }\n    /**\n     * @brief double \u306B\u76F4\u3057\u305F\u5024\
    \n     */\n    constexpr double to_double() const { return (double)p / (double)q;\
    \ }\n    /**\n     * @brief long double \u306B\u76F4\u3057\u305F\u5024\n     */\n\
    \    constexpr long double to_long_double() const { return (long double)p / (long\
    \ double)q; }\n    explicit constexpr operator double() const { return to_double();\
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
    \ + 1)));\n        return is;\n    }\n};\n#line 7 \"test/unittest/rational.test.cpp\"\
    \n\n#include <iostream>\n#include <map>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#line 14 \"test/unittest/rational.test.cpp\"\n#include <vector>\n\
    \nusing i128 = __int128;\n\ni128 gcd128(i128 a, i128 b) {\n    if (a < 0) a =\
    \ -a;\n    if (b < 0) b = -b;\n    while (b) {\n        i128 t = a % b;\n    \
    \    a = b;\n        b = t;\n    }\n    return a;\n}\n\n// p / q \u3092\u65E2\u7D04\
    \u306B\u3057\u3066 Rational<T> \u3068\u4E00\u81F4\u3059\u308B\u304B\ntemplate\
    \ <typename T>\nbool same(const Rational<T>& r, i128 p, i128 q) {\n    if (q <\
    \ 0) p = -p, q = -q;\n    i128 g = gcd128(p, q);\n    return (i128)r.num() ==\
    \ p / g && (i128)r.den() == q / g;\n}\n\ntemplate <typename T>\nbool test(std::mt19937_64&\
    \ rng, long long range) {\n    bool ok = true;\n    auto rnd = [&](bool nonzero)\
    \ {\n        while (true) {\n            long long x = (long long)(rng() % (2\
    \ * range + 1)) - range;\n            if (!nonzero || x != 0) return x;\n    \
    \    }\n    };\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n        long\
    \ long a = rnd(false), b = rnd(true), c = rnd(false), d = rnd(true);\n       \
    \ Rational<T> x(a, b), y(c, d);\n        ok = ok && same(x, a, b) && x.den() >\
    \ 0;\n        ok = ok && same(x + y, (i128)a * d + (i128)c * b, (i128)b * d);\n\
    \        ok = ok && same(x - y, (i128)a * d - (i128)c * b, (i128)b * d);\n   \
    \     ok = ok && same(x * y, (i128)a * c, (i128)b * d);\n        if (c != 0) ok\
    \ = ok && same(x / y, (i128)a * d, (i128)b * c);\n        // \u6BD4\u8F03\n  \
    \      int sgn = (b > 0) == (d > 0) ? 1 : -1;\n        i128 l = (i128)a * d *\
    \ sgn, r = (i128)c * b * sgn;\n        ok = ok && (x < y) == (l < r) && (x ==\
    \ y) == (l == r) && (x <= y) == (l <= r) && (x > y) == (l > r);\n        // floor,\
    \ ceil\n        long long fl = a / b, rem = a % b;\n        if (rem != 0 && ((rem\
    \ < 0) != (b < 0))) fl--;\n        ok = ok && (long long)x.floor() == fl && (long\
    \ long)x.ceil() == fl + (rem != 0);\n        ok = ok && x.is_integer() == (rem\
    \ == 0);\n        // \u6587\u5B57\u5217\u306B\u3057\u3066\u8AAD\u307F\u76F4\u3059\
    \n        std::stringstream ss;\n        ss << x;\n        Rational<T> z;\n  \
    \      ss >> z;\n        ok = ok && z == x;\n    }\n    return ok;\n}\n\nint main()\
    \ {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    ok = ok && test<long\
    \ long>(rng, 20);\n    ok = ok && test<long long>(rng, 1000000000);\n    ok =\
    \ ok && test<int>(rng, 30000);\n    ok = ok && test<__int128>(rng, 20);\n    ok\
    \ = ok && test<__int128>(rng, 1000000000000000000LL);\n\n    // __int128 \u3067\
    \u3001\u901A\u5206\u3059\u308B\u3068 128 bit \u306B\u53CE\u307E\u3089\u306A\u3044\
    \u5024\u3069\u3046\u3057\u306E\u6BD4\u8F03 (\u9023\u5206\u6570\u5C55\u958B\u3067\
    \u6BD4\u3079\u308B)\n    {\n        using R = Rational<__int128>;\n        i128\
    \ big = (i128)1 << 100;\n        R x(big + 1, big), y(big + 2, big + 1);  // 1\
    \ + 1/big > 1 + 1/(big+1)\n        ok = ok && y < x && !(x < y) && x != y && R(big,\
    \ 3) > R(big - 1, 3);\n        ok = ok && R(-big, big + 1) < R(-big + 1, big)\
    \ && R(-(big + 1), 7).floor() == -(big + 1) / 7 - 1;\n    }\n\n    // \u4F8B\n\
    \    using Q = Rational<>;\n    ok = ok && Q(1, 3) + Q(1, 6) == Q(1, 2) && Q(2,\
    \ -4) == Q(-1, 2) && Q(0, -5) == Q(0);\n    ok = ok && Q(3, 2) * 2 == 3 && 1 <\
    \ Q(3, 2) && Q(-7, 2).floor() == -4 && Q(-7, 2).ceil() == -3;\n    ok = ok &&\
    \ Q(-3, 4).inv() == Q(-4, 3) && Q(-3, 4).abs() == Q(3, 4) && -Q(1, 2) == Q(-1,\
    \ 2);\n    ok = ok && Q(1, 3).to_string() == \"1/3\" && Q(-6, 3).to_string() ==\
    \ \"-2\" && Q(1, 4).to_double() == 0.25;\n    // map \u3084 set \u306E\u30AD\u30FC\
    \u306B\u3067\u304D\u308B (\u50BE\u304D\u3092\u6570\u3048\u308B)\n    std::set<Q>\
    \ slopes = {Q(1, 2), Q(2, 4), Q(-1, 3), Q(3, -9)};\n    ok = ok && slopes.size()\
    \ == 2 && *slopes.begin() == Q(-1, 3);\n    std::map<Q, int> mp;\n    mp[Q(2,\
    \ 6)]++, mp[Q(1, 3)]++;\n    ok = ok && mp[Q(1, 3)] == 2;\n    // \u5165\u529B\
    \u306E\u5F62\u5F0F\n    std::stringstream ss(\"3/6 -4 +5/-10\");\n    Q a, b,\
    \ c;\n    ss >> a >> b >> c;\n    ok = ok && a == Q(1, 2) && b == Q(-4) && c ==\
    \ Q(-1, 2);\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Rational \u3092\u3001__int128 \u3067\u901A\u5206\u3057\u3066\u8A08\u7B97\
    \u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../src/math/rational.hpp\"\n\n#include <iostream>\n\
    #include <map>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <string>\n#include <vector>\n\nusing i128 = __int128;\n\ni128 gcd128(i128 a,\
    \ i128 b) {\n    if (a < 0) a = -a;\n    if (b < 0) b = -b;\n    while (b) {\n\
    \        i128 t = a % b;\n        a = b;\n        b = t;\n    }\n    return a;\n\
    }\n\n// p / q \u3092\u65E2\u7D04\u306B\u3057\u3066 Rational<T> \u3068\u4E00\u81F4\
    \u3059\u308B\u304B\ntemplate <typename T>\nbool same(const Rational<T>& r, i128\
    \ p, i128 q) {\n    if (q < 0) p = -p, q = -q;\n    i128 g = gcd128(p, q);\n \
    \   return (i128)r.num() == p / g && (i128)r.den() == q / g;\n}\n\ntemplate <typename\
    \ T>\nbool test(std::mt19937_64& rng, long long range) {\n    bool ok = true;\n\
    \    auto rnd = [&](bool nonzero) {\n        while (true) {\n            long\
    \ long x = (long long)(rng() % (2 * range + 1)) - range;\n            if (!nonzero\
    \ || x != 0) return x;\n        }\n    };\n    for (int rep = 0; rep < 100000\
    \ && ok; rep++) {\n        long long a = rnd(false), b = rnd(true), c = rnd(false),\
    \ d = rnd(true);\n        Rational<T> x(a, b), y(c, d);\n        ok = ok && same(x,\
    \ a, b) && x.den() > 0;\n        ok = ok && same(x + y, (i128)a * d + (i128)c\
    \ * b, (i128)b * d);\n        ok = ok && same(x - y, (i128)a * d - (i128)c * b,\
    \ (i128)b * d);\n        ok = ok && same(x * y, (i128)a * c, (i128)b * d);\n \
    \       if (c != 0) ok = ok && same(x / y, (i128)a * d, (i128)b * c);\n      \
    \  // \u6BD4\u8F03\n        int sgn = (b > 0) == (d > 0) ? 1 : -1;\n        i128\
    \ l = (i128)a * d * sgn, r = (i128)c * b * sgn;\n        ok = ok && (x < y) ==\
    \ (l < r) && (x == y) == (l == r) && (x <= y) == (l <= r) && (x > y) == (l > r);\n\
    \        // floor, ceil\n        long long fl = a / b, rem = a % b;\n        if\
    \ (rem != 0 && ((rem < 0) != (b < 0))) fl--;\n        ok = ok && (long long)x.floor()\
    \ == fl && (long long)x.ceil() == fl + (rem != 0);\n        ok = ok && x.is_integer()\
    \ == (rem == 0);\n        // \u6587\u5B57\u5217\u306B\u3057\u3066\u8AAD\u307F\u76F4\
    \u3059\n        std::stringstream ss;\n        ss << x;\n        Rational<T> z;\n\
    \        ss >> z;\n        ok = ok && z == x;\n    }\n    return ok;\n}\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    ok = ok &&\
    \ test<long long>(rng, 20);\n    ok = ok && test<long long>(rng, 1000000000);\n\
    \    ok = ok && test<int>(rng, 30000);\n    ok = ok && test<__int128>(rng, 20);\n\
    \    ok = ok && test<__int128>(rng, 1000000000000000000LL);\n\n    // __int128\
    \ \u3067\u3001\u901A\u5206\u3059\u308B\u3068 128 bit \u306B\u53CE\u307E\u3089\u306A\
    \u3044\u5024\u3069\u3046\u3057\u306E\u6BD4\u8F03 (\u9023\u5206\u6570\u5C55\u958B\
    \u3067\u6BD4\u3079\u308B)\n    {\n        using R = Rational<__int128>;\n    \
    \    i128 big = (i128)1 << 100;\n        R x(big + 1, big), y(big + 2, big + 1);\
    \  // 1 + 1/big > 1 + 1/(big+1)\n        ok = ok && y < x && !(x < y) && x !=\
    \ y && R(big, 3) > R(big - 1, 3);\n        ok = ok && R(-big, big + 1) < R(-big\
    \ + 1, big) && R(-(big + 1), 7).floor() == -(big + 1) / 7 - 1;\n    }\n\n    //\
    \ \u4F8B\n    using Q = Rational<>;\n    ok = ok && Q(1, 3) + Q(1, 6) == Q(1,\
    \ 2) && Q(2, -4) == Q(-1, 2) && Q(0, -5) == Q(0);\n    ok = ok && Q(3, 2) * 2\
    \ == 3 && 1 < Q(3, 2) && Q(-7, 2).floor() == -4 && Q(-7, 2).ceil() == -3;\n  \
    \  ok = ok && Q(-3, 4).inv() == Q(-4, 3) && Q(-3, 4).abs() == Q(3, 4) && -Q(1,\
    \ 2) == Q(-1, 2);\n    ok = ok && Q(1, 3).to_string() == \"1/3\" && Q(-6, 3).to_string()\
    \ == \"-2\" && Q(1, 4).to_double() == 0.25;\n    // map \u3084 set \u306E\u30AD\
    \u30FC\u306B\u3067\u304D\u308B (\u50BE\u304D\u3092\u6570\u3048\u308B)\n    std::set<Q>\
    \ slopes = {Q(1, 2), Q(2, 4), Q(-1, 3), Q(3, -9)};\n    ok = ok && slopes.size()\
    \ == 2 && *slopes.begin() == Q(-1, 3);\n    std::map<Q, int> mp;\n    mp[Q(2,\
    \ 6)]++, mp[Q(1, 3)]++;\n    ok = ok && mp[Q(1, 3)] == 2;\n    // \u5165\u529B\
    \u306E\u5F62\u5F0F\n    std::stringstream ss(\"3/6 -4 +5/-10\");\n    Q a, b,\
    \ c;\n    ss >> a >> b >> c;\n    ok = ok && a == Q(1, 2) && b == Q(-4) && c ==\
    \ Q(-1, 2);\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/math/rational.hpp
  - src/base/functions.hpp
  isVerificationFile: true
  path: test/unittest/rational.test.cpp
  requiredBy: []
  timestamp: '2026-10-18 00:37:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/rational.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/rational.test.cpp
- /verify/test/unittest/rational.test.cpp.html
title: test/unittest/rational.test.cpp
---
