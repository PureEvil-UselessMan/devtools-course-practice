// Copyright 2022 Olynin Alexander

#include <gtest/gtest.h>
#include "include/cross_line_and_plane.h"

TEST(Class_Line, Constructor_no_throw) {
    EXPECT_NO_THROW(Line(1.1, 3.2, 2.0, 1.0, 0.0, 3.3));
}

TEST(Class_Line, Copy_constructor_no_throw) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_NO_THROW(Line CD(AB));
}

