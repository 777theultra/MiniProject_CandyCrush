namespace CandyCrushApplication {
	partial class GameForm {
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameForm));
			this.CloseButton = new System.Windows.Forms.PictureBox();
			this.PointsLabel = new System.Windows.Forms.Label();
			this.NameLabel = new System.Windows.Forms.Label();
			this.ObjectiveLabel = new System.Windows.Forms.Label();
			this.MovesLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).BeginInit();
			this.SuspendLayout();
			// 
			// CloseButton
			// 
			this.CloseButton.BackColor = System.Drawing.Color.Transparent;
			this.CloseButton.Image = ((System.Drawing.Image)(resources.GetObject("CloseButton.Image")));
			this.CloseButton.Location = new System.Drawing.Point(557, 12);
			this.CloseButton.Name = "CloseButton";
			this.CloseButton.Size = new System.Drawing.Size(24, 24);
			this.CloseButton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.CloseButton.TabIndex = 2;
			this.CloseButton.TabStop = false;
			this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
			this.CloseButton.MouseEnter += new System.EventHandler(this.CloseButton_MouseEnter);
			this.CloseButton.MouseLeave += new System.EventHandler(this.CloseButton_MouseLeave);
			// 
			// PointsLabel
			// 
			this.PointsLabel.AutoSize = true;
			this.PointsLabel.BackColor = System.Drawing.Color.Transparent;
			this.PointsLabel.Font = new System.Drawing.Font("Segoe UI Black", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.PointsLabel.ForeColor = System.Drawing.Color.Transparent;
			this.PointsLabel.Location = new System.Drawing.Point(197, 12);
			this.PointsLabel.Name = "PointsLabel";
			this.PointsLabel.Size = new System.Drawing.Size(93, 25);
			this.PointsLabel.TabIndex = 4;
			this.PointsLabel.Text = "Points: 0";
			this.PointsLabel.DoubleClick += new System.EventHandler(this.PointsLabel_DoubleClick);
			this.PointsLabel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			// 
			// NameLabel
			// 
			this.NameLabel.AutoSize = true;
			this.NameLabel.BackColor = System.Drawing.Color.Transparent;
			this.NameLabel.Font = new System.Drawing.Font("Segoe UI Black", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.NameLabel.ForeColor = System.Drawing.Color.Transparent;
			this.NameLabel.Location = new System.Drawing.Point(12, 12);
			this.NameLabel.Name = "NameLabel";
			this.NameLabel.Size = new System.Drawing.Size(150, 25);
			this.NameLabel.TabIndex = 5;
			this.NameLabel.Text = "Player: Player1";
			// 
			// ObjectiveLabel
			// 
			this.ObjectiveLabel.AutoSize = true;
			this.ObjectiveLabel.BackColor = System.Drawing.Color.Transparent;
			this.ObjectiveLabel.Font = new System.Drawing.Font("Segoe UI Black", 12F, System.Drawing.FontStyle.Bold);
			this.ObjectiveLabel.ForeColor = System.Drawing.Color.Transparent;
			this.ObjectiveLabel.Location = new System.Drawing.Point(12, 593);
			this.ObjectiveLabel.Name = "ObjectiveLabel";
			this.ObjectiveLabel.Size = new System.Drawing.Size(89, 21);
			this.ObjectiveLabel.TabIndex = 6;
			this.ObjectiveLabel.Text = "Objective:";
			// 
			// MovesLabel
			// 
			this.MovesLabel.AutoSize = true;
			this.MovesLabel.BackColor = System.Drawing.Color.Transparent;
			this.MovesLabel.Font = new System.Drawing.Font("Segoe UI Black", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.MovesLabel.ForeColor = System.Drawing.Color.Transparent;
			this.MovesLabel.Location = new System.Drawing.Point(372, 12);
			this.MovesLabel.Name = "MovesLabel";
			this.MovesLabel.Size = new System.Drawing.Size(107, 25);
			this.MovesLabel.TabIndex = 7;
			this.MovesLabel.Text = "Moves: 25";
			// 
			// GameForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackgroundImage = global::CandyCrushApplication.Properties.Resources.GameBackground;
			this.ClientSize = new System.Drawing.Size(593, 623);
			this.Controls.Add(this.MovesLabel);
			this.Controls.Add(this.ObjectiveLabel);
			this.Controls.Add(this.NameLabel);
			this.Controls.Add(this.PointsLabel);
			this.Controls.Add(this.CloseButton);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "GameForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.VisibleChanged += new System.EventHandler(this.GameForm_VisibleChanged);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EventWindowDrag);
			((System.ComponentModel.ISupportInitialize)(this.CloseButton)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox CloseButton;
		private System.Windows.Forms.Label PointsLabel;
		private System.Windows.Forms.Label NameLabel;
		private System.Windows.Forms.Label ObjectiveLabel;
		private System.Windows.Forms.Label MovesLabel;
	}
}