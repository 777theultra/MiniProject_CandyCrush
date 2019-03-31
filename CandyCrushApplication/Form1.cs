﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace CandyCrushApplication {
	public partial class CandyCrushWindow : Form {
		[DllImport("Gdi32.dll", EntryPoint = "CreateRoundRectRgn")]
		private static extern IntPtr CreateRoundRectRgn(int left, int top, int right, int bottom, int width, int height);

		[DllImportAttribute("user32.dll")]
		public static extern int SendMessage(IntPtr win, int msg, int w, int l);
		[DllImportAttribute("user32.dll")]
		public static extern bool ReleaseCapture();

		public CandyCrushWindow() {
			InitializeComponent();
			this.TransparencyKey = this.BackColor;
			//Region = System.Drawing.Region.FromHrgn(CreateRoundRectRgn(0, 0, this.panel1.Width, this.panel1.Height, 16, 16));
		}

		private void EventWindowDrag(object sender, MouseEventArgs e) {
			if (e.Button == MouseButtons.Left) {
				ReleaseCapture();
				SendMessage(Handle, 0xA1, 0x2, 0);
			}
		}

		private void PictureBox2_Click(object sender, EventArgs e) {
			Application.Exit();
		}

		private void PictureBox2_MouseEnter(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Red;
		}

		private void PictureBox2_MouseLeave(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Transparent;
		}
	}
}