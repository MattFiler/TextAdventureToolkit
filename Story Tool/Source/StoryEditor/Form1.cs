using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace StoryEditor
{
    public partial class TextAdventureMaker : Form
    {
        public TextAdventureMaker()
        {
            InitializeComponent();
        }

        private void OpenEditor_Click(object sender, EventArgs e)
        {
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + "elements/Brainiac.exe"))
            {
                ProcessStartInfo process = new ProcessStartInfo();
                process.WorkingDirectory = AppDomain.CurrentDomain.BaseDirectory + "elements";
                process.FileName = "Brainiac.exe";
                Process myProcess = Process.Start(process);
            }
            else
            {
                MessageBox.Show("Cannot find editor! Please check your install.");
            }
        }

        private void OpenGenerator_Click(object sender, EventArgs e)
        {
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + "elements/StoryGenerator.exe"))
            {
                ProcessStartInfo process = new ProcessStartInfo();
                process.WorkingDirectory = AppDomain.CurrentDomain.BaseDirectory + "elements";
                process.FileName = "StoryGenerator.exe";
                Process myProcess = Process.Start(process);
            }
            else
            {
                MessageBox.Show("Cannot find compiler! Please check your install.");
            }
        }

        private void OpenTextAdventure_Click(object sender, EventArgs e)
        {
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + "TextAdventureGame.exe"))
            {
                Process myProcess = Process.Start(AppDomain.CurrentDomain.BaseDirectory+"TextAdventureGame.exe");
            }
            else
            {
                MessageBox.Show("Cannot find game! Please check your install.");
            }
        }
    }
}
