BUILD_DIR = build
INSTALL_DIR = dist
TARGET = chombo
MAHC_DIR = src/mahc
MAHC_CARGO_TOML = $(MAHC_DIR)/Cargo.toml
BINARY_PATH = $(CURDIR)/$(INSTALL_DIR)/bin/$(TARGET)
MAHC_LIB_STATIC = $(MAHC_DIR)/target/debug/libmahc.a
MAHC_HEADER = src/mahc.h

.PHONY: all setup build run clean format format-check bear debug whodoyouthinkyouareiam

all: install

setup:
	@if [ ! -d "$(BUILD_DIR)/meson-private" ]; then \
		echo "CLEARING BUILD AND REFRESHING SUBPROJECTS..."; \
		rm -rf $(BUILD_DIR); \
		meson setup $(BUILD_DIR) \
		--wrap-mode=forcefallback \
		--prefix=$(CURDIR)/$(INSTALL_DIR) \
		--reconfigure; \
	fi

install: build
	meson install -C $(BUILD_DIR)

build: $(MAHC_LIB_STATIC) $(MAHC_HEADER) setup
	meson compile -C $(BUILD_DIR)

run:
	@if [ -f "$(BINARY_PATH)" ]; then \
		"$(BINARY_PATH)"; \
	else \
		echo "BINARY NOT FOUND, BUILDING FIRST..."; \
		$(MAKE) --no-print-directory install; \
		"$(BINARY_PATH)"; \
	fi

# Rust mahc stuffs
$(MAHC_HEADER): $(shell find $(MAHC_DIR) -name "*.rs")
	cbindgen $(MAHC_DIR) --config cbindgen.toml --output $(MAHC_HEADER)

$(MAHC_LIB_STATIC): $(shell find $(MAHC_DIR) -name "*.rs")
	cargo build --manifest-path $(MAHC_CARGO_TOML)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(INSTALL_DIR)
	cargo clean --manifest-path $(MAHC_CARGO_TOML)
	rm -f src/mahc.h

format:
	find ./src -name '*.h' -o -iname '*.c' | xargs clang-format -i --verbose

format-check:
	find ./src -name '*.h' -o -name '*.c' | xargs clang-format --dry-run --Werror --verbose


bear:
	@if [ ! -d $(BUILD_DIR)/meson-private ]; then $(MAKE) setup; fi
	ln -sf $(BUILD_DIR)/compile_commands.json .

debug: setup
	meson configure $(BUILD_DIR) -Dbuildtype=debug
	$(MAKE) build

valgrind:
	valgrind --leak-check=full --suppressions=valgrind.supp $(BINARY_PATH)

record:
	perf record -g --call-graph dwarf $(BINARY_PATH)
	perf script > chombo.perf


	

whodoyouthinkyouareiam: clean setup build run
