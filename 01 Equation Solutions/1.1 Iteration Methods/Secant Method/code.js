var data = require('./data');

function f(x) {
  return x*Math.exp(-x)+Math.pow(x, 3)+1;
}

function secant(x0, x1) {
  var n = 1;

  console.log('n', '|', 'x0', '|', 'x1', '|', 'f(x0)', '|', 'f(x1)', '|', 'x2', '|', '|Dx|');
  do {
    var x2 = ((x0*f(x1))-(x1*f(x0)))/(f(x1)-f(x0));
    var Dx = Math.abs(x2-x1);
    console.log(n, x0.toFixed(4), x1.toFixed(4), f(x0).toFixed(4), f(x1).toFixed(4), x2.toFixed(4), Dx.toFixed(4));
    x0 = x1;
    x1 = x2;
    n++;
  } while (Dx > data.eps);
}

secant(data.x0, data.x1);
