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

def leastsquares(x, y):
    '''
    Example implementation of the Least Squares method for calculating a best-fit line through a set of points.
    Linear least squares

    Args:
        x: array of floats representing x values for each point
        y: array of floats representing y values for each point

    Returns:
        (float, float): representing the y-intercept and slope of the best-fit line

    Raises:
        ValueError: if the two arrays are not the same length
    '''

    if len(x) != len(y):
       raise ValueError('Point arrays must be equal length')
       
    numberOfPoints = len(x)
    sumX = sum(x)
    sumY = sum(y)
    sumXYProduct = sum(x[i] * y[i] for i in range(numberOfPoints))
    sumXSquared = sum(map(lambda a: a ** 2, x))
    xBar = sumX / numberOfPoints
    yBar = sumY / numberOfPoints

    a1 = (numberOfPoints * sumXYProduct - sumX * sumY) / (numberOfPoints * sumXSquared - sumX ** 2)
    a0 = yBar - a1 * xBar

    return a0, a1

# example data
x = (1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)
y = (0.5, 2.5, 2.0, 4.0, 3.5, 6.0, 5.5)

print ("least squares fit ==> y = %.10f + %.10fx" % leastsquares(x, y))

