#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#define ERR_MSG -1
#define DATA_BASE "data.csv"

class BitcoinExchange {
 private:
  const std::string dataBaseName_;
  std::string inputFileName_;
  std::map<std::string, double> dataBase_;
  BitcoinExchange();

 public:
  BitcoinExchange(const std::string& inputFile);
  BitcoinExchange(const BitcoinExchange& obj);
  ~BitcoinExchange();
  BitcoinExchange& operator=(const BitcoinExchange& obj);
  void parseDataBase();
  void parseInputFile();
  void printOut(std::string key, double value);
  std::string& strtrim(std::string& str);
  int isInvalidDate(std::string& date);
  int lastDay(int y, int m);
};

#endif