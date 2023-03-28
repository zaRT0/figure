#include <gtest/gtest.h>
#include <figure/figure.h>

using namespace Figures;

TEST(FigureListTests, CapacityCheck) {
    FigureContainer figures;
    Point p1(1, 3);
    Point p2(2, 4);
    Point p3(3, 6);
    const auto s = Figure::Figure(TRIANGLE, p1, p2, p3);
    for (int i = 0; i < FigureContainer::SIZE; ++i) {
        figures.insert(i, s);
    }

    ASSERT_ANY_THROW(figures.insert(10, s));

}

TEST(IndexOfFigureWithMinValue, NoResult) {
    FigureContainer figures;
    Point p1(1, 3);
    Point p2(2, 4);
    Point p3(3, 6);
    Point p4(4, 8);
    
    const auto index = min_square(figures);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfFigureWithMinValue, ForCircle) {
    FigureContainer figures;

    Point p_c1(1, 2);
    Point p_c2(5, 9);
    Point p_c3(4, 3);
    Point p_c4(15, 11);
    Point p_c5(20, 8);
    Point p_c6(8, 11);
    Point p_c7(7, 12);
    Point p_c8(1, 5);

    figures.insert(0, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(1, Figure::Figure(CIRCLE, p_c3, p_c4));
    figures.insert(2, Figure::Figure(CIRCLE, p_c5, p_c6));
    figures.insert(3, Figure::Figure(CIRCLE, p_c7, p_c8));
    
    const auto index = min_square(figures);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfFigureWithMinValue, ForTriangle) {
    FigureContainer figures;

    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_t4(15, 8);
    Point p_t5(10, 9);
    Point p_t6(8, 7);
    Point p_t7(2, 3);
    Point p_t8(10, 5);
    Point p_t9(12, 4);


    figures.insert(0, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(1, Figure::Figure(TRIANGLE, p_t4, p_t5, p_t6));
    figures.insert(2, Figure::Figure(TRIANGLE, p_t7, p_t8, p_t9));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, ForRectangle) {
    FigureContainer figures;

    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);
    Point p_r5(3, 8);
    Point p_r6(14, 1);
    Point p_r7(2, 7);
    Point p_r8(10, 19);
    Point p_r9(10, 4);
    Point p_r10(9, 1);
    Point p_r11(8, 6);
    Point p_r12(5, 10);
    Point p_r13(3, 8);
    Point p_r14(14, 1);
    Point p_r15(2, 7);
    Point p_r16(10, 19);

    figures.insert(0, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));
    figures.insert(1, Figure::Figure(RECTANGLE, p_r5, p_r6, p_r7, p_r8));
    figures.insert(2, Figure::Figure(RECTANGLE, p_r9, p_r10, p_r11, p_r12));
    figures.insert(3, Figure::Figure(RECTANGLE, p_r13, p_r14, p_r15, p_r16));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfFigureWithMinValue, Mix1) {
    FigureContainer figures;
    
    Point p_c1(1, 2);
    Point p_c2(2, 3);
    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);
    Point p_r5(3, 8);
    Point p_r6(14, 1);
    Point p_r7(2, 7);
    Point p_r8(10, 19);

    figures.insert(0, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(1, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(2, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));
    figures.insert(3, Figure::Figure(RECTANGLE, p_r5, p_r6, p_r7, p_r8));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfFigureWithMinValue, Mix2) {
    FigureContainer figures;
   
    Point p_c1(1, 2);
    Point p_c2(2, 3);
    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_t4(15, 8);
    Point p_t5(10, 9);
    Point p_t6(8, 7);
    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);

    figures.insert(0, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(1, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(2, Figure::Figure(TRIANGLE, p_t4, p_t5, p_t6));
    figures.insert(3, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfFigureWithMinValue, Mix3) { 
    FigureContainer figures;
   
    Point p_c1(1, 2);
    Point p_c2(2, 3);
    Point p_c3(5, 1);
    Point p_c4(7, 10);
    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);

    figures.insert(0, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(1, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));
    figures.insert(2, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(3, Figure::Figure(CIRCLE, p_c3, p_c4));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfFigureWithMinValue, Mix4) {
    FigureContainer figures;
   
    Point p_c1(1, 2);
    Point p_c2(2, 3);
    Point p_c3(5, 1);
    Point p_c4(7, 10);
    Point p_c5(5, 15);
    Point p_c6(3, 11);
    Point p_c7(3, 11);
    Point p_c8(3, 11);
    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_t4(15, 8);
    Point p_t5(10, 9);
    Point p_t6(8, 7);
    Point p_t7(15, 11);
    Point p_t8(6, 7);
    Point p_t9(9, 17);
    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);
    Point p_r5(3, 8);
    Point p_r6(14, 1);
    Point p_r7(2, 7);
    Point p_r8(10, 19);
    Point p_r9(7, 4);
    Point p_r10(5, 9);
    Point p_r11(3, 2);
    Point p_r12(8, 16);

    figures.insert(0, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(1, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(2, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));
    figures.insert(3, Figure::Figure(TRIANGLE, p_t4, p_t5, p_t6));
    figures.insert(4, Figure::Figure(CIRCLE, p_c3, p_c4));
    figures.insert(5, Figure::Figure(RECTANGLE, p_r5, p_r6, p_r7, p_r8));
    figures.insert(6, Figure::Figure(TRIANGLE, p_t7, p_t8, p_t9));
    figures.insert(7, Figure::Figure(RECTANGLE, p_r9, p_r10, p_r11, p_r12));
    figures.insert(8, Figure::Figure(CIRCLE, p_c5, p_c6));
    figures.insert(9, Figure::Figure(CIRCLE, p_c7, p_c8));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 9);
}

TEST(IndexOfFigureWithMinValue, Mix5) {
    FigureContainer figures;
    
    Point p_c1(1, 2);
    Point p_c2(2, 3);
    Point p_c3(5, 1);
    Point p_c4(7, 10);
    Point p_c5(5, 15);
    Point p_c6(3, 11);
    Point p_t1(2, 3);
    Point p_t2(10, 5);
    Point p_t3(12, 4);
    Point p_t4(15, 8);
    Point p_t5(10, 9);
    Point p_t6(8, 7);
    Point p_t7(15, 11);
    Point p_t8(6, 7);
    Point p_t9(9, 17);
    Point p_t10(20, 15);
    Point p_t11(14, 17);
    Point p_t12(2, 10);
    Point p_r1(10, 4);
    Point p_r2(9, 1);
    Point p_r3(8, 6);
    Point p_r4(5, 10);
    Point p_r5(3, 8);
    Point p_r6(14, 1);
    Point p_r7(2, 7);
    Point p_r8(10, 19);
    Point p_r9(7, 4);
    Point p_r10(5, 9);
    Point p_r11(3, 2);
    Point p_r12(8, 16);

    figures.insert(0, Figure::Figure(TRIANGLE, p_t1, p_t2, p_t3));
    figures.insert(1, Figure::Figure(CIRCLE, p_c1, p_c2));
    figures.insert(2, Figure::Figure(RECTANGLE, p_r5, p_r6, p_r7, p_r8));
    figures.insert(3, Figure::Figure(TRIANGLE, p_t4, p_t5, p_t6));
    figures.insert(4, Figure::Figure(RECTANGLE, p_r1, p_r2, p_r3, p_r4));
    figures.insert(5, Figure::Figure(CIRCLE, p_c3, p_c4));
    figures.insert(6, Figure::Figure(TRIANGLE, p_t7, p_t8, p_t9));
    figures.insert(7, Figure::Figure(RECTANGLE, p_r9, p_r10, p_r11, p_r12));
    figures.insert(8, Figure::Figure(TRIANGLE, p_t10, p_t11, p_t12));
    figures.insert(9, Figure::Figure(CIRCLE, p_c5, p_c6));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 7);
}
