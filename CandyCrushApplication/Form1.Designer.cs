using System.Runtime.InteropServices;

namespace CandyCrushApplication {
	partial class CandyCrushWindow {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CandyCrushWindow));
			this.panel1 = new System.Windows.Forms.Panel();
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.label1 = new System.Windows.Forms.Label();
			this.CloseButton = new System.Windows.Forms.PictureBox();
			this.PlayerName = new System.Windows.Forms.Label();
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.panel1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).BeginInit();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
			this.panel1.Controls.Add(this.textBox1);
			this.panel1.Controls.Add(this.PlayerName);
			this.panel1.Controls.Add(this.CloseButton);
			this.panel1.Controls.Add(this.label1);
			this.panel1.Location = new System.Drawing.Point(153, 245);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(340, 182);
			this.panel1.TabIndex = 1;
			this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// pictureBox1
			// 
			this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
			this.pictureBox1.Location = new System.Drawing.Point(12, 12);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(612, 221);
			this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
			this.pictureBox1.TabIndex = 3;
			this.pictureBox1.TabStop = false;
			this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.ForeColor = System.Drawing.Color.Maroon;
			this.label1.Location = new System.Drawing.Point(51, 46);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(240, 25);
			this.label1.TabIndex = 0;
			this.label1.Text = "Welcome to Candy Crush!";
			// 
			// CloseButton
			// 
			this.CloseButton.Image = global::CandyCrushApplication.Properties.Resources.Cross;
			this.CloseButton.Location = new System.Drawing.Point(313, 3);
			this.CloseButton.Name = "CloseButton";
			this.CloseButton.Size = new System.Drawing.Size(24, 24);
			this.CloseButton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.CloseButton.TabIndex = 1;
			this.CloseButton.TabStop = false;
			this.CloseButton.Click += new System.EventHandler(this.PictureBox2_Click);
			this.CloseButton.MouseEnter += new System.EventHandler(this.PictureBox2_MouseEnter);
			this.CloseButton.MouseLeave += new System.EventHandler(this.PictureBox2_MouseLeave);
			// 
			// PlayerName
			// 
			this.PlayerName.AutoSize = true;
			this.PlayerName.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.PlayerName.ForeColor = System.Drawing.Color.Maroon;
			this.PlayerName.Location = new System.Drawing.Point(88, 85);
			this.PlayerName.Name = "PlayerName";
			this.PlayerName.Size = new System.Drawing.Size(168, 25);
			this.PlayerName.TabIndex = 2;
			this.PlayerName.Text = "Enter Your Name:";
			// 
			// textBox1
			// 
			this.textBox1.Location = new System.Drawing.Point(68, 117);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(208, 20);
			this.textBox1.TabIndex = 3;
			// 
			// CandyCrushWindow
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Black;
			this.ClientSize = new System.Drawing.Size(638, 439);
			this.Controls.Add(this.pictureBox1);
			this.Controls.Add(this.panel1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "CandyCrushWindow";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Candy Crush";
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.PictureBox CloseButton;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Label PlayerName;
	}
}

