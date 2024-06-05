//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef ARTHMASIANCALL_H
#define ARTHMASIANCALL_H

#include "PathDepOption.h"

class ArithmeticAsianCall: public PathDepOption
{
public:
    double K;
    ArithmeticAsianCall(double T_, double K_, int m_)
    {set_t(T_); K=K_; set_m(m_);}
    double Payoff(SamplePath& S);
};

#endif //ARTHMASIANCALL_H
