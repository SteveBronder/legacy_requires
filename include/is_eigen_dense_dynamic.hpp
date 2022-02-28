#ifndef LEGACY_REQUIRES_IS_EIGEN_DENSE_DYNAMIC_HPP
#define LEGACY_REQUIRES_IS_EIGEN_DENSE_DYNAMIC_HPP
#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/is_eigen_matrix.hpp>
#include <legacy_requires/is_eigen_dense_base.hpp>
#include <legacy_requires/is_base_pointer_convertible.hpp>
#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {
#ifndef LEGACY_REQUIRES_EIGEN_REQUIRES

template <typename T>
using is_eigen_dense_dynamic = legacy::internal::is_eigen_matrix_dynamic<T>;

#else

/**
 * Checks whether type T is derived from Eigen::DenseBase and has dynamic rows
 * and columns. If true this will have a static member function named value with
 * a type of true, else value is false.
 * @tparam T Type to check
 * @ingroup type_trait
 */
template <typename T>
using is_eigen_dense_dynamic = stan::internal::is_eigen_matrix_dynamic_impl<
    std::decay_t<T>, stan::is_eigen_dense_base<std::decay_t<T>>::value>;


#endif
LEGACY_REQUIRE_ADD_REQUIRE_UNARY(eigen_dense_dynamic, is_eigen_dense_dynamic,
                       require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(eigen_dense_dynamic, is_eigen_dense_dynamic,
                           require_eigens_types);
}  // namespace legacy

#endif
