#pragma once

#include <algorithm>
#include <cstddef>

namespace rc4 {

const size_t S_SIZE = 0xFF;

class Encoder {
 private:
  unsigned char S_[S_SIZE];

  int i_;
  int j_;

  void KSA(const unsigned char *key, size_t key_size);
  unsigned char PRGA();

  void swap(unsigned char &a, unsigned char &b);

 public:
  Encoder(unsigned char *key, size_t key_size);
  Encoder(const Encoder &other) = default;       // no dynamic memory
  ~Encoder() = default;                          // no dynamic memory
  Encoder &operator=(Encoder &other) = default;  // no dynamic memory

  inline void mutate(unsigned char *key, size_t key_size);

  // encode param is useless, encryption & decryption in RC4 are the same
  void encode(char const *fin_name, char const *fout_name, bool encode = true);
};

}  // namespace rc4
