//
// Created by Rakesh Bali on 05/06/2024.
//
#include "EuropeanOption.h"

double EurCall::Payoff(SamplePath& S)
{
    if (S[0]<K) return 0.0;
    return S[0]-K;
}

double EurPut::Payoff(SamplePath& S)
{
    if (K<S[0]) return 0.0;
    return K-S[0];
}
