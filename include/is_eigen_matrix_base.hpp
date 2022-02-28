#ifndef LEGACY_REQUIRES_IS_EIGEN_MATRIX_BASE_HPP
#define LEGACY_REQUIRES_IS_EIGEN_MATRIX_BASE_HPP
#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/is_base_pointer_convertible.hpp>
#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {
#ifndef LEGACY_REQUIRES_EIGEN_REQUIRES

template <typename T>
struct is_eigen_matrix_base : std::false_type {};

#else
/**
 * Checks whether type T is derived from Eigen::MatrixBase.
 * If true this will have a static member function named value with a type
 * of true, else value is false.
 * @tparam T Type to check if it is derived from `MatrixBase`
 * @tparam Enable used for SFINAE deduction.
 * @ingroup type_trait
 */
template <typename T>
struct is_eigen_matrix_base
    : bool_constant<is_base_pointer_convertible<Eigen::MatrixBase, T>::value> {
};

#endif

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(eigen_matrix_base, is_eigen_matrix_base,
                       require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(eigen_matrix_base, is_eigen_matrix_base,
                           require_eigens_types);

}  // namespace legacy

#endif
