
#include <cstring>

#include "leftist_heap.h"
namespace lab1 {

leftist_heap::node::node(const char *value, int priority)
    : skew_heap::node(value, priority), rank_(1) {}

}  // namespace lab1
