/*
 *  20150912L
 *
 *  class matrix
 *
 *  模板参数：
 *  matrix < _Tp>
 *    _Tp : 限定元素类型
 *
 *  成员变量：
 *  m_data : std::vector<_Tp>
 *    存储空间
 *  m_h : size_type;
 *    矩阵高度
 *  m_w : size_type;
 *    矩阵宽度
 *
 *  构造函数：
 *  matrix(size_type __h, size_type __w)
 *    构造高度为__h，宽度为__w的矩阵
 *  static identity(size_type __n) : _Self
 *    构造高度为__n的单位矩阵
 *  static identity(const _Self& __x) : _Self
 *    构造高度与__x相同的单位矩阵
 *
 *  职能：
 *  height() const : size_type
 *    获得矩阵高度
 *
 *  width() const : size_type
 *    获得矩阵宽度
 *
 *  元素访问：
 *  operator [i][j] : value_type&
 *    获得第i行第j列的元素
 *
 *  操作符：
 *  operator + - * += -= *= 运算
 *  operator << 输出
 *
 */
