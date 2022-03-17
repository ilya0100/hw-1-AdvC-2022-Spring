#!/usr/bin/env bash

cd build

lcov -t "tests/test_group_data" -o coverage.info -c -d group_data_lib/
genhtml -o report coverage.info