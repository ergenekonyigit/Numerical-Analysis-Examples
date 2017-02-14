### *Newton's Method*
Newton's method is the classic algorithm for finding roots of functions. It is often introduced in the calculus sequence as an application of the derivative of a function. Historically, it appears to have been first used by Newton in 1669, although the ideas were known to others beforehand. In fact, the ancient Babylonians had ma method for approximating square roots that is essentially Newton's method.
```
x[n + 1] = x[n] - f(x[n]) / f'(x[n])
```

##### Example
f(x) = x * e^(-x) + x^3 +1 , x[0] = 2
