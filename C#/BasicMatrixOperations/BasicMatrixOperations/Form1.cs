using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BasicMatrixOperations
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
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] b = new double[m, m];
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                    b[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }
            print(a);
            print(b);
            c = addition(a, b);
            print(c);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] b = new double[m, m];
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                    b[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }
            print(a);
            print(b);
            c = multiply(a, b);
            print(c);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] b = new double[m, m];
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                    b[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }
            print(a);
            print(b);
            c = elmultiply(a, b);
            print(c);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }
            print(a);
            c = transpose(a);
            print(c);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }

            label1.Text = "Determinant: " + determinant(a); 

            print(a);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            int m = Convert.ToInt32(numericUpDown1.Value);
            dataGridView1.RowCount = 100;
            dataGridView1.ColumnCount = m;
            Random r = new Random();
            double[,] a = new double[m, m];
            double[,] b = new double[m, m];
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                    b[i, j] = Math.Round(r.NextDouble() * 20 - 10);
                }
            }
            print(a);
            print(b);
            c = subtraction(a, b);
            print(c);
        }

        private double[,] addition(double[,] a, double[,] b)
        {
            int m = a.GetLength(0);
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    c[i, j] = a[i, j] + b[i, j];
                }
            }
            return c;
        }

        private double[,] multiply(double[,] a, double[,] b)
        {
            int m = a.GetLength(0);
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int k = 0; k < m; k++)
                    {
                        c[i, j] += a[i, k] * b[k, j];
                    }
                }
            }
            return c;
        }

        private double[,] elmultiply(double[,] a, double[,] b)
        {
            int m = a.GetLength(0);
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    c[i, j] = a[i, j] * b[i, j];
                }
            }
            return c;
        }

        private double[,] transpose(double[,] a)
        {
            int m = a.GetLength(0); // row
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    c[j, i] = a[i, j];
                }
            }
            return c;
        }

        private double determinant(double[,] a)
        {
            int m = a.GetLength(0); // row
            if (m == 1)
            {
                return a[0,0];
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

        private double[,] subtraction(double[,] a, double[,] b)
        {
            int m = a.GetLength(0);
            double[,] c = new double[m, m];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    c[i, j] = a[i, j] - b[i, j];
                }
            }
            return c;
        }


        private void print(double[,] a)
        {
            int m = a.GetLength(0);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dataGridView1[j, i + count].Value = a[i, j];
                }

            }
            count += m + 1;
        }
    }
}

