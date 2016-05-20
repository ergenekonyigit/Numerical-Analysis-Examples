import math

def f(x): #function example
    return math.exp(x) - 2*x**2


def muller(f):
    '''
    Implementation of Muller's method, a generalization of the secant method of root finding.

    Args:
        f: A function whose root is to be found.

    Returns:
        x: Floating point representing f's real root.
    '''

    x0 = input("x0: ")
    x1 = input("x1: ")
    x2 = input("x2: ")
    eps = 1e-6
    x = x0
    it = 0

    while (math.fabs(f(x)) > eps):
        h = x0 - x2
        hi = x2 - x1
        hj = x1 - x0
        l = hi/hj
        d = 1 + l
        g = (l**2) * f(x0) - (d**2) * f(x1) + (l + d) * f(x2)
        c = l * (l * f(x0) - d * f(x1) + f(x2))
        l = min((-2 * d * f(x2)) / (g + math.sqrt((g**2) - 4 * d * f(x2) * c)), (-2 * d * f(x2)) / (g - math.sqrt((g**2) - 4 * d * f(x2) * c)))
        x = x2 + (x2 - x1)*l

        x2,x1,x0 = x,x2,x1

    return x

print muller(f)
