namespace StoryEditor
{
    partial class LocalisationEditor
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
            this.LanguageSelect = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.StringIdentifierList = new System.Windows.Forms.ListBox();
            this.StringList = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.EditString = new System.Windows.Forms.Button();
            this.RemoveString = new System.Windows.Forms.Button();
            this.AddString = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // LanguageSelect
            // 
            this.LanguageSelect.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.LanguageSelect.FormattingEnabled = true;
            this.LanguageSelect.Location = new System.Drawing.Point(6, 19);
            this.LanguageSelect.Name = "LanguageSelect";
            this.LanguageSelect.Size = new System.Drawing.Size(187, 21);
            this.LanguageSelect.TabIndex = 1;
            this.LanguageSelect.SelectedIndexChanged += new System.EventHandler(this.LanguageSelect_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.StringIdentifierList);
            this.groupBox1.Controls.Add(this.StringList);
            this.groupBox1.Location = new System.Drawing.Point(12, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(761, 264);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Game Strings";
            // 
            // StringIdentifierList
            // 
            this.StringIdentifierList.FormattingEnabled = true;
            this.StringIdentifierList.Location = new System.Drawing.Point(6, 19);
            this.StringIdentifierList.Name = "StringIdentifierList";
            this.StringIdentifierList.Size = new System.Drawing.Size(163, 238);
            this.StringIdentifierList.TabIndex = 5;
            this.StringIdentifierList.SelectedIndexChanged += new System.EventHandler(this.StringIdentifierList_SelectedIndexChanged);
            // 
            // StringList
            // 
            this.StringList.FormattingEnabled = true;
            this.StringList.Location = new System.Drawing.Point(175, 19);
            this.StringList.Name = "StringList";
            this.StringList.Size = new System.Drawing.Size(580, 238);
            this.StringList.TabIndex = 4;
            this.StringList.SelectedIndexChanged += new System.EventHandler(this.StringList_SelectedIndexChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.LanguageSelect);
            this.groupBox2.Location = new System.Drawing.Point(12, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 47);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Game Language";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.EditString);
            this.groupBox3.Controls.Add(this.RemoveString);
            this.groupBox3.Controls.Add(this.AddString);
            this.groupBox3.Location = new System.Drawing.Point(218, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(555, 47);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Manage Strings";
            // 
            // EditString
            // 
            this.EditString.Location = new System.Drawing.Point(189, 19);
            this.EditString.Name = "EditString";
            this.EditString.Size = new System.Drawing.Size(177, 21);
            this.EditString.TabIndex = 2;
            this.EditString.Text = "Edit Selected String";
            this.EditString.UseVisualStyleBackColor = true;
            this.EditString.Click += new System.EventHandler(this.EditString_Click);
            // 
            // RemoveString
            // 
            this.RemoveString.Location = new System.Drawing.Point(372, 19);
            this.RemoveString.Name = "RemoveString";
            this.RemoveString.Size = new System.Drawing.Size(177, 21);
            this.RemoveString.TabIndex = 1;
            this.RemoveString.Text = "Remove Selected String";
            this.RemoveString.UseVisualStyleBackColor = true;
            this.RemoveString.Click += new System.EventHandler(this.RemoveString_Click);
            // 
            // AddString
            // 
            this.AddString.Location = new System.Drawing.Point(6, 19);
            this.AddString.Name = "AddString";
            this.AddString.Size = new System.Drawing.Size(177, 21);
            this.AddString.TabIndex = 0;
            this.AddString.Text = "Add New String";
            this.AddString.UseVisualStyleBackColor = true;
            this.AddString.Click += new System.EventHandler(this.AddString_Click);
            // 
            // LocalisationEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 340);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "LocalisationEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Text Adventure Localisation Editor";
            this.Load += new System.EventHandler(this.LocalisationEditor_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ComboBox LanguageSelect;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ListBox StringList;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button EditString;
        private System.Windows.Forms.Button RemoveString;
        private System.Windows.Forms.Button AddString;
        private System.Windows.Forms.ListBox StringIdentifierList;
    }
}