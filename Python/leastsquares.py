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

def leastsquares(x, y):
    '''
    Example implementation of the Least Squares method for calculating a best-fit line through a set of points.

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

print "least squares fit ==> y = %.10f + %.10fx" % leastsquares(x, y)

