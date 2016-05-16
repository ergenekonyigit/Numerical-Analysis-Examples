#lang racket

(define EPS 1e-3)

(define (bisection f a b n)
  (define m (/ (+ a b) 2))
  (if (> (* (f a) (f b)) 0)
      "No root"
      (if (> (abs (/ (- b a) 2)) EPS)
          (if (< (* (f a) (f m)) 0)
              (bisection f a m (add1 n))
              (bisection f m b (add1 n)))
          m
          )))

(bisection (λ (x) (+ (* x (exp (* -1 x))) (expt x 3) 1)) -1 1 20)
