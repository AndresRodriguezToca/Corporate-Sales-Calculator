
//Include libraries
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

//Main Structure
struct Div_Quarter {
	double quarter_1,
		quarter_2, 
		quarter_3, 
		quarter_4;
};
//Structure extracted from file later
struct Div_Quarter_File {
	double quarter_1,
		quarter_2,
		quarter_3,
		quarter_4;
};
// Bubble Sort to find the Highest and Lowest later on
void bubbleSort(double[], int);
void swap(int &, int &);

//Main Function
int main()
{
	int count= 0;
	const int SIZE = 4;
	double Quarterly_Sales[SIZE];
	string Div_Zone[4]{"East","West","North","South"};
	Div_Quarter Division_Q[4];
	Div_Quarter_File Division_Q_F[4];
	fstream file;

	//Gather each quarter value for each division.
	for (int index = 0; index < 4; index++) {
		int counter_c = 0;
		cout << "Enter the quarterly sales for the " << Div_Zone[index] << " Divison:" << endl;

		cout << "\tQuarter " << (counter_c + 1) << ": ";
		cin >> Division_Q[index].quarter_1;
		while (Division_Q[index].quarter_1 < 0) {
			cout << endl << "\tSORRY THAT NUMBER. IT'S INVALID. TRY AGAIN.";
			cout << "\n\tQuarter " << (counter_c + 1) << ": ";
			cin >> Division_Q[index].quarter_1;
		}
		cout << "\tQuarter " << (counter_c + 2) << ": ";
		cin >> Division_Q[index].quarter_2;
		while (Division_Q[index].quarter_2 < 0) {
			cout << endl << "\tSORRY THAT NUMBER. IT'S INVALID. TRY AGAIN.";
			cout << "\n\tQuarter " << (counter_c + 2) << ": ";
			cin >> Division_Q[index].quarter_2;
		}
		cout << "\tQuarter " << (counter_c + 3) << ": ";
		cin >> Division_Q[index].quarter_3;
		while (Division_Q[index].quarter_3 < 0) {
			cout << endl << "\tSORRY THAT NUMBER. IT'S INVALID. TRY AGAIN.";
			cout << "\n\tQuarter " << (counter_c + 3) << ": ";
			cin >> Division_Q[index].quarter_3;
		}
		cout << "\tQuarter " << (counter_c + 4) << ": ";
		cin >> Division_Q[index].quarter_4;
		while (Division_Q[index].quarter_4 < 0) {
			cout << endl << "\tSORRY THAT NUMBER. IT'S INVALID. TRY AGAIN.";
			cout << "\n\tQuarter " << (counter_c + 4) << ": ";
			cin >> Division_Q[index].quarter_4;
		}
	}
		//Open or Create a new file call Division.txt and write out all info
		file.open("Division.txt", ios::out | ios::binary);
		if (!file) {
			cout << "Error opening file. Program aborting.\n";
			return 0;
		}
		for (int index_2 = 0; index_2 < 4; index_2++) {
			file.write(reinterpret_cast<char *>(&Division_Q[index_2]),
				sizeof(file));
		}
		file.close();
		//Open the file again and extract all info and pass it to a new structure
		file.open("Division.txt", ios::in | ios::binary);
		for (int index_3 = 0; index_3 < 4; index_3++) {
			file.read(reinterpret_cast<char *>(&Division_Q_F[index_3]),sizeof(Division_Q[index_3]));
		}
		file.close();
		//Calculate and display Sales for each quarter
		double Corp_sales_quarter1 = Division_Q_F[0].quarter_1 + Division_Q_F[1].quarter_1 + Division_Q_F[2].quarter_1 + Division_Q_F[3].quarter_1;
		cout << fixed << showpoint << setprecision(2);
		cout << "Corporate sales for the 1st quarter: $" << Corp_sales_quarter1;
		Quarterly_Sales[0] = Corp_sales_quarter1;
		double Corp_sales_quarter2 = Division_Q_F[0].quarter_2 + Division_Q_F[1].quarter_2 + Division_Q_F[2].quarter_2 + Division_Q_F[3].quarter_2;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "Corporate sales for the 2st quarter: $" << Corp_sales_quarter2;
		Quarterly_Sales[1] = Corp_sales_quarter2;
		double Corp_sales_quarter3 = Division_Q_F[0].quarter_3 + Division_Q_F[1].quarter_3 + Division_Q_F[2].quarter_3 + Division_Q_F[3].quarter_3;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "Corporate sales for the 3st quarter: $" << Corp_sales_quarter3;
		Quarterly_Sales[2] = Corp_sales_quarter3;
		double Corp_sales_quarter4 = Division_Q_F[0].quarter_4 + Division_Q_F[1].quarter_4 + Division_Q_F[2].quarter_4 + Division_Q_F[3].quarter_4;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "Corporate sales for the 4st quarter: $" << Corp_sales_quarter4;
		Quarterly_Sales[3] = Corp_sales_quarter4;

		//Calculate and display Yearly sales for each division
		cout << endl << "Total yearly sales for each division:";
		double Corp_sales_divE = Division_Q_F[0].quarter_1 + Division_Q_F[0].quarter_2 + Division_Q_F[0].quarter_3 + Division_Q_F[0].quarter_4;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[0] << ": $" << Corp_sales_divE;
		double Corp_sales_divW = Division_Q_F[1].quarter_1 + Division_Q_F[1].quarter_2 + Division_Q_F[1].quarter_3 + Division_Q_F[1].quarter_4;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[1] << ": $" << Corp_sales_divW;
		double Corp_sales_divN = Division_Q_F[2].quarter_1 + Division_Q_F[2].quarter_2 + Division_Q_F[2].quarter_3 + Division_Q_F[2].quarter_4;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[2] << ": $" << Corp_sales_divN;
		double Corp_sales_divS = Division_Q_F[3].quarter_1 + Division_Q_F[3].quarter_2 + Division_Q_F[3].quarter_3 + Division_Q_F[3].quarter_4;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[3] << ": $" << Corp_sales_divS;

		//Calculate and display yearly corporate sales
		double Corp_sales_divT = Corp_sales_divE + Corp_sales_divW + Corp_sales_divN + Corp_sales_divS;
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "Total yearly corporate sales: $" << Corp_sales_divT;
		
		//Calculate and display quarterly sales for each division
		cout << endl << "Average quarterly sales for each division:";
		double Corp_average_divE = (Corp_sales_divE/4);
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[0] << ": $" << Corp_average_divE;
		double Corp_average_divW = (Corp_sales_divW / 4);
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[1] << ": $" << Corp_average_divW;
		double Corp_average_divN = (Corp_sales_divN / 4);
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[2] << ": $" << Corp_average_divN;
		double Corp_average_divS = (Corp_sales_divS / 4);
		cout << fixed << showpoint << setprecision(2);
		cout << endl << "\t" << Div_Zone[3] << ": $" << Corp_average_divS;
		
		//Use Bubble sort to sort the array called Quarterly_Sales.
		bubbleSort(Quarterly_Sales, SIZE);
		//Display the highest and lowest sorted.
		cout << endl << showpoint << setprecision(2) << "Highest quarterly sales: $" << Quarterly_Sales[3];
		cout << endl << showpoint << setprecision(2) << "Lowest quarterly sales: $" << Quarterly_Sales[0];

}
// Bubble Sort
void bubbleSort(double array[], int size)
{
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
	}
}
//Swap
void swap(double &a, double &b)
{
	int temp = a;
	a = b;
	b = temp;
}
