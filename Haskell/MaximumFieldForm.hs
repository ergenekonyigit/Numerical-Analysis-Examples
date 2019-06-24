#!/usr/bin/env runhaskell

import Control.Monad (when, unless)
import System.IO
import Text.Printf

main :: IO ()
main = do
  putStr "a: "
  hFlush stdout
  a <- fmap read getLine :: IO Double
  putStr "\n"
  putStr "b: "
  hFlush stdout
  b <- fmap read getLine :: IO Double
  putStr $ concat
    [ "\n"
    , "i", spaces
    , "a", spaces
    , "b", spaces
    , "c", spaces
    , "f(a)", replicate 7 ' '
    , "f(c)", replicate 7 ' '
    , "|c|", replicate 7 ' '
    , "\n\n"
    ]
  mff f a b 0

spaces = replicate 10 ' '
eps = 1e-6

f :: Double -> Double
f x = (pi - (2 * x)) * sin x * cos x - (sin x ^^ 2)

mff :: (Double -> Double) -> Double -> Double -> Double -> IO ()
mff g a b i = when (abs (b - a) > eps) $ do
  let c = (a + b) / 2
      ga = g a
      gc = g c
  printf "%.0f     %.3f      %.3f       %.3f       %.3f       %.3f       %.3f\n" (i + 1) a b c ga gc (abs c)
  let (a',b') = if ga * gc < 0
        then (a,c)
        else (c,b)
  unless (abs (b' - a') < eps) $ do
    mff g a' b' (i + 1)
