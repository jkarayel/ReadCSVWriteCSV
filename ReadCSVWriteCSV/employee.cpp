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
	int sizeR = this->emp.size();
	int sizeC = this->emp[0].size();
	for (int c = 0; c < sizeR; c++)
	{
		for (int r = 0; r < sizeC; r++)
		{
			cout << this->emp[c][r] << ",";
		}
		cout << endl;
	}
	
}

void employee::WriteToFile()
{
	int sizeR = this->emp.size();
	int sizeC = this->emp[0].size();
	string changePlaces;
	for (int r = 0; r < sizeR; r++)
	{
		changePlaces = emp[r][1] + " " + emp[r][0];
		temp.push_back(changePlaces);
		for (int i = 0; i < sizeC; i++)
		{
			temp.push_back("," + emp[r][i]);
		}
		temp.erase(temp.begin() + 1, temp.begin() + 3);
		emp.push_back(temp);
		temp.clear();
	}

}

void employee::AddToRow(string token)
{
	temp.push_back(token);
}

void employee::AddToLine()
{
	emp.push_back(temp);
	temp.clear();
}
