#ifndef LEGACY_REQUIRES_SCALAR_TYPE_HPP
#define LEGACY_REQUIRES_SCALAR_TYPE_HPP


#include <legacy_requires/require_helpers.hpp>
#include <type_traits>
#include <vector>

namespace legacy {

/** \ingroup type_trait
 * Metaprogram structure to determine the base scalar type
 * of a template argument.
 *
 * <p>This base class should be specialized for structured types.</p>
 *
 * @tparam T type of non-container
 */
template <typename T, typename = void>
struct scalar_type {
  using type = std::decay_t<T>;
};

template <typename T>
using scalar_type_t = typename scalar_type<T>::type;

}  // namespace legacy
#endif
