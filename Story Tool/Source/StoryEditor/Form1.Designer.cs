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
            this.OpenEditor = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.OpenGenerator = new System.Windows.Forms.Button();
            this.OpenTextAdventure = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // OpenEditor
            // 
            this.OpenEditor.Location = new System.Drawing.Point(12, 48);
            this.OpenEditor.Name = "OpenEditor";
            this.OpenEditor.Size = new System.Drawing.Size(206, 37);
            this.OpenEditor.TabIndex = 0;
            this.OpenEditor.Text = "Open Story Editor";
            this.OpenEditor.UseVisualStyleBackColor = true;
            this.OpenEditor.Click += new System.EventHandler(this.OpenEditor_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(206, 25);
            this.label1.TabIndex = 2;
            this.label1.Text = "Text Adventure Maker";
            // 
            // OpenGenerator
            // 
            this.OpenGenerator.Location = new System.Drawing.Point(12, 91);
            this.OpenGenerator.Name = "OpenGenerator";
            this.OpenGenerator.Size = new System.Drawing.Size(206, 37);
            this.OpenGenerator.TabIndex = 3;
            this.OpenGenerator.Text = "Compile Story";
            this.OpenGenerator.UseVisualStyleBackColor = true;
            this.OpenGenerator.Click += new System.EventHandler(this.OpenGenerator_Click);
            // 
            // OpenTextAdventure
            // 
            this.OpenTextAdventure.Location = new System.Drawing.Point(12, 134);
            this.OpenTextAdventure.Name = "OpenTextAdventure";
            this.OpenTextAdventure.Size = new System.Drawing.Size(206, 37);
            this.OpenTextAdventure.TabIndex = 4;
            this.OpenTextAdventure.Text = "Play Game";
            this.OpenTextAdventure.UseVisualStyleBackColor = true;
            this.OpenTextAdventure.Click += new System.EventHandler(this.OpenTextAdventure_Click);
            // 
            // TextAdventureMaker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(231, 181);
            this.Controls.Add(this.OpenTextAdventure);
            this.Controls.Add(this.OpenGenerator);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.OpenEditor);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "TextAdventureMaker";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Text Adventure Maker";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button OpenEditor;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button OpenGenerator;
        private System.Windows.Forms.Button OpenTextAdventure;
    }
}

