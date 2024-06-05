//
// Created by Rakesh Bali on 05/06/2024.
//
#include "ArithmeticAsianCall.h"

double ArithmeticAsianCall::Payoff(SamplePath& S)
{
    double Ave=0.0;
    for (int k=0; k<get_m(); k++)
        Ave=(k*Ave+S[k])/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}
