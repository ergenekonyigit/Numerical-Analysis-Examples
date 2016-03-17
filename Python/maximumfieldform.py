import math

a, b, i, eps = 0, 1, 0, 1e-6


def f(x):
    return (math.pi-2*x)*math.sin(x)*math.cos(x)-math.pow(math.sin(x), 2.0)

print('i', 'a', 'b', 'c', 'f(a)', 'f(c)', '|c|')

while math.fabs(b-a) > eps:
    c = (a + b) / 2.0
    print(i+1, a, b, c, f(a), f(c), math.fabs(c))

    if f(a)*f(c) < 0:
        b = c
    else:
        a = c
    i += 1
    if math.fabs(b-a) < eps:
        break
