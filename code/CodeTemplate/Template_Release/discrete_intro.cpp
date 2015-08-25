/*
 *  20150822L
 *
 *  struct discrete
 *
 *  成员变量：
 *  m_data : std::vector<value_type>
 *    存储空间
 *
 *  职能：
 *  build() : void
 *    对存储空间中的数据进行排序去重
 *
 *  clear() : void
 *    清空存储空间中的数据
 *
 *  size() : std::size_t
 *    返回存储空间的大小
 *
 *  修改符：
 *  insert(value_type __x) : void
 *    插入元素 __x
 *
 *  template <typename _InputIterator>
 *  insert(_InputIterator first, _InputIterator last) : void
 *    插入元素 [first,last)
 *
 *  元素访问：
 *  query(value_type __x) : std::size_t
 *    查询元素 __x 的排行
 *
 */
