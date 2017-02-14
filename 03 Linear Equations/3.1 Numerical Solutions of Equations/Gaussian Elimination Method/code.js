var data = require('./data');

function generateMatrixA(n) {
  var A = new Array(n);
  for (var i = 0; i < n; i++) {
    A[i] = new Array(n);
  }

  for (var i = 0; i < n; i++) {
    for (var j = 0; j < n; j++) {
      A[i][j] = Math.round(Math.random()*10);
    }
  }
  console.log('A:', A);
  return A;
}

function generateMatrixB(n) {
  var B = new Array(n);
  for (var i = 0; i < n; i++) {
    B[i] = new Array();
  }

  for (var i = 0; i < n; i++) {
    B[i][0] = Math.round(Math.random()*100);
  }
  console.log('B:', B);
  return B;
}

function gaussianElimination(A, B, n) {
  var x = new Array(n);
  for (var k = 0; k < n-1; k++) {
    for (var i = k+1; i < n; i++) {
      var p = A[i][k]/A[k][k];
      for (var j = k; j < n; j++) {
        A[i][j] -= p*A[k][j];
      }
      B[i] -= p*B[k];
    }
  }

  for (var i = n-1; i >= 0; i--) {
    var t = B[i];
    for (var j = i+1; j < n; j++) {
      t -= A[i][j]*x[j];
    }
    x[i] = t/A[i][i];
  }
  console.log('x:', x);
}

var matrixA = generateMatrixA(data.n);
var matrixB = generateMatrixB(data.n);
gaussianElimination(matrixA, matrixB, data.n);
