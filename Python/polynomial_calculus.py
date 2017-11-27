'''
POLYNOMIAL CALCULUS

INPUT N                     {Degree of P(x)}
INPUT A(0), A(1)....A(N)    {Coefficients of P(x)}
INPUT C                     {Constant of integration}
INPUT X                     {Indepedent Variable}
INPUT x                     {List of coefficients of the equation}
'''

import numpy
import copy
#   x:@list coefficients of x  such that x2-x-2 would be [1,-1,-2] and x2-1 would be [1,0,-1]
#   note: it is not p of x as in p(4)
def p(x):
    p = numpy.poly1d(x)
    return p

'''
Evaluating p(x)
'''
def eval_polynomial(x, X): 
    equation = p(x)
    A = equation.c      #list of coefficients
    B = copy.copy(A)    
    index = len(A)
    counter = len(A) - 1
    
    B[counter] = A[0] # B(N):=A(N)
    print('b({0}) = {1}'.format(counter, A[0])) 
    counter = counter - 1

    for N in range(1,index):
        B[counter] = A[N] + B[counter + 1] * X 
        print('b({0}) = {1} +({2})*{3} = {4}'.format(counter, A[N], B[counter + 1], X, B[counter]))
        counter = counter - 1  

'''
Evaluating p(x) derivate
'''
def eval_polynomial_derivative(x, X):
    equation = p(x)
    A = equation.c #list of coefficients
    D = copy.copy(A)
    index = len(A) - 1 # -1 to ensure loop stops when K=1
    counter = len(A) - 1

    D[counter - 1] = counter * A[0]  # D(N-1) := N * A(N) 
    print("d({0}) = {1} * {2} = {3}".format(counter - 1, counter, A[0], D[counter - 1])); 
    counter = counter - 1  

    for N in range(1,index): # For K = N-1  DOWNTO 1
        D[counter - 1] = (counter) * A[N] + D[counter] * X # DO D(K-1):= K * A(K) + D(K) * X
        print("d({0}) = {1} * {2} + {3} * {4} = {5}".format(counter - 1, counter, A[N], D[counter], X, D[counter - 1])); 
        
        counter = counter - 1


'''
Algorithm to evaluate I(x)

'''
def eval_polynomial_integral(x,X):
    equation = p(x)
    A = equation.c
    I = copy.copy(x) 
    index = len(A) 
    counter = len(A) - 1
    
    I.insert((counter + 1),(A[0] /(counter + 1))) # I(N+1):= A(N)/(N+1)
    print("I({0}) = {1}/{2} = {3}".format(counter + 1, A[0], counter + 1, I[counter + 1]))
    

    for N in range(1, index): #For K=N DOWNTO 1
        I[counter] =( A[N] / counter ) + I[counter + 1] * X # DO I(K):= A(K-1)/K + I(K+1)*X
        print("I({0}) = {1}/{2} + {3} * {4} = {5}".format(counter, A[N], counter, I[counter + 1], X, I[counter]))
        counter = counter - 1
    
    #   I(0):= C + I(1)*X
    I[0] = 0 + I[1] * X
    print("I(0) = 0 + {0} * {1} = {2}".format(I[1], X, I[0]))
    print('\n')
    
    return I[0];


'''
Definite Integral of p(x) taken over two points
upper       {Upper limit}
lower       {Lower limit}
'''
def eval_polynomial_integral_limits(x,upper, lower):    
    print('I({0}) - I({1}) = {2}'.format(upper, lower, eval_polynomial_integral(x, upper) - eval_polynomial_integral(x,lower)))
    

 

    
print(eval_polynomial([-0.02, 0.2, -0.4,1.28], 4))
print(eval_polynomial_derivative([-0.02, 0.2, -0.4,1.28], 4))
print(eval_polynomial_integral([-0.02, 0.2, -0.4,1.28], 4))
(eval_polynomial_integral_limits([-0.02, 0.2, -0.4,1.28], 4, 1))