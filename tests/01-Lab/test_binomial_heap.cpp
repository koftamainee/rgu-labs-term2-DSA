#include "lab1/tests/test_binomial_heap.h"

#include "lab1/binomial_heap.h"

namespace {

void demo_1() {
  lab1::binomial_heap bh;
  lab1::binomial_heap bh2(bh);
}

}  // namespace

namespace lab1::test {
void binomial_heap(int argc, char **argv) { demo_1(); }
}  // namespace lab1::test
