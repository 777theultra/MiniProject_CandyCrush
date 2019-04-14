using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

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
			Region = System.Drawing.Region.FromHrgn(CreateRoundRectRgn(0, 0, Width, Height, 16, 16));
			this.Focus();
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

		private void CloseButton_MouseEnter(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Red;
		}

		private void CloseButton_MouseLeave(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Transparent;
		}

		private void PlayButton_Click(object sender, EventArgs e) {
			if (this.NameInput.Text.Length <= 0) {
				MessageBox.Show("Please input a valid name.", "Oops!");

			} else {
				Program.CandyCrushRestart();

				string playerName = this.NameInput.Text;
				string saveDataPath = Program.UserDataFolder.Name + "/" + playerName + ".txt";

				Program.Player.SaveFile = saveDataPath;
				if (File.Exists(saveDataPath)) {
					using (StreamReader reader = new StreamReader(saveDataPath)) {
						Program.Player.Name = reader.ReadLine();
						Program.Player.Points = Convert.ToInt32(reader.ReadLine());
					}
				} else {
					Program.Player.Name = playerName;
					Program.Player.Points = 0;
					using (StreamWriter writer = new StreamWriter(saveDataPath)) {
						writer.WriteLine(Program.Player.Name);
						writer.WriteLine(Program.Player.Points);
						writer.WriteLine(Program.Player.SaveFile);
					}
				}
				this.Hide();
				Program.gameForm.Show();
			}
			this.NameInput.Text = "";
		}
	}
}
