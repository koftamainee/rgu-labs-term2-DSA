#include "binary_heap.h"

#include <cstring>
#include <stdexcept>

namespace lab1 {

void binary_heap::resize(size_t new_capacity) {
  node *new_array = new node[new_capacity];

  for (int i = 0; i < size_; ++i) {
    new_array[i].value = new char[std::strlen(heap_array_[i].value) + 1];
    std::strcpy(new_array[i].value, heap_array_[i].value);
    new_array[i].priority = heap_array_[i].priority;
    delete[] heap_array_[i].value;
  }

  delete[] heap_array_;

  heap_array_ = new_array;
  capacity_ = new_capacity;
}

void binary_heap::sift_up(size_t index) {
  while (index > 0 &&
         heap_array_[index].priority < heap_array_[(index - 1) / 2].priority) {
    swap(heap_array_[index], heap_array_[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void binary_heap::sift_down(size_t index) {
  while (2 * index + 1 < size_) {
    size_t left = (2 * index) + 1;
    size_t right = (2 * index) + 2;
    size_t j = left;
    if (right < size_ &&
        heap_array_[right].priority < heap_array_[left].priority) {
      j = right;
    }

    if (heap_array_[index].priority <= heap_array_[j].priority) {
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

binary_heap::binary_heap(const binary_heap &other) {
  capacity_ = other.capacity_;
  size_ = other.size_;
  heap_array_ = new node[capacity_];
  for (int i = 0; i < size_; ++i) {
    heap_array_[i].value =
        new char[std::strlen(other.heap_array_[i].value) + 1];
    std::strcpy(heap_array_[i].value, other.heap_array_[i].value);
    heap_array_[i].priority = other.heap_array_[i].priority;
  }
}

binary_heap::~binary_heap() noexcept {
  for (int i = 0; i < size_; ++i) {
    delete[] heap_array_[i].value;
  }

  delete[] heap_array_;
}

binary_heap &binary_heap::operator=(const binary_heap &other) {
  if (&other == this) {
    return *this;
  }
  if (other.capacity_ > size_) {
    delete[] heap_array_;
    heap_array_ = new node[other.capacity_];
    capacity_ = other.capacity_;
  }
  for (int i = 0; i < size_; ++i) {
    heap_array_[i].value =
        new char[std::strlen(other.heap_array_[i].value) + 1];
    std::strcpy(heap_array_[i].value, other.heap_array_[i].value);
    heap_array_[i].priority = other.heap_array_[i].priority;
  }

  return *this;
}

[[nodiscard]] size_t binary_heap::size() const { return size_; }

[[nodiscard]] size_t binary_heap::capacity() const { return capacity_; }

void binary_heap::insert(const char *value, int priority) {
  char *value_copy = new char[std::strlen(value) + 1];
  std::strcpy(value_copy, value);
  if (size_ == capacity_) {
    resize(capacity_ * BINARY_HEAP_GROWTH_FACTOR);
    capacity_ *= BINARY_HEAP_GROWTH_FACTOR;
  }
  ++size_;
  heap_array_[size_ - 1].value = value_copy;
  heap_array_[size_ - 1].priority = priority;
  sift_up(size_ - 1);
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
  delete[] heap_array_[0].value;

  heap_array_[0] = heap_array_[size_ - 1];
  --size_;
  sift_down(0);
}

heap *binary_heap::merge(heap *other) {
  if (other == nullptr) {
    throw std::invalid_argument("other is nullptr");
  }
  if (other == this) {
    return this;
  }
  while (other->size() > 0) {
    insert(other->top(), other->top_priority());
    other->pop();
  }
  return this;
}

void binary_heap::swap(node &first, node &second) {
  auto temp = first;
  first = second;
  second = temp;
}
}  // namespace lab1
