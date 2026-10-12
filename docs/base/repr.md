---
title: 出力をそのままコンストラクタに使える文字列化 (repr)
documentation_of: //src/base/repr.hpp
---

値を、型名つきの C++ の初期化式のような文字列にします。デバッグ出力で、値の中身と型をまとめて確認できます。

```cpp
repr(std::vector<int>{1, 2});           // "std::vector<int>{1, 2}"
repr(std::make_pair(1, 'x'));           // "std::pair<int, char>{1, 'x'}"
repr(3LL);                              // "3ll"
int n = 3;
DEBUG(n);                               // 標準エラー出力に "n = 3"
```

## 関数・マクロ

| 名前 | 説明 |
|---|---|
| `repr(x)` | 型名と初期化子を合わせた文字列 |
| `type_str(x)` | 型名の文字列 (`"std::vector<int>"` など) |
| `initializer_str(x)` | 初期化子の部分の文字列 (`"{1, 2}"` など) |
| `DEBUG(x)` | 標準エラー出力に `x = repr(x)` を出す |

## 対応している型

| 型 | `repr` の例 |
|---|---|
| `int` / `long` / `long long` | `3` / `3l` / `3ll` |
| `unsigned int` / `unsigned long` / `unsigned long long` | `3u` / `3ul` / `3ull` |
| `float` / `double` / `long double` | `1.500000f` / `1.500000` / `1.500000l` (`std::to_string` を使うので小数点以下 6 桁) |
| `char` | `'a'`、`'\n'` などのエスケープ、表示できない文字は 8 進数 |
| `const char*` / `std::string` | `"abc"` / `std::string{"abc"}` |
| `std::vector` / `std::set` / `std::array` / `std::map` / `std::pair` | `std::vector<int>{1, 2}` など、要素も再帰的に文字列化 |
| `repr()` などのメンバ関数を持つ型 | そのメンバ関数の結果 ([Range](range.hpp) など) |
| それ以外 | `T{}` |

自作の型でも、メンバ関数 `repr()`、または `type_str()` と `initializer_str()` を定義すれば対応できます。
