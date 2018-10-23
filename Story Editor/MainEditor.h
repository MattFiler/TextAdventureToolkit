#pragma once

namespace StoryEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainEditor
	/// </summary>
	public ref class MainEditor : public System::Windows::Forms::Form
	{
	public:
		MainEditor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::Button^  button1;











	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::ListBox^  listBox5;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::ListBox^  listBox6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox9;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::CheckBox^  checkBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(9, 39);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(190, 108);
			this->listBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Level";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(223, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 31);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Zone";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(444, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 31);
			this->label3->TabIndex = 5;
			this->label3->Text = L"State";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(665, 2);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 31);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Input";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 31);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Basic Info";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(11, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(188, 20);
			this->textBox1->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Game Title";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 75);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Game Developer";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(11, 91);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(188, 20);
			this->textBox2->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 200);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Disabled Input Text";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(10, 216);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(188, 20);
			this->textBox3->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 161);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(116, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Invalid Input Response";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(10, 177);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(188, 20);
			this->textBox4->TabIndex = 13;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(3, 128);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 31);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Outputs";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(222, 4);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(152, 31);
			this->label12->TabIndex = 20;
			this->label12->Text = L"Commands";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(229, 39);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(190, 108);
			this->listBox2->TabIndex = 22;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(450, 39);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(190, 108);
			this->listBox3->TabIndex = 23;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(671, 39);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(190, 108);
			this->listBox4->TabIndex = 24;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(765, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 83);
			this->button1->TabIndex = 25;
			this->button1->Text = L"LOAD STORY";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(777, 153);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(84, 29);
			this->button13->TabIndex = 37;
			this->button13->Text = L"-";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(671, 153);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(84, 29);
			this->button14->TabIndex = 36;
			this->button14->Text = L"+";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(556, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 29);
			this->button3->TabIndex = 42;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(450, 153);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(84, 29);
			this->button4->TabIndex = 41;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(335, 153);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(84, 29);
			this->button5->TabIndex = 44;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(229, 153);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(84, 29);
			this->button6->TabIndex = 43;
			this->button6->Text = L"+";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(115, 153);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(84, 29);
			this->button7->TabIndex = 46;
			this->button7->Text = L"-";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(9, 153);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(84, 29);
			this->button8->TabIndex = 45;
			this->button8->Text = L"+";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(9, 191);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(64, 13);
			this->label13->TabIndex = 48;
			this->label13->Text = L"Level Name";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(11, 207);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(188, 20);
			this->textBox6->TabIndex = 47;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(227, 191);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(63, 13);
			this->label14->TabIndex = 50;
			this->label14->Text = L"Zone Name";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(229, 207);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(188, 20);
			this->textBox7->TabIndex = 49;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(450, 190);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(63, 13);
			this->label15->TabIndex = 52;
			this->label15->Text = L"State Name";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(452, 207);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(188, 20);
			this->textBox8->TabIndex = 51;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(669, 191);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(81, 13);
			this->label16->TabIndex = 54;
			this->label16->Text = L"Input Command";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(671, 207);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(187, 21);
			this->comboBox1->TabIndex = 55;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(669, 231);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(70, 13);
			this->label17->TabIndex = 56;
			this->label17->Text = L"Input Subject";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(671, 247);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(188, 20);
			this->textBox9->TabIndex = 58;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(450, 230);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(52, 13);
			this->label18->TabIndex = 60;
			this->label18->Text = L"Intro Text";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(452, 247);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(188, 20);
			this->textBox10->TabIndex = 59;
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Location = System::Drawing::Point(229, 52);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(190, 186);
			this->listBox5->TabIndex = 61;
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(425, 52);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(44, 59);
			this->button9->TabIndex = 62;
			this->button9->Text = L"+";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(425, 179);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(44, 59);
			this->button10->TabIndex = 63;
			this->button10->Text = L"-";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(691, 179);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(44, 59);
			this->button11->TabIndex = 67;
			this->button11->Text = L"-";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(691, 52);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(44, 59);
			this->button12->TabIndex = 66;
			this->button12->Text = L"+";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->Location = System::Drawing::Point(495, 52);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(190, 186);
			this->listBox6->TabIndex = 65;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(487, 4);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(152, 31);
			this->label10->TabIndex = 64;
			this->label10->Text = L"Game Data";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(226, 35);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(111, 13);
			this->label19->TabIndex = 68;
			this->label19->Text = L"User Input Commands";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(492, 35);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(173, 13);
			this->label20->TabIndex = 69;
			this->label20->Text = L"Item and Event Strings for Scripting";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(765, 153);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(96, 83);
			this->button15->TabIndex = 70;
			this->button15->Text = L"SAVE STORY";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label23);
			this->panel1->Controls->Add(this->label22);
			this->panel1->Controls->Add(this->label21);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->listBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->listBox2);
			this->panel1->Controls->Add(this->listBox3);
			this->panel1->Controls->Add(this->listBox4);
			this->panel1->Controls->Add(this->button14);
			this->panel1->Controls->Add(this->button13);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->textBox10);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->textBox9);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->textBox8);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Location = System::Drawing::Point(12, 264);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(871, 276);
			this->panel1->TabIndex = 71;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(205, 85);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(19, 13);
			this->label21->TabIndex = 61;
			this->label21->Text = L"-->";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(425, 85);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(19, 13);
			this->label22->TabIndex = 62;
			this->label22->Text = L"-->";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(646, 85);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(19, 13);
			this->label23->TabIndex = 63;
			this->label23->Text = L"-->";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->button15);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->button11);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->button12);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->listBox6);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->button10);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->button9);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->listBox5);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(12, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(870, 246);
			this->panel2->TabIndex = 72;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->checkBox1);
			this->panel3->Controls->Add(this->label33);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->comboBox7);
			this->panel3->Controls->Add(this->comboBox9);
			this->panel3->Controls->Add(this->label38);
			this->panel3->Controls->Add(this->comboBox8);
			this->panel3->Controls->Add(this->label37);
			this->panel3->Controls->Add(this->label32);
			this->panel3->Controls->Add(this->textBox12);
			this->panel3->Controls->Add(this->label31);
			this->panel3->Controls->Add(this->textBox11);
			this->panel3->Controls->Add(this->label34);
			this->panel3->Controls->Add(this->label36);
			this->panel3->Controls->Add(this->label30);
			this->panel3->Controls->Add(this->label29);
			this->panel3->Controls->Add(this->label28);
			this->panel3->Controls->Add(this->textBox5);
			this->panel3->Controls->Add(this->comboBox6);
			this->panel3->Controls->Add(this->comboBox4);
			this->panel3->Controls->Add(this->label25);
			this->panel3->Controls->Add(this->comboBox5);
			this->panel3->Controls->Add(this->label26);
			this->panel3->Controls->Add(this->comboBox3);
			this->panel3->Controls->Add(this->label24);
			this->panel3->Controls->Add(this->comboBox2);
			this->panel3->Controls->Add(this->label27);
			this->panel3->Controls->Add(this->label35);
			this->panel3->Location = System::Drawing::Point(12, 546);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(871, 356);
			this->panel3->TabIndex = 72;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(3, 4);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(152, 31);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Game Data";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(8, 39);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(103, 13);
			this->label35->TabIndex = 48;
			this->label35->Text = L"Optional Game Data";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(10, 55);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(248, 21);
			this->comboBox2->TabIndex = 64;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(10, 95);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(248, 21);
			this->comboBox3->TabIndex = 66;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(8, 79);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(107, 13);
			this->label24->TabIndex = 65;
			this->label24->Text = L"Required Game Data";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(265, 95);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(248, 21);
			this->comboBox4->TabIndex = 70;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(263, 80);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(104, 13);
			this->label25->TabIndex = 69;
			this->label25->Text = L"Remove Game Data";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(265, 55);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(248, 21);
			this->comboBox5->TabIndex = 68;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(263, 39);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(83, 13);
			this->label26->TabIndex = 67;
			this->label26->Text = L"Add Game Data";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(612, 55);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(248, 21);
			this->comboBox6->TabIndex = 71;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(612, 96);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(247, 20);
			this->textBox5->TabIndex = 64;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(610, 38);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(111, 13);
			this->label28->TabIndex = 72;
			this->label28->Text = L"Input Script Command";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(610, 79);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(100, 13);
			this->label29->TabIndex = 73;
			this->label29->Text = L"Input Script Subject";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(605, 3);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(155, 31);
			this->label30->TabIndex = 74;
			this->label30->Text = L"Referenced";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(5, 135);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(110, 31);
			this->label34->TabIndex = 75;
			this->label34->Text = L"Outputs";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(10, 170);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(73, 13);
			this->label36->TabIndex = 76;
			this->label36->Text = L"OK Response";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(11, 187);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(408, 75);
			this->textBox11->TabIndex = 84;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(450, 187);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(408, 75);
			this->textBox12->TabIndex = 86;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(449, 170);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(83, 13);
			this->label31->TabIndex = 85;
			this->label31->Text = L"Issue Response";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(3, 279);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(119, 31);
			this->label32->TabIndex = 87;
			this->label32->Text = L"Move To";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Location = System::Drawing::Point(10, 328);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(248, 21);
			this->comboBox7->TabIndex = 89;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(8, 311);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(58, 13);
			this->label33->TabIndex = 88;
			this->label33->Text = L"New Level";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Location = System::Drawing::Point(265, 328);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(248, 21);
			this->comboBox8->TabIndex = 91;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(262, 312);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(57, 13);
			this->label37->TabIndex = 90;
			this->label37->Text = L"New Zone";
			// 
			// comboBox9
			// 
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Location = System::Drawing::Point(519, 328);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(248, 21);
			this->comboBox9->TabIndex = 93;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(516, 312);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(57, 13);
			this->label38->TabIndex = 92;
			this->label38->Text = L"New State";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(792, 282);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(68, 67);
			this->button2->TabIndex = 64;
			this->button2->Text = L"SAVE";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(774, 17);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(93, 17);
			this->checkBox1->TabIndex = 94;
			this->checkBox1->Text = L"Is Referenced";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// MainEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 913);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainEditor";
			this->Text = L"MainEditor";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
