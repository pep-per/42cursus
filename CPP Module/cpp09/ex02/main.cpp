#include "PmergeMe.hpp"

int main(int ac, const char** av) {
  try {
    std::clock_t start, endVec, endDeq;
    PmergeMe p(ac, av);
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = p.getDeque().begin();
         it != p.getDeque().end(); it++) {
      std::cout << *it << " ";
    }
    start = std::clock();
    p.mergeInsertionSortVector();
    endVec = std::clock();
    p.mergeInsertionSortDeque();
    endDeq = std::clock();
    std::cout << "\nAfter: ";
    for (std::deque<int>::iterator it = p.getDeque().begin();
         it != p.getDeque().end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << p.getVector().size()
              << " elements with std::vector : " << (endVec - start) << " us"
              << std::endl;
    std::cout << "Time to process a range of " << p.getDeque().size()
              << " elements with std::deque : " << (endDeq - endVec) << " us"
              << std::endl;
    // for (std::deque<int>::iterator it = p.getDeque().begin();
    //      it != p.getDeque().end() - 1; it++) {
    //   if (*it > *(it + 1)) std::cout << "Error: not sorted." << std::endl;
    // }
    // for (std::vector<int>::iterator it = p.getVector().begin();
    //      it != p.getVector().end() - 1; it++) {
    //   if (*it > *(it + 1)) std::cout << "Error: not sorted." << std::endl;
    // }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}