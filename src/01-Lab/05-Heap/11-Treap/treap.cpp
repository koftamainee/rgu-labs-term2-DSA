#include "treap.h"

#include <cstdlib>
#include <cstring>
#include <optional>
#include <stdexcept>

namespace lab1 {

void treap::rotate_left(node *&subtree, bool validate) {
  if (validate && (subtree == nullptr || subtree->right_ == nullptr)) {
    return;
  }

  auto *temp = subtree;
  subtree = subtree->right_;
  temp->right_ = subtree->left_;
  subtree->left_ = temp;
}

void treap::rotate_right(node *&subtree, bool validate) {
  if (validate && (subtree == nullptr || subtree->left_ == nullptr)) {
    return;
  }

  auto *temp = subtree;
  subtree = subtree->left_;
  temp->left_ = subtree->right_;
  subtree->right_ = temp;
}

void treap::cleanup() { clean_node(root_); }

void treap::clean_node(node *root) {
  if (root == nullptr) {
    return;
  }
  clean_node(root->left_);
  clean_node(root->right_);
  delete root;
}

void treap::clone(treap const &from) {
  root_ = clone_node(from.root_);
  randomizer_upper_bound_ = from.randomizer_upper_bound_;
  randomizer_lower_bound_ = from.randomizer_lower_bound_;
  size_ = from.size_;
}

treap::node *treap::clone_node(node const *to_clone) {
  if (to_clone == nullptr) {
    return nullptr;
  }

  node *new_node = new node(*to_clone);
  new_node->right_ = clone_node(to_clone->right_);
  new_node->left_ = clone_node(to_clone->left_);

  return new_node;
}

treap::treap(int seed, int randomizer_lower_bound, int randomizer_upper_bound)
    : randomizer_lower_bound_(randomizer_lower_bound),
      randomizer_upper_bound_(randomizer_upper_bound),
      size_(0),
      root_(nullptr) {
  srand(static_cast<unsigned int>(seed));  // No STL :(
}

treap::treap(treap const &other) { clone(other); }

treap::~treap() { cleanup(); }

treap &treap::operator=(treap const &other) {
  if (&other != this) {
    cleanup();
    clone(other);
  }

  return *this;
}

[[nodiscard]] size_t treap::size() const { return size_; }

void treap::insert_inner(int key, int priority, char const *value,
                         node *&current_node) {
  if (current_node == nullptr) {
    current_node = new node(value, key, priority);
    return;
  }
  auto comparison_result = key - current_node->key_;
  if (comparison_result == 0) {
    throw std::invalid_argument("Repeating key in Treap found");
    return;
  }

  insert_inner(
      key, priority, value,
      comparison_result < 0 ? current_node->left_ : current_node->right_);

  if (comparison_result < 0 &&
      current_node->left_->priority_ < current_node->priority_) {
    rotate_right(current_node);
  } else if (comparison_result > 0 &&
             current_node->right_->priority_ < current_node->priority_) {
    rotate_left(current_node);
  }
}

void treap::insert(const char *value, int key) {
  insert_inner(key,
               rand() % (randomizer_upper_bound_ - randomizer_lower_bound_ + 1),
               value, root_);
  ++size_;
}

std::optional<char const *> treap::find_inner(int key, node *current_node) {
  if (current_node == nullptr) {
    return std::nullopt;
  }

  if (key == current_node->key_) {
    return current_node->value_;
  }
  return find_inner(key, key < current_node->key_ ? current_node->left_
                                                  : current_node->right_);
}

std::optional<char const *> treap::find(int key) {
  return find_inner(key, root_);
}

bool treap::dispose_inner(int key, node *&current_node,
                          disposal_status status) {
  if (current_node == nullptr) {
    return false;
  }

  if (status == disposal_status::bst_find) {
    auto comparison_result = key - current_node->key_;
    if (comparison_result == 0) {
      return dispose_inner(key, current_node, disposal_status::heap_sift_down);
    }

    return dispose_inner(
        key, comparison_result < 0 ? current_node->left_ : current_node->right_,
        disposal_status::bst_find);
  }

  if (status == disposal_status::heap_sift_down) {
    if (current_node->left_ == nullptr && current_node->right_ == nullptr) {
      delete current_node;
      current_node = nullptr;
      return true;
    }
    if (current_node->left_ != nullptr && current_node->right_ != nullptr) {
      if (current_node->left_->priority_ < current_node->right_->priority_) {
        rotate_left(current_node);
        return dispose_inner(key, current_node->left_,
                             disposal_status::heap_sift_down);
      } else {
        rotate_right(current_node);
        return dispose_inner(key, current_node->right_,
                             disposal_status::heap_sift_down);
      }
    } else if (current_node->left_ != nullptr) {
      rotate_right(current_node);
      return dispose_inner(key, current_node->right_,
                           disposal_status::heap_sift_down);
    } else {
      rotate_left(current_node);
      return dispose_inner(key, current_node->left_,
                           disposal_status::heap_sift_down);
    }
  }

  // should be unreachable
  return false;
}

bool treap::dispose(int key) {
  auto result = dispose_inner(key, root_, disposal_status::bst_find);
  if (result) {
    --size_;
  }
  return result;
}

[[nodiscard]] const char *treap::top() const {
  if (size_ == 0) {
    throw std::invalid_argument("Treap is empty");
  }
  node *current = root_;
  while (current->left_ != nullptr) {
    current = current->left_;
  }
  return current->value_;
}

[[nodiscard]] int treap::top_priority() const {
  if (size_ == 0) {
    throw std::invalid_argument("Treap is empty");
  }
  node *current = root_;
  while (current->left_ != nullptr) {
    current = current->left_;
  }
  return current->key_;
}

void treap::pop() {
  if (size_ == 0) {
    throw std::invalid_argument("Treap is empty");
  }
  if (root_->left_ == nullptr) {
    node *new_root = root_->right_;
    delete root_;
    root_ = new_root;
    --size_;
    return;
  }

  node *current = root_;
  node *parent;
  while (current->left_ != nullptr) {
    parent = current;
    current = current->left_;
  }
  parent->left_ = nullptr;
  delete current;
  --size_;
}

heap *treap::merge(heap *other) {
  auto *other_treap = dynamic_cast<treap *>(other);
  while (other_treap->size_ > 0) {
    insert(other_treap->root_->value_, other_treap->root_->key_);
    other_treap->dispose(other_treap->root_->key_);
  }

  return this;
}
}  // namespace lab1
