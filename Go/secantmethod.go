package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {
	return x*math.Exp(-x) + math.Pow(x, 3.0) + 1
}

func main() {
	n := 0
	eps := 1e-6
	var x0 float64
	var x1 float64
	fmt.Println("x0: ")
	fmt.Scanln(&x0)
	fmt.Println("x1: ")
	fmt.Scanln(&x1)

	fmt.Println("n", "x0", "x1", "f(x0)", "f(x1)", "x2", "|Dx|")
	for {
		x2 := ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0))
		Dx := math.Abs(x2 - x1)
		fmt.Println(n+1, x0, x1, f(x0), f(x1), x2, Dx)
		x0 = x1
		x1 = x2
		n++
		if Dx < eps {
			break
		}
	}
}
