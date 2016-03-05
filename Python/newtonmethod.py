import math

i = 0
eps = 1e-6
x0 = input("x0: ")

def f(x):
#    return x*math.exp(-x)+math.pow(x, 3.0)+1
    return (1-math.exp(-x)*(math.cos(x)+math.sin(x)))/(math.exp(-math.pi)+1)

def Df(x):
#     return math.exp(-x)-x*math.exp(-x)+3*math.pow(x, 2.0)
     return (x+math.exp(-x)*math.cos(x))/(1+math.exp(-math.pi))

print('i', "  x0", "  f(x0)", "  Df(x0)", "  x1", "  Dx")
while True:
    x1 = x0-f(x0)/Df(x0)
    Dx = math.fabs(x1-x0)
    print(i+1, "%.4f" % x0, "%.4f" % f(x0), "%.4f" % Df(x0), "%.4f" % x1, "%.4f" % Dx)
    i += 1
    x0 = x1
    if Dx < eps:
        break
