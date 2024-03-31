#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {
 private:
  std::vector<int> vec_;
  std::deque<int> deq_;
  std::vector<int> order_;
  int idx_;

  PmergeMe(const PmergeMe& obj);
  PmergeMe& operator=(const PmergeMe& obj);
  PmergeMe();
  void getSortOrder(size_t n);

 public:
  PmergeMe(int ac, const char** av);
  ~PmergeMe();
  void mergeInsertionSortVector();
  void mergeInsertionSortDeque();
  void mergeVector(int numOfPair, int size);
  void mergeDeque(int numOfPair, int size);
  void makePairVector(int numOfPair, int size);
  void makePairDeque(int numOfPair, int size);
  void insertionVector(int numOfPair, int size);
  void insertionDeque(int numOfPair, int size);
  void binaryInsertionVector(std::vector<int>& mainChain,
                             std::vector<int>& pendingElements, int size,
                             int i);
  void binaryInsertionDeque(std::deque<int>& mainChain,
                            std::deque<int>& pendingElements, int size, int i);
  std::vector<int>& getVector();
  std::deque<int>& getDeque();
};

#endif