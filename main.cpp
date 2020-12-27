#include "CartesianCoordinate.h"

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

int main()
{
  CartesianCoordinate<unsigned> shape({2, 2, 3, 3});
  std::cout << "Max Offset: " << shape.end()() << "\n";

  decltype(shape)::iterator stop = shape.at({1, 1, 1, 1});
  for (decltype(shape)::iterator it = shape.begin(); it != stop; ++it) {
    std::vector<unsigned int> getCoord;
    shape.coordOf(it, std::back_inserter(getCoord));
    decltype(shape)::offset_type currOffset = shape.offsetOf(it);

    std::cout << "coordinate: ";
    for (auto dim : getCoord) {
      std::cout << dim << ", ";
    }
    std::cout << "\t";
    std::cout << "offset: " << currOffset << "\n";
  }
  std::cout << "==========================================\n";
  for (decltype(shape)::iterator it = shape.at({1, 1, 1, 1}); it != shape.end(); ++it) {
    std::vector<unsigned int> getCoord;
    shape.coordOf(it, std::back_inserter(getCoord));
    decltype(shape)::offset_type currOffset = shape.offsetOf(it);

    std::cout << "coordinate: ";
    for (auto dim : getCoord) {
      std::cout << dim << ", ";
    }
    std::cout << "\t";
    std::cout << "offset: " << currOffset << "\n";
  }

  using Container = std::vector<unsigned int>;
  // using Container = std::list<unsigned int>;
  // using Container = std::array<unsigned int, 4>;
  // using Container = std::deque<unsigned int>;

  Container containerCoord{1, 1, 2, 3};
  decltype(shape)::iterator containerIter = shape.at(containerCoord);
  std::cout << "==========================================\n";
  std::cout << "{1, 1, 2, 3} -> offset: " << containerIter() << "\n";

  CartesianCoordinate<unsigned> coord({2, 2, 2, 2});
  for (auto elem : coord) {
    std::cout << elem << " ";
  }
  std::cout << "\n";

  auto result =
    std::accumulate(std::begin(coord), std::end(coord), 0, [](const unsigned& a, const unsigned& b) { return a + b; });

  std::cout << "accumulate result: " << result << "\n";
  std::cout << "Successfully executed\n";
}