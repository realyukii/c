all: build/test_malloc build/compare_bytes

build/test_malloc: malloc.c build/shared_lib.so
	gcc $^ -o $@
build/shared_lib.so: shared_lib.c
	gcc -shared -fPIC $^ -o $@
build/compare_bytes: compare_bytes.c
	gcc $^ -o $@
