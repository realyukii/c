all: build/static_storage build/flex_array build/queue_linked_list build/queue_array build/race_condition build/test_malloc build/compare_bytes build/parser_n_tokenizer

build/test_malloc: malloc.c build/shared_lib.so
	gcc $^ -o $@
build/shared_lib.so: shared_lib.c
	gcc -shared -fPIC $^ -o $@
build/compare_bytes: compare_bytes.c
	gcc $^ -o $@
build/parser_n_tokenizer: parser_n_tokenizer.c
	gcc $^ -o $@
build/race_condition: race_condition.c
	gcc $^ -o $@
build/queue_linked_list: data_structure/queue_linked_list.c
	gcc $^ -o $@
build/queue_array: data_structure/queue_array.c
	gcc $^ -o $@
build/flex_array: array_in_struct.c
	gcc $^ -o $@
build/static_storage: func_ret.c
	gcc $^ -o $@