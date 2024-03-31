#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, const char** av) {
  if (ac < 3) {
    throw std::invalid_argument("Error: not enough arguments.");
  }
  char* strEnd = NULL;
  for (int i = 1; i < ac; i++) {
    size_t arg = std::strtoul(av[i], &strEnd, 10);
    if (*strEnd != '\0') {
      throw std::invalid_argument("Error: invalid argument.");
    } else if (arg <= 0 || arg > std::numeric_limits<unsigned int>::max()) {
      throw std::invalid_argument("Error: argument range error.");
    } else {
      deq_.push_back(arg);
      vec_.push_back(arg);
    }
  }
  getSortOrder(vec_.size());
}
PmergeMe::PmergeMe(const PmergeMe& obj) { *this = obj; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
  if (this != &obj) {
  }
  return *this;
}

std::vector<int>& PmergeMe::getVector() { return vec_; }

std::deque<int>& PmergeMe::getDeque() { return deq_; }

void PmergeMe::binaryInsertionDeque(std::deque<int>& mainChain,
                                    std::deque<int>& pendingElements, int size,
                                    int i) {
  while (static_cast<unsigned long>(order_[idx_]) >
         pendingElements.size() / size) {
    idx_++;
  }
  int idx = order_[idx_++] - 1;
  std::deque<int>::iterator first = pendingElements.begin() + idx * size;
  int key = *first;
  int left = 0;
  int right = idx + i;
  if (static_cast<unsigned int>(right) >= mainChain.size())
    right = mainChain.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (key > mainChain[mid * size]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  if (static_cast<unsigned int>(left * size) > mainChain.size())
    mainChain.insert(mainChain.end(), first, first + size);
  else
    mainChain.insert(mainChain.begin() + left * size, first, first + size);
}

void PmergeMe::insertionDeque(int numOfPair, int size) {
  std::deque<int> mainChain;
  std::deque<int> pendingElements;
  std::deque<int> remainElements;

  for (int i = 0; i < numOfPair; i++) {
    std::deque<int>::iterator it1 = deq_.begin() + (2 * i) * size;
    std::deque<int>::iterator it2 = it1 + size;
    mainChain.insert(mainChain.end(), it1, it1 + size);
    pendingElements.insert(pendingElements.end(), it2, it2 + size);
  }

  unsigned int mainPendingSize = mainChain.size() + pendingElements.size();
  if (deq_.size() - mainPendingSize >= static_cast<unsigned int>(size)) {
    pendingElements.insert(pendingElements.end(),
                           deq_.begin() + mainPendingSize,
                           deq_.begin() + (mainPendingSize + size));
    numOfPair++;
    remainElements.insert(remainElements.end(),
                          deq_.begin() + (mainPendingSize + size), deq_.end());
  } else if (deq_.size() - mainPendingSize > 0) {
    remainElements.insert(remainElements.end(), deq_.begin() + mainPendingSize,
                          deq_.end());
  }

  mainChain.insert(mainChain.begin(), pendingElements.begin(),
                   pendingElements.begin() + size);
  idx_ = 1;
  for (int i = 1; i < numOfPair; i++) {
    binaryInsertionDeque(mainChain, pendingElements, size, i);
  }
  if (remainElements.size() > 0) {
    mainChain.insert(mainChain.end(), remainElements.begin(),
                     remainElements.end());
  }
  deq_.swap(mainChain);
}

void PmergeMe::makePairDeque(int numOfPair, int size) {
  for (int i = 0; i < numOfPair; i++) {
    std::deque<int>::iterator it1 = deq_.begin() + 2 * i * size;
    std::deque<int>::iterator it2 = deq_.begin() + (2 * i + 1) * size;
    if (*it1 < *it2) {
      std::swap_ranges(it1, it2, it2);
    }
  }
}

void PmergeMe::mergeDeque(int numOfPair, int size) {
  makePairDeque(numOfPair, size);
  if (numOfPair > 1) mergeDeque(numOfPair / 2, size * 2);
  insertionDeque(numOfPair, size);
}

void PmergeMe::mergeInsertionSortDeque() { mergeDeque(deq_.size() / 2, 1); }

void PmergeMe::binaryInsertionVector(std::vector<int>& mainChain,
                                     std::vector<int>& pendingElements,
                                     int size, int i) {
  while (static_cast<unsigned long>(order_[idx_]) >
         pendingElements.size() / size) {
    idx_++;
  }
  int idx = order_[idx_++] - 1;
  std::vector<int>::iterator first = pendingElements.begin() + idx * size;
  int key = *first;
  int left = 0;
  int right = idx + i;
  if (static_cast<unsigned int>(right) >= mainChain.size())
    right = mainChain.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (key > mainChain[mid * size]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  if (static_cast<unsigned int>(left * size) > mainChain.size())
    mainChain.insert(mainChain.end(), first, first + size);
  else
    mainChain.insert(mainChain.begin() + left * size, first, first + size);
}

void PmergeMe::insertionVector(int numOfPair, int size) {
  std::vector<int> mainChain;
  std::vector<int> pendingElements;
  std::vector<int> remainElements;

  for (int i = 0; i < numOfPair; i++) {
    std::vector<int>::iterator it1 = vec_.begin() + (2 * i) * size;
    std::vector<int>::iterator it2 = it1 + size;
    mainChain.insert(mainChain.end(), it1, it1 + size);
    pendingElements.insert(pendingElements.end(), it2, it2 + size);
  }

  unsigned int mainPendingSize = mainChain.size() + pendingElements.size();
  if (vec_.size() - mainPendingSize >= static_cast<unsigned int>(size)) {
    pendingElements.insert(pendingElements.end(),
                           vec_.begin() + mainPendingSize,
                           vec_.begin() + (mainPendingSize + size));
    numOfPair++;
    remainElements.insert(remainElements.end(),
                          vec_.begin() + (mainPendingSize + size), vec_.end());
  } else if (vec_.size() - mainPendingSize > 0) {
    remainElements.insert(remainElements.end(), vec_.begin() + mainPendingSize,
                          vec_.end());
  }

  mainChain.insert(mainChain.begin(), pendingElements.begin(),
                   pendingElements.begin() + size);
  idx_ = 1;
  for (int i = 1; i < numOfPair; i++) {
    binaryInsertionVector(mainChain, pendingElements, size, i);
  }
  if (remainElements.size() > 0) {
    mainChain.insert(mainChain.end(), remainElements.begin(),
                     remainElements.end());
  }
  vec_.swap(mainChain);
}

void PmergeMe::makePairVector(int numOfPair, int size) {
  for (int i = 0; i < numOfPair; i++) {
    std::vector<int>::iterator it1 = vec_.begin() + 2 * i * size;
    std::vector<int>::iterator it2 = vec_.begin() + (2 * i + 1) * size;
    if (*it1 < *it2) {
      std::swap_ranges(it1, it2, it2);
    }
  }
}

void PmergeMe::mergeVector(int numOfPair, int size) {
  makePairVector(numOfPair, size);
  if (numOfPair > 1) mergeVector(numOfPair / 2, size * 2);
  insertionVector(numOfPair, size);
}

void PmergeMe::mergeInsertionSortVector() { mergeVector(vec_.size() / 2, 1); }

void PmergeMe::getSortOrder(size_t n) {
  size_t* jacobsthalNumbers = new size_t[n + 2];
  jacobsthalNumbers[0] = 0;
  jacobsthalNumbers[1] = 1;
  for (size_t i = 2; i < n + 2; i++) {
    jacobsthalNumbers[i] =
        jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
  }
  size_t gap, num = 0;
  for (size_t i = 1; i < n + 2; i++) {
    num = jacobsthalNumbers[i];
    gap = jacobsthalNumbers[i] - jacobsthalNumbers[i - 1];
    while (gap-- > 0) {
      order_.push_back(num--);
    }
    if (jacobsthalNumbers[i + 1] >= n) {
      num = n;
      while (order_.size() < n) {
        order_.push_back(num--);
      }
      break;
    }
  }
  delete[] jacobsthalNumbers;
}