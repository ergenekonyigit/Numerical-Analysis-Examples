n, eps = 0, 1e-3
a = [(print 'a: '), gets.rstrip][1].to_f
b = [(print 'b: '), gets.rstrip][1].to_f

def f x
  x*Math.exp(-x)+(x**3.0)+1
end

if f(a) * f(b) > 0
   puts "No root: The function values at the initial state should be opposite sign."
else
  puts "n     a      b     m f(a)*f(m) |Dx/2|"
  while true do
    m = (a + b) / 2.0
    dx = ((b - a) / 2.0).abs
    puts "#{n+1} #{'%.4f' % a} #{'%.4f' % b} #{'%.4f' % m} #{(f(a) * f(m) > 0) ? "+" : "-"} #{'%.4f' % dx}"
    f(a) * f(m) < 0 ? b = m : a = m
    n += 1
    if dx < eps
      break end
  end
end
