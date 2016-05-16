using System;

namespace MaximumFieldForm
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			double a = 0;
			double b = 1;
			double c;
			int i = 0;
			double eps = 1e-6;

			Console.WriteLine ("i, a, b, c, f(a), f(c), |c|");
			while (Math.Abs(b-a) > eps)
			{
				c = (a + b) / 2;
				Console.WriteLine ("{0},{1},{2},{3},{4},{5},{6}", i + 1, a, b, c, f (a), f (c), Math.Abs(c));
				if (f(a)*f(c) < 0)
				{
					b = c;
				} else
				{
					a = c;
				}
				i++;
			}
			Console.ReadLine ();
		}

		private static double f(double x)
		{
			return (Math.PI - 2 * x) * Math.Sin (x) * Math.Cos (x) - Math.Pow (Math.Sin (x), 2.0);
		}
	}
}
