import math
"""
Introduction:
The method starts with a function f() defined over the real numbers x, the 
function's derivative f'(), and an initial guess x0 for a root of the function 
f(), then the function is approximated by its tangent line
y = f'(x0)(x1-x0) + f(x0)
, and one computes the x-intercept of this tangent line (by assign y = 0). 
This x-intercept will typically be a better approximation 
to the function's root than the original guess x0, and with iteration, x0 is 
progressing to the real root and ends when diff < eps.

Args:
    x0: float starting point
    f(x): function over real number x
    Df(x): function's deriative at real number x
    eps: ending bias condition
    
Regurns:
    last x0 is root of f(x), i.e. f(x0) = 0
    this code also prints out above Args of x0, f(x0), Df(x0) and 
    x1: next x0 obtained by x-intercept of tangent line
    Dx: absolute distance between x0 and x1
    
Raises: 
    None
"""

i = 0
eps = 1e-6
x0 = float(input("x0: "))


def f(x):
    return x*math.exp(-x)+math.pow(x, 3.0)+1


def Df(x):
    return math.exp(-x)-x*math.exp(-x)+3*math.pow(x, 2.0)

print('i', "  x0", "  f(x0)", "  Df(x0)", "  x1", "  Dx")
while True:
    x1 = x0-f(x0)/Df(x0)
    Dx = math.fabs(x1-x0)
    print(i+1, "%.4f" % x0, "%.4f" % f(x0), "%.4f" % Df(x0), "%.4f" % x1, "%.4f" % Dx)
    i += 1
    x0 = x1
    if Dx < eps:
        break
