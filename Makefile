.DEFAULT_GOAL := build

TARGETS := \
	help \
	clean clean-ccades clean-dotnetcades \
	build build-ccades build-dotnetcades \
	rebuild

.PHONY: $(TARGETS)

help: ## Display this help screen
	@grep -E '^[a-z.A-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

clean: clean-ccades clean-dotnetcades ## Clean project

clean-ccades:
	rm -fr src/ccades/build
	rm -fr src/ccades/*.so

clean-dotnetcades:
	find . -type d \( -name "bin" -o -name "obj" \) -exec rm -fr {} +

build: build-ccades build-dotnetcades ## Build library

build-ccades:
	cmake -S src/ccades -B src/ccades/build
	cmake --build src/ccades/build -j$$(nproc)

build-dotnetcades:
	dotnet restore
	dotnet build

rebuild: clean build ## Clean and rebuild the library from scratch

# =========================
# Printing out targets
# =========================
GREEN := \033[38;2;0;255;128m
CYAN  := \033[38;5;51m
RESET := \033[0m

define inject_start_hook
.PHONY: .print-start-$1
.print-start-$1:
	@printf "$(GREEN)>>> Running target: [%s]$(RESET)\n" "$1"

$1: .print-start-$1
endef
$(foreach t,$(TARGETS),$(eval $(call inject_start_hook,$t)))