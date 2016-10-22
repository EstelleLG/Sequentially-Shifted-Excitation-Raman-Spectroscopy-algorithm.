// project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>		//ifstream/ofstream
#include <sstream>     //getline and stringstream
#include <iostream>
#include <vector>


using namespace std;

double string_to_double(const std::string& s);
void print_vector(const vector<double> k);
void loadFile_to_row(vector<double>&row, string filename);
double get_value_in_R(size_t k, size_t n, const vector<vector<double>> matrix);
void print_matrix(const vector<vector<double>> k);
double select_max_or_min_at_n(size_t n, const vector<vector<double>> matrix, string instruction);
void construct_initial_F(vector<double>& F, const vector<vector<double>> matrix);
void construct_initial_R(vector<double>& R, const vector<vector<double>> matrix);
double get_value_at_n(size_t n, const vector<double> target);
int capK = 3;

//for each n, at each i, do this iteration(sum up)
double iteration(int iter, int n, vector<double>initR, vector<double>initF, vector<vector<double>> matrix) {
	double w = 0;
	double first = 0; double second = 0; double third = 0;
	for (int k = 0; k < capK; k++) {
		first = get_value_in_R(k, n, matrix);
		second = get_value_at_n(n, initF);
		if (n >= k) {
			third = get_value_at_n(n - k, initR);
		}
		else {
			third = 0;
		}
		w = w + first / (second + third);
	}
	return w;
}

void update(vector<double>& init, vector<double> w) {
	
	vector<double> tempNext;
	for (int i = 0; i < init.size(); i++) {
		double temp = get_value_at_n(i, init);
		double temp2 = get_value_at_n(i, w);
		
		tempNext.push_back(temp*temp2);
	}
	init = tempNext;
	tempNext.clear();
}

ostream& operator<< (ostream& os, const vector<double>& spectrum) {
	for (auto i : spectrum) {
		os << i << endl;
	}
	return os;
};


int main(int argc, char* argv[])
{
	vector<double> row0, row1, row2, row3, row4, row5, row6, row7, row8;
	vector<vector<double>> matrix;

	// k = 3...  each row has size = about 5670
	loadFile_to_row(row0, "18779.014.txt");
	loadFile_to_row(row1, "18779.958.txt");
	loadFile_to_row(row2, "18781.005.txt");

	//loadFile_to_row(row3, "18781.963.txt");
	//loadFile_to_row(row4, "18783.079.txt");
	//loadFile_to_row(row5, "18784.085.txt");

	/*loadFile_to_row(row6, "18784.99.txt");
	loadFile_to_row(row7, "18785.95.txt");
	loadFile_to_row(row8, "18786.985.txt");*/
	//18784.99
	//18785.95
//18786.985



	//matrix (R)
	matrix.push_back(row0);
	matrix.push_back(row1);
	matrix.push_back(row2);
	//matrix.push_back(row3);
	//matrix.push_back(row4);
	//matrix.push_back(row5);
	/*matrix.push_back(row6);
	matrix.push_back(row7);
	matrix.push_back(row8);*/
	cout << endl;

	

	//initialize S(F)/S(R) at i = 0 using max/min selection.
	//first iteration
	vector<double> initFluore;
	vector<double> initRaman;
	construct_initial_F(initFluore, matrix);
	construct_initial_R(initRaman, matrix);


	cout << "finish initializing...." << endl;
	cout << "initFluore size: " << initFluore.size() << " initR.size: " << initRaman.size() << endl;
	
	//cout << get_value_at_n(717, initFluore) << endl;
	

	//cout << get_value_in_R(3, 800, matrix) << endl;
	

	/*print_vector(initFluore);
	cout << endl;
	cout << "next:" << endl;
	print_vector(initRaman);*/

	
	// double iteration(int iter, int n, vector<double>initR, vector<double>initF, vector<vector<double>> matrix)
	// 

	int loop = 2800;
	vector<double> w;
	//bool conv = false;
	//int convAt = 0;

	for (int iter = 0; iter < loop; iter++) {
		cout << iter << endl;
	//	double testConR = get_value_at_n(2, initRaman);
	//	double testConF = get_value_at_n(2, initFluore);


		for (int n = 0; n < initFluore.size(); n++) {
			//		double tempW = iteration(iter, n, initRaman, initFluore, matrix); 
			double result = 0;
			for (int k = 0; k < 3; k++) {
				double first = get_value_in_R(k, n, matrix);
				double second = get_value_at_n(n, initFluore);
				double third = get_value_at_n(n - k, initRaman);
				result = result + (first / (second + third));
			}
			w.push_back(result);


		}

	////	/*vector<double> finalW;
	////	vector<double> testW = initFluore;
	////	for (int k = 0; k < capK)
	////	for (int n = 0; n < initFluore.size(); n++) {
	////		double tempSecond = 0;
	////		if (n > 0) tempSecond = get_value_at_n(n, initRaman);
	////		testW.at(n) = testW.at(n) + tempSecond;
	////		testW.at(n) = get_value_in_R(0, n, matrix) / testW.at(n);
	////	}*/
	////	


	//	//


		update(initFluore, w);  
		update(initRaman, w); //
		w.clear();    


	//
	//	double ConR = get_value_at_n(2, initRaman);
	//	double ConF = get_value_at_n(2, initFluore);

	//	//if ((testConR == ConR) && (testConF == ConF)) {
	//	//	/*cout << " converge!!!!!!!!!!" << endl;
	//	//	cout << "   iteration at i = " << iter << endl;*/
	//	//	conv = true;
	//	//	convAt = iter;
	//	//	break;
	//	//}


	}

	//cout << convAt << "  yo" << endl;

	//if (conv) {
		ofstream ofs("outputRaman.txt", ofstream::out);
		ofs << initRaman;
		ofs.close();

		ofstream ofss("outputFluo.txt", ofstream::out);
		ofss << initFluore;
		ofss.close();

		
		
	//}

		

	cout << "				--- end ---	" << endl;

	return 0;
}


