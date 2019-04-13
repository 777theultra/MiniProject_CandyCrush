using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

namespace CandyCrushApplication {
	public struct PlayerData {
		public string Name;
		public int Points;
		public string SaveFile;
	}
	
	static class Program {
		public static PlayerData Player;
		public static DirectoryInfo UserDataFolder = Directory.CreateDirectory("UserData");
		public static Form mainMenuForm, gameForm;

		[DllImport("CandyCrushSega.dll", EntryPoint = "Initialize", CallingConvention = CallingConvention.StdCall)]
		public static extern void CandyCrushInitialize();
		[DllImport("CandyCrushSega.dll", EntryPoint = "Restart", CallingConvention = CallingConvention.StdCall)]
		public static extern void CandyCrushRestart();
		[DllImport("CandyCrushSega.dll", EntryPoint = "DebugBoard", CallingConvention = CallingConvention.StdCall)]
		public static extern void CandyCrushDebugBoard();

		[STAThread]
		static void Main() {
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);

			mainMenuForm = new CandyCrushWindow();
            CandyCrushInitialize();
            gameForm = new GameForm();
            Application.Run(mainMenuForm);

		}
	}
}
