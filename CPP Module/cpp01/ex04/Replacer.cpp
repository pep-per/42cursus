#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
    : filename_(filename), s1_(s1), s2_(s2) {}

Replacer::~Replacer() {}

void Replacer::newFile() {
  std::ifstream in(filename_);
  if (s1_.empty()) {
    std::cout << "Empty string cannot be replaced" << std::endl;
    return;
  } else if (!in.is_open()) {
    std::cout << "File missing or not authorized" << std::endl;
    return;
  }
  std::string buf;
  std::string newFile = filename_.append(".replace");
  std::ofstream out(newFile);
  size_t pos = 0;
  while (in) {
    getline(in, buf);
    while (1) {
      pos = buf.find(s1_, pos);
      if (pos == std::string::npos) break;
      buf.erase(pos, s1_.size());
      buf.insert(pos, s2_);
      pos += s2_.size();
    }
    if (!in) return;
    out << buf << std::endl;
    pos = 0;
  }
}
