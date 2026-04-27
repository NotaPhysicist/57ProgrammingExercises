#include "FeetToMeterConvert.h"


FeetToMeterConvert::FeetToMeterConvert()
{
}


void FeetToMeterConvert::test_runtTests()
{
    test_BasicConversion();
    test_RoundTrip();
    test_AreaScaling();
    test_EdgeCases();
    test_RepeatedConversion();
    test_Randomized();       
}


double FeetToMeterConvert::ftToM(double ft)
{
    return ft * FT_TO_M;
}


double FeetToMeterConvert::mToFt(double m)
{
    return m * M_TO_F;
}


void FeetToMeterConvert::test_BasicConversion()
{
    // Feet to meters
    assert(nearlyEqual(ftToM(1.0), 0.3048));
    assert(nearlyEqual(ftToM(10.0), 3.048));
    assert(nearlyEqual(ftToM(0.0), 0.0));

    // Meters to feet
    assert(nearlyEqual(mToFt(1.0), 3.280839895));
}


void FeetToMeterConvert::test_RoundTrip() 
{
    double values[] = {0.001, 1.0, 123.456, 1e6};
    for (double v : values)
    {
        double back = mToFt(ftToM(v));
        assert(nearlyEqual(v, back));
    }    
}


void FeetToMeterConvert::test_AreaScaling() 
{
    double w = 10.0;
    double h = 12.0;

    double area_ft = w * h;

    double area_m1 = ftToM(w) * ftToM(h);
    double area_m2 = area_ft * (FT_TO_M * FT_TO_M);

    assert(nearlyEqual(area_m1, area_m2));
}


void FeetToMeterConvert::test_EdgeCases() 
{
    double small = 1e-9;
    double large = 1e9;

    assert(nearlyEqual(mToFt(ftToM(small)), small));
    assert(nearlyEqual(mToFt(ftToM(large)), large));

    double frac = 0.1;
    assert(nearlyEqual(mToFt(ftToM(frac)), frac));
}


void FeetToMeterConvert::test_RepeatedConversion() 
{
    double value = 1.0;

    for (int i = 0; i < 1'000'000; i++)
    {
        value = ftToM(value);
        value = mToFt(value);
    }

    assert(nearlyEqual(value, 1.0, 1e-6));  // relaxed tolerance
}


void FeetToMeterConvert::test_Randomized() 
{
    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(0.0, 10000.0);

    for (int i = 0; i < 10000; i++) 
    {
        double v = dist(rng);
        double back = mToFt(ftToM(v));
        assert(nearlyEqual(v, back));
    }
}

/**
 * Utility: relative comparison
 */
bool FeetToMeterConvert::nearlyEqual(double a, double b, double eps)
{
    return std::fabs(a - b) 
        <= eps * std::fmax(1.0, std::fmax(std::fabs(a), std::fabs(b)));
}


