#!/usr/bin/env runhaskell

import Control.Monad (guard, forM_)
import Text.Printf

type Point = (Double,Double)

productF :: [Double -> Double] -> (Double -> Double)
productF fns = \x -> (product . fmap ($ x)) fns

-- produces the jth Lagrange basis polynomial for the given xs
basis :: Int -> [Double] -> (Double -> Double)
basis j xs = productF $ do
  k <- [0..(length xs - 1)]
  guard (j /= k)
  let xk = xs !! k
      xj = xs !! j
  return $ \x -> (x - xk) / (xj - xk)

sumF :: [Double -> Double] -> (Double -> Double)
sumF fns = \x -> (sum . fmap ($ x)) fns

-- produces the Lagrange polynomial for the given points
interpolate :: [Point] -> (Double -> Double)
interpolate ps = 
  let (xs,ys) = unzip ps 
   in sumF $ do
     (y,j) <- ys `zip` [0..]
     let b = basis j xs
     return $ \x -> y * b x

main = do
  putStrLn "\tx\t\ty"
  let points = [(-3,7),(4, -1),(6,2),(8,1)]
      xs = [-10,-9.5..10]
      l = interpolate points
  forM_ (xs `zip` map l xs) (\(x,y) -> printf "%10.3f\t%10.3f\n" x y)
