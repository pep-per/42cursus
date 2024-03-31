#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < INV_SIZE; i++) {
    this->materiaTemplate_[i] = NULL;
  }
  this->templateCount_ = 0;
  this->garbageSize_ = MAX_GARBAGE;
  this->garbageCount_ = 0;
  this->garbageColletor_ = new AMateria*[this->garbageSize_];
  for (int i = 0; i < this->garbageSize_; i++) {
    this->garbageColletor_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
  for (int i = 0; i < obj.templateCount_; i++) {
    this->materiaTemplate_[i] = obj.materiaTemplate_[i]->clone();
  }
  this->templateCount_ = obj.templateCount_;
  this->garbageSize_ = MAX_GARBAGE;
  this->garbageCount_ = 0;
  this->garbageColletor_ = new AMateria*[this->garbageSize_];
  for (int i = 0; i < this->garbageSize_; i++) {
    this->garbageColletor_[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < this->templateCount_; i++) {
    delete this->materiaTemplate_[i];
  }
  for (int i = 0; i < this->garbageSize_; i++) {
    if (this->garbageColletor_[i] != NULL) {
      delete this->garbageColletor_[i];
    }
  }
  delete[] this->garbageColletor_;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
  if (this != &obj) {
    for (int i = 0; i < this->templateCount_; i++) {
      delete this->materiaTemplate_[i];
      this->materiaTemplate_[i] = NULL;
    }
    for (int i = 0; i < obj.templateCount_; i++) {
      this->materiaTemplate_[i] = obj.materiaTemplate_[i]->clone();
    }
    this->templateCount_ = obj.templateCount_;
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* obj) {
  if (obj == NULL) {
    std::cout << "Invalid materia" << std::endl;
  } else if (templateCount_ < 4) {
    this->materiaTemplate_[templateCount_++] = obj;
  } else {
    std::cout << "already learned 4 Materias" << std::endl;
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  if (this->templateCount_ == 0) {
    std::cout << "No materia learned" << std::endl;
    return 0;
  }
  for (int i = 0; i < templateCount_; i++) {
    if (this->materiaTemplate_[i]->getType() == type) {
      AMateria* clone = this->materiaTemplate_[i]->clone();
      clone->saveSource(this);
      return clone;
    }
  }
  std::cout << "Unknown type: " << type << std::endl;
  return 0;
}

void MateriaSource::collectGarbage(AMateria* garbage) {
  for (int i = 0; i < this->garbageSize_; i++) {
    if (this->garbageColletor_[i] == garbage) {
      return;
    }
  }
  if (this->garbageCount_ < this->garbageSize_) {
    this->garbageColletor_[this->garbageCount_++] = garbage;
  } else {
    AMateria** newGarbage = new AMateria*[MAX_GARBAGE * 2];
    for (int i = 0; i < this->garbageSize_; i++) {
      newGarbage[i] = this->garbageColletor_[i];
    }
    for (int i = this->garbageCount_; i < MAX_GARBAGE * 2; i++) {
      newGarbage[i] = NULL;
    }
    newGarbage[this->garbageCount_++] = garbage;
    this->garbageSize_ = MAX_GARBAGE * 2;
    delete[] this->garbageColletor_;
    this->garbageColletor_ = newGarbage;
  }
}

int MateriaSource::isInGarbage(AMateria* m) {
  for (int i = 0; i < this->garbageSize_; i++) {
    if (this->garbageColletor_[i] == m) {
      return 1;
    }
  }
  return 0;
}