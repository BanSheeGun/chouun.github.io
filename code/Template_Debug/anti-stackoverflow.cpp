//@ Including Header
#include <csl_std.h>

//@ Main Function
void Main() {
  // ...
}

// Anti Stack Overflow
int main() {
#ifdef _ANTI_STACKOVERFLOW
  int _size = 16 << 20; // KB(<< 10), MB(<< 20).
  char* _data = (char*)malloc(_size) + _size;
  __asm__ __volatile__(
#if __x86_64__ || __ppc64__ || _WIN64
      "movq  %0, %%rsp\n pushq $_exit\n"
#else // 64-bit
      "movl  %0, %%esp\n pushl $_exit\n"
#endif // 32-bit
      :: "r"(_data));
#endif // _ANTI_STACKOVERFLOW
  Main();
  exit(0);
}
