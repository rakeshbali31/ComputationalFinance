#include <ArithmeticAsianCall.h>
#include <GeometricAsianCall.h>
#include <BSModel.h>
#include <iostream>

int main()
{
    double S0=100.0, r=0.03, sigma=0.2, epsilon=0.001;
    BSModel Model(S0,r,sigma);

    double T=1.0/12.0, K=100.0;
    int m=30;
    ArithmeticAsianCall ArithmeticAsianCallOption(T,K,m);
    GeometricAsianCall GeometricAsianCallOption(T,K,m);

    long N=30000;
    std::cout << "Arithmetic Asian Call Option Price = " << ArithmeticAsianCallOption.PriceByMC(Model,N, epsilon) << std::endl;
    std::cout << "Pricing Error = " << ArithmeticAsianCallOption.get_pricing_error() << std::endl;
    std::cout << "Delta = " << ArithmeticAsianCallOption.get_delta() << std::endl;
    std::cout << "Gamma = " << ArithmeticAsianCallOption.get_gamma() << std::endl;

    std::cout << "Geometric Asian Call Option Price = " << GeometricAsianCallOption.PriceByMC(Model,N, epsilon) << std::endl;
    std::cout << "Pricing Error = " << GeometricAsianCallOption.get_pricing_error() << std::endl;
    std::cout << "Delta = " << GeometricAsianCallOption.get_delta() << std::endl;
    std::cout << "Gamma = " << GeometricAsianCallOption.get_gamma() << std::endl;

    return 0;
}
