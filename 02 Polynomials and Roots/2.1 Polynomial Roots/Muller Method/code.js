var data = require('./data');

function f(x) {
  return x*Math.exp(-x/2)+Math.pow(x, 3)+1;
}

function muller(x0, x1, x2) {
  var n = 1;

  console.log('n', '|', 'x0', '|', 'x1', '|', 'x2', '|', 'root');
  do {
    var p = (x2-x1)/(x1-x0);
    var q = (x2-x0)/(x1-x0);
    var u = f(x0)*Math.pow(p, 2)-f(x1)*Math.pow(q, 2)+f(x2)*(p+q);
    var v = Math.sqrt((Math.pow(u, 2)-4*f(x2)*p*q*((f(x0)*p)-(f(x1)*q)+f(x2))));
    if (u < 0) {
      var l = (2*f(x2)*q)/(-u+v);
    } else {
      var l = (2*f(x2)*q)/(-u-v);
    }
    var root = x2+l*(x2-x1);
    console.log(n, x0.toFixed(4), x1.toFixed(4), x2.toFixed(4), root.toFixed(4));
    x0 = x1;
    x1 = x2;
    x2 = root;
    n++;
  } while (Math.abs(f(root)) > data.eps);
}

muller(data.x0, data.x1, data.x2);
