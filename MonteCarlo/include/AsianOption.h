//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef ASIANOPTION_H
#define ASIANOPTION_H

#include "PathDepOption.h"

class ArithmeticAsianCall: public PathDepOption
{
public:
    double K;
    ArithmeticAsianCall(double T_, double K_, int m_)
    {set_t(T_); K=K_; set_m(m_);}
    double Payoff(SamplePath& S) override;
};

class GeometricAsianCall: public PathDepOption
{
public:
    double K;
    GeometricAsianCall(double T_, double K_, int m_) {
        K=K_; set_t(T_); set_m(m_);
    }
    double Payoff(SamplePath& S) override;
    double PriceByBSFormula(BSModel Model) override;
};

class DifferenceOfOptions: public PathDepOption
{
public:
    PathDepOption* Option1;
    PathDepOption* Option2;
    DifferenceOfOptions(double T_, int m_, PathDepOption* Option1_, PathDepOption* Option2_)
        {set_t(T_); set_m(m_); Option1=Option1_; Option2=Option2_;}
    double Payoff(SamplePath &S) override {
        return Option1->Payoff(S) - Option2->Payoff(S);
    }
};

#endif //ASIANOPTION_H
