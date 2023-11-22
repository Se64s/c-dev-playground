# App name
APP_NAME=MyApp

# Commands vars
COMPOSE=docker compose
MAKE_MSG=MAKE :

# Bring up container with services
.PHONY: up
up:
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Bring up docker services"
	@echo "--------------------------------------"
	$(COMPOSE) up -d

# Bring down services
.PHONY: down
down:
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Shutdown services"
	@echo "--------------------------------------"
	$(COMPOSE) down

# Attach to image
ATTACH_CMD=/bin/bash
.PHONY: attach
attach: up
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Launch build application process"
	@echo "--------------------------------------"
	$(COMPOSE) exec base sh -c "$(ATTACH_CMD)"

# Launch build actions
INIT_BUILD_CMD=mkdir -p ./build && cd ./build
CLEAN_BUILD_CMD=$(INIT_BUILD_CMD) && rm -f -R ./*
BUILD_CMD=$(CLEAN_BUILD_CMD) && cmake .. && cmake --build .
.PHONY: build
build: up
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Launch build application process"
	@echo "--------------------------------------"
	$(COMPOSE) exec base sh -c "$(BUILD_CMD)"

# Run application
APP_ARGS=
RUN_CMD=$(INIT_BUILD_CMD) && ./$(APP_NAME).out $(APP_ARGS)
.PHONY: run
run: build
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Run application with following args: $(APP_ARGS)"
	@echo "--------------------------------------"
	$(COMPOSE) exec base sh -c "$(RUN_CMD)"

# Debug application
GDB_APP=gdb
DEBUG_ARGS=
DEBUG_CMD=$(INIT_BUILD_CMD) && $(GDB_APP) ./$(APP_NAME).out $(DEBUG_ARGS)
.PHONY: debug
debug: build
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Debug application with following args: $(DEBUG_ARGS)"
	@echo "--------------------------------------"
	$(COMPOSE) exec base sh -c "$(DEBUG_CMD)"

# Remove build artifacts
.PHONY: clean
clean: up
	@echo "--------------------------------------"
	@echo "$(MAKE_MSG) Clean build artifacts"
	@echo "--------------------------------------"
	$(COMPOSE) exec base sh -c "$(CLEAN_BUILD_CMD)"

# EOF
