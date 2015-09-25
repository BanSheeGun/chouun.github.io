/*
 *  20150926L
 *
 *  struct discrete
 *
 *  成员变量：
 *  m_data : std::vector<_Tp>
 *    存储空间
 *
 *  职能：
 *  build() : void
 *    对存储空间中的数据进行排序去重
 *
 *  clear() : void
 *    清空存储空间中的数据
 *
 *  size() : size_type
 *    返回存储空间的大小
 *
 *  reserve(size_type __n) : void
 *    保证存储空间容量不小于__n，预先使用能提高效率
 *
 *  修改符：
 *  insert(_Tp __x) : void
 *    插入元素 __x
 *
 *  template <typename _InputIterator>
 *  insert(_InputIterator first, _InputIterator last) : void
 *    插入元素 [first,last)
 *
 *  元素访问：
 *  query(const _Tp& __x) : size_type
 *    查询元素 __x 的排行
 *
 *  operator [] (size_type __x) const : _Tp
 *    查询排行 __x 的元素
 *
 */
