# VanillaOptions
Introduction to European vanilla options

https://paperswithbacktest.com/wiki/european-vanilla-call-put-option-pricing-with-python

Black-Scholes Model is used for pricing European options with the following formula for a call option

$`C = S_0 \left( d_1 \right) - X e^{rt} \phi \left( d_2 \right)`$

Where

* $`S_0`$ is the current stock price
* $`X`$ is the strike price
* $`r`$ is the risk-free interest rate
* $`t`$ is the time to expiration
* $`\phi`$ is the cumulative distribution function of the standard normal distribution
* $`d_0 = \frac{ln \left( S_0 / X \right) + \left( r + \sigma^2 / 2  \right) t}{\sigma \sqrt(t)}`$
* $`d_1 - \sigma \sqrt(t)`$

Although the model can be succinctly encoded with a few lines of Python, we will be using C++, just because :-)

```python
import numpy as np
from scipy.stats import norm

def black_scholes_call(S, X, t, r, sigma):
    d1 = (np.log(S / X) + (r + 0.5 * sigma**2) * t) / (sigma * np.sqrt(t))
    d2 = d1 - sigma * np.sqrt(t)
    call = S * norm.cdf(d1) - X * np.exp(-r * t) * norm.cdf(d2)
    return call

# Example usage
S = 100  # Current stock price
X = 105  # Strike price
t = 1    # Time to expiration (in years)
r = 0.05 # Risk-free interest rate
sigma = 0.2  # Volatility

call_price = black_scholes_call(S, X, t, r, sigma)
```
