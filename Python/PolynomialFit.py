# -*- coding: utf-8 -*-
"""
Created on Wed Sep  5 20:43:32 2018

@author: chen jin

Polynomial Fitting with polyfit: yj = sum(pi * xj ^ (n + 1 - i))

Input:
    x : array_like, shape (n,)
    y : array_like, shape (n,) 
    
Output:
    f : A one-dimensional polynomial class fit to x, y at degree n
    plot of fitted function along new_x
"""
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import pylab

# n is degree of polynomial
n = 3
# initialise input list of x and y pairs
x = np.linspace(0, 1, 20)
y = np.cos(x) + 0.3*np.random.rand(20)
# error detection
if len(x) != len(y):
    print("x and y must have same length")
# fit a polynomial class with x, y and degree of 3, pi are saved in fit
fit = np.polyfit(x, y, 3)
# ploy1d encapsulate one-dimensional polynomial with pi from fit
f = np.poly1d(fit)
print(f)

# plot the function 
new_x = np.linspace(0, 1, 200)
print(f(new_x).3)
plt.plot(x, y, 'o', new_x, f(new_x), '-')
pylab.title('Polynomial Fit with Matplotlib')
plt.show()