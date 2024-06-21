namespace Regex_DOT_NET
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.richTextBoxLastName = new System.Windows.Forms.RichTextBox();
			this.richTextBoxFirstName = new System.Windows.Forms.RichTextBox();
			this.buttonOK = new System.Windows.Forms.Button();
			this.maskedTextBoxPhoneNuber = new System.Windows.Forms.MaskedTextBox();
			this.labelPhoneNumber = new System.Windows.Forms.Label();
			this.richTextBoxEmail = new System.Windows.Forms.RichTextBox();
			this.labelEmail = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// richTextBoxLastName
			// 
			this.richTextBoxLastName.Location = new System.Drawing.Point(72, 12);
			this.richTextBoxLastName.Multiline = false;
			this.richTextBoxLastName.Name = "richTextBoxLastName";
			this.richTextBoxLastName.Size = new System.Drawing.Size(211, 20);
			this.richTextBoxLastName.TabIndex = 0;
			this.richTextBoxLastName.Text = "";
			// 
			// richTextBoxFirstName
			// 
			this.richTextBoxFirstName.Location = new System.Drawing.Point(72, 38);
			this.richTextBoxFirstName.Multiline = false;
			this.richTextBoxFirstName.Name = "richTextBoxFirstName";
			this.richTextBoxFirstName.Size = new System.Drawing.Size(211, 20);
			this.richTextBoxFirstName.TabIndex = 1;
			this.richTextBoxFirstName.Text = "";
			// 
			// buttonOK
			// 
			this.buttonOK.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.buttonOK.Location = new System.Drawing.Point(332, 16);
			this.buttonOK.Name = "buttonOK";
			this.buttonOK.Size = new System.Drawing.Size(75, 23);
			this.buttonOK.TabIndex = 4;
			this.buttonOK.Text = "OK";
			this.buttonOK.UseVisualStyleBackColor = true;
			this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
			// 
			// maskedTextBoxPhoneNuber
			// 
			this.maskedTextBoxPhoneNuber.Location = new System.Drawing.Point(72, 64);
			this.maskedTextBoxPhoneNuber.Mask = "(999) 000-00-00";
			this.maskedTextBoxPhoneNuber.Name = "maskedTextBoxPhoneNuber";
			this.maskedTextBoxPhoneNuber.Size = new System.Drawing.Size(211, 20);
			this.maskedTextBoxPhoneNuber.TabIndex = 5;
			// 
			// labelPhoneNumber
			// 
			this.labelPhoneNumber.AutoSize = true;
			this.labelPhoneNumber.Location = new System.Drawing.Point(290, 70);
			this.labelPhoneNumber.Name = "labelPhoneNumber";
			this.labelPhoneNumber.Size = new System.Drawing.Size(41, 13);
			this.labelPhoneNumber.TabIndex = 6;
			this.labelPhoneNumber.Text = "Phone:";
			// 
			// richTextBoxEmail
			// 
			this.richTextBoxEmail.Location = new System.Drawing.Point(72, 90);
			this.richTextBoxEmail.Multiline = false;
			this.richTextBoxEmail.Name = "richTextBoxEmail";
			this.richTextBoxEmail.Size = new System.Drawing.Size(211, 20);
			this.richTextBoxEmail.TabIndex = 3;
			this.richTextBoxEmail.Text = "";
			// 
			// labelEmail
			// 
			this.labelEmail.AutoSize = true;
			this.labelEmail.Location = new System.Drawing.Point(69, 113);
			this.labelEmail.Name = "labelEmail";
			this.labelEmail.Size = new System.Drawing.Size(54, 13);
			this.labelEmail.TabIndex = 7;
			this.labelEmail.Text = "labelEmail";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(419, 203);
			this.Controls.Add(this.labelEmail);
			this.Controls.Add(this.labelPhoneNumber);
			this.Controls.Add(this.maskedTextBoxPhoneNuber);
			this.Controls.Add(this.buttonOK);
			this.Controls.Add(this.richTextBoxEmail);
			this.Controls.Add(this.richTextBoxFirstName);
			this.Controls.Add(this.richTextBoxLastName);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.RichTextBox richTextBoxLastName;
		private System.Windows.Forms.RichTextBox richTextBoxFirstName;
		private System.Windows.Forms.Button buttonOK;
		private System.Windows.Forms.MaskedTextBox maskedTextBoxPhoneNuber;
		private System.Windows.Forms.Label labelPhoneNumber;
		private System.Windows.Forms.RichTextBox richTextBoxEmail;
		private System.Windows.Forms.Label labelEmail;
	}
}

