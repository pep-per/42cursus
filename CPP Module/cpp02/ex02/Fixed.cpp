#include "Fixed.hpp"

const int Fixed::numOfFractionBits_ = 8;

Fixed::Fixed() : rawBits_(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : rawBits_(0) {
  // std::cout << "Int constructor called" << std::endl;
  setRawBits(num << numOfFractionBits_);
}

Fixed::Fixed(const float num) : rawBits_(0) {
  // std::cout << "Float constructor called" << std::endl;
  setRawBits(roundf(num * (1 << numOfFractionBits_)));
}

Fixed::Fixed(const Fixed &fixed) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() { /*std::cout << "Destructor called" << std::endl;*/
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  // std::cout << "Copy assignment operator called" << std::endl;
  this->rawBits_ = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const { return this->rawBits_; }

void Fixed::setRawBits(int const raw) { this->rawBits_ = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << numOfFractionBits_);
}

int Fixed::toInt() const { return roundf(toFloat()); }

bool Fixed::operator>(const Fixed &fixed) const {
  return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
  return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
  return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return this->getRawBits() != fixed.getRawBits();
}

Fixed &Fixed::operator++(void) {
  this->rawBits_++;
  return *this;
}

const Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->rawBits_++;
  return tmp;
}

Fixed &Fixed::operator--(void) {
  this->rawBits_--;
  return *this;
}

const Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->rawBits_--;
  return tmp;
}

Fixed Fixed::operator+(const Fixed &a) const {
  return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed Fixed::operator-(const Fixed &a) const {
  return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed Fixed::operator*(const Fixed &a) const {
  return (Fixed(this->toFloat() * a.toFloat()));
}

Fixed Fixed::operator/(const Fixed &a) const {
  return (Fixed(this->toFloat() / a.toFloat()));
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a >= b)
    return a;
  else
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a >= b)
    return a;
  else
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a <= b)
    return a;
  else
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a <= b)
    return a;
  else
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}