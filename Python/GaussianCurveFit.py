# -*- coding: utf-8 -*-
"""
Created on Thu Sep  6 17:55:21 2018

@author: chen jin

Fit data to Gaussian profile

Input:
    gaussian function: g(x, vals)
    initial guess of parameter: init_vals = [amp, cen, wid]

Output:
    best_vals with cur_fit
    plot fitted curve on new_x, new_y
    
"""
import numpy as np
from numpy import exp, linspace, random
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt
from matplotlib import pylab

def gaussian(x, amp, cen, wid):
    return amp * exp(-(x-cen)**2 / wid)

x = linspace(-10, 10, 101)
y = gaussian(x, 2.33, 0.21, 1.51) + random.normal(0, 0.2, len(x))

init_vals = [1, 0, 1]  # for [amp, cen, wid]
best_vals, covar = curve_fit(gaussian, x, y, p0=init_vals)
print(best_vals)

# plot the function 
new_x = np.linspace(-10, 10, 20)
new_y = gaussian(new_x, *best_vals)
plt.plot(x, y, 'o', new_x, new_y, '-')
pylab.title('Polynomial Fit with Matplotlib')
plt.show()

