#include "ScalarConverter.hpp"

int detectType(std::string str);
void toChar(std::string str);
void toInt(std::string str);
void toFloat(std::string str);
void toDouble(std::string str);
double checkValue(std::string str);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) { *this = obj; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
  if (this != &obj) {
  }
  return *this;
}

void ScalarConverter::convert(std::string str) {
  if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str + 'f' << std::endl;
    std::cout << "double: " << str << std::endl;
    return;
  } else if (str == "nanf" || str == "inff" || str == "+inff" ||
             str == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << std::endl;
    str = str.substr(0, str.size() - 1);
    std::cout << "double: " << str << std::endl;
    return;
  }
  switch (detectType(str)) {
    case CHAR:
      toChar(str);
      break;
    case INT:
      toInt(str);
      break;
    case FLOAT:
      toFloat(str.substr(0, str.size() - 1));
      break;
    case DOUBLE:
      toDouble(str);
      break;
    default:
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      break;
  }
}

int detectType(std::string str) {
  if (str == "") {
    return CHAR;
  } else if (str.size() == 1) {
    if (str.find_first_of("0123456789") == std::string::npos)
      return CHAR;
    else
      return INT;
  } else if (str.find_first_not_of("0123456789.f-+") == std::string::npos) {
    if (str.find_first_of(".f") == std::string::npos) {
      return INT;
    } else if (str.find_first_of(".") != std::string::npos) {
      if (str.find_first_of("f") == std::string::npos)
        return DOUBLE;
      else if (str.find_first_of("f") == str.size() - 1)
        return FLOAT;
      else
        return -1;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

void toChar(std::string str) {
  char c = static_cast<char>(str[0]);
  std::ostringstream oss;
  oss << "char: ";
  if (c < 32 || c > 126)
    oss << "Non displayable" << std::endl;
  else
    oss << "'" << c << "'" << std::endl;
  oss << "int: " << static_cast<int>(c) << std::endl;
  oss << "float: " << std::fixed << std::setprecision(1)
      << static_cast<float>(c) << "f" << std::endl;
  oss << "double: " << static_cast<double>(c) << std::endl;
  std::cout << oss.str();
}

void toInt(std::string str) {
  std::istringstream iss(str);
  std::ostringstream oss;
  int i = 0;
  iss >> i;
  std::cout << i << std::endl;
  if (!iss.eof() || iss.fail()) {
    oss << "char: impossible" << std::endl;
    oss << "int: impossible" << std::endl;
    oss << "float: impossible" << std::endl;
    oss << "double: impossible" << std::endl;
  } else {
    oss << "char: ";
    if (i > std::numeric_limits<char>::max() ||
        i < std::numeric_limits<char>::min())
      oss << "impossible" << std::endl;
    else if (i < 32 || i > 126)
      oss << "Non displayable" << std::endl;
    else
      oss << "'" << static_cast<char>(i) << "'" << std::endl;
    oss << "int: " << i << std::endl;
    oss << std::fixed << std::setprecision(1);
    oss << "float: " << static_cast<float>(i) << "f" << std::endl;
    oss << "double: " << static_cast<double>(i) << std::endl;
  }
  std::cout << oss.str();
}

void toFloat(std::string str) {
  std::istringstream iss(str);
  std::ostringstream oss;
  float f = 0;
  iss >> f;
  if (!iss.eof() || iss.fail()) {
    oss << "char: impossible" << std::endl;
    oss << "int: impossible" << std::endl;
    oss << "float: impossible" << std::endl;
    oss << "double: impossible" << std::endl;
  } else {
    oss << "char: ";
    if (f > std::numeric_limits<char>::max() ||
        f < std::numeric_limits<char>::min())
      oss << "impossible" << std::endl;
    else if (f < 32 || f > 126)
      oss << "Non displayable" << std::endl;
    else
      oss << "'" << static_cast<char>(f) << "'" << std::endl;
    double val = checkValue(str);
    oss << "int: ";
    if (val > std::numeric_limits<int>::max() ||
        val < std::numeric_limits<int>::min())
      oss << "impossible" << std::endl;
    else
      oss << static_cast<int>(val) << std::endl;
    oss << std::fixed << std::setprecision(1);
    oss << "float: " << f << "f" << std::endl;
    oss << "double: " << static_cast<double>(f) << std::endl;
  }
  std::cout << oss.str();
}

void toDouble(std::string str) {
  std::istringstream iss(str);
  std::ostringstream oss;
  double d = 0;
  iss >> d;
  if (!iss.eof() || iss.fail()) {
    oss << "char: impossible" << std::endl;
    oss << "int: impossible" << std::endl;
    oss << "float: impossible" << std::endl;
    oss << "double: impossible" << std::endl;
  } else {
    oss << "char: ";
    if (d > std::numeric_limits<char>::max() ||
        d < std::numeric_limits<char>::min())
      oss << "impossible" << std::endl;
    else if (d < 32 || d > 126)
      oss << "Non displayable" << std::endl;
    else
      oss << "'" << static_cast<char>(d) << "'" << std::endl;
    oss << "int: ";
    if (d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min())
      oss << "impossible" << std::endl;
    else
      oss << static_cast<int>(d) << std::endl;
    oss << std::fixed << std::setprecision(1);
    oss << "float: " << static_cast<float>(d) << "f" << std::endl;
    oss << "double: " << d << std::endl;
  }
  std::cout << oss.str();
}

double checkValue(std::string str) {
  std::istringstream iss(str);
  double d = 0;
  iss >> d;
  return d;
}