double string_to_double(const std::string& s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}

void print_vector(const vector<double> k)    //change this into template
{
	if (k.size() == 0) {
		cout << "	empty vector" << endl;
	}
	for (double i : k) {
		cout.precision(7);
		cout << fixed << i << "   ";
	}

}

void print_matrix(const vector<vector<double>> k)    //change this into template
{

	for (auto i = k.begin(); i != k.end(); i++) {
		print_vector(*i);
		cout << endl;
	}

}

void loadFile_to_row(vector<double>&row, string filename) {
	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		cout << "didn't open" << endl;
	}
	else {   //successfully open a file.
		cout << endl;
		cout << "load file...			";
		while (file) {
			string data;
			getline(file, data);		//a data value at a specific n position
			//cout << data << "   ";
			double aDouble = string_to_double(data);
			if (aDouble != 0) {
				row.push_back(aDouble);
			}
		}
		cout << "close file" << endl;
		
		file.close();
		//print_vector(row);
	}
}

double get_value_in_R(size_t k, size_t n, const vector<vector<double>> matrix){
	double result = 0;
	if (k < matrix.size()) {
		if (n < matrix.at(0).size()){
			result = matrix.at(k).at(n);
		}
	}
	
	return result;
}

double select_max_or_min_at_n(size_t n, const vector<vector<double>> matrix, string instruction){
	double result = -1;
	if (n < matrix.at(0).size()) {
		result = matrix.at(0).at(n);      //default       value at n   at k=0  row data.
		for (auto i = matrix.begin(); i != matrix.end(); i++) {
			if (instruction == "max"){
				if (i->at(n) > result) {
					result = i->at(n);
				}
			}
			if (instruction == "min"){
				if (i->at(n) < result) {
					result = i->at(n);
				}
			}
		}
	}
	return result;
}
//
//double select_max(vector<double> column) {
//	double result = 0;
//	for (auto i : column) {
//		if (i > result) {
//			result = i;
//		}
//	}
//	cout << "result: " << result << endl;
//	return result;
//}
//
//double select_min(vector<double> column) {
//	double result = 1;
//	for (auto i : column) {
//		if (i < result) {
//			result = i;
//		}
//	}
//	return result;
//}


void construct_initial_F(vector<double>& F, const vector<vector<double>> matrix) {
	auto n = matrix.at(0).size();
	for (auto i = 0; i < n; i++) {
		double somef = select_max_or_min_at_n(i, matrix, "min");
		F.push_back(somef);
	}
	/*for (auto i : matrix) {
		double test = select_max(i);
		F.push_back(test);
	}*/
}

void construct_initial_R(vector<double>& R, const vector<vector<double>> matrix) {
	auto n = matrix.at(0).size();
	for (auto i = 0; i < n; i++) {
		double someR = select_max_or_min_at_n(i, matrix, "max");
		R.push_back(someR);
	}

	/*for (auto i : matrix) {
		double test = select_min(i);
		R.push_back(test);
	}*/
}

double get_value_at_n(size_t n, const vector<double> target) {
	if (n < target.size() && n >= 0) {
		return target.at(n);
	}
	else return 0;
}