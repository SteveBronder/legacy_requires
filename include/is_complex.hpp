#ifndef LEGACY_REQUIRES_IS_COMPLEX_HPP
#define LEGACY_REQUIRES_IS_COMPLEX_HPP

#include <legacy_requires/scalar_type.hpp>
#include <legacy_requires/value_type.hpp>
#include <legacy_requires/require_helpers.hpp>

#include <complex>
#include <type_traits>

namespace legacy {
namespace internal {

/**
 * Provides a member constant `value` which is equal to `true` if
 * `T` is an instance of `std::complex` and `false` otherwise.
 *
 * @tparam T type to check
 * @ingroup type_trait
 */
template <typename T>
struct is_complex_impl : std::false_type {};

template <typename... Ts>
struct is_complex_impl<std::complex<Ts...>> : std::true_type {};

}  // namespace internal

/**
 * If `T` is an arithmetic type (that is, an instance of
 * `std::complex`) or a cv-qualified version thereof, provides the
 * member constant `value` equal `true`; for any other type the value is
 * `false`.
 *
 * @tparam T type to check
 * @ingroup type_trait
 */
template <typename T, typename = void>
struct is_complex : std::false_type {};

template <typename T>
struct is_complex<
    T, std::enable_if_t<internal::is_complex_impl<std::decay_t<T>>::value>>
    : std::true_type {};

/** \ingroup type_trait
 *
 * Template metaprogram defining the scalar type for values
 * stored in a complex number.
 *
 * @tparam T type of complex number
 */
template <typename T>
struct scalar_type<T, std::enable_if_t<is_complex<T>::value>> {
  using type = std::complex<typename std::decay_t<T>::value_type>;
};

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(complex, is_complex, require_stan_scalar_complex);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(complex, is_complex, require_stan_scalar_complex);

}  // namespace legacy

#endif
