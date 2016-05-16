using System;

namespace NewtonMethod
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.Write("x0:");
			double x0 = Convert.ToDouble (Console.ReadLine ());
			double x1 = 0;
			double eps = 1e-6;
			double Dx;
			int i = 0;

			Console.WriteLine ("i, x0, f(x0), Df (x0), x1, Dx");
			do {
				x1 = x0 - f (x0) / Df (x0);
				Dx = Math.Abs (x1 - x0);
				Console.WriteLine ("{0},{1},{2},{3},{4},{5}", i + 1, x0, f (x0), Df (x0), x1, Dx);
				i++;
				x0 = x1;
			} while(Dx > eps);
      	Console.ReadLine();
		}

		private static double f(double x)
		{
			return x * Math.Exp (-x) + Math.Pow (x, 3.0) + 1.0;
		}

		private static double Df(double x)
		{
			return Math.Exp (-x) - x * Math.Exp (-x) + 3.0 * Math.Pow (x, 2.0);
		}
	}
}
