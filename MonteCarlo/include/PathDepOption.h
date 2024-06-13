//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef PATHDEPOPTION_H
#define PATHDEPOPTION_H
#include <BSModel.h>

class PathDepOption
{
private:
    double T, Price, PricingError, delta, rho, vega, theta, gamma;
    int m;
public:
    virtual ~PathDepOption() = default;

    double PriceByMC(BSModel Model, long N, double epsilon);
    virtual double Payoff(SamplePath& S)=0;
    double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption);
    virtual double PriceByBSFormula(BSModel Model) {return 0.0;}

    double get_t() const {
        return T;
    }

    void set_t(const double t) {
        T = t;
    }

    double get_price() const {
        return Price;
    }

    void set_price(const double price) {
        Price = price;
    }

    double get_pricing_error() const {
        return PricingError;
    }

    void set_pricing_error(const double pricing_error) {
        PricingError = pricing_error;
    }

    double get_delta() const {
        return delta;
    }

    void set_delta(const double delta) {
        this->delta = delta;
    }

    double get_rho() const {
        return rho;
    }

    void set_rho(const double rho) {
        this->rho = rho;
    }

    double get_vega() const {
        return vega;
    }

    void set_vega(const double vega) {
        this->vega = vega;
    }

    double get_theta() const {
        return theta;
    }

    void set_theta(const double theta) {
        this->theta = theta;
    }

    double get_gamma() const {
        return gamma;
    }

    void set_gamma(const double gamma) {
        this->gamma = gamma;
    }

    int get_m() const {
        return m;
    }

    void set_m(const int m) {
        this->m = m;
    }
};



#endif //PATHDEPOPTION_H
