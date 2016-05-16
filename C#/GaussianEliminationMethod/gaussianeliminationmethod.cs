using System;

namespace GaussianEliminationMethod
{
	class MainClass
	{
		
		public static void Main (string[] args)
		{
			int m = Convert.ToInt32 (Console.ReadLine ());
			Random r = new Random ();

			double[] x1 = new double[m];
			for (int i = 0; i < m; i++) {
				x1 [i] = Math.Round (r.NextDouble () * 200 - 100);
			}
			double[,] a = new double[m, m];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					a [i, j] = Math.Round (r.NextDouble () * 100 - 50);
				}
			}
			double[] b = new double[m];
			for (int i = 0; i < m; i++) {
				double t = 0;
				for (int j = 0; j < m; j++) {
					t += a [i, j] * x1 [j];
				}
				b [i] = t;
			}
			print(a, x1, b);
			double[] x2 = GaussianElimination (a, b);
			Console.ReadLine ();
		}

		private static double[] GaussianElimination(double[,] a, double[] b)
		{
			int m = b.GetLength(0);

			double[] x = new double[m];
			double p;
			for (int k = 0; k < m - 1; k++) {
				for (int i = k + 1; i < m; i++) {
					p = a [i, k] / a [k, k];
					for (int j = k; j < m; j++) {
						a [i, j] -= p * a [k, j];
					}
					b [i] -= p * b [k];
				}
			}
			for (int i = m - 1; i >= 0; i--) {
				double t = b [i];
				for (int j = i + 1; j < m; j++) {
					t -= a [i, j] * x [j];
				}
				x [i] = t / a [i, i];
			}
			print(a, x, b);
			return x;
		}

		private static void print(double[,] a, double[] x, double[] b)
		{
			int count = 0;
			int m = b.GetLength(0);
			double[,] w = new double[10 * m, 10 * m]; 
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					w [j, i + count] = a [i, j];
				}
				w [m + 1, i + count] = x [i];
				w [m + 3, i + count] = b [i];
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					Console.Write (string.Format("{0}\t",w[i,j]));
				}
				Console.Write (Environment.NewLine + Environment.NewLine);
			}

			count += m + 1;
		}
	}
}
