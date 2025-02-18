#include "encoder.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace rc4 {

inline void Encoder::swap(unsigned char &a, unsigned char &b) {
  unsigned char temp = a;
  a = b;
  b = temp;
}

Encoder::Encoder(unsigned char *key, size_t key_size) { mutate(key, key_size); }

void Encoder::KSA(const unsigned char *key, size_t key_size) {
  for (int k = 0; k < S_SIZE; k++) S_[k] = k;

  j_ = 0;
  for (int k = 0; k < S_SIZE; k++) {
    j_ = (j_ + S_[k] + key[k % key_size]) % S_SIZE;
    swap(S_[k], S_[j_]);
  }

  i_ = 0;
  j_ = 0;
}

unsigned char Encoder::PRGA() {
  i_ = (i_ + 1) % S_SIZE;
  j_ = (j_ + S_[i_]) % S_SIZE;
  swap(S_[i_], S_[j_]);
  return S_[(S_[i_] + S_[j_]) % S_SIZE];
}

inline void Encoder::mutate(unsigned char *key, size_t key_size) {
  KSA(key, key_size);
}

void Encoder::encode(const char *fin_name, const char *fout_name, bool encode) {
  std::ifstream fin(fin_name);
  std::ofstream fout(fout_name);
  if (!fin || !fout) {
    throw std::runtime_error("failed to open file");
  }
  unsigned char buffer[4096];
  while (!fin.eof()) {
    fin.read((char *)buffer, sizeof(buffer));
    size_t read_bytes = fin.gcount();
    if (read_bytes > 0) {
      for (int k = 0; k < read_bytes; ++k) {
        buffer[k] ^= PRGA();
      }
      fout.write((char *)buffer, read_bytes);
    }
  }
  fin.close();
  fout.close();
}

}  // namespace rc4
