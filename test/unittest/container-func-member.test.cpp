#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// container_func.hpp の関数が、コンテナが同名のメンバ関数を持つときはそちらを呼ぶことを確かめる
// 問題の入力は使わず、すべて期待どおりなら Hello World を出力する

#include <iostream>
#include <vector>

#include "../../src/utility/container_func.hpp"

// 要素は {3, 1, 2} だが、メンバ関数は目印の値を返す
struct Base {
    using value_type = int;
    std::vector<int> v{3, 1, 2};
    auto begin() const { return v.begin(); }
    auto end() const { return v.end(); }
};
struct WithMax : Base {
    int max() const { return 100; }
};
struct WithMin : Base {
    int min() const { return -100; }
};
struct WithMaxMin : Base {
    int max() const { return 100; }
    int min() const { return -100; }
};
struct WithSum : Base {
    int sum() const { return 1000; }
};
struct WithProduct : Base {
    int product() const { return 2000; }
};
struct WithProductXor : Base {
    int product_xor() const { return 3000; }
};
struct WithSorted : Base {
    std::vector<int> sorted() const { return {42}; }
};
struct WithReversed : Base {
    std::vector<int> reversed() const { return {43}; }
};

int main() {
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond) {
            std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };

    check(max(WithMax{}) == 100, "max はメンバ関数 max を呼ぶ");
    check(min(WithMax{}) == 1, "max だけを持つ型の min は要素の最小値");
    check(min(WithMin{}) == -100, "min はメンバ関数 min を呼ぶ");
    check(max(WithMin{}) == 3, "min だけを持つ型の max は要素の最大値");
    check(max(WithMaxMin{}) == 100 && min(WithMaxMin{}) == -100, "max と min を両方持つ型");
    check(sum(WithSum{}) == 1000, "sum はメンバ関数 sum を呼ぶ");
    check(product(WithProduct{}) == 2000, "product はメンバ関数 product を呼ぶ");
    check(product_xor(WithProductXor{}) == 3000, "product_xor はメンバ関数 product_xor を呼ぶ");
    check(sorted(WithSorted{}) == std::vector<int>{42}, "sorted はメンバ関数 sorted を呼ぶ");
    check(reversed(WithReversed{}) == std::vector<int>{43}, "reversed はメンバ関数 reversed を呼ぶ");
    check(sum(Base{}) == 6 && product(Base{}) == 6 && product_xor(Base{}) == 0, "メンバ関数を持たない型");

    if (ok) std::cout << "Hello World" << std::endl;
}
