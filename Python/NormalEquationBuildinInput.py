# -*- coding: utf-8 -*-
"""
Created on Tue Sep  4 20:22:55 2018

@author: chen jin

Introduction: simple implementation of normal equation solving linear model:
    i.e. y = theta0 + theta1* x1 + ...thetan * Xn = Theta * X
    According to normal equation: Theta = inv(X.T * X) * X.T * y
    
    Args:
        build in random generated X, y
        estimated Theta: theta_best
        random generated X_new
        
    Returns:
        y_predict the y prediected at X_new
"""

import numpy as np

# random generate X, y
X = 2 * np.random.rand(100, 1)
y = 4 + 3 * X + np.random.randn(100, 1)

# add bias x0 = 1 to each instance
X_b = np.c_[np.ones((100, 1)), X] 
# apply normal equation estimate Theta 
theta_best = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)

X_new = np.array([[0], [2]])
# add bias x0 = 1 to each instance
X_new_b = np.c_[np.ones((2, 1)), X_new]  
y_predict = X_new_b.dot(theta_best)
print('estimated model: y = %.3f + %.3f * x1' % (theta_best[0], theta_best[1]))
for i in range(len(y_predict)):
    print('Prediected y = %.3f at x = %.3f' % (y_predict[i], X_new[i]))