var data = require('./data');

function f(x) {
  return Math.pow(x, 4)-5*Math.pow(x, 3)-34*Math.pow(x, 2)+56*x+192;
}

function Df(x) {
  return 4*Math.pow(x, 3)-15*Math.pow(x, 2)-68*x+56;
}

function newton(x0) {
  var n = 1;

  do {
    var x1 = x0-f(x0)/Df(x0);
    var Dx = Math.abs(x1-x0);
    x0 = x1;
    n++;
  } while (Dx > data.eps);

  return x1;
}

function synthetic() {

}
