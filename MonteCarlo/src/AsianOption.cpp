//
// Created by Rakesh Bali on 05/06/2024.
//

#include "AsianOption.h"

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