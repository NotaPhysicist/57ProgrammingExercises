#include <iostream>
#include <cassert>
#include <cmath>
#include <random>

/**
 * This class converts feet to meters and meters to feet, using double
 * precision values, with a tested accuracy of epsilon 1e-9. The class
 * includes a test suite to test accuracy, which will pass silently, or
 * fail with an assertion. 
 */
class FeetToMeterConvert 
{
    public:
        // Constants
        static constexpr double FT_TO_M = 0.3048;        // Feet to meters
        static constexpr double M_TO_F = 1.0 / FT_TO_M;  // Meters to feet
        static constexpr double EPS = 1e-9;              // epsilon value

        // Constructors
        FeetToMeterConvert();

        // Getters
        // Setters
        // Functions
        void test_runtTests();
        double ftToM(double ft);
        double mToFt(double m);
        
        // Test Suite
        void test_BasicConversion();
        void test_RoundTrip();
        void test_AreaScaling();
        void test_EdgeCases();
        void test_RepeatedConversion();
        void test_Randomized();

    private:
        bool nearlyEqual(double a, double b, double eps = EPS);
};

