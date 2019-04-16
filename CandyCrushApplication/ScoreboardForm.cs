using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CandyCrushApplication {
	public partial class ScoreboardForm : Form {
		public ScoreboardForm() {
			InitializeComponent();
		}

		private void CloseButton_Click(object sender, EventArgs e) {
			this.Hide();
			Program.mainMenuForm.Show();
		}

		private void CloseButton_MouseEnter(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Red;
		}

		private void CloseButton_MouseLeave(object sender, EventArgs e) {
			this.CloseButton.BackColor = Color.Transparent;
		}

		private void ListBox1_VisibleChanged(object sender, EventArgs e) {
			if (this.Visible) {

			};
		}
	}
}
