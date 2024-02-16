template <typename T>
Array<T>::Array() : arr_(0), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(const Array& obj) : arr_(new T[obj.size()]) {
  *this = obj;
}

template <typename T>
Array<T>::~Array() {
  delete[] arr_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
  if (this != &obj) {
    delete[] arr_;
    arr_ = new T[obj.size()];
    for (unsigned int i = 0; i < obj.size(); i++) {
      arr_[i] = obj[i];
    }
    this->size_ = obj.size();
  }
  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n) {
  if (n >= this->size_) {
    throw std::out_of_range("Index out of range");
  } else {
    return arr_[n];
  }
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const {
  if (n >= this->size_) {
    throw std::out_of_range("Index out of range");
  } else {
    return arr_[n];
  }
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->size_;
}
