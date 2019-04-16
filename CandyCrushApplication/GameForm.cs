using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.IO;
using Timer = System.Windows.Forms.Timer;

namespace CandyCrushApplication {
	public partial class GameForm : Form {
		[DllImport("Gdi32.dll", EntryPoint = "CreateRoundRectRgn")]
		private static extern IntPtr CreateRoundRectRgn(int left, int top, int right, int bottom, int width, int height);
		[DllImportAttribute("user32.dll")]
		public static extern int SendMessage(IntPtr win, int msg, int w, int l);
		[DllImportAttribute("user32.dll")]
		public static extern bool ReleaseCapture();

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		public delegate void RenderCandyCrushPointer();
		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		public delegate void AwardPointsPointer(int points);
		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
		public delegate void ObjectiveCompletePointer(int id);

		[DllImport("CandyCrushSega.dll", EntryPoint = "ConnectRenderer", CallingConvention = CallingConvention.Cdecl)]
		public static extern void CandyCrushConnectRenderer(RenderCandyCrushPointer f);
		[DllImport("CandyCrushSega.dll", EntryPoint = "ConnectAwardPoints", CallingConvention = CallingConvention.Cdecl)]
		public static extern void CandyCrushConnectAwardPoints(AwardPointsPointer f);
		[DllImport("CandyCrushSega.dll", EntryPoint = "ConnectObjectiveComplete", CallingConvention = CallingConvention.Cdecl)]
		public static extern void CandyCrushConnectObjectiveComplete(ObjectiveCompletePointer f);
		[DllImport("CandyCrushSega.dll", EntryPoint = "GetCandy", CallingConvention = CallingConvention.Cdecl)]
		public static extern int CandyCrushGetCandy(int x, int y);
		[DllImport("CandyCrushSega.dll", EntryPoint = "CandyMove", CallingConvention = CallingConvention.Cdecl)]
		public static extern void CandyCrushCandyMove(int x, int y, int dir);

		//Objectives
		[DllImport("CandyCrushSega.dll", EntryPoint = "GetObjectiveBColor", CallingConvention = CallingConvention.Cdecl)]
		public static extern int CandyCrushGetObjectiveBColor();
		[DllImport("CandyCrushSega.dll", EntryPoint = "GetObjectiveBAmount", CallingConvention = CallingConvention.Cdecl)]
		public static extern int CandyCrushGetObjectiveBAmount();
		[DllImport("CandyCrushSega.dll", EntryPoint = "GetObjectiveDCombo", CallingConvention = CallingConvention.Cdecl)]
		public static extern int CandyCrushGetObjectiveDCombo();
		[DllImport("CandyCrushSega.dll", EntryPoint = "GetObjectiveDAmount", CallingConvention = CallingConvention.Cdecl)]
		public static extern int CandyCrushGetObjectiveDAmount();

		private static RenderCandyCrushPointer renderCandyCrushPointer;
		private static AwardPointsPointer gameAwardPoints;
		private static ObjectiveCompletePointer objectiveCompletePointer;
		private static PictureBox[,] candyGrid = new PictureBox[6, 6];
		private static bool IsSelected = false;
		private static Point selectionPoint;

		private static int MovesRemaining = 25;

		public void SetMoves(int moves) {
			MovesRemaining = moves;
		}

