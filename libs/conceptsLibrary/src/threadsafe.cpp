#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

#include "threadsafe.h"

void synchronizedHelper() {
  
  static int i = 0;
  // Synchronized blocks are executed under a global lock. Leaving a synchronized block by any means (e.g. reaching the end, jump statement,
  // exception) results in a synchronization with the next block in the total synchronized order. Entering a synchronized block via jump statement
  // is prohibited. A synchronized block can contain any functions.
  synchronized {
      std::cout << i << " -> ";
      ++i;
      std::cout << i << '\n';
  }
}

void f() {}

void synchronizedExample() {
  
  std::vector<std::thread> v(10);
  
  for(auto& t: v)
    t = std::thread([]{ f(); });
  
  for(auto& t: v)
    t.join();
}

void atomicExample(int a, int b, int c) {

  static int i = 0, j = 0, k = 0;
  
  // If an exception occurs, abort the transaction and continue stack unwinding.
  atomic_noexcept {
    i += a;
    if (i > 10000) throw std::runtime_error("i too big");
  }
  
  // If an exception occurs, abort the transaction and continue stack unwinding, unless its one of several approved exceptions which just cancel the
  // transaction.
  atomic_cancel {
    j += b;
    if (j > 10000) throw std::runtime_error("j too big");
  }
  
  // If an exception occurs, the transaction commits normally.
  atomic_commit {
    k += c;
    if (k > 10000) throw std::runtime_error("k too big");
  };
}
