#!/usr/bin/env runhaskell

import Text.Printf

maxIterations = 200
epsilon = 1e-6

f :: Double -> Double
f x = x * exp x + x ^^ 3 + 1

bisect :: (Double -> Double) -> Double -> Double -> Int -> IO ()
bisect g a b i = do
  let m = (a + b) / 2
      fa = g a
      fm = g m
      dx = (b - a) / 2
  printf "%d      %.3f      %.3f       %.3f       %.3f       %.3f      %.3f\n" i a b m fa fm dx
  if dx < epsilon || i > maxIterations
  then return () 
  else if fa * fm > 0 then bisect g m b (i+1) else bisect g a m (i+1)

main :: IO ()
main = do
  putStr "a: "
  a <- fmap read getLine :: IO Double
  putStr "b: "
  b <- fmap read getLine :: IO Double
  putStrLn "i        a        b         m       f(a)       f(m)        |Δx/2|"
  bisect f a b 0
