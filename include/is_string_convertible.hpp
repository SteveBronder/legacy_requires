#ifndef LEGACY_REQUIRES_IS_STRING_CONVERTIBLE_HPP
#define LEGACY_REQUIRES_IS_STRING_CONVERTIBLE_HPP

#include <legacy_requires/require_helpers.hpp>
#include <type_traits>
#include <string>

namespace legacy {

/**
 * Deduces whether type is convertible to string
 * @tparam T type to check
 * @ingroup type_trait
 */
template <typename T>
using is_string_convertible = std::is_convertible<T, std::string>;

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(string_convertible, is_string_convertible, require_std);
LEGACY_REQUIRE_ADD_REQUIRE_UNARY_INNER(string_convertible, is_string_convertible,
                             require_std);

}  // namespace legacy

#endif
