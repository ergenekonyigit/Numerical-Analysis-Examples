using System;

namespace BisectionMethod
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.Write ("a:");
			double a = Convert.ToDouble (Console.ReadLine ());
			Console.Write ("b:");
			double b = Convert.ToDouble (Console.ReadLine ());
			double eps = 1e-6;
			double m = 0;
			int i = 0;

			if (f(a) * f(m) > 0)
			{
				Console.Write ("No Root");
			} else
			{
				do {
					m = (a + b) / 2;
					Console.WriteLine ("{0},{1},{2},{3},{4},{5}", i + 1, a, b, m, f (a) * f (b) > 0 ? "+" : "-", Math.Abs ((b - a) / 2));

					if (f (a) * f (m) == 0) {

					}

					if (f (a) * f (m) < 0) {
						b = m;
					} else {
						a = m;
					}
					i++;
				
				} while (Math.Abs ((b - a) / 2) > eps);
			}
			Console.ReadLine ();
		}

		private static double f(double x)
		{
			return x * Math.Exp(-x) + Math.Pow(x, 3) + 1;
		}
	}
}
