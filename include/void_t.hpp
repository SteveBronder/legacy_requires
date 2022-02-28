#ifndef LEGACY_REQUIRES_VOID_T_HPP
#define LEGACY_REQUIRES_VOID_T_HPP

#include <legacy_requires/bool_constant.hpp>
#include <type_traits>

namespace legacy {

// Dummy struct that has a type void
template <typename... Ts>
struct make_void {
  typedef void type;
};

/**
 * Utility metafunction that maps a sequence of any types to the type void
 * This metafunction is used in template metaprogramming to detect ill-formed
 * types or the validity of an expression in an SFINAE context:
 */
template <typename... Ts>
using void_t = typename make_void<Ts...>::type;

}  // namespace legacy
#endif
