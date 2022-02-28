# legacy_requires
A C++14 header only library for a pseudo version of requires syntax

Still a work in progress porting, but the concept is that you would like to use
perfect forwarding or generatic templates, but you don't have access to C++20.


So for example her we have a basic multiply function.

```cpp
template <typename T1, typename T2>
auto multiply(T1&& x, T2&& y) {
  return std::forward<T1>(x) * std::forward<T2>(y);
}
```

But for some reason when the program calls `multiply` with matrices from the
 `Eigen` library it would be better if the definition used lazy products such as.

```cpp
template <typename T1, typename T2>
auto multiply(T1&& x, T2&& y) {
  return std::forward<T1>(x).lazyProduct(std::forward<T2>(y));
}
```

The `legacy::requires` namespace comes with structs that are just specialized
 `enable_if_t<>`s. We can use these like in the below to have multiple
 definitions of multiply that still have generic templates and can use
 perfect forwarding.

```cpp
template <typename Mat1, typename Mat2, legacy::require::all_not_eigen_t<Mat1, Mat2>* = nullptr>
auto multiply(T1&& x, T2&& y) {
  return std::forward<T1>(x) * std::forward<T2>(y);
}

template <typename Mat1, typename Mat2, legacy::require::all_eigen_t<Mat1, Mat2>* = nullptr>
auto multiply(T1&& x, T2&& y) {
  return std::forward<T1>(x).lazyProduct(std::forward<T2>(y));
}
```


## TODOs

- [ ] Port tests and docs
 
