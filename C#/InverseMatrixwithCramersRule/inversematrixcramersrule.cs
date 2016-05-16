using System;

namespace InverseMatrixwithCramersRule
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int m = Convert.ToInt32 (Console.ReadLine ());
			Random r = new Random ();
			double[,] a = new double[m, m];
			double[,] R = new double[m, m];

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					a [i, j] = Math.Round (r.NextDouble () * 20 - 10);
				}
			}

			print (a);
			double D = determinant (a);

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					R [j, i] = Minor (a, i, j) / D;
				}
			}
			print (R);
			Console.ReadLine ();
		}

		private static double Minor(double[,] a, int row, int col)
		{
			int m = a.GetLength(0);
			double[,] M = new double[m - 1, m - 1];
			int ii = 0, jj = 0;

			for (int i = 0; i < m; i++) {
				if (i != row) {
					jj = 0;
					for (int j = 0; j < m; j++) {
						if (j != col) {
							M [ii, jj] = a [i, j];
							jj++;
						}
					}
					ii++;
				}
			}
			return determinant(M);
		}

		private static double determinant(double[,] a)
		{
			int m = a.GetLength (0);
			if (m == 1) {
				return a [0, 0];
			}
			double[,] c = new double[m - 1, m - 1];
			double t = 0;
			int n;
			for (int j = 0; j < m; j++) {
				for (int i = 1; i < m; i++) {
					n = 0;
					for (int k = 0; k < m; k++) {
						if (j != k) {
							c [i - 1, n++] = a [i, k];
						}
					}
				}
				t += Math.Pow (-1, j) * a [0, j] * determinant (c);
			}
			return t;
		}

		private static void print(double[,] c)
		{
			int count = 0;
			int m = c.GetLength (0);
			double[,] w = new double[10 * m, 10 * m];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					w [j, i + count] = c [i, j];
				}
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					Console.Write (string.Format ("{0}\t", w [i, j]));
				}
				Console.Write (Environment.NewLine + Environment.NewLine);
			}

			count += m + 1;
		}
	}
}
