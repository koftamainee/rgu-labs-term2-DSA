#pragma once

#include <stdexcept>
#include <utility>

#include "cvector.h"

namespace cstd {

template <typename T>
size_t vector<T>::GROWTH_FACTOR = 2;

template <typename T>
vector<T>::vector() : data(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(std::size_t size, T const &value)
    : size_(size), capacity_(size) {
  data = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data[i] = value;
  }
}

template <typename T>
vector<T>::vector(vector<T> const &other)
    : size_(other.size_), capacity_(other.capacity_) {
  data = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data[i] = other.data[i];
  }
}

template <typename T>
vector<T>::vector(vector<T> &&other) noexcept
    : data(other.data), size_(other.size_), capacity_(other.capacity_) {
  other.data = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T>
vector<T>::~vector() {
  delete[] data;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> const &other) {
  if (this != &other) {
    delete[] data;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&other) noexcept {
  if (this != &other) {
    delete[] data;
    data = other.data;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

template <typename T>
T &vector<T>::operator[](std::size_t index) {
  return data[index];
}

template <typename T>
T const &vector<T>::operator[](std::size_t index) const {
  return data[index];
}

template <typename T>
T &vector<T>::at(std::size_t index) {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
T const &vector<T>::at(std::size_t index) const {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
std::size_t vector<T>::size() const {
  return size_;
}

template <typename T>
std::size_t vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
void vector<T>::push_back(T const &value) {
  if (size_ == capacity_) {
    capacity_ = (capacity_ == 0) ? 1 : capacity_ * GROWTH_FACTOR;
    T *new_data = new T[capacity_];
    for (std::size_t i = 0; i < size_; ++i) {
      new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
  }
  data[size_++] = value;
}

template <typename T>
void vector<T>::clear() {
  delete[] data;
  data = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return data;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return data + size_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return data;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return data + size_;
}

}  // namespace cstd
