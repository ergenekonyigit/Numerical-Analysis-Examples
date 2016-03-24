using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace InverseMatrixwithCramersRule
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
            dataGridView1.RowCount = 3*m;
            dataGridView1.ColumnCount = m;

            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] R = new double[m, m];


            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }

            print(a);
            double D = determinant(a);

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    R[j, i] = Minor(a, i, j) / D;
                }
            }
            print(R);
        }

        private double Minor(double[,] a, int row, int col)
        {
            int m = a.GetLength(0);
            double[,] M = new double[m - 1, m - 1];
            int ii = 0, jj = 0;

            for (int i = 0; i < m; i++)
            {
                if (i != row)
                {
                    jj = 0;
                    for (int j = 0; j < m; j++)
                    {
                        if (j != col)
                        {
                            M[ii, jj] = a[i, j];
                            jj++;
                        }
                    }
                    ii++;
                }
            }
            return determinant(M);
        }

        private void print(double[,] c)
        {
            int m = c.GetLength(0);

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dataGridView1[j, i + count].Value = c[i, j];
                }
            }
            count += m + 1;
        }

        private double determinant(double[,] a)
        {
            int m = a.GetLength(0);
            if (m == 1)
            {
                return a[0, 0];
            }
            double[,] c = new double[m - 1, m - 1];
            double t = 0;
            int n;
            for (int j = 0; j < m; j++)
            {
                for (int i = 1; i < m; i++)
                {
                    n = 0;
                    for (int k = 0; k < m; k++)
                    {
                        if (j != k)
                        {
                            c[i - 1, n++] = a[i, k];
                        }
                    }
                }
                t += Math.Pow(-1, j) * a[0, j] * determinant(c);
            }
            return t;
        }

    }
}
