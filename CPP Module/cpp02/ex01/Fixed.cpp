#include "Fixed.hpp"

const int Fixed::fraction_ = 8;

Fixed::Fixed() : exponent_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : exponent_(0) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : exponent_(0) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->exponent_ = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->exponent_;
}

void Fixed::setRawBits(int const raw) { this->exponent_ = raw; }

float Fixed::toFloat() const {}

int Fixed::toInt() const {}