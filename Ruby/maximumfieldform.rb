a, b, i, eps = 0, 1, 0, 1e-6

def f x
  (Math::PI-2*x)*Math.sin(x)*Math.cos(x)-Math.sin(x)**2
end

puts "i  a   b   c   f(a)   f(c)    |c|"

while (b-a).abs > eps
  c = (a + b) / 2.0
  puts  "#{i+1} #{a} #{b} #{c} #{f(a)} #{f(c)} #{c.abs}"

  f(a)*f(c) < 0 ? b = c : a = c
  i += 1

  if (b - a).abs < eps
    break end
end
