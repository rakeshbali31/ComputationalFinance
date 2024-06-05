//
// Created by Rakesh Bali on 05/06/2024.
//
#include <GeometricAsianCall.h>

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
