#lang racket

(define EPS 1e-3)

(define (newtons-method f df x0 n)
  (define x1 (- x0 (/ (f x0) (df x0))))
  (define dx (abs (- x1 x0)))
  (if (>= dx EPS)
      (newtons-method f df x1 (add1 n))
      x1))

(newtons-method (λ (x) (+ (* x (exp (* -1 x))) (expt x 3) 1))
                (λ (x) (+ (* (- (exp (* -1 x)) x) (exp (* -1 x))) (* 3 (expt x 2))))
                0
                0)
