//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef PATHDEPOPTION_H
#define PATHDEPOPTION_H
#include <BSModel.h>

class PathDepOption
{
private:
    double T, Price, PricingError, delta, gamma;
    int m;
public:
    double PriceByMC(BSModel Model, long N, double epsilon);
    virtual double Payoff(SamplePath& S)=0;

    double get_t() const {
        return T;
    }

    void set_t(const double t) {
        this->T = t;
    }

    int get_m() const {
        return m;
    }

    void set_m(const int m) {
        this->m = m;
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

    double get_gamma() const {
        return gamma;
    }

    void set_gamma(const double gamma) {
        this->gamma = gamma;
    }
};



#endif //PATHDEPOPTION_H
