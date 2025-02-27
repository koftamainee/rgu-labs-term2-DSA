# Data structures and alghoritms labs
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
