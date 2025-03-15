#pragma once

#include <cstddef>
namespace lab1 {

class heap {
 public:
  virtual ~heap() = default;

  [[nodiscard]] virtual size_t size() const = 0;

  virtual void insert(const char *value, int priority) = 0;
  [[nodiscard]] virtual const char *top() const = 0;
  [[nodiscard]] virtual int top_priority() const = 0;
  virtual void pop() = 0;

  virtual heap *merge(heap *other) = 0;
};
}  // namespace lab1
