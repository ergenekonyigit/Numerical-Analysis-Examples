#!/usr/bin/env runhaskell

import Data.List (intercalate)
import Text.Printf (printf)

type Interval = (Double, Double)
type Subdivisions = Double
type Function = Double -> Double
type Polynomial = Function
type Spline = [(Interval, Polynomial)]

delta = 0.1 :: Double

pairs :: [a] -> [(a,a)]
pairs xs = zip xs (drop 1 xs)

uniform :: Interval -> Subdivisions -> [Interval]
uniform (a,b) n = pairs $ map (\i -> a + (b-a)*(i-1)/n) [1..n+1]

mesh :: Interval -> [Double]
mesh (a,b) = [a,a+delta..b]

ddx :: Function -> Function
ddx f = \x -> (f(x+h)-f(x-h))/(2*h) where h = 1e-9

bb :: Interval -> (Function, Function)
bb (a,b) = (\t -> (b-t)/h, \t -> (t-a)/h) where h = b-a

type Scheme = Function -> Interval -> Polynomial

hermiteCubic :: Scheme
hermiteCubic f (a,b) = let (b0,b1) = bb (a,b)
                           f' = ddx f
                           h = b - a
                           c30 = f(a)
                           c21 = c30 + (h/3) * f'(a)
                           c03 = f(b)
                           c12 = c03 - (h/3) * f'(b)
                        in \t -> c30 * b0(t)**3  +  
                                 3 * c21 * b0(t)**2 * b1(t)  +  
                                 3 * c12 * b0(t) * b1(t)**2  + 
                                 c03 * b1(t)**3
                                 
hermiteQuadratic :: Scheme
hermiteQuadratic f (a,b) = let m = (a+b)/2
                               (b0,b1) = bb (a,m)
                               (b0',b1') = bb (m,b)
                               f' = ddx f
                               h = b-a
                               c20 = f(a)
                               c02' = f(b)
                               c11 = c20 + (h/4)*f'(a)
                               c11' = c02' - (h/4)*f'(b)
                               c02 = (c11+c11')/2
                               c20'= c02
                            in \t -> if t < m
                                     then c20 * b0(t)**2 +  
                                          2 * c11 * b0(t) * b1(t) +  
                                          c02 * b1(t)**2
                                     else c20' * b0'(t)**2 +
                                          2 * c11' * b0'(t) * b1'(t) +
                                          c02' * b1'(t)**2

spline :: Function -> Interval -> Subdivisions -> Scheme -> Spline
spline f i n s = map (\h -> (h, g h)) (uniform i n) where g = s f

data Row = Row Double Double Double -- x, f(x), s(x)

eval :: Function -> Spline -> [Row]
eval f s = concatMap g s
           where g (i, p) = map (\x -> Row x (f x) (p x)) (mesh i)

pr (Row x fx sx) = printf "%.5f  \t%.5f  \t%.5f\n" x fx sx

main = do
  let f x = 1 / (1 + x**2)
      interval = (-5,5)
      n = 10
      
  putStrLn "hermite quadratic:"
  putStrLn "x \t\tf(x)\t\t s(x)"
  let quadratic = spline f interval n hermiteQuadratic
  mapM_ pr (eval f quadratic)
  
  putStrLn "hermite cubic:"
  putStrLn "x \t\tf(x)\t\t s(x)"
  let cubic = spline f interval n hermiteCubic
  mapM_ pr (eval f cubic)
