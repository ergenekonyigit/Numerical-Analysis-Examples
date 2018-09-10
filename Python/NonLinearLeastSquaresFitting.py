# -*- coding: utf-8 -*-
"""
Created on Wed Sep  5 22:11:24 2018

@author: chen jin

Non-Linear Least-Squares Fitting: solve a curve fitting problem using robust 
loss function to take care of outliers in the data. Define the model function 
as y = a + b * exp(c * x), where t is a predictor variable, y is an observation
and a, b, c are parameters to estimate.
Put all coefficients in beta, this could be write as:
    y = beta[0] + beta[1] * exp(beta[2] * x)
    
Input:
    target function: y = a + b * np.exp(x * c)
    x_train linspace generated
    y_train generated with noise and outliers
    par: parameters (a, b, c) of target function
    loss_fun: loss or residual function (simple f(x) - y used here) 
    beta: initial guess of parameters (a, b, c)
    
Output:
    res_lsq: standard least-squares solution with beta = [*res_lsq.x]
    res_soft_l1: robust soft_11 solution with beta = [*res_soft_l1.x]
    res_log: robust cauchy solution with beta = [*res_log.x]
"""

import numpy as np
from scipy.optimize import least_squares
import matplotlib.pyplot as plt

# First, define the function which generates the data with noise and outliers, 
# define the model parameters with default setting in par

def gen_data(x, par = [0.5, 2, -1], noise=0, n_outliers=0, random_state=0):
    
    a, b, c = par[0], par[1], par[2]
    y = a + b * np.exp(x * c)

    rnd = np.random.RandomState(random_state)
    error = noise * rnd.randn(x.size)
    outliers = rnd.randint(0, x.size, n_outliers)
    error[outliers] *= 10

    return y + error

# generate data
x_train = np.linspace(0, 10, 15)
par = [0.5, 2, -1]
y_train = gen_data(x_train, par, noise=0.1, n_outliers=3)

# Define function for computing Loss (residuals)
def loss_fun(beta, x, y):
    return beta[0] + beta[1] * np.exp(beta[2] * x) - y

# initial estimate of parameters
beta = np.array([1.0, 1.0, 0.0])

# Compute a standard least-squares solution
res_lsq = least_squares(loss_fun, beta, args=(x_train, y_train))

# compute two solutions with two different robust loss functions. 
# The parameter f_scale is set to 0.1, meaning that inlier residuals 
# should not significantly exceed 0.1 (the noise level used)

res_soft_l1 = least_squares(loss_fun, beta, loss='soft_l1', f_scale=0.1,
                            args=(x_train, y_train))
res_log = least_squares(loss_fun, beta, loss='cauchy', f_scale=0.1,
                        args=(x_train, y_train))

# plot all curves
x_test = np.linspace(0, 10, 15 * 10)
y_true = gen_data(x_test, par)
y_lsq = gen_data(x_test, [*res_lsq.x])
y_soft_l1 = gen_data(x_test, [*res_soft_l1.x])
y_log = gen_data(x_test, [*res_log.x])

plt.plot(x_train, y_train, 'o')
plt.plot(x_test, y_true, 'k', linewidth=2, label='true')
plt.plot(x_test, y_lsq, label='linear loss')
plt.plot(x_test, y_soft_l1, label='soft_l1 loss')
plt.plot(x_test, y_log, label='cauchy loss')
plt.xlabel("t")
plt.ylabel("y")
plt.legend()
plt.show()