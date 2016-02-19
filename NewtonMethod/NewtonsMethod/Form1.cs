using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NewtonsMethod
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
                dataGridView1.RowCount = 22;
                dataGridView1.Columns[0].HeaderText = "n";
                dataGridView1.Columns[1].HeaderText = "x0";
                dataGridView1.Columns[2].HeaderText = "f(x0)";
                dataGridView1.Columns[3].HeaderText = "Df(x0)";
                dataGridView1.Columns[4].HeaderText = "x1";
                dataGridView1.Columns[5].HeaderText = "Dx";

                double x0 = Convert.ToDouble(textBox1.Text);
                double x1 = 0;
                double eps = 1e-6;
                double Dx;
                int i = 0;

                do
                {
                    x1 = x0 - f(x0) / Df(x0);

                    Dx = Math.Abs(x1 - x0);

                    dataGridView1[0, i].Value = i + 1;
                    dataGridView1[1, i].Value = x0;
                    dataGridView1[2, i].Value = f(x0);
                    dataGridView1[3, i].Value = Df(x0);
                    dataGridView1[4, i].Value = x1;
                    dataGridView1[5, i].Value = Dx;

                    i++;
                    x0 = x1;
                } while (Dx > eps);
            }

        private double f(double x)
        {
            return x * Math.Exp(-x) + Math.Pow(x, 3.0) + 1.0;
        }

        private double Df(double x)
        {
            return Math.Exp(-x) - x * Math.Exp(-x) + 3.0 * Math.Pow(x, 2.0);
        }
    }
}
