package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {
	// return x*math.Exp(-x) + math.Pow(x, 3.0) + 1
	return (2/math.Exp(-math.Pi) + 1) * math.Exp(-x) * math.Sin(x)
}

func main() {
	n := 0
	eps := 1e-2
	var a float64
	var b float64
	fmt.Println("a: ")
	fmt.Scanln(&a)
	fmt.Println("b: ")
	fmt.Scanln(&b)

	fmt.Println("n", "a", "b", "m", "|Dx/2|")
	for {
		m := (a + b) / 2.0
		Dx := math.Abs((b - a) / 2.0)
		fmt.Println(n+1, a, b, m, Dx)
		if f(a)*f(m) < 0 {
			b = m
		} else {
			a = m
		}
		n++
		if Dx < eps {
			break
		}
	}
}