		public void RenderCandyCrush() {
			//Program.CandyCrushDebugBoard();
			NameLabel.Text = "Player: " + Program.Player.Name;
			PointsLabel.Text = "Points: " + Program.Player.Points;

			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 6; x++) {
					int CandyId = CandyCrushGetCandy(x, y);

					candyGrid[x, y].BackColor = Color.Transparent;
					switch (CandyId) {
						//Render Raw Candies;
						case 0:
							candyGrid[x, y].Image = Properties.Resources.Candy_Red;
							break;
						case 1:
							candyGrid[x, y].Image = Properties.Resources.Candy_Orange;
							break;
						case 2:
							candyGrid[x, y].Image = Properties.Resources.Candy_Yellow;
							break;
						case 3:
							candyGrid[x, y].Image = Properties.Resources.Candy_Green;
							break;
						case 4:
							candyGrid[x, y].Image = Properties.Resources.Candy_Blue;
							break;
						case 5:
							candyGrid[x, y].Image = Properties.Resources.Candy_Purple;
							break;

						//Render Stripped Candies;
						case 10:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialRed;
							break;
						case 11:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialOrange;
							break;
						case 12:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialYellow;
							break;
						case 13:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialGreen;
							break;
						case 14:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialBlue;
							break;
						case 15:
							candyGrid[x, y].Image = Properties.Resources.Candy_SpecialPurple;
							break;

						//Render Wrapped Candies;
						case 20:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedRed;
							break;
						case 21:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedOrange;
							break;
						case 22:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedYellow;
							break;
						case 23:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedGreen;
							break;
						case 24:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedBlue;
							break;
						case 25:
							candyGrid[x, y].Image = Properties.Resources.Candy_WrappedPurple;
							break;

						case 40:
							candyGrid[x, y].Image = Properties.Resources.Candy_Choco;
							break;
						case -1:
							candyGrid[x, y].Image = Properties.Resources.Candy_Dead;
							break;
					}
					candyGrid[x, y].Refresh();
				}
			}
			if (Program.Player.Level == 1) {
				int objectiveColor = CandyCrushGetObjectiveBColor();
				string color = "None";
				switch (objectiveColor) {
					case 0:
						color = "Red";
						break;
					case 1:
						color = "Orange";
						break;
					case 2:
						color = "Yellow";
						break;
					case 3:
						color = "Green";
						break;
					case 4:
						color = "Blue";
						break;
					case 5:
						color = "Purple";
						break;
				}
				ObjectiveLabel.Text = "Objective: Eliminate " + CandyCrushGetObjectiveBAmount() + " " + color + " candies with in " + MovesRemaining  + " moves.";
			} else if (Program.Player.Level == 2) {
				int objectiveCombo = CandyCrushGetObjectiveDCombo();
				string combo = "None";
				switch (objectiveCombo) {
					case 0:
						combo = "Stripped Candies";
						break;
					case 1:
						combo = "Wrapped Candies";
						break;
					case 2:
						combo = "Colour Bomb";
						break;
				}
				ObjectiveLabel.Text = "Objective: Make " + CandyCrushGetObjectiveDAmount() + " " + combo + " with in " + MovesRemaining + " moves.";
			}
			Thread.Sleep(200);
		}

		public void AwardPoints(int points) {
			Program.Player.Points += points;
		}

		public void ShowLeaderboard() {
			this.Hide();
			Program.scoreForm.Show();
		}

		public void ReturnToMenu() {
			this.Hide();
			Program.mainMenuForm.Show();
		}

		public void CompleteObjective(int id) {
			if (Program.Player.Level == id) {
				MessageBox.Show("You completed the objective. You won!", "Winner!");
				ReturnToMenu();
			}
		}

		public GameForm() {
			InitializeComponent();
			Region = System.Drawing.Region.FromHrgn(CreateRoundRectRgn(0, 0, Width, Height, 16, 16));

			renderCandyCrushPointer = new RenderCandyCrushPointer(RenderCandyCrush);
			CandyCrushConnectRenderer(renderCandyCrushPointer);

			gameAwardPoints = new AwardPointsPointer(AwardPoints);
			CandyCrushConnectAwardPoints(gameAwardPoints);

			objectiveCompletePointer = new ObjectiveCompletePointer(CompleteObjective);
			CandyCrushConnectObjectiveComplete(objectiveCompletePointer);

			const int candyDisplaySize = 85;

			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 6; x++) {
					PictureBox pictureBox = new PictureBox {
						Name = "pictureBox(" + x + "," + y + ")",
						Size = new Size(candyDisplaySize, candyDisplaySize),
						Location = new Point(Width / 2 - (candyDisplaySize * 6 / 2) + x * candyDisplaySize, Height / 2 - (candyDisplaySize * 6 / 2) + 10 + y * candyDisplaySize),
						Image = Properties.Resources.Candy_Red,
						BackColor = System.Drawing.Color.Transparent,
						SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage,
						Cursor = Cursors.Hand,
					};
					pictureBox.MouseDoubleClick += OnCandyDoubleClick;
					pictureBox.MouseClick += OnCandyClicked;
					this.Controls.Add(pictureBox);
					candyGrid[x, y] = pictureBox;
				}
			}

			RenderCandyCrush();
		}

		private Point GetCandyPoint(Control control) {
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 6; x++) {
					if (candyGrid[x, y] == control) {
						return new Point(x, y);
					}
				}
			}
			return new Point(-1, -1);
		}

		private void OnCandyClicked(object sender, MouseEventArgs e) {
			Control control = (Control)sender;
			if (IsSelected) {
				Point p = GetCandyPoint(control);
				if (p.X >= 0) {
					if (p.X == selectionPoint.X && p.Y == selectionPoint.Y) {
						control.BackColor = Color.Transparent;
						IsSelected = false;
					} else {
						int dir = (selectionPoint.Y - p.Y == 1 && selectionPoint.X == p.X) ? 1
							: (p.Y - selectionPoint.Y == 1 && selectionPoint.X == p.X) ? 2
							: (selectionPoint.X - p.X == 1 && selectionPoint.Y == p.Y) ? 3
							: (p.X - selectionPoint.X == 1 && selectionPoint.Y == p.Y) ? 4 : -1;
						if (dir != -1) {
							MovesRemaining--;
							MovesLabel.Text = "Moves: " + MovesRemaining;
							CandyCrushCandyMove(selectionPoint.X, selectionPoint.Y, dir);
							if (MovesRemaining <= 0) {
								MessageBox.Show("You are out of moves! Do you want to see the leaderboard? You lost!", "Loser!");
								ReturnToMenu();
							}
							IsSelected = false;
						} else {
							Console.WriteLine("Invalid movement point: " + control.Name);
						}
					}
				} else {
					Console.WriteLine("Invalid selection point: " + control.Name);
				}
			} else {
				control.BackColor = Color.LightYellow;
				Point p = GetCandyPoint(control);
				if (p.X >= 0) {
					selectionPoint.X = p.X;
					selectionPoint.Y = p.Y;
					IsSelected = true;
				} else {
					Console.WriteLine("Invalid selection point: " + control.Name);
				}
			}
		}

		private void OnCandyDoubleClick(object sender, MouseEventArgs e) {
			/*Control control = (Control) sender;
			if (Program.Player.Name == "Player1") {
				MessageBox.Show(control.Name.ToString(), "Debug");
			}*/
		}

		private void EventWindowDrag(object sender, MouseEventArgs e) {
			if (e.Button == MouseButtons.Left) {
				ReleaseCapture();
				SendMessage(Handle, 0xA1, 0x2, 0);
			}
		}

		private void CloseButton_Click(object sender, EventArgs e) {
			DialogResult dialogResult = MessageBox.Show("Are you sure you want to exit to main menu?", "Leaving so soon?", MessageBoxButtons.YesNo);
			if (dialogResult == DialogResult.Yes) {
				ReturnToMenu();
			}
		}

		private void CloseButton_MouseEnter(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Red;
		}

		private void CloseButton_MouseLeave(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Transparent;
		}

		private void GameForm_VisibleChanged(object sender, EventArgs e) {
			if (this.Visible) {
				RenderCandyCrush();
			}
		}

		private void PointsLabel_DoubleClick(object sender, EventArgs e) {
			RenderCandyCrush();
		}
	}
}
