#pragma once

#include <cstddef>

namespace cstd {

template <typename T>
class vector final {
 private:
  static std::size_t GROWTH_FACTOR;

  T *data;
  std::size_t size_;
  std::size_t capacity_;

 public:
  using iterator = T *;
  using const_iterator = const T *;

  vector();
  vector(std::size_t size, T const &value = T());
  vector(vector<T> const &other);
  vector(vector<T> &&other) noexcept;
  ~vector();

  vector<T> &operator=(vector<T> const &other);
  vector<T> &operator=(vector<T> &&other) noexcept;

  T &operator[](std::size_t index);
  T const &operator[](std::size_t index) const;
  T &at(std::size_t index);
  T const &at(std::size_t index) const;

  [[nodiscard]] std::size_t size() const;
  [[nodiscard]] std::size_t capacity() const;
  [[nodiscard]] bool empty() const;

  void push_back(T const &value);
  void clear();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

}  // namespace cstd

#include "cvector.tpp"
