using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace InverseMatrixwithGaussianEliminationMethod
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
            dataGridView1.RowCount = 3 * m;
            dataGridView1.ColumnCount = m;
            Random r = new Random();

            double[,] a = new double[m, m];
            double[,] b = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }

        }
        private double[,] GaussElimination(double[,] a, double[,] b)
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
                        b[i, j] -= p * a[k, j];
                    }
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
                        b[i, j] -= p * a[k, j];
                    }
                }
            }

            // identity matrix
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    b[i, j] = a[i, i];
                    a[i, i] = 1;
                }
            }
            return b;
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
