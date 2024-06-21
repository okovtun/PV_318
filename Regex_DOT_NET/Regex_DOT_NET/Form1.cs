//Добить проект, кто этого еще не сделал.
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Regex_DOT_NET
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void buttonOK_Click(object sender, EventArgs e)
		{
			labelPhoneNumber.Text = "Phone: " + maskedTextBoxPhoneNuber.Text;
			string sPhone = maskedTextBoxPhoneNuber.Text;
			sPhone = sPhone.Replace("(", "");
			sPhone = sPhone.Replace(")", "");
			sPhone = sPhone.Replace("-", "");
			sPhone = sPhone.Replace(" ", "");
			long iPhone = Convert.ToInt64(sPhone);
			labelPhoneNumber.Text += $"\n{iPhone}";

			//############################

			try
			{
				System.Net.Mail.MailAddress email = new System.Net.Mail.MailAddress(richTextBoxEmail.Text);
				labelEmail.Text = email.Address;
			}
			catch (Exception ex)
			{
				labelEmail.Text = ex.Message;
			}
		}
	}
}
