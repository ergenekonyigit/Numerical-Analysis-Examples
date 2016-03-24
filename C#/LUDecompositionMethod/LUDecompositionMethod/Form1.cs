using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LUDecompositionMethod
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int count = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 10 * m;
            dataGridView1.ColumnCount = m + 4;
            Random r = new Random();

            double[] x1 = new double[m];
            for (int i = 0; i < m; i++)
            {
                x1[i] = Math.Round(r.NextDouble() * 200 - 100);
            }
            double[,] a = new double[m, m];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 100 - 50);
                }
            }
            double[] b = new double[m];
            for (int i = 0; i < m; i++)
            {
                double t = 0;
                for (int j = 0; j < m; j++)
                {
                    t += a[i, j] * x1[j];
                }
                b[i] = t;
            }
            print(a, x1, b);
            double[] x2 = GaussElimination(a, b);
        }

        private double[] GaussElimination(double[,] a, double[] b)
        {
            int m = b.GetLength(0);

            double[] x = new double[m];
            double p;

            print(a, x, b);

            // lower triangular matrix
            for (int k = 0; k < m - 1; k++)
            {
                for (int i = k + 1; i < m; i++)
                {
                    p = a[i, k] / a[k, k];
                    for (int j = k; j < m; j++)
                    {
                        a[i, j] -= p * a[k, j];
                    }
                    b[i] -= p * b[k];
                }
            }

            print(a, x, b);

            // upper triangular matrix
            for (int k = m - 1; k > 0 - 1; k--)
            {
                for (int i = k - 1; i >= 0; i--)
                {
                    p = a[i, k] / a[k, k];
                    for (int j = k; j < m; j++)
                    {
                        a[i, j] -= p * a[k, j];
                    }
                    b[i] -= p * b[k];
                }
            }

            // identity matrix
            for (int i = m - 1; i >= 0; i--)
            {
                double t = b[i];
                for (int j = i + 1; j < m; j++)
                {
                    t -= a[i, j] * x[j];
                }
                x[i] = t / a[i, i];
            }

            for (int i = 0; i < m; i++)
            {
                b[i] /= a[i, i];
                a[i, i] = 1;
            }

            print(a, x, b);
            return x;
        }

        private double[] LU(double[,] a, double[] b)
        {
            int m = b.GetLength(0);
            double[] x = new double[m];
            double[,] L = new double[m, m];
            double[,] U = new double[m, m];
            double t1, t2;

            for (int i = 0; i < m; i++)
            {
                L[i, i] = 1;
                for (int j = 0; j < m; j++)
                {
                    t1 = 0;
                    for (int k = 0; k < i-1; k++)
                    {
                        t1 += L[i, k] * U[k, j];
                    }
                    U[i, j] = a[i, j] - t1;

                    t2 = 0;
                    for (int k = 0; k < j-1; k++)
                    {
                        t2 += L[i, k] * U[k, j];
                    }
                    L[i, j] = 1.0 / U[i, j] * (a[i, j] - t2);
                }
            }

            print(L, x, b);
            print(U, x, b);
            return x;
        }

        private void print(double[,] a, double[] x, double[] b)
        {
            int m = b.GetLength(0);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dataGridView1[j, i + count].Value = a[i, j];
                }
                dataGridView1[m + 1, i + count].Value = x[i];
                dataGridView1[m + 3, i + count].Value = b[i];
            }

            count += m + 1;
        }
    }
}
