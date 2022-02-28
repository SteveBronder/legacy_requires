#ifndef LEGACY_REQUIRES_STATIC_SELECT_HPP
#define LEGACY_REQUIRES_STATIC_SELECT_HPP

#include <type_traits>
#include <utility>

namespace legacy {


/**
 * Returns one of the arguments that can be of different type, depending on the
 * compile time condition. Can often be used in place of c++17 `if constexpr`.
 *
 * @tparam Condition condition
 * @tparam T1 type of the first argument
 * @tparam T2 type of the second argument
 *
 * @param a first argument; returned if the `Condition` is true
 * @param b second argument; returned if the `Condition` is false
 * @return One of the arguemtns, depending on the `Condition`
 */
template <bool Condition, typename T1, typename T2,
          std::enable_if_t<Condition>* = nullptr>
T1 static_select(T1&& a, T2&& b) {
  return std::forward<T1>(a);
}

template <bool Condition, typename T1, typename T2,
          std::enable_if_t<!Condition>* = nullptr>
T2 static_select(T1&& a, T2&& b) {
  return std::forward<T2>(b);
}


}  // namespace legacy

#endif  // STATIC_SELECT_HPP
