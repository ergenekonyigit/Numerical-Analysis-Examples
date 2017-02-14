var data = require('./data');

function f(x) {
  return x*Math.exp(-x)+Math.pow(x, 3)+1;
}

function bisection(a, b) {
  var n = 1;

  console.log('n', '|', 'a', '|', 'b', '|', 'm', '|', 'f(a)*f(m)', '|', '|Dx/2|');
  if (f(a)*f(b)>0) {
    console.log('No root: The function values at the initial state should be opposite sign.');
  } else {
    do {
      var m = (a+b)/2;
      var Dx = Math.abs((b-a)/2);
      var kind = f(a)*f(m)>0 ? '+' : '-';
      console.log(n, a.toFixed(4), b.toFixed(4), m.toFixed(4), kind, Dx.toFixed(4));
      if (f(a)*f(m) < 0) {
        b = m;
      } else {
        a = m;
      }
      n++;
    } while (Math.abs(b-a)/2 > data.eps);
  }
}

bisection(data.a, data.b);
