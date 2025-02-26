#pragma once

namespace lab1 {

class heap {
 public:
  virtual ~heap() = default;

  virtual heap &operator=(heap &other) = 0;
  virtual void insert(char *value, int key) = 0;
  virtual char *top() = 0;
  virtual void pop() = 0;

  virtual heap &merge(heap &other) = 0;
};
}  // namespace lab1
