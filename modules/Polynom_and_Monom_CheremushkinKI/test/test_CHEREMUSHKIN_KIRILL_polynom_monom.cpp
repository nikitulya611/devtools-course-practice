// Copyright 2022 Cheremushkin Kirill
#include <gtest/gtest.h>
#include "include/Polynom.h"
#include "include/Monom.h"

TEST(Cheremushkin_Kirill_Monom, Monom_plus_Monom) {
    // Create Monom
    Monom test1(3, 3);  // Create  monom 1-coef, 2-degree
    Monom test2(2, 3);
    Monom res(0, 0);
    // Act
    res = test1 + test2;

    // Assert
    ASSERT_EQ(5, res.GetCoef());
}
TEST(Cheremushkin_Kirill_Monom, Monom_minus_Monom) {
    // Create Monom
    Monom test1(3, 3);  // Create  monom 1-coef, 2-degree
    Monom test2(2, 3);
    Monom res(0, 0);
    // Act
    res = test1 - test2;

    // Assert
    ASSERT_EQ(1, res.GetCoef());
}
TEST(Cheremushkin_Kirill_Monom, Monom_multiplication_Monom) {
    // Create Monom
    Monom test1(5, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom res(0, 0);
    // Act
    res = test1 * test2;

    // Assert
    ASSERT_EQ(15, res.GetCoef());
    ASSERT_EQ(6, res.GetDegree());
}
TEST(Cheremushkin_Kirill_Monom, Monom_division_Monom) {
    // Create Monom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom res(0, 0);
    // Act
    res = test1 / test2;

    // Assert
    ASSERT_EQ(2, res.GetCoef());
    ASSERT_EQ(2, res.GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Monom, Polynom_plus_Monom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test(4, 4);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test2 = Test1 + test2;
    Res = Test2 + test;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(10, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(4, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(3, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(2, Res.GetStartMonom()->GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Monom, Polynom_minus_Monom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test(4, 4);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test2 = Test1 + test2;
    Res = Test2 - test;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(2, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(4, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(3, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(2, Res.GetStartMonom()->GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Monom, Polynom_multiplication_Monom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test(4, 4);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test2 = Test1 + test2;
    Res = Test2 * test;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(24, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(8, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(12, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(6, Res.GetStartMonom()->GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Monom, Polynom_division_Monom) {
    // Create Monom  & Polynom
    Monom test1(8, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(8, 4);
    Monom test(4, 4);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test2 = Test1 + test2;
    Res = Test2 /test;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(4, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(0, Res.GetStartMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Polynom, Polynom_plus_Polynom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test3(4, 5);
    Monom test4(5, 2);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test1.SetSize(2);
    Test2.SetSize(2);
    Test2.GetStartMonom()->SetCoef(test3.GetCoef());
    Test2.GetStartMonom()->SetDegree(test3.GetDegree());
    Test1.GetStartMonom()->SetNextMonom(test2);
    Test2.GetStartMonom()->SetNextMonom(test4);
    Res = Test1 + Test2;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(6, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(4, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(8, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(2, Res.GetStartMonom()->GetNextMonom()->GetDegree());
    ASSERT_EQ(4, Res.GetStartMonom()->GetNextMonom()->
        GetNextMonom()->GetCoef());
    ASSERT_EQ(5, Res.GetStartMonom()->
        GetNextMonom()->GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Polynom, Polynom_minus_Polynom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test3(4, 5);
    Monom test4(5, 2);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test1.SetSize(2);
    Test2.SetSize(2);
    Test2.GetStartMonom()->SetCoef(test3.GetCoef());
    Test2.GetStartMonom()->SetDegree(test3.GetDegree());
    Test1.GetStartMonom()->SetNextMonom(test2);
    Test2.GetStartMonom()->SetNextMonom(test4);
    Res = Test1 - Test2;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(6, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(4, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(-2, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(2, Res.GetStartMonom()->GetNextMonom()->GetDegree());
    ASSERT_EQ(-4, Res.GetStartMonom()->GetNextMonom()->
        GetNextMonom()->GetCoef());
    ASSERT_EQ(5, Res.GetStartMonom()->GetNextMonom()->
        GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Polynom, Polynom_multiplication_Polynom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);   // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test3(4, 5);
    Monom test4(5, 2);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test1.SetSize(2);
    Test2.SetSize(2);
    Test2.GetStartMonom()->SetCoef(test3.GetCoef());
    Test2.GetStartMonom()->SetDegree(test3.GetDegree());
    Test1.GetStartMonom()->SetNextMonom(test2);
    Test2.GetStartMonom()->SetNextMonom(test4);
    Res = Test1 * Test2;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(120, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(11, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(60, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(9, Res.GetStartMonom()->GetNextMonom()->GetDegree());
}
TEST(Cheremushkin_Kirill_Polynom_Polynom, Polynom_division_Polynom) {
    // Create Monom  & Polynom
    Monom test1(6, 4);  // Create  monom 1-coef, 2-degree
    Monom test2(3, 2);
    Monom test3(4, 5);
    Monom test4(5, 2);
    Polynom Test1(1);
    Polynom Res(1);
    Monom res(0, 0);
    // Act
    Test1.GetStartMonom()->SetCoef(test1.GetCoef());
    Test1.GetStartMonom()->SetDegree(test1.GetDegree());
    Polynom Test2(Test1);
    Test1.SetSize(2);
    Test2.SetSize(2);
    Test2.GetStartMonom()->SetCoef(test3.GetCoef());
    Test2.GetStartMonom()->SetDegree(test3.GetDegree());
    Test1.GetStartMonom()->SetNextMonom(test2);
    Test2.GetStartMonom()->SetNextMonom(test4);
    Res = Test1 / Test2;
    Res.Equalizer();
    // Assert
    ASSERT_EQ(0.3, Res.GetStartMonom()->GetCoef());
    ASSERT_EQ(-3, Res.GetStartMonom()->GetDegree());
    ASSERT_EQ(0.15, Res.GetStartMonom()->GetNextMonom()->GetCoef());
    ASSERT_EQ(-5, Res.GetStartMonom()->GetNextMonom()->GetDegree());
}
