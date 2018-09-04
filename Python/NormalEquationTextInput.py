# -*- coding: utf-8 -*-
"""
Created on Tue Sep  4 20:53:17 2018

@author: chen jin

Introduction: simple implementation of normal equation solving linear model
    i.e. y = theta0 + theta1* x1 + ...thetan * Xn = Theta * X
    According to normal equation: Theta = inv(X.T * X) * X.T * y
    
    Args:
        X, y reading input from txt file
        estimated Theta: theta_best
        
    Returns:
        estimated model with theta_best
"""

# Modules
import numpy as np

# Loading data set
y, X = np.loadtxt('data\cricket_chirps_versus_temperature.txt', delimiter=',', unpack=True)

def normalEquation(X, y):
    # number of examples n
    n = len(y)
    theta = []

    # add bias to X
    X_b = np.c_[np.ones((n, 1)), X]

    # Normal Equation:
    # theta = inv(X^T * X) * X^T * y
    # Calculating theta
    theta = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)
    return theta

theta_best = normalEquation(X, y)
print('estimated model: y = %.3f + %.3f * x1' % (theta_best[0], theta_best[1]))