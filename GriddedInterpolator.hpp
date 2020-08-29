#include <vector>
#include <iostream>

class GriddedInterpolator{

private:
  std::vector< std::vector<double> > inputGrid;
  std::vector<double> outputValues;
  int numberOfElements;
  

  void checkGrid(std::vector< std::vector<double> > inputGrid);
  bool isIncreasing(std::vector<double> subGrid);
  void stackGrid(std::vector< std::vector<double> >, std::vector<int> offset, std::vector<double> stacked_grid);
  

public:
  GriddedInterpolator(std::vector< std::vector<double> > inputGrid, std::vector<double> outputValues);
  
};


GriddedInterpolator::GriddedInterpolator(std::vector< std::vector<double> > inputGrid,
					 std::vector<double> outputValues): inputGrid(inputGrid),
									    outputValues(outputValues)
{
  std::cout << "Constructor Executed Succesfully" << std::endl;
}
