#!/usr/bin/env runhaskell

import Text.Printf

maxIterations = 200
epsilon = 1e-6

f :: Double -> Double
f x = x * exp x + x ^^ 3 + 1

ddx :: (Double -> Double) -> (Double -> Double)
ddx g = \x -> (g (x + dx) - g (x - dx)) / (2*dx) where dx = 1e-9

step :: (Double -> Double) -> Double -> Double
step g x = x - (g x) / (ddx g x)

newton :: (Double -> Double) -> Double -> Int -> IO ()
newton g xi i = do
  let xj = step g xi
      dx = abs (xi - xj)
  printf "%i   %10.3f   %10.3f   %10.3f\n" i xi xj dx
  if dx < epsilon || i > maxIterations
  then return ()
  else newton g xj (i+1)

main :: IO ()
main = do 
  putStr "x0: "
  x0  <- fmap read getLine :: IO Double
  printf "i        x_i         x_(i+1)         Δx\n"
  newton f x0 0
