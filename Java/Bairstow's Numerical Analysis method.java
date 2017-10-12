//----------------------- HOW TO USE THIS CODE --------------------------
// The easiest way is to put the data in a file named input.txt
// The first line is n, degree of the polynomial.
// In the second line n + 1 values that correspond 
// to the n + 1 coefficients, separated by a single space, in order:
// If the polynomial is f(x)=  a[0] + a[1] * x + ... + a[n] * x^n
// then the input should be
// a[n] a[n-1] ... a[1] a[0]
// 
// Sample input file:
// 4
// 1 3 1 2 4
//
// This input corresponds to the polynomial:
// f(x) = 4 * x^4 + 2 * x^3 + x^2 + 3 * x + 1
//
// Run the file as : 
// $ java LinBairstow < input.txt
// $ java Bairstow < input.txt > output.txt #if you want to output in a file named output.txt
//-------------------- THAT'S ALL - YOU CAN RUN THE CODE NOW--------------
import java.io.*;

public class Bairstow {
  private double[] a;
  private double[] b;
  private double[] c;
  private int n;

  public Bairstow()
  {
    a = new double[20];
    b = new double[20];
    c = new double[20];
  }

  public void readInput() throws IOException
  {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(reader.readLine());

    String[] tokens = reader.readLine().split(" ");

    for (int i = 0; i < n + 1; i++)
      a[n-i] = Double.parseDouble(tokens[i]);
  }

  public void solve()
  {
    int i, j;
    double r1, r2, du, dv, u, v, r, dr;
    double sq, det, nu, nv, error;
    double epsilon = 1e-8;
    while (n > 3) {
      u = 0;
      v = 0;
      error = 1;
      c[n] = b[n] = a[n];

      while (error > epsilon) {
        b[n-1] = a[n-1] + u * b[n];
        c[n-1] = b[n-1] + u * c[n];

        for (i = n - 2; i > 0; i--) {
          b[i] = a[i] + u * b[i+1] + v * b[i+2];
          c[i] = b[i] + u * c[i+1] + v * c[i+2];
        }

        b[0] = a[0] + u * b[1] + v * b[2];

        det = (c[2] * c[2]) - c[1] * c[3];

        nu = b[0] * c[3] - b[1] * c[2];
        nv = b[1] * c[1] - b[0] * c[2];
        
        if (det == 0) {
          du = dv = 1;
        } else {
          du = nu / det;
          dv = nv / det;
        }
        
        u += du;
        v += dv;

        error = Math.sqrt(du * du + dv * dv);
      }
      System.out.println("1" + " " + (-1*u) + " "+(-1*v));
      for(int t=n-2;t>=0;t--){
        System.out.print(b[t]+" ");
      }
      System.out.println();
      sq = u * u + 4 * v;

      if (sq < 0) {
        r1 = u/2;
        r2 = Math.sqrt(-sq)/2;

        System.out.println(r1 + " + " + r2 + "i");
        System.out.println(r1 + " - " + r2 + "i");
      } else {
        r1 = u/2 + Math.sqrt(sq)/2;
        r2 = u/2 - Math.sqrt(sq)/2;

        System.out.println(r1);
        System.out.println(r2);
      }

      n -= 2;

      for (i = 0; i < n + 1; i++)
        a[i] = b[i+2];
    }
    
    if (n == 3) {
      r = 0;
      error = 1;
      b[n] = a[n];

      while (error > epsilon) {
        b[2] = a[2] + r * b[3];
        b[1] = a[1] + r * b[2];
        b[0] = a[0] + r * b[1];

        double d = a[1] + (2 * a[2] * r) + (3 * a[3] * r * r);

        if (d == 0)
          dr = 1;
        else
          dr = -b[0] / d;

        r -= dr;
        error = Math.abs(dr);
      }

      System.out.println(r);
      n--;

      for (i = 0; i < n + 1; i++)
        a[i] = b[i + 1];
    }


    if (n == 2) {
      u = -a[1] / a[2];
      v = -a[0] / a[2];
      sq = u * u + 4 * v;

      if (sq < 0) {
        r1 = u/2;
        r2 = Math.sqrt(-sq)/2;

        System.out.println(r1 + " + " + r2 + "i");
        System.out.println(r1 + " - " + r2 + "i");
      } else {
        r1 = u/2 + Math.sqrt(sq)/2;
        r2 = u/2 - Math.sqrt(sq)/2;

        System.out.println(r1);
        System.out.println(r2);
      }
    } else if (n == 1) {
      System.out.println(-a[0] / a[1]);
    }
  }

  public static void main(String[] args) throws IOException
  {
    Bairstow Bairstow = new Bairstow();

    Bairstow.readInput();
    Bairstow.solve();
  }
}

//--------------------------CODE OVER-------------------------