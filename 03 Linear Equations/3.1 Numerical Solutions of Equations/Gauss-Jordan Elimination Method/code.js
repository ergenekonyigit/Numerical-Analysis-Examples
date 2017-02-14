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

function addition(A, B, n) {
  var C = new Array(n);
  for (var i = 0; i < n; i++) {
    C[i] = new Array(n);
  }
  for (var i = 0; i < n; i++) {
    for (var j = 0; j < n; j++) {
      C[i][j] = A[i][j];
    }
  }
  for (var i = 0; i < n; i++) {
    C[i][n] = B[i][0];
  }
  console.log('C:', C);
  return C;
}

function gaussJordan(C, n) {
  for (var j = 0; j < n; j++) {
    for (var i = 0; i < n; i++) {
      if (i != j) {
        var t = C[i][j]/C[j][j];
        for (var k = 0; k < n+1; k++) {
          C[i][k] -= t*C[j][k];
        }
      }
    }
  }

  var x = new Array(n);
  for (var i = 0; i < n; i++) {
    x[i] = C[i][n]/C[i][i];
  }
  console.log('C:', C);
  console.log('x:', x);
}

var matrixA = generateMatrixA(data.n);
var matrixB = generateMatrixB(data.n);
var matrix = addition(matrixA, matrixB, data.n);
gaussJordan(matrix, data.n);
