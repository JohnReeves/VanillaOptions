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





#endif VANILLA_CPP


