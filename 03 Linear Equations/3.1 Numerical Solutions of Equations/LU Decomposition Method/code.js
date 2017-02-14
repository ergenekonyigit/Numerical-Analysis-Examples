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

function LU(A, B, n) {
  var L = new Array(n);
  for (var i = 0; i < n; i++) {
    L[i] = new Array(n);
  }
  for (var i = 0; i < n; i++) {
    for (var j = 0; j < n; j++) {
      L[i][j] = 0;
    }
  }

  var U = new Array(n);
  for (var i = 0; i < n; i++) {
    U[i] = new Array(n);
  }
  for (var i = 0; i < n; i++) {
    for (var j = 0; j < n; j++) {
      U[i][j] = 0;
    }
  }

  for (var j = 0; j < n; j++) {
    for (var i = 0; i < n; i++) {
      if (i <= j) {
        U[i][j] = A[i][j];
        for (var k = 0; k < i-1; k++) {
          U[i][j] -= L[i][k]*U[k][j];
        }
        if (i == j) {
          L[i][j] = 1;
        } else {
          L[i][j] = 0;
        }
      } else {
        L[i][j] = A[i][j];
        for (var k = 0; k <= j-1; k++) {
          L[i][j] -= L[i][k]*U[k][j];
        }
        L[i][j] /= U[j][j];
        U[i][j] = 0;
      }
    }
  }

  var Y = new Array(n);
  for (var i = 0; i < n; i++) {
    Y[i] = 0;
  }
  for (var i = 0; i < n; i++) {
    Y[i] = B[i][0];
    for (var j = 0; j < i; j++) {
      Y[i] -= L[i][j]*Y[j];
    }
  }

  var X = new Array(n);
  for (var i = 0; i < n; i++) {
    X[i] = 0;
  }
  for (var i = n-1; i >= 0; i--) {
    X[i] = Y[i];
    for (var j = i+1; j < n; j++) {
      X[i] -= U[i][j]*X[j];
    }
    X[i] /= U[i][i];
  }

  console.log('Y:', Y);
  console.log('X:', X);
  console.log('L:', L);
  console.log('U:', U);
}

var matrixA = generateMatrixA(data.n);
var matrixB = generateMatrixB(data.n);
LU(matrixA, matrixB, data.n);
