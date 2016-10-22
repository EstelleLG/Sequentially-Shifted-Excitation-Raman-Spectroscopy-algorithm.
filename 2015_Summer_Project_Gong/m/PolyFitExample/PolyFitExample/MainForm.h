#pragma once
#include "polyfit.hpp"
#include <cliext/vector> 
#include <math.h>

namespace PolyFitExample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  polyfitChart;
	private: System::Windows::Forms::NumericUpDown^  numericField;

	protected: 

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
			System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::Button^  buttonGraph;
			System::Windows::Forms::Label^  label1;
			this->polyfitChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->numericField = (gcnew System::Windows::Forms::NumericUpDown());
			tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			buttonGraph = (gcnew System::Windows::Forms::Button());
			label1 = (gcnew System::Windows::Forms::Label());
			tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->polyfitChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericField))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			tableLayoutPanel1->ColumnCount = 3;
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 82.37624F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 17.62376F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 85)));
			tableLayoutPanel1->Controls->Add(this->polyfitChart, 0, 0);
			tableLayoutPanel1->Controls->Add(buttonGraph, 2, 1);
			tableLayoutPanel1->Controls->Add(this->numericField, 1, 1);
			tableLayoutPanel1->Controls->Add(label1, 0, 1);
			tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			tableLayoutPanel1->Name = L"tableLayoutPanel1";
			tableLayoutPanel1->RowCount = 2;
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			tableLayoutPanel1->Size = System::Drawing::Size(430, 441);
			tableLayoutPanel1->TabIndex = 0;
			// 
			// polyfitChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->polyfitChart->ChartAreas->Add(chartArea1);
			tableLayoutPanel1->SetColumnSpan(this->polyfitChart, 3);
			this->polyfitChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->polyfitChart->Legends->Add(legend1);
			this->polyfitChart->Location = System::Drawing::Point(3, 3);
			this->polyfitChart->Name = L"polyfitChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"Data";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"PolyFit";
			this->polyfitChart->Series->Add(series1);
			this->polyfitChart->Series->Add(series2);
			this->polyfitChart->Size = System::Drawing::Size(424, 404);
			this->polyfitChart->TabIndex = 2;
			this->polyfitChart->Text = L"chart";
			// 
			// buttonGraph
			// 
			buttonGraph->Anchor = System::Windows::Forms::AnchorStyles::Left;
			buttonGraph->Location = System::Drawing::Point(347, 414);
			buttonGraph->Name = L"buttonGraph";
			buttonGraph->Size = System::Drawing::Size(75, 23);
			buttonGraph->TabIndex = 1;
			buttonGraph->Text = L"&Graph";
			buttonGraph->UseVisualStyleBackColor = true;
			buttonGraph->Click += gcnew System::EventHandler(this, &Form1::buttonGraph_Click);
			// 
			// numericField
			// 
			this->numericField->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericField->Location = System::Drawing::Point(287, 415);
			this->numericField->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numericField->Name = L"numericField";
			this->numericField->Size = System::Drawing::Size(54, 20);
			this->numericField->TabIndex = 0;
			this->numericField->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7, 0, 0, 0});
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Dock = System::Windows::Forms::DockStyle::Fill;
			label1->Location = System::Drawing::Point(3, 410);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(278, 31);
			label1->TabIndex = 3;
			label1->Text = L"Poly Order:";
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 441);
			this->Controls->Add(tableLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L"PolyFit";
			this->Load += gcnew System::EventHandler(this, &Form1::Form_Load);
			tableLayoutPanel1->ResumeLayout(false);
			tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->polyfitChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericField))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			GraphData();
		}

		System::Void buttonGraph_Click(System::Object^  sender, System::EventArgs^  e) 
		{	
			GraphData();
		}
		
		array<double>^ to_array( const std::vector<double>& vec )
		{
			using namespace System;
			using namespace System::Runtime::InteropServices;

			array<double>^ ret = gcnew array<double>(vec.size());
			Marshal::Copy((IntPtr)((void*)vec.data()), ret, 0, vec.size());
			return ret;
		}

		void GraphData()
		{
			const double PI2 = 6.283185307179586476925286766559;

			// generate the data
			std::vector<double> oX(1024); 
			std::vector<double> oY(1024); 
			Random^ oRand = gcnew Random();
			for ( unsigned int i = 0; i < oX.size(); i++ )
			{
				oX[i] = i;
				oY[i] = sin( (double)i/1024.0 * PI2 ) + (oRand->NextDouble()-0.5);
			}
			polyfitChart->Series[0]->Points->DataBindXY(to_array(oX), to_array(oY));

			// polynomial fitting
			std::vector<double> oCoeff = polyfit( oX, oY, (int)numericField->Value );
			std::vector<double> oFittedY = polyval( oCoeff, oX );

			polyfitChart->Series[1]->Points->DataBindXY(to_array(oX), to_array(oFittedY));
		}
};
}

