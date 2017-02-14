var data = require('./data');

function f(x) {
  return x*Math.exp(-x)+Math.pow(x, 3)+1;
}

function Df(x) {
  return Math.exp(-x)-x*Math.exp(-x)+3*Math.pow(x, 2);
}

function newton(x0) {
  var n = 1;

  console.log('n', '|', 'x0', '|', 'f(x0)', '|', 'Df(x0)', '|', 'x1', '|', 'Dx');
  do {
    var x1 = x0-f(x0)/Df(x0);
    var Dx = Math.abs(x1-x0);
    console.log(n, x0.toFixed(4), f(x0).toFixed(4), Df(x0).toFixed(4), x1.toFixed(4), Dx.toFixed(4));
    x0 = x1;
    n++;
  } while (Dx > data.eps);
}

newton(data.x0);
