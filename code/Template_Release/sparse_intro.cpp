/*
 *  20150808L
 *
 *  模板参数：
 *  sparse_table <_Tp, _Compare>
 *    _Tp : 限定元素类型
 *    _Compare : 比较函数
 *
 *  成员变量：
 *  m_data : vector< vector<_Tp*> >
 *    存储空间
 *
 *  m_comp : _Compare
 *    比较函数实例
 *
 *  职能：
 *  clear() : void
 *    清空存储空间
 *
 *  元素访问：
 *  query(size_t first, size_t last) const : _Tp
 *    查询区间[first,last]的最值
 *
 *  修改符：
 *  build(_Tp* p_data, size_t p_size) : void
 *    以p_data为源数据地址, p_size为元素数量
 *
 */
