#ifndef LEGACY_REQUIRES_IS_BASE_POINTER_CONVERTIBLE_HPP
#define LEGACY_REQUIRES_IS_BASE_POINTER_CONVERTIBLE_HPP

#include <legacy_requires/require_helpers.hpp>
#include <type_traits>
#include <utility>

namespace legacy {

/**
 * Checks if a type's pointer is convertible to a templated base type's pointer.
 * If the arbitrary function
 * ```
 * std::true_type f(const Base<Derived>*)
 * ```
 * is well formed for input `std::declval<Derived*>() this has a member
 *  value equal to `true`, otherwise the value is false.
 * @tparam Base The templated base type for valid pointer conversion.
 * @tparam Derived The type to check
 * @ingroup type_trait
 */
template <template <typename> class Base, typename Derived>
struct is_base_pointer_convertible {
  static std::false_type f(const void *);
  template <typename OtherDerived>
  static std::true_type f(const Base<OtherDerived> *);
  enum {
    value
    = decltype(f(std::declval<std::remove_reference_t<Derived> *>()))::value
  };
};

}  // namespace legacy

#endif
