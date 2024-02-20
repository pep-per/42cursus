#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;
  typedef typename Container::size_type size_type;
  typedef typename Container::iterator iterator;

 protected:
  container_type c_;

 public:
  MutantStack() : std::stack<T, Container>(){};

  MutantStack(const MutantStack& obj) : std::stack<T, Container>() {
    *this = obj;
  };

  ~MutantStack(){};

  MutantStack& operator=(const MutantStack& obj) {
    c_ = obj.c_;
    return *this;
  }

  reference top() { return c_.back(); }

  const_reference top() const { return c_.back(); }

  bool empty() const { return c_.empty(); }

  size_type size() const { return c_.size(); }

  void push(const value_type& value) { return c_.push_back(value); }

  void pop() { c_.pop_back(); }

  iterator begin() { return c_.begin(); }

  iterator end() { return c_.end(); }
};

#endif