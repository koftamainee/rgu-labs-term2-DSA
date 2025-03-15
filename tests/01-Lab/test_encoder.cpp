#include "tests/test_encoder.h"

#include <iostream>
#include <stdexcept>

#include "encoder.h"

namespace lab1::test {

const size_t ENCODER_KEY_LEN = 10;

void encoder(int argc, char **argv) {
  if (argc < 3) {
    throw std::runtime_error(
        "test_encoder: Not enough cli arguments: ./rgu-labs src_file "
        "target_file");
  }

  unsigned char key[ENCODER_KEY_LEN] = {'a', 'b', 'c', 'd', 'e',
                                        'f', 'g', 'h', 'i', 'j'};

  lab1::encoder enc(key, ENCODER_KEY_LEN);

  enc.encode(argv[0], argv[1]);
  std::cout << "'" << argv[0] << "' encoded into '" << argv[1]
            << "' succesfully." << std::endl;

  lab1::encoder enc2(key, ENCODER_KEY_LEN);

  enc2.encode(argv[1], argv[2]);
}
}  // namespace lab1::test
