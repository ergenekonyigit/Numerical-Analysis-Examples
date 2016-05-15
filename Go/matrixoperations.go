package main

import (
  "fmt"
  "math"
  "math/rand"
)
var count int = 0
func addition(a [][]float64, b [][]float64) [][]float64 {
  m := float(len(a[0]))
//  s := int(math.Pow(m, 2))
  c := make([][]float64, int(math.Pow(m, 2)))
  for i := range c {
    c[i] = make([]float64, int(math.Pow(m, 2)))
  }
  for i := 0; i  < m; i++ {
    for j := 0; j < m; j++ {
      c[i][j]=a[i][j]+b[i][j]
    }
  }
  return c
}

func print(a [][]float64)  {
  m := len(a[0])

  for i := 0; i < m; i++ {
    for j := 0; j < m; j++ {
      fmt.Println("", a[i][j])
    }
    fmt.Println("\n")
  }
  count += m+1
}

func main() {
  var m int
  fmt.Scanln("length: ", m)
  r := rand.NewSource(100)
  var a = [m][m]float64
  var b = [m][m]float64
  var c = [m][m]float64

  for i := 0; i < m; i++ {
    for j := 0; j < m; j++ {
      a[i][j] = r.Int63()
      b[i][j] = r.Int63()
    }
  }
  print(a)
  print(b)
  c = addition(a, b)
  print(c)
}
