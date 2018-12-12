namespace StoryEditor
{
    partial class TextAdventureMaker
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TextAdventureMaker));
            this.OpenEditor = new System.Windows.Forms.Button();
            this.OpenGenerator = new System.Windows.Forms.Button();
            this.OpenTextAdventure = new System.Windows.Forms.Button();
            this.CreateNewGame = new System.Windows.Forms.Button();
            this.ExistingGames = new System.Windows.Forms.ComboBox();
            this.DeleteSelectedGame = new System.Windows.Forms.Button();
            this.SaveGameToShare = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.OpenLocalisationEditor = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.CompileLanguage = new System.Windows.Forms.ComboBox();
            this.ExportVersionSelector = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // OpenEditor
            // 
            this.OpenEditor.Location = new System.Drawing.Point(6, 19);
            this.OpenEditor.Name = "OpenEditor";
            this.OpenEditor.Size = new System.Drawing.Size(193, 30);
            this.OpenEditor.TabIndex = 0;
            this.OpenEditor.Text = "Edit Logic";
            this.OpenEditor.UseVisualStyleBackColor = true;
            this.OpenEditor.Click += new System.EventHandler(this.OpenEditor_Click);
            // 
            // OpenGenerator
            // 
            this.OpenGenerator.Location = new System.Drawing.Point(6, 46);
            this.OpenGenerator.Name = "OpenGenerator";
            this.OpenGenerator.Size = new System.Drawing.Size(193, 30);
            this.OpenGenerator.TabIndex = 3;
            this.OpenGenerator.Text = "Compile";
            this.OpenGenerator.UseVisualStyleBackColor = true;
            this.OpenGenerator.Click += new System.EventHandler(this.OpenGenerator_Click);
            // 
            // OpenTextAdventure
            // 
            this.OpenTextAdventure.Location = new System.Drawing.Point(6, 46);
            this.OpenTextAdventure.Name = "OpenTextAdventure";
            this.OpenTextAdventure.Size = new System.Drawing.Size(194, 30);
            this.OpenTextAdventure.TabIndex = 4;
            this.OpenTextAdventure.Text = "Play";
            this.OpenTextAdventure.UseVisualStyleBackColor = true;
            this.OpenTextAdventure.Click += new System.EventHandler(this.OpenTextAdventure_Click);
            // 
            // CreateNewGame
            // 
            this.CreateNewGame.Location = new System.Drawing.Point(89, 13);
            this.CreateNewGame.Name = "CreateNewGame";
            this.CreateNewGame.Size = new System.Drawing.Size(52, 21);
            this.CreateNewGame.TabIndex = 5;
            this.CreateNewGame.Text = "New";
            this.CreateNewGame.UseVisualStyleBackColor = true;
            this.CreateNewGame.Click += new System.EventHandler(this.CreateNewGame_Click);
            // 
            // ExistingGames
            // 
            this.ExistingGames.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ExistingGames.FormattingEnabled = true;
            this.ExistingGames.Location = new System.Drawing.Point(6, 37);
            this.ExistingGames.Name = "ExistingGames";
            this.ExistingGames.Size = new System.Drawing.Size(193, 21);
            this.ExistingGames.TabIndex = 6;
            // 
            // DeleteSelectedGame
            // 
            this.DeleteSelectedGame.Location = new System.Drawing.Point(147, 13);
            this.DeleteSelectedGame.Name = "DeleteSelectedGame";
            this.DeleteSelectedGame.Size = new System.Drawing.Size(52, 21);
            this.DeleteSelectedGame.TabIndex = 8;
            this.DeleteSelectedGame.Text = "Delete";
            this.DeleteSelectedGame.UseVisualStyleBackColor = true;
            this.DeleteSelectedGame.Click += new System.EventHandler(this.DeleteSelectedGame_Click);
            // 
            // SaveGameToShare
            // 
            this.SaveGameToShare.Location = new System.Drawing.Point(6, 82);
            this.SaveGameToShare.Name = "SaveGameToShare";
            this.SaveGameToShare.Size = new System.Drawing.Size(194, 30);
            this.SaveGameToShare.TabIndex = 10;
            this.SaveGameToShare.Text = "Export";
            this.SaveGameToShare.UseVisualStyleBackColor = true;
            this.SaveGameToShare.Click += new System.EventHandler(this.SaveGameToShare_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ExistingGames);
            this.groupBox1.Controls.Add(this.CreateNewGame);
            this.groupBox1.Controls.Add(this.DeleteSelectedGame);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(205, 67);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Game";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.OpenLocalisationEditor);
            this.groupBox2.Controls.Add(this.OpenEditor);
            this.groupBox2.Location = new System.Drawing.Point(12, 85);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(205, 92);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Edit Selected Game";
            // 
            // OpenLocalisationEditor
            // 
            this.OpenLocalisationEditor.Location = new System.Drawing.Point(6, 55);
            this.OpenLocalisationEditor.Name = "OpenLocalisationEditor";
            this.OpenLocalisationEditor.Size = new System.Drawing.Size(193, 30);
            this.OpenLocalisationEditor.TabIndex = 4;
            this.OpenLocalisationEditor.Text = "Edit Localisation";
            this.OpenLocalisationEditor.UseVisualStyleBackColor = true;
            this.OpenLocalisationEditor.Click += new System.EventHandler(this.OpenLocalisationEditor_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.ExportVersionSelector);
            this.groupBox3.Controls.Add(this.OpenTextAdventure);
            this.groupBox3.Controls.Add(this.SaveGameToShare);
            this.groupBox3.Location = new System.Drawing.Point(11, 271);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(206, 118);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Play/Export Selected Game";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.CompileLanguage);
            this.groupBox4.Controls.Add(this.OpenGenerator);
            this.groupBox4.Location = new System.Drawing.Point(12, 183);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(205, 82);
            this.groupBox4.TabIndex = 14;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Compile Selected Game";
            // 
            // CompileLanguage
            // 
            this.CompileLanguage.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CompileLanguage.FormattingEnabled = true;
            this.CompileLanguage.Location = new System.Drawing.Point(6, 19);
            this.CompileLanguage.Name = "CompileLanguage";
            this.CompileLanguage.Size = new System.Drawing.Size(193, 21);
            this.CompileLanguage.TabIndex = 4;
            // 
            // ExportVersionSelector
            // 
            this.ExportVersionSelector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ExportVersionSelector.FormattingEnabled = true;
            this.ExportVersionSelector.Items.AddRange(new object[] {
            "2D - ASGE",
            "2D - Unity",
            "3D - UE4"});
            this.ExportVersionSelector.Location = new System.Drawing.Point(7, 18);
            this.ExportVersionSelector.Name = "ExportVersionSelector";
            this.ExportVersionSelector.Size = new System.Drawing.Size(193, 21);
            this.ExportVersionSelector.TabIndex = 5;
            // 
            // TextAdventureMaker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(228, 397);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "TextAdventureMaker";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Text Adventure Creator";
            this.Load += new System.EventHandler(this.TextAdventureMaker_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button OpenEditor;
        private System.Windows.Forms.Button OpenGenerator;
        private System.Windows.Forms.Button OpenTextAdventure;
        private System.Windows.Forms.Button CreateNewGame;
        private System.Windows.Forms.ComboBox ExistingGames;
        private System.Windows.Forms.Button DeleteSelectedGame;
        private System.Windows.Forms.Button SaveGameToShare;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button OpenLocalisationEditor;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ComboBox CompileLanguage;
        private System.Windows.Forms.ComboBox ExportVersionSelector;
    }
}

