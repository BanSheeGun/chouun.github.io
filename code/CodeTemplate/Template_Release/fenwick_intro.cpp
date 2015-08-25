/*
 *  20150821L
 *
 *  struct fenwick_tree
 *
 *  模板参数：
 *  fenwick_tree <_Tp>
 *    _Tp : 限定元素类型
 *
 *  成员变量：
 *  m_data : std::vector<_Tp>
 *    存储空间
 *
 *  职能：
 *  build(_Tp* p_data, size_t p_size) : void
 *    以p_data为源数据地址, p_size为元素数量, 建立树状数组
 *
 *  build(size_t p_size) : void
 *    以p_size为元素数量, 建立空树状数组
 *
 *  元素访问：
 *  query(int __x) const : _Tp
 *    获得前__x个元素之和
 *
 *  修改符：
 *  update(int __x, _Tp __v) : void
 *    第__x个元素的值增加__v
 *
 */
