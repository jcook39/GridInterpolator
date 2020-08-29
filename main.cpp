// Simple test program to get started
#include <iostream>
#include "GriddedInterpolator.hpp"

using namespace std;

int main(){
  vector<vector<double>> inputGrid = {{1,2}};
  vector<double> outputValues = {1,2};
  

  GriddedInterpolator griddedInterpolator(inputGrid, outputValues);
  
  cout << "Main program executed succesfully. \n";

  vector<double> inputOneVec = {1,2,3};
}
