#ifndef LEGACY_REQUIRES_IS_EIGEN_SPARSE_BASE_HPP
#define LEGACY_REQUIRES_IS_EIGEN_SPARSE_BASE_HPP
#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/is_base_pointer_convertible.hpp>
#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {
#ifndef LEGACY_REQUIRES_EIGEN_REQUIRES

/**
 * Check if type derives from `EigenBase`
 * @tparam T Type to check if it is derived from `EigenBase`
 * @tparam Enable used for SFINAE deduction.
 * @ingroup type_trait
 **/
template <typename T>
struct is_eigen_sparse_base : std::false_type {};

#else

/**
 * Checks whether type T is derived from Eigen::SparseMatrixBase.
 * If true this will have a static member function named value with a type
 * of true, else value is false.
 * @tparam T Type to check if it is derived from `SparseMatrixBase`
 * @tparam Enable used for SFINAE deduction.
 * @ingroup type_trait
 */
template <typename T>
struct is_eigen_sparse_base
    : bool_constant<
          is_base_pointer_convertible<Eigen::SparseMatrixBase, T>::value> {};
#endif
LEGACY_REQUIRE_ADD_REQUIRE_UNARY(eigen_sparse_base, is_eigen_sparse_base,
                       require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(eigen_sparse_base, is_eigen_sparse_base,
                           require_eigens_types);

}  // namespace legacy

#endif
