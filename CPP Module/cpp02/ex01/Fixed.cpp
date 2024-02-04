#include "Fixed.hpp"

const int Fixed::numOfFractionBits_ = 8;

Fixed::Fixed() : rawBits_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : rawBits_(0) {
  std::cout << "Int constructor called" << std::endl;
  setRawBits(num << numOfFractionBits_);
}

Fixed::Fixed(const float num) : rawBits_(0) {
  std::cout << "Float constructor called" << std::endl;
  setRawBits(roundf(num * (1 << numOfFractionBits_)));
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->rawBits_ = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const { return this->rawBits_; }

void Fixed::setRawBits(int const raw) { this->rawBits_ = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << numOfFractionBits_);
}

int Fixed::toInt() const { return roundf(toFloat()); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << static_cast<float>(fixed.getRawBits()) / (1 << 8);
  return out;
}