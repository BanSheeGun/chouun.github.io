/*
 *  20150823L
 *
 *  struct fenwick_tree
 *
 *  模板参数：
 *  fenwick_tree < _Tp, _Op = std::plus<_Tp> >
 *    _Tp : 限定元素类型
 *    _Op : 限定元素运算
 *
 *  成员变量：
 *  m_data : std::vector<_Tp>
 *    存储空间
 *  m_func : _Op
 *    运算仿函数
 *
 *  职能：
 *  build(value_type* p_data, size_type p_size) : void
 *    以p_data为源数据地址, p_size为元素数量, 建立树状数组
 *
 *  build(size_type p_size) : void
 *    以p_size为元素数量, 建立空树状数组
 *
 *  元素访问：
 *  query(size_type __x, value_type __res = value_type()) : value_type
 *    获得前__x个元素的统计, 以__res为底
 *
 *  修改符：
 *  update(size_type __x, value_type __v) : void
 *    第__x个元素的值修改__v
 *
 */
