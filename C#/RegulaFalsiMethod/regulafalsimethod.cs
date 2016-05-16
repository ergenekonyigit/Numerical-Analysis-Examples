using System;

namespace RegulaFalsa
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.Write ("a:");
			double a = Convert.ToDouble (Console.ReadLine ());
			Console.Write ("b:");
			double b = Convert.ToDouble (Console.ReadLine ());
			double c;
			double eps = 1e-6;
			int i = 0;

			Console.WriteLine ("i, a, b, f(a), f (b), c, f(c), +/-");
			do {
				c = (a * f (b) - b * f (a)) / (f (b) - f (a));
				Console.WriteLine ("{0},{1},{2},{3},{4},{5},{6},{7}", i + 1, a, b, f (a), f (b), c, f (c), f (c) > 0 ? "+" : "-");
				i++;
				if (f (a) * f (c) > 0) {
					a = c;
				} else {
					b = c;
				}

			} while(Math.Abs (f (c)) > eps);
			Console.ReadLine ();
		}
		
		private static double f(double x)
		{
			return 10 * Math.Exp (-x / 2.0) * (Math.Cos (6.0 * x) + Math.Sin (8.0 * x));
		}
	}
}
