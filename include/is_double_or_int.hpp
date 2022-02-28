#ifndef LEGACY_REQUIRES_IS_DOUBLE_OR_INT_HPP
#define LEGACY_REQUIRES_IS_DOUBLE_OR_INT_HPP

#include <legacy_requires/require_helpers.hpp>
#include <legacy_requires/scalar_type.hpp>
#include <legacy_requires/value_type.hpp>
#include <type_traits>

namespace legacy {
/**
 * Checks if decayed type is a double or integer
 * @tparam The type to check
 * @ingroup type_trait
 */
template <typename T>
struct is_double_or_int
    : bool_constant<
          math::disjunction<std::is_same<double, std::decay_t<T>>,
                            std::is_same<int, std::decay_t<T>>>::value> {};

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(double_or_int, is_double_or_int,
                       require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(double_or_int, is_double_or_int,
                             require_stan_scalar_real);

}  // namespace legacy
#endif
