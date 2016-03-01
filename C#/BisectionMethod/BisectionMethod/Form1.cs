using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BisectionMethod
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 6;
            dataGridView1.RowCount = 25;

            dataGridView1.Columns[0].HeaderText = "n";
            dataGridView1.Columns[1].HeaderText = "a";
            dataGridView1.Columns[2].HeaderText = "b";
            dataGridView1.Columns[3].HeaderText = "m";
            dataGridView1.Columns[4].HeaderText = "f(a)*f(m)";
            dataGridView1.Columns[5].HeaderText = "|(b-a)/2|";

            double a = Convert.ToDouble(textBox1.Text);
            double b = Convert.ToDouble(textBox2.Text);

            double eps = 1e-6;
            double m = 0;
            int n = 0;
            
            if (f(a) * f(m) > 0)
            {
                label4.Text = "No Root";
            } else
            {
                do
                {
                    m = (a + b) / 2;


                    dataGridView1[0, n].Value = n + 1;
                    dataGridView1[1, n].Value = a;
                    dataGridView1[2, n].Value = b;
                    dataGridView1[3, n].Value = m;
                    dataGridView1[4, n].Value = f(a) * f(m) > 0 ? "+" : "-";
                    dataGridView1[5, n].Value = Math.Abs((b - a) / 2);

                    if (f(a) * f(m) == 0)
                    {

                    }

                    if (f(a) * f(m) < 0)
                    {
                        b = m;
                    }
                    else
                    {
                        a = m;
                    }
                    n++;

                } while (Math.Abs((b - a) / 2) > eps);
            }
        }

        private double f(double x)
        {
            return x * Math.Exp(-x) + Math.Pow(x, 3) + 1;
        }
    }
}
