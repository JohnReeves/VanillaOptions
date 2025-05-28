//
// Created by John Reeves on 24/05/2025.
//
#ifndef VANILLA_H
#define VANILLA_H

#include <cmath>
using namespace std;

class VanillaOption {

public:
    VanillaOption();
    VanillaOption(const VanillaOption &rhs);
    VanillaOption(
        const double& _strike_price, // K
        const double& _risk_free_rate, // r
        const double& _maturity_time, // T
        const double& _underlying_asset_price, // S
        const double& _volatility_of_underlying_asset // sigma
        );

    VanillaOption& operator=(const VanillaOption &rhs);
    virtual ~VanillaOption();

    double getK() const;
    double getr() const;
    double getT() const;
    double getS() const;
    double getSigma() const;

    double d1() const;
    double d2() const;

    double calc_call_price() const;
    double calc_put_price() const;

private:
    double K{}; //strike_price
    double r{}; // risk_free_rate
    double T{}; // maturity_time
    double S{}; // underlying_asset_price
    double sigma{}; // volatility_of_underlying_asset

    void init();
    void copy(const VanillaOption& other);

    // Standard normal cumulative distribution function (CDF)
    static double normalCDF(double const x) {
        return erfc( -x / sqrt(2) ) / 2;
    };

};

#endif // VANILLA_H
