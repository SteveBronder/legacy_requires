#ifndef LEGACY_REQUIRES_IS_CONTAINER_HPP
#define LEGACY_REQUIRES_IS_CONTAINER_HPP

#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/disjunction.hpp>
#include <legacy_requires/is_eigen.hpp>
#include <legacy_requires/is_vector.hpp>
#include <legacy_requires/scalar_type.hpp>
#include <legacy_requires/value_type.hpp>
#include <legacy_requires/require_helpers.hpp>

#include <type_traits>

namespace legacy {

/**
 * Deduces whether type is eigen matrix or standard vector.
 * @tparam Container type to check
 */
template <typename Container>
using is_container = bool_constant<
    math::disjunction<is_eigen<Container>, is_std_vector<Container>>::value>;

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(container, is_container, general_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(container, is_container, general_types);

}  // namespace legacy

#endif
