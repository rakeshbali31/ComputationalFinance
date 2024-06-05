//
// Created by Rakesh Bali on 05/06/2024.
//

#include "PathDepOption.h"

double PathDepOption::PriceByMC(BSModel Model, long N) {
    double H = 0.0, Hsq = 0.0;
    SamplePath S(m);
    for(long i=0; i<N; i++) {
        Model.GenerateSamplePath(T, m, S);
        H = (i*H + Payoff(S))/(i+1.0);
        Hsq = (i*Hsq + pow(Payoff(S),2.0)) / (i+1.0);
    }
    Price = exp(-Model.get_r()*T)*H;
    PricingError = exp(-Model.get_r()*T)*sqrt(Hsq - H*H) / sqrt(N-1.0);
    return Price;
}
