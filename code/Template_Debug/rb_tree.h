// Name : red-black tree 红黑树
// Copyright : fateud.com

#ifndef RB_TREE_H_
#define RB_TREE_H_
#define RB_TREE_H_VERSION 20150926L

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace csl
{
  typedef __gnu_pbds::rb_tree_tag rb_tree_tag;
  typedef __gnu_pbds::null_type null_type;

  template <typename Key, typename Mapped = null_type, typename Cmp_Fn = std::less<Key>,
      template<typename Node_CItr, typename Node_Itr, typename Cmp_Fn_,
      typename _Alloc_> class Node_Update = __gnu_pbds::null_node_update>
  struct rb_tree :
      public __gnu_pbds::tree<Key, Mapped, Cmp_Fn,
      rb_tree_tag, Node_Update, std::allocator<char> >
  {
    rb_tree() { }
    virtual ~rb_tree() { }
  };

} // namespace csl

#endif /* RB_TREE_H_ */
