BUILD_TYPE ?= Release

BUILD_DIR := build
BUILD_DIR_DEBUG := $(BUILD_DIR)/Debug
BUILD_DIR_RELEASE := $(BUILD_DIR)/Release

CMAKE_CMD := cmake
NINJA_CMD := ninja

all: build

configure:
	@echo "Configuring project for $(BUILD_TYPE) build..."
	@mkdir -p $(BUILD_DIR)/$(BUILD_TYPE)
	@$(CMAKE_CMD) -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -B$(BUILD_DIR)/$(BUILD_TYPE) -H.

build: configure
	@echo "Building project in $(BUILD_TYPE) mode..."
	@$(NINJA_CMD) -C $(BUILD_DIR)/$(BUILD_TYPE)

clean:
	@echo "Cleaning up build files..."
	@rm -rf $(BUILD_DIR)

clean_target:
	@echo "Cleaning target directory..."
	@rm -rf $(TARGET_DIR)

distclean: clean clean_target

debug:
	@$(MAKE) BUILD_TYPE=Debug build

release:
	@$(MAKE) BUILD_TYPE=Release build

run: debug
	@echo "Running the project in Debug mode..."
	@echo "------------------------------------"
	@$(BUILD_DIR)/Debug/src/rgu-labs $(f)

valgrind: debug
	@echo "Running the project in Debug mode via valgrind..."
	@echo "------------------------------------"
	@valgrind --leak-check=full $(BUILD_DIR)/Debug/src/rgu-labs $(f)

help:
	@echo "Usage:"
	@echo "  make build           - Build the project with the default build type (Release)"
	@echo "  make debug           - Build the project in Debug mode"
	@echo "  make release         - Build the project in Release mode"
	@echo "  make clean           - Clean the build directory"
	@echo "  make clean_target    - Clean the target directory"
	@echo "  make distclean       - Clean both build and target directories"
	@echo "  make tests           - Run tests (adjust for your project)"
	@echo "  make run             - Run the project in Debug mode"
	@echo "  make valgrind        - Run the project in Debug mode via valgrind"

.PHONY: all configure build clean clean_target distclean debug release tests help run valgrind

