all: build/race_condition build/test_malloc build/compare_bytes build/parser_n_tokenizer

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