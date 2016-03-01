using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SecantMethod
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 7;
            dataGridView1.RowCount = 25;
            dataGridView1.Columns[0].HeaderText = "n";
            dataGridView1.Columns[1].HeaderText = "x0";
            dataGridView1.Columns[2].HeaderText = "x1";
            dataGridView1.Columns[3].HeaderText = "f(x0)";
            dataGridView1.Columns[4].HeaderText = "f(x1)";
            dataGridView1.Columns[5].HeaderText = "x2";
            dataGridView1.Columns[6].HeaderText = "|Dx|";

            double x0 = Convert.ToDouble(textBox1.Text);
            double x1 = Convert.ToDouble(textBox2.Text);
            double x2;
            double eps = 1e-6;
            int n = 0;
            double Dx;
            do
            {
                
                x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
                Dx = Math.Abs(x2 - x1);

                dataGridView1[0, n].Value = n + 1;
                dataGridView1[1, n].Value = x0;
                dataGridView1[2, n].Value = x1;
                dataGridView1[3, n].Value = f(x0);
                dataGridView1[4, n].Value = f(x1);
                dataGridView1[5, n].Value = x2;
                dataGridView1[6, n].Value = Dx;

                x0 = x1;
                x1 = x2;
                n++;
            } while (Dx > eps);
            
        }

        private double f(double x)
        {
            return x * Math.Exp(-x) + Math.Pow(x, 3.0) + 1;
        }

    }
}
