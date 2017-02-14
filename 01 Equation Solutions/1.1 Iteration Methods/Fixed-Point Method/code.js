var data = require('./data');

function f(x) {
  return Math.sin(x)-Math.pow(x, 2);
}

// Be improved.
function fixedpoint(x0, iteration) {
  var n = 1;

  console.log('n', '|', 'x0', '|', 'x1', '|', '|Dx|');
  do {

    var x1 = Math.sqrt(Math.sin(x0));
    var Dx = Math.abs(x1-x0);
    console.log(n, x0.toFixed(4), x1.toFixed(4), Dx.toFixed(4));
    x0 = x1;

    if (n > iteration) {
      console.log('Maximum number of iterations exceeded.');
    }

    n++;
  } while (Dx > data.eps);
}

fixedpoint(data.x0, data.iteration);
