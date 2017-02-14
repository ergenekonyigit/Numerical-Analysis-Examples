### *Secant Method*
In numerical analysis, the secant method is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function f. The secant method can be thought of as a finite difference approximation of Newton's method. However, the method was developed independently of Newton's method, and predates it by over 3,000 years.
```
x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0))
```

#### Example
f(x) = x * e^(-x) + x^3 + 1 , [a, b] = [-1, 2]
