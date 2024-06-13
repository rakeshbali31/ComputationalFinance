//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef EUROPEANOPTION_H
#define EUROPEANOPTION_H

#include "PathDepOption.h"

class EurCall: public PathDepOption
{
public:
    double K;
    EurCall(double T_, double K_)
    {set_t(T_); K=K_;set_m(1);}
    double Payoff(SamplePath& S);

    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0,
       double sigma, double r);
    double VegaByBSFormula(double S0,
       double sigma, double r);
};

class EurPut: public PathDepOption
{
public:
    double K;
    EurPut(double T_, double K_)
    {set_t(T_); K=K_;set_m(1);}
    double Payoff(SamplePath& S);
};

#endif //EUROPEANOPTION_H
