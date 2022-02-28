// This is not used anywhere. Should it be deleted?
#ifndef LEGACY_REQUIRES_SCALAR_TYPE_PRE_HPP
#define LEGACY_REQUIRES_SCALAR_TYPE_PRE_HPP

#include <legacy_requires/is_vector.hpp>
#include <legacy_requires/value_type.hpp>

namespace legacy {
namespace internal {
template <bool is_vec, typename T, typename T_container>
struct scalar_type_helper_pre {
  using type = T_container;
};

template <typename T, typename T_container>
struct scalar_type_helper_pre<true, T, T_container> {
  using type = typename scalar_type_helper_pre<
      is_vector<typename value_type<T>::type>::value,
      typename value_type<T>::type,
      typename value_type<T_container>::type>::type;
};
}  // namespace internal

/** \ingroup type_trait
 * Metaprogram structure to determine the type of first container of
 * the base scalar type of a template argument.
 *
 * @tparam T Type of object.
 */
template <typename T>
struct scalar_type_pre {
  using type = typename internal::scalar_type_helper_pre<
      is_vector<typename value_type<T>::type>::value,
      typename value_type<T>::type, T>::type;
};

}  // namespace legacy
#endif
