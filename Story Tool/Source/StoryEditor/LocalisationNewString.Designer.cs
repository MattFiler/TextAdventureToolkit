namespace StoryEditor
{
    partial class LocalisationNewString
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
            this.LocalisedString = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.LanguageSelect = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.SaveAll = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.StringID = new System.Windows.Forms.TextBox();
            this.ApplyToAll = new System.Windows.Forms.Button();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // LocalisedString
            // 
            this.LocalisedString.Font = new System.Drawing.Font("VCR OSD Mono", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LocalisedString.Location = new System.Drawing.Point(6, 19);
            this.LocalisedString.Multiline = true;
            this.LocalisedString.Name = "LocalisedString";
            this.LocalisedString.Size = new System.Drawing.Size(673, 248);
            this.LocalisedString.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.LanguageSelect);
            this.groupBox2.Location = new System.Drawing.Point(12, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 47);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Language";
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
            this.groupBox1.Controls.Add(this.LocalisedString);
            this.groupBox1.Location = new System.Drawing.Point(12, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(684, 274);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Localised String";
            // 
            // SaveAll
            // 
            this.SaveAll.Location = new System.Drawing.Point(557, 345);
            this.SaveAll.Name = "SaveAll";
            this.SaveAll.Size = new System.Drawing.Size(139, 31);
            this.SaveAll.TabIndex = 6;
            this.SaveAll.Text = "Save and Close";
            this.SaveAll.UseVisualStyleBackColor = true;
            this.SaveAll.Click += new System.EventHandler(this.SaveAll_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.StringID);
            this.groupBox3.Location = new System.Drawing.Point(218, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(200, 47);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "String Unique ID";
            // 
            // StringID
            // 
            this.StringID.Location = new System.Drawing.Point(6, 19);
            this.StringID.Name = "StringID";
            this.StringID.ReadOnly = true;
            this.StringID.Size = new System.Drawing.Size(188, 20);
            this.StringID.TabIndex = 0;
            // 
            // ApplyToAll
            // 
            this.ApplyToAll.Location = new System.Drawing.Point(12, 345);
            this.ApplyToAll.Name = "ApplyToAll";
            this.ApplyToAll.Size = new System.Drawing.Size(139, 31);
            this.ApplyToAll.TabIndex = 7;
            this.ApplyToAll.Text = "Apply Current To All";
            this.ApplyToAll.UseVisualStyleBackColor = true;
            this.ApplyToAll.Click += new System.EventHandler(this.ApplyToAll_Click);
            // 
            // LocalisationNewString
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(705, 384);
            this.Controls.Add(this.ApplyToAll);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.SaveAll);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "LocalisationNewString";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Localisation Editor";
            this.Load += new System.EventHandler(this.LocalisationNewString_Load);
            this.groupBox2.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox LocalisedString;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ComboBox LanguageSelect;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button SaveAll;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox StringID;
        private System.Windows.Forms.Button ApplyToAll;
    }
}