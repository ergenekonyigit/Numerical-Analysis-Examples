#!/usr/bin/env runhaskell

import Control.Monad (mapM_)
import Text.Printf (printf)

type Point = (Double,Double)
type Interval = (Double,Double)

breakAt :: Int -> [a] -> ([a], a, [a])
breakAt k as = (take (k-1) as, head $ drop (k-1) as, drop k as)

-- produces the kth Lagrange basis polynomial for the given xs
basis :: Int -> [Double] -> (Double -> Double)
basis k xs t = product (map factor xs')
  where (as, xk, bs) = breakAt k xs
        xs' = as ++ bs
        factor xj = (t - xj) / (xk - xj)

-- produces the Lagrange polynomial for the given points
interpolate :: [Point] -> (Double -> Double)
interpolate ps x = 
  let (xs,ys) = unzip ps 
   in sum . map ($ x) $ do
     (y,j) <- ys `zip` [1..]
     let b = basis j xs
     return $ \x -> y * b x

-- produces a list of n+1 values from a to b with consecutive values
-- (b-a)/n apart
uniform :: Interval -> Int -> [Double]
uniform (a,b) n = [a,(a+d)..b] where d = (b - a) / (fromIntegral n)

-- produces a list of n+1 values from a to b with the distance between
-- consecutive values determined by Chebyshev's criterion
chebyshev :: Interval -> Int -> [Double]
chebyshev (a,b) n = let c0 = (a+b) / 2
                        c1 = (a-b) / 2
                        n' = fromIntegral n
                     in map (\i -> c0 + c1 * cos(pi/n'*(i-1))) [1..n'+1]

-- produces the Lagrange polynomial approximation of the given
-- function f with samples drawn from the given xs
approximate :: (Double -> Double) -> [Double] -> (Double -> Double)
approximate f xs = \x -> interpolate (xs `zip` map f xs) x

pr (x,y) = printf "%10.3f\t%10.3f\n" x y

main = do
  putStrLn "Interpolate a set of points:"
  putStrLn "\tx\t\ty"
  let points = [(-3,7),(4, -1),(6,2),(8,1)]
      xs = [-10,-9.5..10]
      l = interpolate points
  mapM_ pr (xs `zip` map l xs)
  
  putStrLn "Approximate a function with a polynomial:"
  let f x = abs (cos (2*x))
  let xs' = [-pi,-pi+0.1..pi]
      n = 40
      interval = (-pi,pi)
  putStrLn "using uniform nodes:"
  putStrLn "\tx\t\ty"
  let uniformApproximation = approximate f (uniform interval n)
  mapM_ pr (xs' `zip` map uniformApproximation xs')
  putStrLn "using Chebyshev nodes:"
  putStrLn "\tx\t\ty"
  let chebyshevApproximation = approximate f (chebyshev interval n)
  mapM_ pr (xs' `zip` map chebyshevApproximation xs')
