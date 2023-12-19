#ifndef REPLACER_H
#define REPLACER_H

#include <fstream>
#include <iostream>

class Replacer {
 private:
  // std::ifstream in_;
  // std::ofstream out_;
  std::string filename_;
  std::string s1_;
  std::string s2_;
  // int pos_;

 public:
  Replacer(std::string filename, std::string s1, std::string s2);
  void newFile();
  ~Replacer();
};

#endif