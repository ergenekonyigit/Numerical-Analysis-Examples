### *Muller's Method*
Muller's method is a root-finding algorithm, a numerical method for solving equations of the form f(x) = 0. It was first presented by David E. Muller in 1956.
Muller's method is based on the secant method, which constructs at every iteration a line through two points on the graph of f. Instead, Muller's method uses three points, constructs the parabola through these three points, and takes the intersection of the x-axis with the parabola to be the next approximation.

#### Example
f(x) = x * e^(-x/2) + x^3 + 1 , [x0, x1, x2] = [-1, 0, 2]
