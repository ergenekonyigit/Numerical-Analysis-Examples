i, eps = 0, 1e-6
a = [(print 'a: '), gets.rstrip][1].to_f
b = [(print 'b: '), gets.rstrip][1].to_f

def f x
  10*Math.exp(-x/2.0)*(Math.cos(6.0*x)+Math.sin(8.0*x))
end

puts "i   a     b      f(a)     f(b)    c    f(c) +/-"
while true
  c = (a*f(b)-b*f(a))/(f(b)-f(a))
  puts "#{i+1} #{'%.4f' % a} #{'%.4f' % b} #{'%.4f' % f(a)} #{'%.4f' % f(b)} #{'%.4f' % c} #{'%.4f' % f(c)} #{f(c) > 0 ? "+" : "-"}"
  i += 1
  f(a) * f(c) > 0 ? a = c : b = c
  if f(c).abs < eps
    break end
end
