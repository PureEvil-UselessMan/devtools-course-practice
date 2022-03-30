// Copyright 2022 Olynin Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Olynin_Alexandr_ComplexNumberTest, Initialize) {
    EXPECT_NO_THROW(ComplexNumber num(3.22, 3.21));
}

TEST(Olynin_Alexandr_ComplexNumberTest, Initialize_Correct) {
    ComplexNumber num(3.22, 3.21);

    EXPECT_EQ(3.22, num.getRe());
    EXPECT_EQ(3.21, num.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Set_Correct) {
    ComplexNumber num;
    double re = 1.0;
    double im = 2.0;

    num.setRe(re);
    num.setIm(im);

    EXPECT_EQ(1.0, num.getRe());
    EXPECT_EQ(2.0, num.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Copy) {
    ComplexNumber num_1(3.1, 1.2);

    EXPECT_NO_THROW(ComplexNumber num_2(num_1));
}

TEST(Olynin_Alexandr_ComplexNumberTest, Copy_Correct) {
    ComplexNumber num_1(3.1, 1.2);

    ComplexNumber num_2(num_1);

    EXPECT_EQ(num_1.getRe(), num_2.getRe());
    EXPECT_EQ(num_1.getIm(), num_2.getIm());
    EXPECT_EQ(3.1, num_2.getRe());
    EXPECT_EQ(1.2, num_2.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Equal_Correct) {
    ComplexNumber num_1(3.2, 2.3);
    ComplexNumber num_2(1.1, 1.2);

    num_2 = num_1;

    EXPECT_EQ(num_1.getRe(), num_2.getRe());
    EXPECT_EQ(num_1.getIm(), num_2.getIm());
    EXPECT_EQ(3.2, num_2.getRe());
    EXPECT_EQ(2.3, num_2.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Sum_Correct) {
    ComplexNumber num_1(2.0, 5.2);
    ComplexNumber num_2(3.1, 4.0);
    ComplexNumber res;

    res = num_1 + num_2;

    EXPECT_DOUBLE_EQ(num_1.getRe() + num_2.getRe(), res.getRe());
    EXPECT_DOUBLE_EQ(num_1.getIm() + num_2.getIm(), res.getIm());
    EXPECT_DOUBLE_EQ(5.1, res.getRe());
    EXPECT_DOUBLE_EQ(9.2, res.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Prod_Correct) {
    ComplexNumber num_1(2.0, 5.2);
    ComplexNumber num_2(3.1, 4.0);
    ComplexNumber res;

    res = num_1 * num_2;

    EXPECT_DOUBLE_EQ(-14.6, res.getRe());
    EXPECT_DOUBLE_EQ(24.12, res.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Diff_Correct) {
    ComplexNumber num_1(2.0, 5.2);
    ComplexNumber num_2(3.1, 4.0);
    ComplexNumber res;

    res = num_1 - num_2;

    EXPECT_DOUBLE_EQ(num_1.getRe() - num_2.getRe(), res.getRe());
    EXPECT_DOUBLE_EQ(num_1.getIm() - num_2.getIm(), res.getIm());
    EXPECT_DOUBLE_EQ(-1.1, res.getRe());
    EXPECT_DOUBLE_EQ(1.2, res.getIm());
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Is_Equal_Correct) {
    ComplexNumber num_1(5.5, 6.0);
    ComplexNumber num_2;

    num_2 = num_1;

    EXPECT_TRUE(num_1 == num_2);
}

TEST(Olynin_Alexandr_ComplexNumberTest, Operator_Is_Not_Equal_Correct) {
    ComplexNumber num_1(5.5, 6.0);
    ComplexNumber num_2;

    num_2 = num_1;

    EXPECT_FALSE(num_1 != num_2);
}
