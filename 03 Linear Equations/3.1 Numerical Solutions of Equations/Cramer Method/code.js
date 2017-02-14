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
  return B
}

function determinant(A) {
  var m = A.length;
  if (m == 1) {
    return A[0][0];
  }

  var c = new Array(m-1);
  for (var i = 0; i < m-1; i++) {
    c[i] = new Array(m-1);
  }

  var t = 0;
  for (var j = 0; j < m; j++) {
    for (var i = 1; i < m; i++) {
      var n = 0;
      for (var k = 0; k < m; k++) {
        if (j != k) {
          c[i-1][n++] = A[i][k];
        }
      }
    }
    t += Math.pow(-1, j)*A[0][j]*determinant(c);
  }

  return t;
}

function cramer(A, B, t, n) {
  if (t == 0) {
    console.log('Your equation can not be solved with Cramer\'s Rule');
  }

  var C = new Array(n);
  for (var i = 0; i < n; i++) {
    C[i] = new Array(n);
  }

  for (var i = 0; i < n; i++) {
    for (var j = 0; j < n; j++) {
      C[i][j] = A[i][j];
    }
  }

  var x = new Array(n);
  for (var i = 0; i < B.length; i++) {
    for (var j = 0; j < B.length; j++) {
      C[j][i] = B[j];
    }
    x[i] = determinant(C);
    for (var k = 0; k < n; k++) {
      for (var l = 0; l < n; l++) {
        C[k][l] = A[k][l];
      }
    }
  }

  for (var i = 0; i < x.length; i++) {
    x[i] *= 1/determinant(A);
  }

  console.log('determinant:', determinant(A));
  console.log('x:', x);
}

var matrixA = generateMatrixA(data.n);
var matrixB = generateMatrixB(data.n);
var det = determinant(matrixA);
cramer(matrixA, matrixB, det, data.n);
