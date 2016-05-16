n, eps = 0, 1e-6
x0 = [(print 'x0: '), gets.rstrip][1].to_f
x1 = [(print 'x1: '), gets.rstrip][1].to_f

def f x
  x*Math.exp(-x)+(x**3.0)+1
end

puts "n   x0     x1    f(x0)    f(x1)   x2    |Dx|"

while true do
  x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0))
  dx = (x2 - x1).abs
  puts "#{n+1} #{'%.4f' % x0} #{'%.4f' % x1} #{'%.4f' % f(x0)} #{'%.4f' % f(x1)} #{'%.4f' % x2} #{'%.4f' % dx}"
  x0, x1 = x1, x2
  n += 1
  if dx < eps
    break end
end
