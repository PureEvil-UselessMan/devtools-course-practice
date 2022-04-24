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

TEST(Class_Line, Operator_set_x_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetX_1(2.2);
    EXPECT_EQ(AB.GetX_1(), 2.2);
}

TEST(Class_Line, Operator_set_y_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetY_1(3.0);
    EXPECT_EQ(AB.GetY_1(), 3.0);
}

TEST(Class_Line, Operator_set_z_1_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetZ_1(5.1);
    EXPECT_EQ(AB.GetZ_1(), 5.1);
}

TEST(Class_Line, Operator_set_a_x_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetA_x(2.1);
    EXPECT_EQ(AB.GetA_x(), 2.1);
}

TEST(Class_Line, Operator_set_a_y_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetA_y(0.2);
    EXPECT_EQ(AB.GetA_y(), 0.2);
}

TEST(Class_Line, Operator_set_a_z_correct) {
    Line AB(1.1, 3.2, 2.0, 1.0, 0.0, 3.3);
    AB.SetA_z(0.0);
    EXPECT_EQ(AB.GetA_z(), 0.0);
}

TEST(Class_Plane, Constructor_no_throw) {
    EXPECT_NO_THROW(Plane(2.1, 0.3, 1.1, 4.0));
}

TEST(Class_Plane, Copy_constructor_no_throw) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_NO_THROW(Plane b(a));
}

TEST(Class_Plane, Copy_operator_equal_no_throw) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_NO_THROW(Plane b = a);
}
