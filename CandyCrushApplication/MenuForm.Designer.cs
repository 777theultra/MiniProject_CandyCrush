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
			this.CloseButton = new System.Windows.Forms.PictureBox();
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.NameInput = new System.Windows.Forms.TextBox();
			this.PlayerName = new System.Windows.Forms.Label();
			this.Title = new System.Windows.Forms.Label();
			this.PlayButton = new System.Windows.Forms.Button();
			this.PlayButton2 = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			this.SuspendLayout();
			// 
			// CloseButton
			// 
			this.CloseButton.BackColor = System.Drawing.Color.Transparent;
			this.CloseButton.Image = ((System.Drawing.Image)(resources.GetObject("CloseButton.Image")));
			this.CloseButton.Location = new System.Drawing.Point(309, 12);
			this.CloseButton.Name = "CloseButton";
			this.CloseButton.Size = new System.Drawing.Size(24, 24);
			this.CloseButton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.CloseButton.TabIndex = 1;
			this.CloseButton.TabStop = false;
			this.CloseButton.Click += new System.EventHandler(this.PictureBox2_Click);
			this.CloseButton.MouseEnter += new System.EventHandler(this.CloseButton_MouseEnter);
			this.CloseButton.MouseLeave += new System.EventHandler(this.CloseButton_MouseLeave);
			// 
			// pictureBox1
			// 
			this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
			this.pictureBox1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.BackgroundImage")));
			this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.pictureBox1.Location = new System.Drawing.Point(3, 24);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(342, 123);
			this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.pictureBox1.TabIndex = 3;
			this.pictureBox1.TabStop = false;
			this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// NameInput
			// 
			this.NameInput.Location = new System.Drawing.Point(70, 249);
			this.NameInput.MaxLength = 24;
			this.NameInput.Name = "NameInput";
			this.NameInput.Size = new System.Drawing.Size(208, 20);
			this.NameInput.TabIndex = 6;
			// 
			// PlayerName
			// 
			this.PlayerName.AutoSize = true;
			this.PlayerName.BackColor = System.Drawing.Color.Transparent;
			this.PlayerName.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.PlayerName.ForeColor = System.Drawing.Color.White;
			this.PlayerName.Location = new System.Drawing.Point(89, 221);
			this.PlayerName.Name = "PlayerName";
			this.PlayerName.Size = new System.Drawing.Size(168, 25);
			this.PlayerName.TabIndex = 5;
			this.PlayerName.Text = "Enter Your Name:";
			this.PlayerName.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// Title
			// 
			this.Title.AutoSize = true;
			this.Title.BackColor = System.Drawing.Color.Transparent;
			this.Title.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.Title.ForeColor = System.Drawing.Color.White;
			this.Title.Location = new System.Drawing.Point(53, 187);
			this.Title.Name = "Title";
			this.Title.Size = new System.Drawing.Size(240, 25);
			this.Title.TabIndex = 4;
			this.Title.Text = "Welcome to Candy Crush!";
			this.Title.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// PlayButton
			// 
			this.PlayButton.Location = new System.Drawing.Point(70, 281);
			this.PlayButton.Name = "PlayButton";
			this.PlayButton.Size = new System.Drawing.Size(102, 25);
			this.PlayButton.TabIndex = 7;
			this.PlayButton.Text = "Level 1";
			this.PlayButton.UseVisualStyleBackColor = true;
			this.PlayButton.Click += new System.EventHandler(this.PlayButton_Click);
			// 
			// PlayButton2
			// 
			this.PlayButton2.Location = new System.Drawing.Point(178, 281);
			this.PlayButton2.Name = "PlayButton2";
			this.PlayButton2.Size = new System.Drawing.Size(100, 25);
			this.PlayButton2.TabIndex = 8;
			this.PlayButton2.Text = "Level 2";
			this.PlayButton2.UseVisualStyleBackColor = true;
			this.PlayButton2.Click += new System.EventHandler(this.PlayButton_Click);
			// 
			// CandyCrushWindow
			// 
			this.AcceptButton = this.PlayButton;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
			this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
			this.ClientSize = new System.Drawing.Size(347, 321);
			this.Controls.Add(this.PlayButton2);
			this.Controls.Add(this.PlayButton);
			this.Controls.Add(this.CloseButton);
			this.Controls.Add(this.NameInput);
			this.Controls.Add(this.PlayerName);
			this.Controls.Add(this.Title);
			this.Controls.Add(this.pictureBox1);
			this.ForeColor = System.Drawing.SystemColors.ControlText;
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "CandyCrushWindow";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Candy Crush";
			this.TransparencyKey = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(64)))));
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.PictureBox CloseButton;
		private System.Windows.Forms.TextBox NameInput;
		private System.Windows.Forms.Label PlayerName;
		private System.Windows.Forms.Label Title;
		private System.Windows.Forms.Button PlayButton;
		private System.Windows.Forms.Button PlayButton2;
	}
}

