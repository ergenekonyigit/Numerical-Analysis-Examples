using System;

namespace SecantMethod
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("x0:");
			double x0 = Convert.ToDouble(Console.ReadLine());
			Console.WriteLine ("x1:");
			double x1 = Convert.ToDouble(Console.ReadLine());
			double x2;
			double eps = 1e-6;
			int i = 0;
			double Dx;

			Console.WriteLine ("i, x0, x1, f (x0), f(x1), x2, Dx");
			do {
				x2 = ((x0 * f (x1)) - (x1 * f (x0))) / (f (x1) - f (x0));
				Dx = Math.Abs (x2 - x1);
				Console.WriteLine ("{0},{1},{2},{3},{4},{5}", i + 1, x0, x1, f (x0), f (x1), x2, Dx);
				x0 = x1;
				x1 = x2;
				i++;
			} while (Dx > eps);
			Console.ReadLine ();
		}

		private static double f(double x)
		{
			return x * Math.Exp (-x) + Math.Pow (x, 3.0) + 1.0;
		}
	}
}
