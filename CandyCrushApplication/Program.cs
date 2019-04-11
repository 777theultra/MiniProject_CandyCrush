using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CandyCrushApplication {
	static class Program {
		public static Form mainMenuForm, gameForm;

		[STAThread]
		static void Main() {
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			mainMenuForm = new CandyCrushWindow();
			gameForm = new GameForm();
			Application.Run(mainMenuForm);
		}
	}
}
