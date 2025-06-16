# Compiler settings
CC       := gcc
CFLAGS   := -g3 -O0 -Wall -Wextra

# Build directory & targets
BUILDDIR := build
PROGS    := bitshift \
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

# ensure build/ exists
$(BUILDDIR):
	mkdir -p $@

# --- shared lib for test_malloc ---
$(BUILDDIR)/shared_lib.so: shared_lib.c | $(BUILDDIR)
	$(CC) -shared -fPIC $(CFLAGS) $< -o $@

# test_malloc needs both malloc.c and the shared lib
$(BUILDDIR)/test_malloc: malloc.c $(BUILDDIR)/shared_lib.so | $(BUILDDIR)
	$(CC) $(CFLAGS) $^ -o $@

# --- explicit “name mismatches” ---
$(BUILDDIR)/static_storage: func_ret.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR)/flex_array: array_in_struct.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# --- generic C → executable rules ---

# top‐level .c files matching prog name
$(BUILDDIR)/%: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# data_structure/*.c
$(BUILDDIR)/%: data_structure/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# clean everything
clean:
	rm -rf $(BUILDDIR)
