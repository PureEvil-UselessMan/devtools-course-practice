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

TEST(Class_Plane, Operator_get_a_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_EQ(a.GetA(), 2.1);
}

TEST(Class_Plane, Operator_get_b_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_EQ(a.GetB(), 0.3);
}

TEST(Class_Plane, Operator_get_c_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_EQ(a.GetC(), 1.1);
}

TEST(Class_Plane, Operator_get_d_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    EXPECT_EQ(a.GetD(), 4.0);
}

TEST(Class_Plane, Operator_set_a_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    a.SetA(1.0);
    EXPECT_EQ(a.GetA(), 1.0);
}

TEST(Class_Plane, Operator_set_b_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    a.SetB(3.1);
    EXPECT_EQ(a.GetB(), 3.1);
}

TEST(Class_Plane, Operator_set_c_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    a.SetC(0.2);
    EXPECT_EQ(a.GetC(), 0.2);
}

TEST(Class_Plane, Operator_set_d_correct) {
    Plane a(2.1, 0.3, 1.1, 4.0);
    a.SetD(1.2);
    EXPECT_EQ(a.GetD(), 1.2);
}

TEST(Class_Space, Relationship_intersection) {
    Space My_Space;
    Line AB(1, 2, 3, 5, 2, 3);
    Plane a(2, 3, -1, 1);
    EXPECT_EQ(My_Space.Relationship(AB, a), 1);
}

TEST(Class_Space, Relationship_parallel) {
    Space My_Space;
    Line AB(1, -2, 2, 2, 3, -4);
    Plane a(1, 6, 5, 4);
    EXPECT_EQ(My_Space.Relationship(AB, a), 0);
}

TEST(Class_Space, Relationship_line_lies_on_the_plane) {
    Space My_Space;
    Line AB(-4, -2, 0, 9, -2, -12);
    Plane a(2, -3, 2, 2);
    EXPECT_EQ(My_Space.Relationship(AB, a), 2);
}

TEST(Class_Space, Relationship_get_point_of_intersection) {
    Space My_Space;
    Line AB(-3, 0, -2, -1, -3, 3);
    Plane a(1, -2, -1, 3);
    double x_common, y_common, z_common;
    My_Space.GetPointOfIntersection(AB, a, &x_common, &y_common, &z_common);
    EXPECT_EQ(x_common, -2);
    EXPECT_EQ(y_common, 3);
    EXPECT_EQ(z_common, -5);
}

TEST(Class_Space, Relationship_point_of_intersection_throw_type_one) {
    Space My_Space;
    Line AB(1, -2, 2, 2, 3, -4);
    Plane a(1, 6, 5, 4);
    double x_common, y_common, z_common;
    EXPECT_ANY_THROW(My_Space.GetPointOfIntersection(AB, a,
                     &x_common, &y_common, &z_common));
}

TEST(Class_Space, Relationship_point_of_intersection_throw_type_two) {
    Space My_Space;
    Line AB(-4, -2, 0, 9, -2, -12);
    Plane a(2, -3, 2, 2);
    double x_common, y_common, z_common;
    EXPECT_ANY_THROW(My_Space.GetPointOfIntersection(AB, a,
                     &x_common, &y_common, &z_common));
}
