//
// Created by John Reeves on 24/05/2025.
//
#ifndef VANILLA_H
#define VANILLA_H
class VanillaOption {

public:
    VanillaOption();
    VanillaOption(const VanillaOption &rhs);
    VanillaOption(
        const double& _strike_price,
        const double& _risk_free_rate,
        const double& _maturity_time,
        const double& _underlying_asset_price,
        const double& _volatility_of_underlying_asset
        );
    VanillaOption& operator=(const VanillaOption &rhs);
    virtual ~VanillaOption();

    double get_strike_price() const;
    double get_risk_free_rate() const;
    double get_maturity_time() const;
    double get_underlying_asset_price() const;
    double get_volatility_asset_price() const;

    double calc_call_price() const;
    double calc_put_price() const;

private:
    void init();
    void copy(const VanillaOption& other);

    double strike_price;
    double risk_free_rate;
    double maturity_time;
    double underlying_asset_price;
    double volatility_of_underlying_asset;

};


#endif VANILLA_H
