#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class employee
{
public:
	employee(string, string);
	void ReadFromFile();
	void WriteToFile();
	void CloseFiles();
private:
	void AddToRow(string);
	void AddToLine();
protected:
	ifstream empin;
	ofstream empout;
	vector<string> temp;
	vector<vector<string>> emp;
};

