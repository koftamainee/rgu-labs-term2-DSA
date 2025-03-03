#include "lab1/heap.h"

namespace lab1 {
heap &heap::merge(heap &other) {
  if (&other == this) {
    return *this;
  }
  while (other.size() > 0) {
    insert(other.top(), other.top_priority());
    other.pop();
  }
  return *this;
}
}  // namespace lab1
