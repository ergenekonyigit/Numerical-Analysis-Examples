package main

import (
	"fmt"
	"math"
)

var u [][]float64
var count int

// func LU(a [][]float64, b []float64) []float64 {
// 	m := len(b)
// 	x := []float64{}
// 	L := [][]float64{}
// 	U := [][]float64{}
// 	var t1, t2 float64
// 	for i := 0; i < m; i++ {
// 		L[i][i] = 1
// 		for j := 0; j < m; j++ {
// 			t1 := 0
// 			for k := 0; k < i-1; k++ {
// 				t1 += L[i][k] * U[k][j]
// 			}
// 			U[i][j] = a[i][j] - t1
// 			t2 := 0
// 			for k := 0; k < j-1; k++ {
// 				t2 += L[i][k] * U[k][j]
// 			}
// 			L[i][j] = 1.0 / U[i][j] * (a[i][j] - t2)
// 		}
// 	}
//
// 	print(L, x, b)
// 	print(L, x, b)
// 	return x
// }

func print(a [][]float64, x []float64, b []float64) {
	m := len(b)
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			u[j][i+count] = a[i][j]
		}
		u[m+1][i+count] = x[i]
		u[m+1][i+count] = b[i]
	}
}

func main() {
	fmt.Println("a ...interface{}", math.Pi)

	/*
	   print(a [][]float64, x []float64, b []float64) {

	 }*/
}
