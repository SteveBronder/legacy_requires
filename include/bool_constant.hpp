#ifndef LEGACY_REQUIRES_BOOL_CONSTANT_HPP
#define LEGACY_REQUIRES_BOOL_CONSTANT_HPP

#include <type_traits>

namespace legacy {
/** \ingroup type_trait
 * Alias for structs used for wraps a static constant of bool.
 * @tparam B On true, inherits std::true_type, false is std::false_type
 */
template <bool B>
using bool_constant = std::integral_constant<bool, B>;
}  // namespace legacy

#endif
