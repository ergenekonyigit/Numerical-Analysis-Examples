import math

x0 = input("x0: ")
x1 = input("x1: ")
eps = 1e-6
n = 0


def f(x):
    return x*math.exp(-x)+math.pow(x, 3.0)+1

print('n', " x0", "  x1", "    f(x0)", "  f(x1)", "  x2", " |Dx|")

while True:
    x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0))
    Dx = math.fabs(x2 - x1)
    print(n+1, "%.4f" % x0, "%.4f" % x1, "%.4f" % f(x0), "%.4f" % f(x1), "%.4f" % x2, "%.4f" % Dx)
    x0 = x1
    x1 = x2
    n += 1
    if Dx < eps:
        break
