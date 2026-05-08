#include "Shape.h"
// #include "ShapeCollection.h"  // for the first practice test
// #include "Console.h"          // for the first practice test

#include <print>

bool almostEqual(double a, double b, int decimalPlaces);
// void firstTest();  // first attempt at testing
void check(bool condition, const char* testName);


int main()
{
    // Prepare inputs
    Rectangle r1(3500, 4800);
    // Rectangle r2(4523, 2364);
    // Rectangle r2(2313, 2005);
    
    // Call the function
    r1.calcArea();  // (3500 mm * 4800 mm) / 10^6 = 16.8 m^2
    
    // Verfity output
    check((almostEqual(r1.getArea() ,16.8, 3)), "rectangle calculate area");
    
    return 0;
}


void check(bool condition, const char* testName)
{
    if (condition) {
        std::println("PASS: {}", testName);
    }
    else {
        std::println("FAIL: {}", testName);
    }
}

/**
 * Check the equality of two double values to the accuracy of n 
 * decimal places. 
 */
bool almostEqual(double a, double b, int decimalPlaces)
{
    double scale = std::pow(10.0, decimalPlaces);
    return std::round(a * scale) == std::round(b * scale);
}


// void firstTest()  // before I knew what I was doing. 
//                   // Figured out pretty quick I had better learn unit testing..
// {
//     Console console;
//     ShapeCollection collection;

//     collection.add<Rectangle>(3500, 4800);
//     collection.add<Rectangle>(4000, 3820);
//     collection.add<Rectangle>(2800, 5200);

//     collection.add<Circle>(3200);
//     collection.add<Circle>(1500);
//     collection.add<Circle>(2000);

//     collection.calcTotalArea();
//     collection.calcTotalLiters();

//     std::println("\nTEST SUITE");
//     std::println("Total area: {} m^2", collection.getTotalArea());
//     std::println("Total liters: {} liters\n", collection.getLiters());

//                                                  // Test accuracy to 3 significant figures
//     [[maybe_unused]] double areaR1{ 3500 * 4800 };             // 16,800,000 / 1,000,000 = 16.8 m^2
//     [[maybe_unused]] double areaR2{ 4000 * 3820 };             // 15,280,000 / 1,000,000 = 15.28 m^2
//     [[maybe_unused]] double areaR3{ 2800 * 5200 };             // 14,560,000 / 1,000,000 = 14.56 m^2
//     [[maybe_unused]] double areaC1{ 3200 * std::numbers::pi }; // 3200 / 1000 * PI       = 10.05309
//     [[maybe_unused]] double areaC2{ 1500 * std::numbers::pi }; // 1500 / 1000 * PI       =  4.71238
//     [[maybe_unused]] double areaC3{ 2000 * std::numbers::pi }; // 2000 / 1000 * PI       =  6.28318
//                                                                //                          --------
//                                                                // Total area:              67.68865 

//     double areaActual   = collection.getTotalArea();
//     double areaExpected = 67.68865;
//     std::println("Test Total Area:");
//     std::println("  expected: {}", areaExpected);
//     std::println("    actual: {}", areaActual);
//     std::println("    passed: {}", almostEqual(areaActual, areaExpected, 3));
// }
