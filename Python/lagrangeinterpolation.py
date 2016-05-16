#
# Copyright 2016 Scott J. Johnson (http://scottjjohnson.com)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS-IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

def lagrangepolynomialinterpolation(x, xp, yp):
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

print "Example #1 : ", zip(xp, yp)
print "interpolated value at %.10f is %.10f" % (x, lagrangepolynomialinterpolation(x, xp, yp))

# example #2: x**3

x = 2.5
xp = (1.0, 2.0, 3.0)
yp = (1.0, 8.0, 27.0)

print "Example #2 : ", zip(xp, yp)
print "interpolated value at %.10f is %.10f" % (x, lagrangepolynomialinterpolation(x, xp, yp))

