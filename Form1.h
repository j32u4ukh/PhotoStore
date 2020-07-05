#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Execute;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Label^ DebugLog;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ previous_button;
	private: System::Windows::Forms::Button^ next_button;
	
	private: System::String^ dir_path = "";
	private: array<String^>^ files;
	private: int index = 0;
	private: int n_file = 0;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge鄚dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Execute = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->DebugLog = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->previous_button = (gcnew System::Windows::Forms::Button());
			this->next_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Execute
			// 
			this->Execute->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Execute->Location = System::Drawing::Point(320, 564);
			this->Execute->Name = L"Execute";
			this->Execute->Size = System::Drawing::Size(188, 53);
			this->Execute->TabIndex = 0;
			this->Execute->Text = L"Execute";
			this->Execute->UseVisualStyleBackColor = true;
			this->Execute->Click += gcnew System::EventHandler(this, &Form1::Execute_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(41, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(691, 362);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// DebugLog
			// 
			this->DebugLog->AutoSize = true;
			this->DebugLog->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->DebugLog->Dock = System::Windows::Forms::DockStyle::Top;
			this->DebugLog->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DebugLog->Location = System::Drawing::Point(3, 0);
			this->DebugLog->Name = L"DebugLog";
			this->DebugLog->Size = System::Drawing::Size(685, 38);
			this->DebugLog->TabIndex = 1;
			this->DebugLog->Text = L"Log\r\n";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->DebugLog, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(41, 423);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(691, 122);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// previous_button
			// 
			this->previous_button->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->previous_button->Location = System::Drawing::Point(41, 564);
			this->previous_button->Name = L"previous_button";
			this->previous_button->Size = System::Drawing::Size(240, 53);
			this->previous_button->TabIndex = 4;
			this->previous_button->Text = L"<< Previous";
			this->previous_button->UseVisualStyleBackColor = true;
			this->previous_button->Click += gcnew System::EventHandler(this, &Form1::previous_button_Click);
			// 
			// next_button
			// 
			this->next_button->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next_button->Location = System::Drawing::Point(547, 564);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(185, 53);
			this->next_button->TabIndex = 5;
			this->next_button->Text = L"Next >>";
			this->next_button->UseVisualStyleBackColor = true;
			this->next_button->Click += gcnew System::EventHandler(this, &Form1::next_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 673);
			this->Controls->Add(this->next_button);
			this->Controls->Add(this->previous_button);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Execute);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ open_file_dialog = gcnew OpenFileDialog;

		// Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*
		// 設定Filter，用以限定使用者開啟的檔案
		open_file_dialog->Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";

		// 預設檔案名稱為空值
		open_file_dialog->FileName = "";

		// 設定跳出選擇視窗的標題名稱
		open_file_dialog->Title = "載入影像";

		// 設定 Filter 選擇模式(依照 Filter 數，如本例選擇 1 表示起始出現的為點陣圖，選擇 2 表示 All files)
		open_file_dialog->FilterIndex = 1;

		// D:/影音/圖片
		//open_file_dialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
		open_file_dialog->InitialDirectory = "D:\\影音\\圖片";

		if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			FileInfo^ file_info = gcnew FileInfo(open_file_dialog->FileName);

			dir_path = file_info->DirectoryName;

			// TODO: 篩選圖片類型的檔案，其他檔案(如: .doc)會造成 OutOfMemoryException
			files = Directory::GetFiles(dir_path);
			n_file = files->Length;

			DebugLog->Text += String::Format("dir_path: {0}\n", dir_path);
			showPicture(open_file_dialog->FileName);
		}		
	}

	private: void showPicture_() {
		// 宣告點陣圖的格式 
		// Ref 類別與結構 (C++/CX) 參考類型的宣告附加了 "^"。
		//Bitmap^ image;

		// new 一個新的 open_file_dialog 開啟檔案
		// 建立 .NET 物件時使用 gcnew 關鍵字而不是 new，而且 gcnew 會傳回控制代碼 (^) 而不是指標 (*)
		OpenFileDialog^ open_file_dialog = gcnew OpenFileDialog;

		// 設定Filter，用以限定使用者開啟的檔案
		open_file_dialog->Filter = "點陣圖 (*.bmp)| *.bmp| All files (*.*)| *.*";

		// 預設檔案名稱為空值
		open_file_dialog->FileName = "";

		// 設定跳出選擇視窗的標題名稱
		open_file_dialog->Title = "載入影像";

		// 設定Filter選擇模式(依照Filter數，如本例選擇1表示起始出現的為點陣圖，選擇2表示All files)
		open_file_dialog->FilterIndex = 1;

		// 跳出檔案選擇視窗(ShowDialog)，並且如果使用者點選檔案，並且檔案名稱超過0個字元，則判斷是為True，進入處理程序
		if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK && open_file_dialog->FileName->Length > 0)
		{
			
			// safe_cast<T> C風格轉換: 失敗時將丟擲 InvalidCastException 異常
			//image = safe_cast<Bitmap^>(Image::FromFile(open_file_dialog->FileName));			
			showPicture(open_file_dialog->FileName);
		}
	}

	// System::Void === void
	private: System::Void showPicture(System::String^ file_path) {
		// 將影像顯示在 pictureBox1
		pictureBox1->Image = Image::FromFile(file_path);
	}

	private: void showFolderPath() {
		FolderBrowserDialog^ folder_browser_dialog = gcnew FolderBrowserDialog();

		// Set the help text description for the FolderBrowserDialog.
		folder_browser_dialog->Description = "FolderBrowserDialog";

		// Do not allow the user to create new files via the FolderBrowserDialog.
		folder_browser_dialog->ShowNewFolderButton = false;

		// Default folder.
		folder_browser_dialog->RootFolder = Environment::SpecialFolder::Desktop;

		if (folder_browser_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			DebugLog->Text = folder_browser_dialog->SelectedPath;
		}
	}
	
	private: System::Void previous_button_Click(System::Object^ sender, System::EventArgs^ e) {
		index--;

		if (index < 0) {
			index = n_file - 1;
		}

		showPicture(files[index]);
	}

	private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e) {
		index++;

		if (index >= n_file) {
			index = 0;
		}

		showPicture(files[index]);
	}
};
}
