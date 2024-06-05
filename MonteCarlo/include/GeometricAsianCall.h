//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef GEOMETRICASIANCALL_H
#define GEOMETRICASIANCALL_H
#include "PathDepOption.h"

class GeometricAsianCall: public PathDepOption
{
public:
    double K;
    GeometricAsianCall(double T_, double K_, int m_) {
        K=K_;
        set_t(T_);
        set_m(m_);
    }
    double Payoff(SamplePath& S);
};

#endif //GEOMETRICASIANCALL_H
