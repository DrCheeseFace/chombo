BUILD_DIR = build
TARGET = chombo
MAHC_DIR = src/mahc
MAHC_CARGO_TOML = $(MAHC_DIR)/Cargo.toml

.PHONY: all setup build run clean format format-check bear debug mahc-header mahc-lib whodoyouthinkyouareiam

all: build
	@$(MAKE) run

# BUILD COMMANDS 

setup:
	    @if [ ! -d "$(BUILD_DIR)/meson-private" ]; then \
		echo "Clearing build and refreshing subprojects..."; \
		rm -rf $(BUILD_DIR); \
		meson setup $(BUILD_DIR) --wrap-mode=forcefallback; \
	    fi

build: mahc-lib setup
	meson compile -C $(BUILD_DIR)

run:
	@if [ -f $(BUILD_DIR)/$(TARGET) ]; then \
		./$(BUILD_DIR)/$(TARGET); \
	else \
		echo "building first..."; \
		$(MAKE) build && ./$(BUILD_DIR)/$(TARGET); \
	fi

# rust mahc stuffs
mahc-header:
	cbindgen $(MAHC_DIR) --config cbindgen.toml --output src/mahc.h

mahc-lib: mahc-header
	cargo build --manifest-path $(MAHC_CARGO_TOML)


# UTILS COMMADNS

clean:
	rm -rf $(BUILD_DIR)
	cargo clean --manifest-path $(MAHC_CARGO_TOML)
	rm -f src/mahc.h

format: 
	find ./src -name '*.h' -o -iname '*.c' | xargs clang-format -i --verbose

format-check:
	find ./src -name '*.h' -o -iname '*.c' | xargs clang-format --dry-run --Werror

bear:
	@if [ ! -d $(BUILD_DIR)/meson-private ]; then $(MAKE) setup; fi
	ln -sf $(BUILD_DIR)/compile_commands.json .

debug: setup
	meson configure $(BUILD_DIR) -Dbuildtype=debug
	$(MAKE) build

whodoyouthinkyouareiam: clean setup build run
