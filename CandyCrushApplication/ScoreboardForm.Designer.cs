namespace CandyCrushApplication {
	partial class ScoreboardForm {
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ScoreboardForm));
			this.CloseButton = new System.Windows.Forms.PictureBox();
			this.listBox1 = new System.Windows.Forms.ListBox();
			this.NameLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).BeginInit();
			this.SuspendLayout();
			// 
			// CloseButton
			// 
			this.CloseButton.BackColor = System.Drawing.Color.Transparent;
			this.CloseButton.Image = ((System.Drawing.Image)(resources.GetObject("CloseButton.Image")));
			this.CloseButton.Location = new System.Drawing.Point(320, 12);
			this.CloseButton.Name = "CloseButton";
			this.CloseButton.Size = new System.Drawing.Size(24, 24);
			this.CloseButton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.CloseButton.TabIndex = 3;
			this.CloseButton.TabStop = false;
			this.CloseButton.Click += new System.EventHandler(CloseButton_Click);
			this.CloseButton.MouseEnter += new System.EventHandler(CloseButton_MouseEnter);
			this.CloseButton.MouseLeave += new System.EventHandler(CloseButton_MouseLeave);
			// 
			// listBox1
			// 
			this.listBox1.BackColor = System.Drawing.Color.Salmon;
			this.listBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.listBox1.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
			this.listBox1.ForeColor = System.Drawing.Color.White;
			this.listBox1.FormattingEnabled = true;
			this.listBox1.ItemHeight = 21;
			this.listBox1.Location = new System.Drawing.Point(12, 44);
			this.listBox1.Name = "listBox1";
			this.listBox1.Size = new System.Drawing.Size(330, 378);
			this.listBox1.TabIndex = 4;
			this.listBox1.VisibleChanged += new System.EventHandler(this.ListBox1_VisibleChanged);
			// 
			// NameLabel
			// 
			this.NameLabel.AutoSize = true;
			this.NameLabel.BackColor = System.Drawing.Color.Transparent;
			this.NameLabel.Font = new System.Drawing.Font("Segoe UI Black", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.NameLabel.ForeColor = System.Drawing.Color.Transparent;
			this.NameLabel.Location = new System.Drawing.Point(115, 12);
			this.NameLabel.Name = "NameLabel";
			this.NameLabel.Size = new System.Drawing.Size(130, 25);
			this.NameLabel.TabIndex = 6;
			this.NameLabel.Text = "Leaderboard";
			// 
			// ScoreboardForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackgroundImage = global::CandyCrushApplication.Properties.Resources.GameBackground;
			this.ClientSize = new System.Drawing.Size(356, 450);
			this.Controls.Add(this.NameLabel);
			this.Controls.Add(this.listBox1);
			this.Controls.Add(this.CloseButton);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "ScoreboardForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "ScoreboardForm";
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox CloseButton;
		private System.Windows.Forms.ListBox listBox1;
		private System.Windows.Forms.Label NameLabel;
	}
}