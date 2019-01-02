#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> v{ 3, 3, 3, 7, 7, 13, 18, 21, 25, 27 };
    std::vector<int>::iterator upper1;

    upper1 = std::upper_bound(v.begin(), v.end(), 3);

    auto lower1 = std::lower_bound(v.begin(), v.end(), 3);
    std::cout << "\nupper_bound for element 3 is at position : "
              << (upper1 - v.begin());
    std::cout << "\nlower_bound for element 3 is at position : "
              << (lower1 - v.begin());
    std::cout << "\n";
  return 0;
}
