#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main() {
  {
    std::cout << "========== MutantStack Test ==========" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "empty: " << mstack.empty() << std::endl;
    mstack.push(3);
    mstack.push(65);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "======= Copy Constructor Test =======" << std::endl;
    MutantStack<int> mstackCopy(mstack);
    MutantStack<int>::iterator it1 = mstackCopy.begin();
    MutantStack<int>::iterator ite1 = mstackCopy.end();
    ++it1;
    --it1;
    while (it1 != ite1) {
      std::cout << *it1 << std::endl;
      ++it1;
    }
  }
  {
    std::cout << "============= List Test =============" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "top: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "size: " << list.size() << std::endl;
    list.pop_back();
    std::cout << "empty: " << list.empty() << std::endl;
    list.push_back(3);
    list.push_back(65);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::list<int> s(list);
  }
  return 0;
}