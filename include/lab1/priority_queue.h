#pragma once

namespace lab1 {

class priority_queue {
 public:
  virtual ~priority_queue() = default;

  virtual priority_queue &operator=(priority_queue &other) = 0;
  virtual void insert(char *value, int key) = 0;
  virtual char *top() = 0;
  virtual void pop() = 0;

  virtual priority_queue &merge(priority_queue &other) = 0;
};
}  // namespace lab1
