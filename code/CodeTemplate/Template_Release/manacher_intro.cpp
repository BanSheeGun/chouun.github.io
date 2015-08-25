/*
 *  20150821L
 *
 *  class manacher
 *
 *  职能：
 *  build(const key_type* __src) : void
 *    __src拓展为__dist, 长度[0,2*len-1), 偶数位为源字符
 *    对__dist进行匹配
 *
 *  query() : value_type
 *    获取最长回文子串的长度
 *
 *  元素访问：
 *  at(size_type __x) : value_type
 *    获取以第__x位为中心的最长回文子串的长度(边界保护)
 *
 *  operator [] (size_type __x) : value_type
 *    获取以第__x位为中心的最长回文子串的长度
 *
 */
