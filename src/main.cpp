#include <iostream>
#include <stdexcept>

#include "01-Encoder/test_encoder.h"

int main(int argc, char **argv) {
  try {
    test::encoder(argc, argv);
  } catch (std::runtime_error &e) {
    std::cerr << "Error occured during execution: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occured during execution." << std::endl;
  }
  return 0;
}
