//@ Including Header
#include <csl_std.h>

//@ Main Function
void Main() {
  // ...
}

// Anti Stack Overflow
int main() {
  int _size = 16 << 20; // MB : << 20 ; KB : << 10 ;
  char* _data = (char*)malloc(_size) + _size;
#if __x86_64__ || __ppc64__ || _WIN64
  __asm__ __volatile__("movq %0,%%rsp\n pushq $_exit\n"::"r"(_data));
#else // 64-bit
  __asm__ __volatile__("movl %0,%%esp\n pushq $_exit\n"::"r"(_data));
#endif // 32-bit
  Main();
  exit(0);
}
