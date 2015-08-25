// Name : fastio 快速读入
// Copyright : fateud.com

#ifndef FASTIO_H_
#define FASTIO_H_
#define FASTIO_H_VERSION

#include <stdio.h>
#include <ctype.h>

#ifndef BUF_SIZE
#define BUF_SIZE (20 << 20) // KB(<< 10), MB(<< 20).
#endif

namespace csl
{
  namespace fastio
  {
    char BUF[BUF_SIZE];

    char* ptr;
    char* end;

    inline void
    build()
    {
      ptr = BUF;
      end = BUF + fread(BUF, sizeof(char), BUF_SIZE, stdin);
    }

    inline bool
    empty()
    {
      for (char* __x = ptr; __x < end; ++__x) {
        if (isspace(*__x)) continue;
        if (isalnum(*__x)) return false;
      }
      return true;
    }

    template <typename _Tp>
    inline void
    nextInt(_Tp& __x)
    {
      __x = _Tp();
      for (register bool __vf = 0, __sf = 0; true; ++ptr)
      {
        if (*ptr >= '0' && *ptr <= '9')
          __x = (__x << 3) + (__x << 1) + *ptr - '0', __vf = 1;
        else if (__vf)
        {
          if (__sf) __x = -__x;
          break;
        }
        else if (*ptr == '-') __sf = true;
      }
    }

    inline void
    nextChar(char& __x)
    { __x = *ptr, ++ptr; }

    inline void
    nextStr(char* __s)
    {
      for (; *ptr; ++__s, ++ptr) *__s = *ptr;
      *__s = 0;
    }

  }; // namespace fastio

} // namespace csl

#endif /* FASTIO_H_ */
