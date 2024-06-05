
#include <AsianOption.h>
#include <BSModel.h>
#include <EuropeanOption.h>
#include <iostream>
using namespace std;

int main()
{
    double S0=100., r=0.03, sigma=0.2;
    BSModel Model(S0,r,sigma);

    double T=0.5, K=100.0;
    int m = 30;

    long N=30000;
    double epsilon=0.001;
    ArithmeticAsianCall Option1(T,K,m);
    Option1.PriceByMC(Model,N,epsilon) ;
    cout << "Arithmetic Call:" << endl;
    cout << "Option Price = " << Option1.get_price() << endl
         << "Pricing Error = " << Option1.get_pricing_error() << endl
         << "        delta = " << Option1.get_delta() << endl
         << "          rho = " << Option1.get_rho() << endl
         << "         vega = " << Option1.get_vega() << endl
         << "        theta = " << Option1.get_theta() << endl
         << "        gamma = " << Option1.get_gamma() << endl;

    EurCall Option2(T,K);
    cout << "European Call:" << endl;
    Option2.PriceByMC(Model,N,epsilon);
    cout << "Option Price = " << Option2.get_price() << endl
         << "Pricing Error = " << Option2.get_pricing_error() << endl
         << "        delta = " << Option2.get_delta() << endl
         << "          rho = " << Option2.get_rho() << endl
         << "         vega = " << Option2.get_vega() << endl
         << "        theta = " << Option2.get_theta() << endl
         << "        gamma = " << Option2.get_gamma() << endl;

    return 0;
}
