#!/usr/bin/env runhaskell

import Text.Printf

maxIterations = 200
epsilon = 1e-6

f :: Double -> Double
f x = x * exp x + x ^^ 3 + 1

secant :: (Double -> Double) -> Double -> Double -> Int -> IO ()
secant g x0 x1 i = do
  let fx0 = g x0
      fx1 = g x1
      x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0)
      dx = abs (x2 - x1)
  printf "%d     %.3f     %.3f     %.3f     %.3f     %.3f     %.30f\n" i x0 x1 fx0 fx1 x2 dx
  if dx < epsilon || i > maxIterations
  then return () 
  else secant g x1 x2 (i+1)

main :: IO ()
main = do
  putStr "x0: "
  x0 <- fmap read getLine :: IO Double
  putStr "x1: "
  x1 <- fmap read getLine :: IO Double
  putStrLn "i       x0       x1       f(x0)        f(x1)       x2         |Δx|"
  secant f x0 x1 0
