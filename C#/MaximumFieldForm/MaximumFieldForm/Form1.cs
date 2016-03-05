using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MaximumFieldForm
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
            dataGridView1.Columns[1].HeaderText = "a";
            dataGridView1.Columns[2].HeaderText = "b";
            dataGridView1.Columns[3].HeaderText = "c";
            dataGridView1.Columns[4].HeaderText = "f(a)";
            dataGridView1.Columns[5].HeaderText = "f(c)";
            dataGridView1.Columns[6].HeaderText = "|c|";

            double a = 0;
            double b = 1;
            double c;
            int i = 0;
            double eps = 1e-6;

            while (Math.Abs(b-a) > eps)
            {
                c = (a + b) / 2;
                dataGridView1[0, i].Value = i + 1;
                dataGridView1[1, i].Value = a;
                dataGridView1[2, i].Value = b;
                dataGridView1[3, i].Value = c;
                dataGridView1[4, i].Value = f(a);
                dataGridView1[5, i].Value = f(c);
                dataGridView1[6, i].Value = Math.Abs(c);

                if (f(a)*f(c) < 0)
                {
                    b = c;
                } else
                {
                    a = c;
                }
                i++;
            }
            
        }

        private double f(double x)
        {
            return (Math.PI - 2 * x) * Math.Sin(x) * Math.Cos(x) - Math.Pow(Math.Sin(x), 2.0);
        }
    }
}
