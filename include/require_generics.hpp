#ifndef LEGACY_REQUIRES_REQUIRE_GENERICS_HPP
#define LEGACY_REQUIRES_REQUIRE_GENERICS_HPP

#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {

LEGACY_REQUIRE_ADD_REQUIRE_BINARY(same, std::is_same, require_std);
LEGACY_REQUIRE_ADD_REQUIRE_BINARY_INNER(same, std::is_same, require_std);

LEGACY_REQUIRE_ADD_REQUIRE_BINARY(convertible, std::is_convertible, require_std);
LEGACY_REQUIRE_ADD_REQUIRE_BINARY_INNER(convertible, std::is_convertible, require_std);
LEGACY_REQUIRE_ADD_REQUIRE_BINARY(assignable, std::is_assignable, require_std);
LEGACY_REQUIRE_ADD_REQUIRE_BINARY_INNER(assignable, std::is_assignable, require_std);

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(arithmetic, std::is_arithmetic,
                       require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(arithmetic, std::is_arithmetic,
                             require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY(floating_point, std::is_floating_point,
                       require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(floating_point, std::is_floating_point,
                             require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY(integral, std::is_integral, require_stan_scalar_real);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(integral, std::is_integral,
                             require_stan_scalar_real);

}  // namespace legacy
#endif
