#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : dataBaseName_(""), inputFileName_("") {}

BitcoinExchange::BitcoinExchange(const std::string& inputFileName)
    : dataBaseName_(DATA_BASE), inputFileName_(inputFileName) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
    : dataBaseName_(DATA_BASE) {
  *this = obj;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
  if (this != &obj) {
    inputFileName_ = obj.inputFileName_;
    dataBase_ = obj.dataBase_;
  }
  return *this;
}

void BitcoinExchange::parseDataBase() {
  std::ifstream file(dataBaseName_);
  if (!file.is_open()) throw std::runtime_error("Error: could not open file.");
  std::string head;
  if (!std::getline(file, head)) throw std::runtime_error("Error: empty file.");
  std::string headCopy = head;
  while (strtrim(headCopy).empty()) {
    if (!std::getline(file, head))
      throw std::runtime_error("Error: empty file.");
    headCopy = head;
  }
  if (head != "date,exchange_rate")
    throw std::runtime_error("Error: invalid head format.");

  std::string line;
  std::string date;
  std::string price;
  double priceD;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::getline(ss, date, ',');
    if (line.empty() || strtrim(line).empty()) {
      continue;
    } else if (isInvalidDate(date)) {
      throw std::runtime_error("Error: invalid data format.");
    } else if (ss.eof()) {
      throw std::runtime_error("Error: invalid data format.");
    }
    std::getline(ss, price);
    if (price.empty() || price[0] < '0' || price[0] > '9')
      throw std::runtime_error("Error: invalid data format.");
    std::istringstream iss(price);
    iss >> priceD;
    if (iss.fail() || !iss.eof()) {
      throw std::runtime_error("Error: invalid data format.");
    } else if (priceD < 0) {
      throw std::runtime_error("Error: not a positive number.");
    } else {
      if (dataBase_.insert(std::pair<std::string, double>(date, priceD))
              .second == false)
        throw std::runtime_error("Error: duplicate date.");
    }
  }
  if (this->dataBase_.empty()) {
    throw std::runtime_error("Error: No data.");
  }
  file.close();
}

void BitcoinExchange::parseInputFile() {
  std::ifstream file(inputFileName_);
  if (!file.is_open()) throw std::runtime_error("Error: could not open file.");
  std::string head;
  if (!std::getline(file, head)) throw std::runtime_error("Error: empty file.");
  std::string headCopy = head;
  while (strtrim(headCopy).empty()) {
    if (!std::getline(file, head))
      throw std::runtime_error("Error: empty file.");
    headCopy = head;
  }
  if (head != "date | value")
    throw std::runtime_error("Error: invalid head format.");

  std::string line;
  std::string lineCopy;
  std::string date;
  std::string value;
  double valueD;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::getline(ss, date, '|');
    lineCopy = line;
    if (lineCopy.empty() || strtrim(lineCopy).empty()) {
      continue;
    } else if (date.size() != 11 || isInvalidDate(strtrim(date))) {
      printOut("Error: bad input => " + line, ERR_MSG);
      continue;
    } else if (ss.eof() || line[10] != ' ' || line[12] != ' ') {
      printOut("Error: bad input => " + line, ERR_MSG);
      continue;
    }
    std::getline(ss, value);
    if (value.size() < 2 || value[0] != ' ' || value[1] < '0' ||
        value[1] > '9') {
      printOut("Error: bad input => " + line, ERR_MSG);
      continue;
    }
    std::istringstream iss(value);
    iss >> valueD;
    if (iss.fail() || !iss.eof()) {
      printOut("Error: bad input => " + line, ERR_MSG);
      iss.clear();
    } else if (valueD <= 0 || valueD >= 1000) {
      printOut("Error: argument range error.", ERR_MSG);
    } else {
      printOut(date, valueD);
    }
  }
  file.close();
}

std::string& BitcoinExchange::strtrim(std::string& str) {
  str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
  str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
  return str;
}

int BitcoinExchange::isInvalidDate(std::string& date) {
  if (date.size() != 10) {
    return 1;
  } else if (date[0] <= '0' || date[0] > '3' || date[1] < '0' ||
             date[1] > '9' || date[2] < '0' || date[2] > '9' || date[3] < '0' ||
             date[3] > '9' || date[4] != '-' || date[5] < '0' ||
             date[5] > '1' || date[6] < '0' || date[6] > '9' ||
             date[7] != '-' || date[8] < '0' || date[8] > '3' ||
             date[9] < '0' || date[9] > '9') {
    return 1;
  }
  // 윤년 체크
  char* year = new char[4];
  char* month = new char[2];
  char* day = new char[2];
  date.copy(year, 4, 0);
  date.copy(month, 2, 5);
  date.copy(day, 2, 8);
  int y = strtol(year, NULL, 10);
  int m = strtol(month, NULL, 10);
  int d = strtol(day, NULL, 10);
  delete[] year;
  delete[] month;
  delete[] day;
  if (d > lastDay(y, m)) {
    return 1;
  } else
    return 0;
}

int BitcoinExchange::lastDay(int y, int m) {
  int mArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int d = mArr[m - 1];
  if (m == 2) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) d = 29;
  }
  return d;
}

void BitcoinExchange::printOut(std::string key, double value) {
  if (value == ERR_MSG) {
    std::cout << key << std::endl;
  } else {
    std::map<std::string, double>::iterator it = dataBase_.lower_bound(key);
    if (dataBase_.find(key) == dataBase_.end()) {
      if (it == dataBase_.begin()) {
        std::cout << "Error: could not find data in dataBase. => " << key
                  << std::endl;
      } else {
        --it;
        std::cout << key << " => " << value << " = " << value * it->second
                  << std::endl;
      }
    } else {
      std::cout << key << " => " << value << " = " << value * dataBase_[key]
                << std::endl;
    }
  }
}