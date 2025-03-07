#include <iostream>
#include <sstream>
#include <stdexcept>

#include "includes.h"
#include "lab1/tests/test_binary_heap.h"
#include "lab1/tests/test_binomial_heap.h"

void (*const LAB_1_FUNCTION_POINTERS[])(int, char **) = {
    lab1::test::encoder,
    lab1::test::logical_values_array,
    lab1::test::complex,
    lab1::test::matrix,
    nullptr,  // task 5 is not executable
    lab1::test::binary_heap,
    lab1::test::binomial_heap};

void (*const *const LABS_FUNCTION_POINTERS[])(int, char **) = {
    LAB_1_FUNCTION_POINTERS};

const int LABS_COUNT = 4;
const int TASKS_COUNT[] = {11, 8, 9, 6};

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cerr << "Not enough CLI arguments. Aborting." << std::endl;
    return -1;
  }

  std::stringstream lab_stream(argv[1]);
  int lab_number = 0;
  lab_stream >> lab_number;

  std::stringstream test_stream(argv[2]);
  int test_number = 0;
  test_stream >> test_number;

  if (lab_number < 1 || lab_number > LABS_COUNT) {
    std::cerr << "Invalid lab number provided. Aborting." << std::endl;
    return -1;
  }

  if (test_number < 1 || test_number > TASKS_COUNT[lab_number - 1]) {
    std::cerr << "Invalid test number provided. Aborting." << std::endl;
    return -1;
  }
  if (test_number == 5 && lab_number == 1) {
    std::cerr << "Task 5 in 1 lab is not executable" << std::endl;
    return -1;
  }

  void (*test)(int, char **) =
      LABS_FUNCTION_POINTERS[lab_number - 1][test_number - 1];

  std::cout << "Running lab #" << lab_number << ", test #" << test_number
            << std::endl;
  try {
    test(argc - 3, argv + 3);
  } catch (std::runtime_error &e) {
    std::cerr << "Error occurred during execution: " << e.what() << std::endl;
    return -1;
  } catch (std::bad_alloc &e) {
    std::cerr << "Memory allocation error: " << e.what() << std::endl;
    return -1;
  } catch (std::invalid_argument &e) {
    std::cerr << "Invalid argument passed to the function: " << e.what()
              << std::endl;
    return -1;
  } catch (std::out_of_range &e) {
    std::cerr << "Index is out of bounds: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred during execution." << std::endl;
    return -1;
  }
  std::cout << "All tests completed." << std::endl;
  return 0;
}
