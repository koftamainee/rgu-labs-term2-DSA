#include "test_encoder.h"

#include <iostream>
#include <stdexcept>

#include "encoder.h"

namespace test {

const size_t ENCODER_KEY_LEN = 10;

void encoder(int argc, char **argv) {
  if (argc < 2) {
    throw std::runtime_error(
        "test_encoder: Not enough cli arguments: ./rgu-labs src_file "
        "target_file");
  }

  unsigned char key[ENCODER_KEY_LEN] = {'a', 'b', 'c', 'd', 'e',
                                        'f', 'g', 'h', 'i', 'j'};

  rc4::Encoder enc(key, ENCODER_KEY_LEN);
  enc.encode(argv[0], argv[1]);
  std::cout << "'" << argv[0] << "' encoded into '" << argv[1]
            << "' succesfully." << std::endl;
}
}  // namespace test
