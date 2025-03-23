# Data structures and alghoritms labs
## Contents
- Task 1 -- RC4 Encoder
- Task 2 -- Logical values array implemented on uint, with binary operations support
- Task 3 -- Class for computing with complex numbers
- Task 4 -- Class for matrix computation
- Task 5 -- Interface for priority queue (heap)
- Task 6 -- Binary heap, based on Task 5
- Task 7 - Binomial heap, based on Task 5
- Task 8 -- Fibonacci heap, based on Task 5
- Task 9 -- Leftist heap, based on skew heap from Task 10
- Task 10 -- SKew heap, based on Task 5
- Task 11 -- Treap, based on Task 5 
## Compilation
```bash
make
```
### Compile in debug and run
```bash
make run f="cli args"
```

### Make is a wrapper for CMake, generating build files for Ninja build system
```bash
sudo apt install make cmake ninja-build   # Debian-based
sudo pacman -Syu make cmake ninja         # Arch-based
```
You can build with other build system, if CMake supports it, eg
```bash
make GENERATOR=Unix\ Makefiles build
```
