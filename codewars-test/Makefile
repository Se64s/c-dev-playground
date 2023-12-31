APP_NAME=MyTest

# Check if initial arg passed with test to execute
MODULE?=ex_00

# -----------------------------------------------------------------------------

# Bring up container with services
.PHONY: up
up:
	@echo "Bring up services:\n"
	docker compose up -d

# -----------------------------------------------------------------------------

# Bring down services
.PHONY: down
down:
	@echo "Shutdown services:\n"
	docker compose down

# -----------------------------------------------------------------------------

# Launch build actions
INIT_BUILD_CMD=mkdir -p ./build && cd ./build
CLEAN_BUILD_CMD=$(INIT_BUILD_CMD) && rm -f -R ./*
BUILD_CMD=$(CLEAN_BUILD_CMD) && cmake -DMODULE=$(MODULE) .. && cmake --build .
.PHONY: build
build:
	@echo "Launch build application process:\n"
	docker compose exec base sh -c "$(BUILD_CMD)"

# -----------------------------------------------------------------------------

# Run application
APP_ARGS=
RUN_CMD=$(INIT_BUILD_CMD) && ./$(APP_NAME).out $(APP_ARGS)
.PHONY: run
run: build
	@echo "Run application with following args: $(APP_ARGS)\n"
	docker compose exec base sh -c "$(RUN_CMD)"

# -----------------------------------------------------------------------------

# Debug application
GDB_APP=gdb
DEBUG_ARGS=
DEBUG_CMD=$(INIT_BUILD_CMD) && $(GDB_APP) ./$(APP_NAME).out $(DEBUG_ARGS)
.PHONY: debug
debug: build
	@echo "Debug application with following args: $(DEBUG_ARGS)\n"
	docker compose exec base sh -c "$(DEBUG_CMD)"

# -----------------------------------------------------------------------------

# Remove build artifacts
.PHONY: clean
clean:
	@echo "Clean build artifacts:\n"
	docker compose exec base sh -c "$(CLEAN_BUILD_CMD)"

# EOF
