#if false

//@ Including Header

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";

  }
  return 0;
}

//@ Anti StackOverFlow
int main() {
  size_t _size=16<<20; // KB(<<10), MB(<<20).
  char* _data=(char*)malloc(_size)+_size;
#if __x86_64__ || __ppc64__ || _WIN64
  __asm__ __volatile__("movq %0,%%rsp\n pushq $_exit\n" ::"r"(_data));
#else
  __asm__ __volatile__("movl %0,%%esp\n pushl $_exit\n" ::"r"(_data));
#endif
  exit(Main());
}

#endif /* false */
