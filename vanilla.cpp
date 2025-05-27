//
// Created by John Reeves on 24/05/2025.
//

#ifndef VANILLA_CPP
#define VANILLA_CPP

#include "vanilla.h"
#include <cmath>

void VanillaOption::init() {
    K = 100.0;
    r = 0.5;
    T = 1.0;
    S =100.0;
    sigma = 0.2;
}

void VanillaOption::copy(const VanillaOption &other) {
    K = other.K;
    r = other.r;
    T = other.T;
    S = other.S;
    sigma = other.sigma;
}

VanillaOption::VanillaOption() {
    init();
}

VanillaOption::VanillaOption(
    const double &_strike_price,
    const double &_risk_free_rate,
    const double &_maturity_time,
    const double &_underlying_asset_price,
    const double &_volatility_of_underlying_asset) {

    K = _strike_price;
    r = _risk_free_rate;
    T = _maturity_time;
    S = _underlying_asset_price;
    sigma = _volatility_of_underlying_asset;
}

VanillaOption::VanillaOption(const VanillaOption &rhs) {
    copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption &rhs) {
    if (this != &rhs) {
        copy(rhs);
    }
    return *this;
}

VanillaOption::~VanillaOption() {
    // compiler tidy up
}

double VanillaOption::getK() const {
    return K;
}

double VanillaOption::getT() const {
    return r;
}

double VanillaOption::getr() const {
    return T;
}

double VanillaOption::getS() const {
    return S;
}

double VanillaOption::getSigma() const {
    return sigma;
}

double normalCDF(double const x) {
    return erfc( -x / sqrt(2) ) / 2;
}

double VanillaOption::calc_call_price() const {
    double const sigma_sqrt_T = sigma * sqrt( T );
    double const d1 = ( ( log( S / K ) )
                    + ( r + 0.5 * pow( sigma, 2.0 ) ) * T )
                    / sigma_sqrt_T;
    double const d2 = d1 - sigma_sqrt_T;
    double const call = K * normalCDF(d1)
                      - K * exp(r * T)
                      * normalCDF(d2);
    return call;
}


#endif VANILLA_CPP
