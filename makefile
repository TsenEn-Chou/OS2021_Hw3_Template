
GIT_HOOKS := .git/hooks/applied

all: $(GIT_HOOKS) $(BINARY)

$(GIT_HOOKS):
	@.githooks/install-git-hooks
	@echo


.PHONY: clean
clean:
