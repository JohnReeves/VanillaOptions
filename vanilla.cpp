//
// Created by John Reeves on 24/05/2025.
//

#ifndef VANILLA_CPP
#define VANILLA_CPP
#include "vanilla.h"
#include <cmath>

void VanillaOption::init() {
    strike_price = 100.0;
    risk_free_rate = 0.5;
    maturity_time = 1.0;
    underlying_asset_price =100.0;
    volatility_of_underlying_asset = 0.2;
}

void VanillaOption::copy(const VanillaOption &other) {
    strike_price = other.strike_price;
    risk_free_rate = other.risk_free_rate;
    maturity_time = other.maturity_time;
    underlying_asset_price = other.underlying_asset_price;
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

    strike_price = _strike_price;
    risk_free_rate = _risk_free_rate;
    maturity_time = _maturity_time;
    underlying_asset_price = _underlying_asset_price;
    volatility_of_underlying_asset = _volatility_of_underlying_asset;
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

double VanillaOption::get_strike_price() const {
    return strike_price;
}

double VanillaOption::get_risk_free_rate() const {
    return risk_free_rate;
}

double VanillaOption::get_maturity_time() const {
    return maturity_time;
}

double VanillaOption::get_underlying_asset_price() const {
    return underlying_asset_price;
}


#endif VANILLA_CPP


