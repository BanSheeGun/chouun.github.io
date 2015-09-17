/*
 *  20150904L
 *
 *  template <typename _Tp>
 *  struct less : public std::binary_function<_Tp, _Tp, _Tp>
 *    返回较小值
 *
 *  template <typename _Tp>
 *  struct greater : public std::binary_function<_Tp, _Tp, _Tp>
 *    返回较大值
 *
 *  namespace euler
 *    欧拉函数
 *
 *  euler::phi : std::vector<int>
 *    获取欧拉函数
 *
 *  euler::div : std::vector<int>
 *    获取最小因子
 *
 *  euler::prm : std::vector<int>
 *    获得素数序列
 *
 *  euler::build(int __n) : void
 *    欧拉筛法, [0,__n)
 *    初始化欧拉函数/最小因子/素数序列
 *
 *  template <typename _Tp, typename _Comp >
 *  isomorph_min(_Tp* data, std::size_t size, _Comp comp) : std::size_t
 *    求data的循环最大/小同构中下标最小的
 *
 *  template <typename _Tp, typename _Comp >
 *  isomorph_max(_Tp* data, std::size_t size, _Comp comp) : std::size_t
 *    求data的循环最大/小同构中下标最大的
 *
 */
