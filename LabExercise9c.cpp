/*
 * CSC/CIS-5-48828/48893  Fall 2023 Program Logic Using C++
 *
 * STUDENT:    Hailey Campbell
 * ASSIGNMENT: Lab Exercise 9c
 * DUE DATE:   11/18/2022
 *
 */

/* Place Library References Here */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;


// function that will return a pointer to a dynamically allocated float array 
// of the requested size
double* allocateArray(int size)
{
    double* array = new double [size];
    return array;
}

        
int main()
{
  // Variables for holding monthly sales figures
  float total = 0;  // Total of all sales
  float average;    // Average of monthly sales
  int   numOfSales; // Number of sales to be processed

  // Establish output characteristics
  cout << fixed << showpoint << setprecision(2);

  // ??? Ask the user for the name of the input file and open it
  ifstream infile;
  string filename;
  cout << "2022 Sales for Professor Locke's, Seed, Feed and Fertilizer Stores." 
       << endl << endl << "Which sales file would you like to process? ";
  cin >> filename;
  infile.open(filename);
  
  
  // ??? Read the number of sales to process from  the input file
  infile >> numOfSales;
  
  
  // ??? Dynamically allocate a float array that will hold the
  //     sales figures. -- function
  double *salesPtr = allocateArray(numOfSales);

  
  // ??? Get the monthly sales values from the file and store them
  // in the monthly sales array
  
  // ??? Output the monthly sales per store followed by
  // number of figures read
  
    // ??? Output remaining statistics: Total sales, Average Sales,
  // lowest and highest grossing store numbers and amounts.
  
  cout << endl << "Yearly Sales" << endl;
  int count, largesub, smallsub;
  double large = 0, small = 1000000000; 
  for (count = 0; count < numOfSales; count++)
  {
      double num; 
      infile >> num; 
      salesPtr[count] = num;
      cout << "Store " << setw(2) << count+1 << ": $" << setw(10) << num << endl;
      total += num;
      if (num < small)
      {
          small = num;
          smallsub = count;
      }
      if (num > large)
      {
          large = num;
          largesub = count;
      }
  }
  cout << "\nNumber of sales figures read: " << count << endl << endl;
  cout << setw(27) << left << "Total Sales: " << "$" << setw(10) << right << total << endl;
  cout << setw(27) << left << "Average Sales per store: " << "$" << setw(10) << right << total/count << endl;
  cout << left << "Lowest grossing Store " << smallsub+1 << setw(3) << ":" << "$" << setw(10) << right << small << endl;
  cout << left << "Highest grossing Store " << largesub+1 << setw(2) << ":" << "$" << setw(10) << right << large << endl;
  

  // ??? Deallocate memory allocated to the array
  delete [] salesPtr;
  salesPtr = nullptr;
     
  return 0;
}
