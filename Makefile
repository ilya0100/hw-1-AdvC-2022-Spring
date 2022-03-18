.PHONY: all build rebuild check test memtest clean covtest

all: clean check build test memtest

clean:
	rm -rf build
	rm -rf *.log

build:
	./build.sh

rebuild: clean build

check:
	./run_linters.sh

test:
	./build.sh 
	./build/tests/test_group_data

memtest:
	./build.sh
	./memtest.sh ./build/tests/test_group_data

covtest: rebuild test
	./code_cov.sh