i,eps = 0, 1e-6
x0 = [(print 'x0: '), gets.rstrip][1].to_f

def f x
  x*Math.exp(-x)+(x**3.0)+1
end

def Df x
  Math.exp(-x)-x*Math.exp(-x)+3*(x**2.0)
end

puts "i   x0    f(x0)     Df(x0)   x1   Dx"
while true do
  x1 = x0-f(x0)/Df(x0)
  dx = (x1 - x0).abs
  puts "#{i+1} #{'%.4f' % x0} #{'%.4f' % f(x0)} #{'%.4f' % Df(x0)} #{'%.4f' % x1} #{'%.4f' % dx}"
  i += 1
  x0 = x1
  if dx < eps
    break end
end
