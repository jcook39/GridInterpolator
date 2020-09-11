// Simple test program to get started
#include <iostream>
#include "GridInterpolator.hpp"

using namespace std;

int main(){
  vector<vector<double>> inputGrid = {{1,2}};
  vector<double> outputValues = {1,2};
  

  GridInterpolator gridInterpolator(inputGrid, outputValues);

  vector<double> inputVal = {1.5};
  vector<double> outputVal = gridInterpolator.eval(inputVal);
  
  cout << "Main program executed succesfully. \n";
  return 0;
}
