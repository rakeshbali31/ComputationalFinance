
#include <AsianOption.h>
#include <BSModel.h>
#include <EuropeanOption.h>
#include <iostream>
using namespace std;


void asianOptionPricing() {
     double S0=100.0, r=0.03, sigma=0.2;
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
}


void asianOptionPricingByVarianceReduction() {
    double S0=100.0, r=0.03, sigma=0.2, epsilon=0.0001;
    BSModel Model(S0,r,sigma);

    double T =1.0/12.0, K=100.0;
    int m=30;

    ArithmeticAsianCall Option(T,K,m);
    GeometricAsianCall  CVOption(T,K,m);

    long N=30000;
    Option.PriceByVarRedMC(Model,N,CVOption);
    cout << "Arithmetic call price = " << Option.get_price() << endl
         << "Error = " << Option.get_pricing_error() << endl;

    Option.PriceByMC(Model,N, epsilon);
    cout << "Price by direct MC = " << Option.get_price() << endl
         << "MC Error = " << Option.get_pricing_error() << endl;
}

int main()
{
     asianOptionPricing();
     cout << endl << endl;
     asianOptionPricingByVarianceReduction();
     return 0;
}

