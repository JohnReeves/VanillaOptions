//
// Created by John Reeves on 24/05/2025.
//
#ifndef VANILLA_CPP
#define VANILLA_CPP

#include "vanilla.h"

void VanillaOption::init() {
    K = 100.0;
    r = 0.5;
    T = 1.0;
    S = 100.0;
    sigma = 0.2;
}

void VanillaOption::copy(const VanillaOption &other) {
    K = other.K;
    r = other.r;
    T = other.T;
    S = other.S;
    sigma = other.sigma;
}

VanillaOption::VanillaOption() { init(); }

VanillaOption::VanillaOption(
    const double &_strike_price, // K
    const double &_risk_free_rate, // r
    const double &_maturity_time, // T
    const double &_underlying_asset_price, // S
    const double &_volatility_of_underlying_asset) { // sigma

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

VanillaOption::~VanillaOption() = default;

double VanillaOption::getK() const { return K; }
double VanillaOption::getT() const { return T; }
double VanillaOption::getr() const { return r; }
double VanillaOption::getS() const { return S; }
double VanillaOption::getSigma() const { return sigma; }

double VanillaOption::d1() const {
    return (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
}

double VanillaOption::d2() const {
    return d1() - sigma * sqrt(T);
}

double VanillaOption::calc_call_price() const {
    double d_1 = d1();
    double d_2 = d2();
    return S * normalCDF(d_1) - K * std::exp(-r * T) * normalCDF(d_2);
}

double VanillaOption::calc_put_price() const {
    double d_1 = d1();
    double d_2 = d2();
    return K * std::exp(-r * T) * normalCDF(-d_2) - S * normalCDF(-d_1);
}

#endif // VANILLA_CPP
