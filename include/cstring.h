#pragma once

#include <cstddef>
#include <iostream>

namespace cstd {
class string {
 private:
  const size_t STRING_INITIAL_CAPACITY = 16;

  char *data_;
  size_t size_;
  size_t capacity_;

  void resize(size_t new_size);

 public:
  string();
  string(const string &other);
  string(const char *other);
  ~string() noexcept;
  string &operator=(const string &other);

  char &operator[](size_t index) const noexcept;
  char &at(size_t index) const;

  size_t size() const noexcept;
  size_t capacity() const noexcept;

  void clear();
  bool empty() const noexcept;

  string operator+(const string &other) const;
  string &operator+=(const string &other);

  void push_back(char c);
  void insert(char c, size_t index);

  void pop_back();

  string substr(const string &needle) const;
  int compare(const string &other) const noexcept;

  char *c_str() const noexcept;

  friend std::ostream &operator<<(std::ostream &out, const string &str);
  friend std::istream &operator>>(std::istream &in, string &str);
};
}  // namespace cstd
