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
using System.Threading;

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

		public void SavePlayerData() {
			using (StreamWriter writer = new StreamWriter(Program.Player.SaveFile)) {
				writer.WriteLine(Program.Player.Name);
				writer.WriteLine(Program.Player.Points);
				writer.WriteLine(Program.Player.SaveFile);
			}
		}

		private void PlayButton_Click(object sender, EventArgs e) {
			Control control = (Control)sender;
			if (this.NameInput.Text.Length <= 0) {
				MessageBox.Show("Please input a valid name.", "Oops!");

			} else {
				Program.CandyCrushRestart();

				Program.Player.Level = (control.Name == "PlayButton") ? 1 : (control.Name == "PlayButton2") ? 2 : 3;

				DirectoryInfo LevelSaves = Directory.CreateDirectory(Program.UserDataFolder.Name + "/" + "Level" + Program.Player.Level);

				string playerName = this.NameInput.Text;
				string saveDataPath = Program.UserDataFolder.Name + "/" + LevelSaves.Name + "/" + playerName + ".txt";

				Program.Player.SaveFile = saveDataPath;
				if (File.Exists(saveDataPath)) {
					using (StreamReader reader = new StreamReader(saveDataPath)) {
						Program.Player.Name = reader.ReadLine();
						Program.Player.Points = Convert.ToInt32(reader.ReadLine());
					}
					MessageBox.Show("Welcome, " + Program.Player.Name + ". You best score was " + Program.Player.Points + " points.", "Welcome back!");
					Program.Player.Points = 0;
				} else {
					Program.Player.Name = playerName;
					Program.Player.Points = 0;
					SavePlayerData();
				}
				this.Hide();
				Program.gameForm.Show();
				Program.gameForm.SetMoves(25);
			}
			this.NameInput.Text = "";
		}
	}
}
