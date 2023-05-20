#include <gtest/gtest.h>
#include <figure/figure.h>

using namespace Figures;
using namespace std;

TEST(MaxSumNthElemIndex, NoResult) {
    FigureContainer figures;
    const auto index = min_square(figures);
    ASSERT_EQ(index, -1);
}

TEST(IndexOfFigureWithMinValue, ForCircle) {
    FigureContainer figures;
    figures.insert(make_shared<Circle>(Point(1, 2), Point(5, 9)));
    figures.insert(make_shared<Circle>(Point(4, 3), Point(15, 11)));
    figures.insert(make_shared<Circle>(Point(20, 8), Point(8, 11)));
    figures.insert(make_shared<Circle>(Point(7, 12), Point(1, 5)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 0);
}

TEST(IndexOfFigureWithMinValue, ForTriangle) {
    FigureContainer figures;
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Triangle>(Point(3, 4), Point(11, 6), Point(7, 10)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 1);
}

TEST(IndexOfFigureWithMinValue, ForRectangle) {
    FigureContainer figures;
    figures.insert(make_shared<Rectangle>(Point(10, 4), Point(9, 1)));
    figures.insert(make_shared<Rectangle>(Point(8, 6), Point(5, 10)));
    figures.insert(make_shared<Rectangle>(Point(3, 8), Point(14, 1)));
    figures.insert(make_shared<Rectangle>(Point(2, 7), Point(10, 19)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 0);
}

TEST(IndexOfFigureWithMinValue, Mix1) {
    FigureContainer figures;
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 3)));
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Rectangle>(Point(10, 4), Point(9, 1)));
    figures.insert(make_shared<Rectangle>(Point(8, 6), Point(5, 10)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix2) {
    FigureContainer figures;
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 3)));
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Triangle>(Point(15, 8), Point(10, 9), Point(8, 7)));
    figures.insert(make_shared<Rectangle>(Point(10, 4), Point(9, 1)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 3);
}

TEST(IndexOfFigureWithMinValue, Mix3) { 
    FigureContainer figures;
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 3)));
    figures.insert(make_shared<Circle>(Point(5, 1), Point(7, 10)));
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Rectangle>(Point(10, 4), Point(9, 1)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 3);
}

TEST(IndexOfFigureWithMinValue, Mix4) {
    FigureContainer figures;
    figures.insert(make_shared<Triangle>(Point(2, 3), Point(10, 5), Point(12, 4)));
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 3)));
    figures.insert(make_shared<Rectangle>(Point(10, 4), Point(9, 1)));
    figures.insert(make_shared<Triangle>(Point(15, 8), Point(10, 9), Point(8, 7)));
    figures.insert(make_shared<Circle>(Point(5, 1), Point(7, 10)));
    figures.insert(make_shared<Rectangle>(Point(8, 6), Point(5, 10)));
    figures.insert(make_shared<Triangle>(Point(15, 11), Point(6, 7), Point(9, 17)));
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 3)));
    figures.insert(make_shared<Circle>(Point(5, 15), Point(3, 11)));
    figures.insert(make_shared<Rectangle>(Point(7, 4), Point(3, 2)));
    figures.insert(make_shared<Triangle>(Point(3, 8), Point(4, 10), Point(5, 3)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix5) {
    FigureContainer figures;
    figures.insert(make_shared<Triangle>(Point(3, 4), Point(10, 5), Point(17, 4)));
    figures.insert(make_shared<Circle>(Point(9, 4), Point(5, 3)));
    figures.insert(make_shared<Rectangle>(Point(11, 4), Point(9, 9)));
    figures.insert(make_shared<Triangle>(Point(4, 8), Point(9, 10), Point(2, 3)));
    figures.insert(make_shared<Rectangle>(Point(7, 4), Point(1, 2)));
    figures.insert(make_shared<Circle>(Point(5, 11), Point(3, 12)));
    figures.insert(make_shared<Triangle>(Point(3, 2), Point(4, 13), Point(9, 7)));
    figures.insert(make_shared<Rectangle>(Point(7, 4), Point(3, 2)));
    figures.insert(make_shared<Triangle>(Point(3, 7), Point(4, 11), Point(8, 3)));
    figures.insert(make_shared<Circle>(Point(1, 2), Point(2, 4)));
    const auto index = min_square(figures);
    ASSERT_EQ(index, 0);
}