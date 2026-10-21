#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// repr.hpp の文字列化を検証する
// CHECK_REPR(値, 式) は repr(値) が「式」の文字列と一致し、さらにその式を評価すると値と等しくなることを確かめる
// (式はこのファイルで C++ としてコンパイルされるので、repr の出力が C++ の式として正しいことも確かめられる)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/utility/repr.hpp"

#include <array>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "../../../src/utility/range.hpp"

bool ok = true;
void check(bool cond, const std::string& what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

#define CHECK_REPR(value, ...)                                                                                  \
    do {                                                                                                        \
        const auto& value_ = (value);                                                                           \
        check(repr(value_) == #__VA_ARGS__, "repr(" #value ") == " #__VA_ARGS__ " (got " + repr(value_) + ")"); \
        check(value_ == (__VA_ARGS__), "evaluating " #__VA_ARGS__);                                             \
    } while (0)

// repr などのメンバ関数を持たない型
struct Plain {};
// initializer_str だけを持つ型
struct OnlyInit {
    int x;
    std::string initializer_str() const { return "{" + std::to_string(x) + "}"; }
};

// char の期待値 (愚直に作る)
std::string naive_char_repr(char c) {
    unsigned char u = static_cast<unsigned char>(c);
    switch (c) {
        case '\0':
            return "'\\0'";
        case '\a':
            return "'\\a'";
        case '\b':
            return "'\\b'";
        case '\f':
            return "'\\f'";
        case '\r':
            return "'\\r'";
        case '\n':
            return "'\\n'";
        case '\v':
            return "'\\v'";
        case '\'':
            return "'\\''";
        case '\\':
            return "'\\\\'";
    }
    if (32 <= u && u <= 126) return std::string("'") + c + "'";
    return "'\\" + std::to_string(u / 64) + std::to_string(u / 8 % 8) + std::to_string(u % 8) + "'";
}

int main() {
    std::mt19937 rng(314);

    // 整数・浮動小数点数
    CHECK_REPR(5, 5);
    CHECK_REPR(-3, -3);
    CHECK_REPR(5L, 5l);
    CHECK_REPR(-7LL, -7ll);
    CHECK_REPR(5U, 5u);
    CHECK_REPR(5UL, 5ul);
    CHECK_REPR(18446744073709551615ULL, 18446744073709551615ull);
    CHECK_REPR(1.5f, 1.500000f);
    CHECK_REPR(-0.25, -0.250000);
    CHECK_REPR(2.5L, 2.500000l);
    check(type_str(5) == "int" && type_str(5L) == "long" && type_str(5LL) == "long long", "type_str (signed)");
    check(type_str(5U) == "unsigned int" && type_str(5UL) == "unsigned long" && type_str(5ULL) == "unsigned long long", "type_str (unsigned)");
    check(type_str(1.0f) == "float" && type_str(1.0) == "double" && type_str(1.0L) == "long double", "type_str (floating)");
    check(initializer_str(5LL) == "5ll" && initializer_str(1.5f) == "1.500000f", "initializer_str (number)");

    // char
    CHECK_REPR('a', 'a');
    CHECK_REPR('\n', '\n');
    CHECK_REPR('\0', '\0');
    CHECK_REPR('\'', '\'');
    CHECK_REPR('\\', '\\');
    CHECK_REPR(static_cast<char>(1), '\001');
    CHECK_REPR(static_cast<char>(127), '\177');
    CHECK_REPR(static_cast<char>(-61), '\303');  // UTF-8 の文字のバイトなど、負の値の char
    check(type_str('a') == "char" && initializer_str('a') == "'a'", "type_str / initializer_str (char)");
    for (int i = -128; i <= 127; i++) {
        char c = static_cast<char>(i);
        check(repr(c) == naive_char_repr(c), "repr(char) for all values");
    }

    // 文字列
    {
        const char* s = "abc";
        check(repr(s) == "\"abc\"" && type_str(s) == "char*" && initializer_str(s) == "\"abc\"", "const char*");
    }
    CHECK_REPR(std::string("abc"), std::string{"abc"});
    CHECK_REPR(std::string(), std::string{""});
    check(type_str(std::string()) == "std::string" && initializer_str(std::string("x")) == "\"x\"", "type_str / initializer_str (string)");

    // コンテナ
    CHECK_REPR((std::vector<int>{1, 2, 3}), std::vector<int>{1, 2, 3});
    CHECK_REPR(std::vector<int>(), std::vector<int>{});
    CHECK_REPR((std::vector<std::vector<long long>>{{1, 2}, {}}), std::vector<std::vector<long long>>{{1ll, 2ll}, {}});
    CHECK_REPR((std::set<int>{3, 1, 2}), std::set<int>{1, 2, 3});
    CHECK_REPR((std::pair<int, std::string>{1, "a"}), std::pair<int, std::string>{1, "a"});
    CHECK_REPR((std::pair<char, double>{'x', 0.5}), std::pair<char, double>{'x', 0.500000});
    CHECK_REPR((std::map<int, char>{{2, 'b'}, {1, 'a'}}), std::map<int, char>{{1, 'a'}, {2, 'b'}});
    CHECK_REPR((std::map<std::string, std::vector<int>>{{"k", {1}}}), std::map<std::string, std::vector<int>>{{"k", {1}}});
    CHECK_REPR((std::array<int, 3>{1, 2, 3}), std::array<int, 3>{1, 2, 3});
    CHECK_REPR((std::vector<std::pair<int, unsigned>>{{1, 2u}}), std::vector<std::pair<int, unsigned int>>{{1, 2u}});
    check(type_str(std::vector<std::set<long long>>()) == "std::vector<std::set<long long>>", "type_str (nested)");
    check(initializer_str(std::vector<int>{1, 2}) == "{1, 2}", "initializer_str (vector)");

    // repr / type_str / initializer_str をメンバ関数に持つ型 (Range)
    CHECK_REPR(Range(0, 10, 2), Range(0, 10, 2));
    CHECK_REPR((std::vector<Range>{Range(0, 3, 1)}), std::vector<Range>{{0, 3, 1}});
    check(type_str(Range(5)) == "Range" && initializer_str(Range(1, 5, 2)) == "{1, 5, 2}", "Range");

    // メンバ関数を持たない型は "T" と "{}"
    check(type_str(Plain{}) == "T" && initializer_str(Plain{}) == "{}" && repr(Plain{}) == "T{}", "Plain");
    // initializer_str だけを持つ型
    check(repr(OnlyInit{7}) == "T{7}" && initializer_str(std::vector<OnlyInit>{{1}, {2}}) == "{{1}, {2}}", "OnlyInit");

    // ランダム: 整数の vector
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 5;
        std::vector<long long> v(n);
        std::string expect = "std::vector<long long>{";
        for (int i = 0; i < n; i++) {
            v[i] = static_cast<long long>(rng() % 2001) - 1000;
            expect += (i ? ", " : "") + std::to_string(v[i]) + "ll";
        }
        expect += "}";
        check(repr(v) == expect, "repr(vector<long long>) (random)");
    }

    // DEBUG(x) は std::cerr に "x = repr(x)" を出力する
    {
        std::ostringstream buf;
        std::streambuf* old = std::cerr.rdbuf(buf.rdbuf());
        std::vector<int> xs{1, 2};
        DEBUG(xs);
        std::cerr.rdbuf(old);
        check(buf.str() == "xs = std::vector<int>{1, 2}\n", "DEBUG");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
