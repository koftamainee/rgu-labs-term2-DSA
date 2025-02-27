#include "lab1/binary_heap.h"

#include <cstring>
#include <stdexcept>

namespace lab1 {

void binary_heap::resize(size_t new_size) {
  node *temp = new node[new_size];
  std::memcpy(temp, heap_array_, size_);
  delete[] heap_array_;
  heap_array_ = temp;
  temp = nullptr;
}

void binary_heap::sift_up(size_t index) {
  while (heap_array_[index].priority > heap_array_[(index - 1) / 2].priority) {
    swap(heap_array_[index], heap_array_[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void binary_heap::sift_down(size_t index) {
  while (2 * index + 1 < size_) {
    size_t left_child_index = (2 * index) + 1;
    size_t right_child_index = (2 * index) + 2;
    size_t j = left_child_index;
    if (right_child_index < size_ &&
        heap_array_[right_child_index].priority <
            heap_array_[left_child_index].priority) {
      j = left_child_index;
    }
    if (heap_array_[index].priority >= heap_array_[j].priority) {
      break;
    }
    swap(heap_array_[index], heap_array_[j]);
    index = j;
  }
}

binary_heap::binary_heap() {
  heap_array_ = new node[BINARY_HEAP_INITIAL_CAPACITY];
  capacity_ = BINARY_HEAP_INITIAL_CAPACITY;
  size_ = 0;
}

binary_heap::binary_heap(binary_heap &other) {
  heap_array_ = new node[other.capacity_];
  capacity_ = other.capacity_;
  size_ = other.size_;
}

binary_heap::~binary_heap() { delete[] heap_array_; }

binary_heap &binary_heap::operator=(binary_heap &other) {
  if (&other == this) {
    return *this;
  }
  if (other.capacity_ > size_) {
    delete[] heap_array_;
    heap_array_ = new node[other.capacity_];
    capacity_ = other.capacity_;
  }
  std::memcpy(heap_array_, other.heap_array_, other.size_ * sizeof(node));
  size_ = other.size_;
  return *this;
}

[[nodiscard]] size_t binary_heap::size() const { return size_; }

[[nodiscard]] size_t binary_heap::capacity() const { return capacity_; }

void binary_heap::insert(const char *value, int priority) {
  char *value_copy = new char[std::strlen(value)];
  std::strcpy(value_copy, value);
  if (size_ == capacity_) {
    resize(capacity_ * BINARY_HEAP_GROWTH_FACTOR);
    capacity_ *= BINARY_HEAP_GROWTH_FACTOR;
  }
  heap_array_[size_].value = value_copy;
  heap_array_[size_].priority = priority;
  sift_up(size_);
  ++size_;
}

[[nodiscard]] const char *binary_heap::top() const {
  return heap_array_->value;
}

[[nodiscard]] int binary_heap::top_priority() const {
  return heap_array_->priority;
}

void binary_heap::pop() {
  if (size_ == 0) {
    throw std::out_of_range("Heap is empty");
  }
  if (size_ == 1) {
    size_ = 0;
  } else {
    --size_;
    heap_array_[0] = heap_array_[size_ - 1];
    sift_down(0);
  }
}

binary_heap &binary_heap::merge(heap &other) {
  if (&other == this) {
    return *this;
  }
  while (other.size() > 0) {
    insert(other.top(), other.top_priority());
    other.pop();
  }
  return *this;
}

void binary_heap::swap(node &first, node &second) {
  auto temp = first;
  first = second;
  second = temp;
}
}  // namespace lab1
