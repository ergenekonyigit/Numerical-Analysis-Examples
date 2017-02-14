var data = require('./data');

function f(x) {
  return 10*Math.exp(-x/2)*(Math.cos(6*x)+Math.sin(8*x));
}

function regulafalsi(a, b) {
  var n = 1;

  console.log('n', '|', 'a', '|', 'b', '|', 'f(a)', '|', 'f(b)', '|', 'c', '|', 'f(c)', '|', '+/-');
  do {
    var c = ((a*f(b))-(b*f(a)))/(f(b)-f(a));
    var kind = f(c)>0 ? '+' : '-';
    console.log(n, a.toFixed(4), b.toFixed(4), f(a).toFixed(4), f(b).toFixed(4), c.toFixed(4), f(c).toFixed(4), kind);
    if (f(a)*f(c) > 0) {
      a = c;
    } else {
      b = c;
    }
    n++;
  } while (Math.abs(f(c)) > data.eps);
}

regulafalsi(data.a, data.b);
