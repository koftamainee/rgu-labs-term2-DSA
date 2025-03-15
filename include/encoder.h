#pragma once

#include <cstddef>

namespace lab1 {

const size_t S_SIZE = 0xFF;  // 255 in hexidecimal

class encoder final {
 private:
  unsigned char S_[S_SIZE];

  size_t i_;
  size_t j_;

  void KSA(const unsigned char *key, size_t key_size);
  unsigned char PRGA();

  static void swap(unsigned char &a, unsigned char &b);

 public:
  encoder(unsigned char *key, size_t key_size);
  encoder(const encoder &other) = default;       // no dynamic memory
  ~encoder() noexcept = default;                 // no dynamic memory
  encoder &operator=(encoder &other) = default;  // no dynamic memory

  inline void mutate(unsigned char *key, size_t key_size);

  void encode(char const *fin_name, char const *fout_name, bool encode = true);
};

}  // namespace lab1
