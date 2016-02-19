using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace regula_falsa
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 8;
            dataGridView1.RowCount = 30;
            dataGridView1.Columns[0].HeaderText = "n";
            dataGridView1.Columns[1].HeaderText = "a";
            dataGridView1.Columns[2].HeaderText = "b";
            dataGridView1.Columns[3].HeaderText = "f(a)";
            dataGridView1.Columns[4].HeaderText = "f(b)";
            dataGridView1.Columns[5].HeaderText = "c";
            dataGridView1.Columns[6].HeaderText = "f(c)";
            dataGridView1.Columns[7].HeaderText = "+/-";

            double a = Convert.ToDouble(textBox1.Text);
            double b = Convert.ToDouble(textBox2.Text);
            double c;
            double eps = 1e-6;
            int i = 0;

            do
            {
                c = (a * f(b) - b * f(a)) / (f(b) - f(a));
                dataGridView1[0, i].Value = i+1;
                dataGridView1[1, i].Value = a;
                dataGridView1[2, i].Value = b;
                dataGridView1[3, i].Value = f(a).ToString("N7");
                dataGridView1[4, i].Value = f(b).ToString("N7");
                dataGridView1[5, i].Value = c.ToString("N7");
                dataGridView1[6, i].Value = f(c).ToString("N7");
                dataGridView1[7, i].Value = f(c) > 0 ? "+" : "-"; 
                i++;

                if (f(a)*f(c) > 0)
                {
                    a = c;
                } else
                {
                    b = c;
                }
                
            } while (Math.Abs(f(c)) > eps);

        }

        private double f(double x)
        {
            return 10*Math.Exp(-x/2.0)*(Math.Cos(6.0*x)+Math.Sin(8.0*x));
        }
    }
}
