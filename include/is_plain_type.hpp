#ifndef LEGACY_REQUIRES_IS_PLAIN_TYPE_HPP
#define LEGACY_REQUIRES_IS_PLAIN_TYPE_HPP

#include <legacy_requires/require_helpers.hpp>
#include <legacy_requires/plain_type.hpp>
#include <type_traits>

namespace legacy {
/** \ingroup type_trait
 * Checks whether the template type `T` is an assignable type. This is used
 * to detect whether a type is an Eigen matrix expression.
 */
template <typename S>
using is_plain_type = std::is_same<std::decay_t<S>, plain_type_t<S>>;

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(plain_type, is_plain_type, require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(plain_type, is_plain_type, require_eigens_types);

}  // namespace legacy
#endif
