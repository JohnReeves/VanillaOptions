#include <iostream>
#include <iomanip>  // For std::setprecision
#include "vanilla.h"

int main() {
    std::cout << std::fixed << std::setprecision(4);

    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free interest rate (5%)
    double T = 1.0;      // Time to maturity in years
    double S = 100.0;    // Spot price
    double sigma = 0.2;  // Volatility (20%)

    VanillaOption vanilla(
        K,
        r,
        T,
        S,
        sigma);

    std::cout << "Black-Scholes European Option Pricing\n";
    std::cout << "-------------------------------------\n";
    std::cout << "Strike Price:     " << vanilla.getK() << '\n';
    std::cout << "Risk-free Rate:   " << vanilla.getr() * 100 << "%\n";
    std::cout << "Time to Maturity: " << vanilla.getT() << " years\n";
    std::cout << "Spot Price:       " << vanilla.getS() << '\n';
    std::cout << "Volatility:       " << vanilla.getSigma() * 100 << "%\n\n";

    std::cout << "Call Price:     £" << vanilla.calc_call_price() << '\n';
    std::cout << "Put Price:      £" << vanilla.calc_put_price() << '\n';

    return 0;
}