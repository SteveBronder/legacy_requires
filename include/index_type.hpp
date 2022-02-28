#ifndef LEGACY_REQUIRES_INDEX_TYPE_HPP
#define LEGACY_REQUIRES_INDEX_TYPE_HPP


#include <legacy_requires/is_eigen.hpp>
#include <legacy_requires/is_vector.hpp>
#include <legacy_requires/require_generics.hpp>
#include <type_traits>
#include <vector>

namespace legacy {


/** \ingroup type_trait
 * Primary template class for the metaprogram to compute the index
 * type of a container.
 *
 * Only the specializations have behavior that can be used, and
 * all implement a typedef <code>type</code> for the type of the
 * index given container <code>T</code>.
 *
 * @tparam T type of container.
 */
template <typename T, typename = void>
struct index_type {};

/** \ingroup type_trait
 * Specialization of index_type for pointers.
 *
 * @tparam T type of container.
 */
template <typename T>
struct index_type<T, std::enable_if_t<std::is_pointer<T>::value>> {
  using type = int;
};

template <typename T>
using index_type_t = typename index_type<T>::type;

/** \ingroup type_trait
 * Template metaprogram class to compute the type of index for a
 * standard vector.
 *
 * @tparam T type of elements in standard vector.
 */
template <typename T>
struct index_type<T, require_std_vector_t<T>> {
  using type = typename std::decay_t<T>::size_type;
};

/** \ingroup type_trait
 * Template metaprogram defining typedef for the type of index for
 * an Eigen matrix, vector, or row vector.
 *
 * @tparam T type of matrix.
 */
template <typename T>
struct index_type<T, require_eigen_t<T>> {
  using type = typename std::decay_t<T>::Index;
};



}  // namespace legacy

#endif
