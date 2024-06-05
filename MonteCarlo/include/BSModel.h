//
// Created by Rakesh Bali on 05/06/2024.
//

#ifndef BSMODEL_H
#define BSMODEL_H

#include <vector>
typedef std::vector<double> SamplePath;

class BSModel {
private:
    double S0, r, sigma;
public:
    BSModel(double S0_, double r_, double sigma_) {
        this->S0 = S0_;
        this->r = r_;
        this->sigma = sigma_;
        srand(time(NULL));
    }

    void GenerateSamplePath(double T, int m, SamplePath& S) const;

    double get_s0() const {
        return S0;
    }

    double get_r() const {
        return r;
    }

    double get_sigma() const {
        return sigma;
    }
};

#endif //BSMODEL_H
