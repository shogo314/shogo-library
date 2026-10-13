---
title: 型特性
documentation_of: //src/utility/traits.hpp
---

ライブラリ内のテンプレートで使う型特性とマクロです。[コンテナに対する関数](container_func.hpp) や [repr](repr.hpp) が、コンテナのメンバ関数の有無で呼び分けるのに使っています。

```cpp
static_assert(is_range_v<std::vector<int>>);
static_assert(has_sum_v<Range>);
template <class T, ENABLE_IF_T(std::is_integral_v<T>)>
T twice(T x) { return x * 2; }
```

## 型特性

| 名前 | 意味 |
|---|---|
| `is_range_v<T>` | `begin`、`end` で走査できるか |
| `is_sorted_container_v<T>` | `std::set` / `std::multiset` か |
| `has_repr_v<T>`、`has_type_str_v<T>`、`has_initializer_str_v<T>` | 同名のメンバ関数 (引数なし) を持つか |
| `has_max_v<T>`、`has_min_v<T>`、`has_sum_v<T>`、`has_product_v<T>`、`has_product_xor_v<T>` | 同上 |
| `has_reversed_v<T>`、`has_sorted_v<T>` | 同上 |
| `has_count_v<T, U>`、`has_find_v<T, U>`、`has_lower_bound_v<T, U>`、`has_upper_bound_v<T, U>` | `U` を引数に取る同名のメンバ関数を持つか |
| `mem_value_type<C>` / `mem_difference_type<C>` | `C::value_type` / `C::difference_type` |

## マクロ

| マクロ | 説明 |
|---|---|
| `ENABLE_IF_T(cond)` | テンプレート引数に書く SFINAE。`std::enable_if_t<cond, std::nullptr_t> = nullptr` になる |
| `HAS_METHOD(f)` | 引数なしのメンバ関数 `f` を持つかを調べる `has_f` / `has_f_v` を定義する |
| `HAS_METHOD_ARG(f)` | 引数を 1 つ取るメンバ関数 `f` を持つかを調べる `has_f` / `has_f_v` を定義する |
