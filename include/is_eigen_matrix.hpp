#ifndef LEGACY_REQUIRES_IS_EIGEN_MATRIX_DYNAMIC_HPP
#define LEGACY_REQUIRES_IS_EIGEN_MATRIX_DYNAMIC_HPP
#include <legacy_requires/bool_constant.hpp>
#include <legacy_requires/conjunction.hpp>
#include <legacy_requires/disjunction.hpp>
#include <legacy_requires/is_base_pointer_convertible.hpp>
#include <legacy_requires/require_helpers.hpp>
#include <type_traits>

namespace legacy {
#ifndef LEGACY_REQUIRES_EIGEN_REQUIRES
template <typename T>
struct is_eigen_matrix_dynamic : std::false_type {};
#else
namespace internal {

/**
 * Underlying implimenation to check if an Eigen matrix has rows or cols not
 *  equal to 1.
 */
template <typename T, bool>
struct is_eigen_matrix_dynamic_impl : std::false_type {};

template <typename T>
struct is_eigen_matrix_dynamic_impl<T, false> : std::false_type {};

template <typename T>
struct is_eigen_matrix_dynamic_impl<T, true>
    : bool_constant<!(T::RowsAtCompileTime == 1 || T::ColsAtCompileTime == 1)> {
};

}  // namespace internal

/**
 * Checks whether type T is derived from Eigen::MatrixBase and has columns and
 * rows not equal to 1. If true this will have a
 * static member function named value with a type of true, else value is false.
 * @tparam T Type to check if it is derived from `MatrixBase` and has more than
 * 1 compile time row and column.
 * @ingroup type_trait
 */
template <typename T>
struct is_eigen_matrix_dynamic
    : bool_constant<internal::is_eigen_matrix_dynamic_impl<
          std::decay_t<T>,
          is_base_pointer_convertible<Eigen::MatrixBase, T>::value>::value> {};


#endif

LEGACY_REQUIRE_ADD_REQUIRE_UNARY(eigen_matrix_dynamic, is_eigen_matrix_dynamic,
                       require_eigens_types);
LEGACY_REQUIRE_ADD_REQUIRE_CONTAINER(eigen_matrix_dynamic, is_eigen_matrix_dynamic,
                           require_eigens_types);

}  // namespace legacy

#endif
