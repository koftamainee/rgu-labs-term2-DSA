#include "lab1/binomial_heap.h"

#include <cstring>
#include <stdexcept>

namespace lab1 {

binomial_heap::binomial_heap() : minimal_(nullptr), roots_(nullptr), size_(0) {}

binomial_heap::binomial_heap(binomial_heap& other)
    : minimal_(nullptr), roots_(nullptr), size_(0) {
  copy_from(other);
}

binomial_heap::~binomial_heap() noexcept { cleanup(); }

binomial_heap& binomial_heap::operator=(binomial_heap& other) {
  if (this != &other) {
    cleanup();
    copy_from(other);
  }
  return *this;
}

size_t binomial_heap::size() const { return size_; }

void binomial_heap::insert(const char* value, int priority) {}

const char* binomial_heap::top() const {
  if (size_ == 0) {
    throw std::out_of_range("Heap is empty");
  }
  return minimal_->value_;
}

int binomial_heap::top_priority() const {
  if (size_ == 0) {
    throw std::out_of_range("Heap is empty");
  }
  return minimal_->priority_;
}

void binomial_heap::pop() {}

binomial_heap& binomial_heap::merge(heap& other_heap) {}

binomial_heap::node* binomial_heap::circular_to_linear(node* circ) {
  if (circ == nullptr) {
    return nullptr;
  }
  node* head = circ;
  node* current = circ;
  while (current->sibling_ != circ) {
    current = current->sibling_;
  }
  current->sibling_ = nullptr;
  return head;
}

binomial_heap::node* binomial_heap::linear_to_circular(node* head) {
  if (head == nullptr) {
    return nullptr;
  }
  node* current = head;
  while (current->sibling_ != nullptr) {
    current = current->sibling_;
  }
  current->sibling_ = head;
  return head;
}

binomial_heap::node* binomial_heap::merge_root_lists(node* list1, node* list2) {
  if (list1 == nullptr) {
    return list2;
  }
  if (list2 == nullptr) {
    return list1;
  }
  node* head = nullptr;
  node** lastPtr = &head;
  while ((list1 != nullptr) && (list2 != nullptr)) {
    if (list1->degree_ <= list2->degree_) {
      *lastPtr = list1;
      list1 = list1->sibling_;
    } else {
      *lastPtr = list2;
      list2 = list2->sibling_;
    }
    lastPtr = &((*lastPtr)->sibling_);
  }
  *lastPtr = (list1 != nullptr) ? list1 : list2;
  return head;
}

binomial_heap::node* binomial_heap::consolidate(node* head) {
  if (head == nullptr) {
    return nullptr;
  }
  node* prev = nullptr;
  node* curr = head;
  node* next = curr->sibling_;
  while (next != nullptr) {
    if ((curr->degree_ != next->degree_) ||
        ((next->sibling_ != nullptr) &&
         next->sibling_->degree_ == curr->degree_)) {
      prev = curr;
      curr = next;
    } else {
      if (curr->priority_ <= next->priority_) {
        curr->sibling_ = next->sibling_;
        next->parent_ = curr;
        next->sibling_ = curr->child_;
        curr->child_ = next;
        curr->degree_++;
      } else {
        if (prev == nullptr) {
          head = next;
        } else {
          prev->sibling_ = next;
        }
        curr->parent_ = next;
        curr->sibling_ = next->child_;
        next->child_ = curr;
        next->degree_++;
        curr = next;
      }
    }
    next = curr->sibling_;
  }
  return head;
}

binomial_heap::node* binomial_heap::find_minimum(node* circ) const {
  if (circ == nullptr) {
    return nullptr;
  }
  node* min = circ;
  node* current = circ->sibling_;
  while (current != circ) {
    if (current->priority_ < min->priority_) {
      min = current;
    }
    current = current->sibling_;
  }
  return min;
}

binomial_heap::node* binomial_heap::reverse_list(node* head) {
  node* prev = nullptr;
  node* current = head;
  while (current != nullptr) {
    node* next = current->sibling_;
    current->sibling_ = prev;
    current->parent_ = nullptr;
    prev = current;
    current = next;
  }
  return prev;
}

void binomial_heap::cleanup() {
  if (roots_ == nullptr) {
    return;
  }
  node* linear = circular_to_linear(roots_);

  while (linear != nullptr) {
    node* next = linear->sibling_;
    auto delete_tree = [](node* root, auto& delete_tree_ref) -> void {
      if (!root) {
        return;
      }
      node* child = root->child_;
      while (child) {
        node* next_child = child->sibling_;
        delete_tree_ref(child, delete_tree_ref);
        child = next_child;
      }
      delete root;
    };
    delete_tree(linear, delete_tree);
    linear = next;
  }
  roots_ = nullptr;
  minimal_ = nullptr;
  size_ = 0;
}

void binomial_heap::copy_from(const binomial_heap& other) {
  cleanup();
  size_ = other.size_;
  if (other.roots_ == nullptr) {
    roots_ = nullptr;
    minimal_ = nullptr;
    return;
  }
  node* head = nullptr;
  node* tail = nullptr;
  node* current = other.roots_;
  do {
    node* cloned = current->clone();
    if (head == nullptr) {
      head = cloned;
      tail = cloned;
    } else {
      tail->sibling_ = cloned;
      tail = cloned;
    }
    current = current->sibling_;
  } while (current != other.roots_);
  roots_ = linear_to_circular(head);
  minimal_ = find_minimum(roots_);
}

}  // namespace lab1
