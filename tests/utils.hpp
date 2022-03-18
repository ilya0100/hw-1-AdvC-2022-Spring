#pragma once

#include <gtest/gtest.h>

extern "C" {
    #include "group_data.h"
}

bool listcmp(const List &list_l, const List &list_r);
