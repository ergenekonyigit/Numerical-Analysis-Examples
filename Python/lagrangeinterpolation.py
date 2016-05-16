#
# The MIT License (MIT)
#
# Copyright (c) 2016 Scott J. Johnson
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

def lagrangeinterpolation(x, xp, yp):
    '''
    Example implementation of the Lagrange Polynomial Interpolation method.

    Args:
        x: float representing x value for which to calculate the interpolated y value 
        xp: array of floats representing x values for each interpolation point
        yp: array of floats representing y values for each interpolation point

    Returns:
        float containing the interpolated y value

    Raises:
        ValueError: if the two input arrays are not the same length
    '''

    if len(xp) != len(yp):
       raise ValueError('Point arrays must be equal length')

    numberOfPoints = len(xp)

    y = 0
    for i in range(numberOfPoints):
        product = yp[i]
        for j in range(numberOfPoints):
            if i != j:
                product *= (x - xp[j])/(xp[i] - xp[j])

        y += product

    return y

# example #1: x**2

x = 1.5 
xp = (1.0, 2.0, 3.0)
yp = (1.0, 4.0, 9.0)

print "\nExample #1: "
print "Given points: ", zip(xp, yp)
print "interpolated y value = %.3f at x = %.3f" % (lagrangeinterpolation(x, xp, yp), x)

# example #2: x**3

x = 2.5
xp = (1.0, 2.0, 3.0)
yp = (1.0, 8.0, 27.0)

print "\nExample #2: "
print "Given points: ", zip(xp, yp)
print "interpolated y value = %.3f at x = %.3f" % (lagrangeinterpolation(x, xp, yp), x)

