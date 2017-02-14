### *Bisection Method*
Bisection is a marvelously simple idea that is based on little more than the continuity of the function f. Suppose we know that f(a) * f(b) < 0. This means that f is negative at one point and positive at the other. If we assume that f is continuous, then it follows (by the Intermediate Value Theorem) that there must be some value between a and b at which f is zero. In other words, we know that there is a root a between a and b. (Note: There may be more than one root in the interval.)
Now let's try to use these ideas to find a. Let c be the midpoint of the interval
```
m = (a + b) * 1 / 2
```
and consider the product f(a) * f(m). There are three possibilities:
1. f(a) * f(m) < 0; this means that a root (there might be more than one) is between a and c.
2. f(a) * f(m) = 0; if we assume that we already know f != 0, this means that f(c) = 0, thus a = c and we have found a root.
3. f(a) * f(m) > 0; this means that a root must lie in the other half of the interval.

##### Example
f(x) = x * e^(-x) + x^3 + 1 , [a, b] = [-1, 2]
