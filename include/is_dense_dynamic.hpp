#ifndef LEGACY_REQUIRES_IS_DENSE_DYNAMIC_HPP
#define LEGACY_REQUIRES_IS_DENSE_DYNAMIC_HPP
#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/is_base_pointer_convertible.hpp>
#include <legacy_requires/is_eigen_matrix.hpp>
#include <legacy_requires/is_eigen_dense_base.hpp>
#include <legacy_requires/is_eigen_dense_dynamic.hpp>
#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {

#ifndef LEGACY_REQUIRES_EIGEN_REQUIRES
template <typename T>
struct is_dense_dynamic : std::false_type {};

namespace internal {
template <typename T, typename = void>
struct is_dense_dynamic_impl : std::false_type {};
}
#else
namespace internal {
template <typename T, typename = void>
struct is_dense_dynamic_impl : std::false_type {};

template <typename T>
struct is_dense_dynamic_impl<T,
                             require_t<is_eigen_dense_dynamic<std::decay_t<T>>>>
    : std::true_type {};

}  // namespace internal

/**
 * Checks whether type T is derived from Eigen::DenseBase and has dynamic rows
 * and columns or is a `var_value<>` whose inner type satisfies the conditions
 * above. If true this will have a static member function named value with
 * a type of true, else value is false.
 * @tparam T Type to check
 * @ingroup type_trait
 */
template <typename T>
using is_dense_dynamic = internal::is_dense_dynamic_impl<std::decay_t<T>>;


#endif
LEGACY_REQUIRE_ADD_REQUIRE_UNARY(dense_dynamic, is_dense_dynamic, require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(dense_dynamic, is_dense_dynamic,
                           require_eigens_types);
}  // namespace legacy

#endif
