import math

i = 0
eps = 1e-6
a = input("a: ")
b = input("b: ")


def f(x):
    return 10*math.exp(-x/2.0)*(math.cos(6.0*x)+math.sin(8.0*x))

print('i', "  a", "  b", "   f(a)", "   f(b)", "   c", "   f(c)", " +/-")
while True:
    c = (a*f(b)-b*f(a))/(f(b)-f(a))
    s = "+" if f(c) > 0 else "-"
    print(i+1, "%.4f" % a, "%.4f" % b, "%.4f" % f(a), "%.4f" % f(b), "%.4f" % c, "%.4f" % f(c), s)
    i += 1
    if f(a)*f(c) > 0:
        a = c
    else:
        b = c
    if math.fabs(f(c)) < eps:
        break
