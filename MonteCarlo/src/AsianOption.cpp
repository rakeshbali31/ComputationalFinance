//
// Created by Rakesh Bali on 05/06/2024.
//

#include <AsianOption.h>
#include <EuropeanOption.h>

double ArithmeticAsianCall::Payoff(SamplePath& S)
{
    double Ave=0.0;
    for (int k=0; k<get_m(); k++)
        Ave=(k*Ave+S[k])/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}

double GeometricAsianCall::Payoff(SamplePath &S) {
    double Prod=1.0;
    int m = get_m();
    for (int i=0; i<m; i++)
    {
        Prod=Prod*S[i];
    }
    if (pow(Prod,1.0/m)<K) return 0.0;
    return pow(Prod,1.0/m)-K;
}

double GeometricAsianCall::PriceByBSFormula(BSModel Model) {
    double r = Model.get_r(), sigma = Model.get_sigma();
    double T = get_t(), S0 = Model.get_s0(), m = get_m();

    double a = exp(-r*T)*S0*exp((m+1.0)*T/(2.0*m)*(r+sigma*sigma*((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
    double b = sigma * sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
    EurCall G(T, K);
    double price = G.PriceByBSFormula(a, b, r);
    set_price(price);
    return price;
}
