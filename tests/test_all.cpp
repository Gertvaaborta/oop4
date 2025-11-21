#include <gtest/gtest.h>
#include <point.h>
#include <triangle.h>
#include <square.h>
#include <rectangle.h>
#include <array.h>

// Point Tests
TEST(PointTest, BasicOperations) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(3.0, 4.0);
    
    EXPECT_DOUBLE_EQ(p1.getX(), 1.0);
    EXPECT_DOUBLE_EQ(p1.getY(), 2.0);
    
    Point<double> sum = p1 + p2;
    EXPECT_DOUBLE_EQ(sum.getX(), 4.0);
    EXPECT_DOUBLE_EQ(sum.getY(), 6.0);
    
    EXPECT_DOUBLE_EQ(p1.distanceTo(p2), sqrt(8.0));
}

// Triangle Tests
TEST(TriangleTest, AreaAndCenter) {
    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(0, 4);
    
    Triangle<double> triangle(p1, p2, p3);
    
    EXPECT_DOUBLE_EQ(triangle.area(), 6.0);
    
    Point<double> center = triangle.geometricCenter();
    EXPECT_DOUBLE_EQ(center.getX(), 1.0);
    EXPECT_DOUBLE_EQ(center.getY(), 4.0/3.0);
}

// Square Tests
TEST(SquareTest, AreaAndCenter) {
    Point<double> center(2, 3);
    Square<double> square(center, 4.0);
    
    EXPECT_DOUBLE_EQ(square.area(), 16.0);
    
    Point<double> result = square.geometricCenter();
    EXPECT_DOUBLE_EQ(result.getX(), 2.0);
    EXPECT_DOUBLE_EQ(result.getY(), 3.0);
}

// Rectangle Tests
TEST(RectangleTest, AreaAndCenter) {
    Point<double> center(1, 1);
    Rectangle<double> rectangle(center, 4.0, 3.0);
    
    EXPECT_DOUBLE_EQ(rectangle.area(), 12.0);
    
    Point<double> result = rectangle.geometricCenter();
    EXPECT_DOUBLE_EQ(result.getX(), 1.0);
    EXPECT_DOUBLE_EQ(result.getY(), 1.0);
}

// Array Tests
TEST(ArrayTest, BasicOperations) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    // Add figures
    Point<double> center(0, 0);
    auto square = std::make_shared<Square<double>>(center, 2.0); // area = 4
    auto rect = std::make_shared<Rectangle<double>>(center, 3.0, 2.0); // area = 6
    
    array.push_back(square);
    array.push_back(rect);
    
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_DOUBLE_EQ(array.totalArea(), 10.0);
    
    // Test erase
    array.erase(0);
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_DOUBLE_EQ(array.totalArea(), 6.0);
}

TEST(ArrayTest, DifferentTypes) {
    // Test with int
    Array<std::shared_ptr<Figure<int>>> intArray;
    Point<int> p1(0, 0), p2(2, 0), p3(0, 2);
    auto triangle = std::make_shared<Triangle<int>>(p1, p2, p3);
    intArray.push_back(triangle);
    
    EXPECT_EQ(intArray.getSize(), 1);
    EXPECT_DOUBLE_EQ(intArray.totalArea(), 2.0);
}

// Concept Test
TEST(ConceptTest, ScalarTypeCheck) {
    // This should compile - double is scalar
    Point<double> p1(1.0, 2.0);
    
    // This should compile - int is scalar  
    Point<int> p2(1, 2);
    
    EXPECT_TRUE(true); // If we get here, concepts work
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
