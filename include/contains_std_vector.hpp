#ifndef LEGACY_REQUIRES_CONTAINS_STD_VECTOR_HPP
#define LEGACY_REQUIRES_CONTAINS_STD_VECTOR_HPP

#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/disjunction.hpp>
#include <legacy_requires/is_vector.hpp>
#include <type_traits>

namespace legacy {
/** \ingroup type_trait
 * Checks if any types are std vectors.
 */
template <typename... Ts>
using contains_std_vector = math::disjunction<is_std_vector<Ts>...>;
}  // namespace legacy

#endif
