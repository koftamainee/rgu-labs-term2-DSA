#include <expected>
#include <optional>

#include "heap.h"

namespace lab1 {
class treap final : public heap {
 private:
  class node final {
   public:
    char *value_;
    int priority_;
    int key_;
    node *left_;
    node *right_;

    node(char *value, int key, int priority);
    node(node const &other);
    ~node() noexcept;
  };

  node *root_;
  int randomizer_lower_bound_;
  int randomizer_upper_bound_;

  std::size_t size_;

  void cleanup();
  static void clean_node(node *root);
  void clone(treap const &from);
  static node *clone_node(node const *to_clone);

  static std::optional<char const *> find_inner(int key, node *current_node);

 public:
  treap(int seed = 0, int randomizer_lower_bound = 0,
        int randomizer_upper_bound = 1024);
  treap(treap const &other);
  ~treap() override;

  treap &operator=(treap const &other);

  [[nodiscard]] size_t size() const override;

  void insert(const char *value, int key) override;
  std::optional<char const *> find(int key);
  bool dispose(int key);
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  heap *merge(heap *other) override;
};
}  // namespace lab1
