import numpy as np

#IMPLEMENTATION OF POWER METHOD FOR APPROXIMATING EIGENVALUES

print("Give the size of the matrix: ")

n = int(input())

A = np.random.randint(20, size=(n, n)) # Create a random Matrix. First param is the upper bound for elements in the matrix
print(A)

b = np.random.rand(A.shape[0])
print(b)

eigenvalues = []

i = 0

while True:

    b = np.matmul(A, b)  # Matrix Multiplication

    div = b[0]
    eigenvalues.append(div)
    b = (1 / b[0]) * b
    if i >= 1:
        if abs(eigenvalues[i] - eigenvalues[i-1]) < 0.5 * 10 ** -10: # number of precision digits
            break
    i += 1

print(eigenvalues[i]) # Prints the last approx of the eigenvalue!