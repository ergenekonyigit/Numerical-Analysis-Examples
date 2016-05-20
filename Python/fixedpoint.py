#!/usr/bin/env python2

from __future__ import print_function

import math
import warnings

def fixed_point_solver(f, x0=0.0, tol=1e-3, max_iter=10000):
    """
    Example implementation of fixed point solver for solving equations of
    the form f(x) = x

    Args:
        f: Function from float to float to be solved
        x0: Initial guess for the solver to use
        tol: Amount of precision desired for the solution
        max_iter: Maximum number of iterations to perform

    Returns:
        float solution to the equation
    """

    i = 0
    x = x0
    while math.fabs(x - f(x)) > tol and i < max_iter:
        x = f(x)
        i += 1

    if i == max_iter:
        warning_message = (
            "fixed_point_solver: desired tolerance not reached in given max "
            "iterations {}"
            .format(max_iter)
        )
        warnings.warn(warning_message, RuntimeWarning)

    return x

if __name__ == "__main__":
    print("solving cos(x) = x for x...")
    example_function = lambda x: math.cos(x)
    result = fixed_point_solver(example_function)
    print("x = {}".format(result))

    print("solving cos(x) = sin(x) for x...")
    # subtract sin(x) from both sides and add x to both sides to get desired form
    example_function = lambda x: x + math.cos(x) - math.sin(x)
    result = fixed_point_solver(example_function)
    print("x = {}".format(result))

