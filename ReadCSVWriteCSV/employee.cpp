#include "employee.h"
using namespace std;

employee::employee(string inpF, string outF)
{
	empin.open(inpF);
	empout.open(outF, ios::trunc);
}

void employee::ReadFromFile()
{
	char character;
	string line;
	if (empin.is_open()) {
		while (getline(this->empin, line)) {
			stringstream ss(line);
			string token;

			while (getline(ss, token, ',')) {
				AddToRow(token);

			}

			AddToLine();
		}
	}
	else
	{
		cout << "Something is wrong with input file"<< endl;
	}
}

void employee::WriteToFile()
{	
	if (empout.is_open())
	{
		int sizeR = this->emp.size();
		int sizeC = this->emp[0].size();
		bool notFirst = false;
		for (int c = 0; c < sizeR; c++)
		{
			for (int r = 0; r < sizeC; r++)
			{
				if (notFirst == true) {
					empout << ",";

				}
				notFirst = true;
				empout << this->emp[c][r];
			}
			empout << endl;
			notFirst = false;
		}
		
	}
	else
	{
		cout << "Something is wrong with output file" << endl;
	}
	

}

void employee::CloseFiles()
{
	empin.close();
	empout.close();
}

void employee::AddToRow(string token)
{
	temp.push_back(token);
}

void employee::AddToLine()
{
	string changePlaces;
	
	changePlaces = temp[1] + " " + temp[0];
	temp.erase(temp.begin(), temp.begin() + 2);
	temp.insert(temp.begin(), changePlaces);
	emp.push_back(temp);
	temp.clear();
	
	
	
}