# top-level vars
CC       := gcc
CFLAGS   := -g3 -O0 -Wall -Wextra
BUILDDIR := build

# your “special” targets
SPECIAL_SRCS := \
	func_ret.c      static_storage \
	array_in_struct.c flex_array

# list of all the commands you want to build
PROGS := \
	bitshift \
	static_storage \
	flex_array \
	queue_linked_list \
	queue_array \
	race_condition \
	parser_n_tokenizer \
	compare_bytes \
	test_malloc

.PHONY: all clean
all: $(BUILDDIR) $(addprefix $(BUILDDIR)/,$(PROGS))

# make build dir if needed
$(BUILDDIR):
	mkdir -p $@

# shared lib used only by test_malloc
$(BUILDDIR)/shared_lib.so: shared_lib.c | $(BUILDDIR)
	$(CC) -shared -fPIC $(CFLAGS) $< -o $@

# test_malloc depends on malloc.c + shared lib
$(BUILDDIR)/test_malloc: malloc.c $(BUILDDIR)/shared_lib.so | $(BUILDDIR)
	$(CC) $(CFLAGS) $^ -o $@

# map func_ret.c → static_storage, array_in_struct.c → flex_array
$(BUILDDIR)/%: $(filter %,$(SPECIAL_SRCS)) | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# general C‐to‐EXE rules:
#   root‐level .c that matches prog name
$(BUILDDIR)/%: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

#   data_structure/*.c
$(BUILDDIR)/%: data_structure/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# clean up
clean:
	rm -rf $(BUILDDIR)
