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

TEST(Class_Line, Operator_equal_no_throw) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_NO_THROW(Line CD = AB);
}

TEST(Class_Line, Operator_get_x_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetX_1(), 1.1);
}

TEST(Class_Line, Operator_get_y_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetY_1(), 3.2);
}

TEST(Class_Line, Operator_get_z_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetZ_1(), 2.0);
}

TEST(Class_Line, Operator_get_a_x_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetA_x(), 1.0);
}

TEST(Class_Line, Operator_get_a_y_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetA_y(), 0.0);
}

TEST(Class_Line, Operator_get_a_z_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    EXPECT_EQ(AB.GetA_z(), 3.3);
}