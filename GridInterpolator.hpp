#include <vector>
#include <iostream>
#include <array>

class GridInterpolator{

private:
  std::vector< std::vector<double> > inputGrid;
  std::vector<double> outputValues;
  std::vector<double> stackedGrid;
  std::vector<int> offset;
  
  int numberOfElements;
  int inputDimension;
  int outputDimension;
  
  void checkGrid(std::vector< std::vector<double> > inputGrid);
  bool isIncreasing(std::vector<double> subGrid);
  void stackGrid();

  // void calculateWeights(std::array<double> x, std::array<int> leftIndex, std::array<double> alpha);
  // void interpolate(std::array<int> leftIndex, std::array<double> alpha,
  // 		     std::array<int> corner, std::array<double> coefficient, std::array<double> result);
  // bool flipCorner(std::array<int> corner);
  

public:
  GridInterpolator(std::vector< std::vector<double> > inputGrid, std::vector<double> outputValues);
  std::vector<double> eval(std::vector<double> point);
};


GridInterpolator::GridInterpolator(std::vector< std::vector<double> > inputGrid,
					 std::vector<double> outputValues): inputGrid(inputGrid),
									    outputValues(outputValues),
									    stackedGrid(),
									    numberOfElements(1),
									    inputDimension(inputGrid.size()),
									    outputDimension(1)
									    
{
  // Compute number of elements on the grid
  for(std::vector<double> inputGridTics : this->inputGrid){
    this->numberOfElements *= inputGridTics.size();
  }

  // Check dimension consistency
  bool isConsistent = ((this->outputValues.size() % this->numberOfElements) == 0);
  if(!isConsistent){
    throw "The input grid and output values provided have in consistent dimensions.";
  }


  //Stack grid
  this->stackGrid();

  // Check input and output dimensions
  bool isOutputDimensionConsistent = this->outputDimension ==
    this->outputValues.size() / this->numberOfElements;
  bool isInputDimensionConsistent = this->inputDimension == (this->offset.size() - 1);
  
  
  
  std::cout << "Constructor Executed Succesfully" << std::endl;
  std::cout << "Number of Elements is: " << this->numberOfElements << "\n";
}

std::vector<double> GridInterpolator::eval(std::vector<double> point){
  std::vector<int> leftIndex(inputDimension);
  std::vector<int> corner(inputDimension);
  std::vector<double> alpha(inputDimension);
  std::vector<double> coefficient(inputDimension);
  std::vector<double> result(outputDimension);

  // calculateWeights(x, leftIndex, alpha);
  // while(true){
  //   interpolate(leftIndex, alpha, corner, coefficient, result);
  //   if (flipCorner(corner) == false){
  //     break;
  //   }
  // }
  return result;
}

void GridInterpolator::stackGrid(){
  offset.clear();
  offset.push_back(0);
  for(std::vector<double> subGrid : inputGrid){
    offset.push_back( offset.back() + subGrid.size() );
  }

  stackedGrid.clear();
  for(std::vector<double> subGrid: inputGrid){
    stackedGrid.insert(stackedGrid.end(), subGrid.begin(), subGrid.end());
  }
  
  // std::cout << "Print offset = { ";
  // for(auto & val : offset){
  //   std::cout << val << " ";
  // }
  // std::cout << "} \n";

  // std::cout << "Print stackeGrid = { ";
  // for(auto & val : stackedGrid){
  //   std::cout << val << " ";
  // }
  // std::cout << "} \n";
}
