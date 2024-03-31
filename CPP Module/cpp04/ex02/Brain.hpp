#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain();
  Brain(const Brain& obj);
  ~Brain();
  Brain& operator=(const Brain& obj);
  const std::string& getIdeas() const;
  void setIdeas(const std::string& str);
};

#endif