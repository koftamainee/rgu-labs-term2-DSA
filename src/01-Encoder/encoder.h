#pragma once

#include <cstddef>

namespace rc4 {

class Encoder {
 private:
  unsigned char *key;
  size_t key_size;

  void KSA(unsigned char *key);
  void PRGA(unsigned char *key, unsigned char *data, size_t data_size);
  void swap(unsigned char &a, unsigned char &b);

 public:
  Encoder(unsigned char *key, size_t key_size);
  ~Encoder();

  void mutate(unsigned char *key, size_t key_size);
  void encode(char const *fin_name, char const *fout_name, bool encode);
};

}  // namespace rc4
