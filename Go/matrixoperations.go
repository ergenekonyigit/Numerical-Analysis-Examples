package main

import (
	"fmt"
	"math"
	"math/rand"
)

// Size of matrix
var size = 5

func addition(a [][]float64, b [][]float64) [][]float64 {
	m := len(a[0])
	c := make([][]float64, m*m)
	for i := range c {
		c[i] = make([]float64, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			c[i][j] = a[i][j] + b[i][j]
		}
	}
	return c
}

func subtraction(a [][]float64, b [][]float64) [][]float64 {
	m := len(a[0])
	c := make([][]float64, m*m)
	for i := range c {
		c[i] = make([]float64, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			c[i][j] = a[i][j] - b[i][j]
		}
	}
	return c
}

func multiplication(a [][]float64, b [][]float64) [][]float64 {
	m := len(a[0])
	c := make([][]float64, m*m)
	for i := range c {
		c[i] = make([]float64, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			var sum float64
			for y := 0; y < m; y++ {
				sum += a[i][y] * b[y][j]
			}
			c[i][j] = sum
		}
	}
	return c
}

func transpose(a [][]float64) [][]float64 {
	m := len(a[0])
	c := make([][]float64, m*m)
	for i := range c {
		c[i] = make([]float64, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			c[i][j] = a[j][i]
		}
	}
	return c
}

func determinant(a [][]float64) float64 {
	return detHelp(a, len(a[0]))
}

func detHelp(a [][]float64, n int) float64 {
	var det float64
	if n == 1 {
		det = a[0][0]
	} else if n == 2 {
		det = a[0][0]*a[1][1] - a[1][0]*a[0][1]
	} else {
		for i := 0; i < n; i++ {
			mat := make([][]float64, (n-2)*(n-1))
			for j := 0; j < n-1; j++ {
				mat[j] = make([]float64, n-1)
			}
			for x := 1; x < n; x++ {
				z := 0
				for y := 0; y < n; y++ {
					if y != i {
						mat[x-1][z] = a[x][y]
						z++
					}
				}
			}
			det += math.Pow(-1.0, float64(1.0+i+1.0)) * a[0][i] * detHelp(mat, n-1)
		}
	}
	return det
}

func print(a [][]float64) {
	m := len(a[0])

	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			fmt.Printf("%d ", int(a[i][j]))
		}
		fmt.Printf("\n")
	}
	fmt.Printf("\n")
}

func main() {
	a := make([][]float64, size*size)
	b := make([][]float64, size*size)
	c := make([][]float64, size*size)
	for j := 0; j < size; j++ {
		a[j] = make([]float64, size)
		b[j] = make([]float64, size)
		c[j] = make([]float64, size)
	}

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			a[i][j] = math.Floor(10 * rand.Float64())
			b[i][j] = math.Floor(10 * rand.Float64())
		}
	}

	print(a)
	fmt.Println(determinant(a))
	fmt.Printf("\n")
	print(b)
	c = addition(a, b)
	print(c)
	c = multiplication(a, b)
	print(c)
	c = transpose(c)
	print(c)
}
