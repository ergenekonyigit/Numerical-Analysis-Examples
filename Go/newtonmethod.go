package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {
	// return x*math.Exp(-x) + math.Pow(x, 3.0) + 1
	return 4*math.Log10(x) - math.Pow(x, 2) + x
}

func Df(x float64) float64 {
	//return math.Exp(-x) - x*math.Exp(-x) + 3*math.Pow(x, 2.0)
	return (4 / math.Log10(x)) - 2*x + 1
}

func main() {
	i := 0
	eps := 1e-2
	var x0 float64
	fmt.Println("x0: ")
	fmt.Scanln(&x0)

	fmt.Println("i", "x0", "f(x0)", "Df(x0)", "x1", "Dx")
	for {
		x1 := x0 - f(x0)/Df(x0)
		Dx := math.Abs(x1 - x0)
		fmt.Println(i+1, x0, f(x0), Df(x0), x1, Dx)
		i++
		x0 = x1
		if Dx < eps {
			break
		}
	}
}
