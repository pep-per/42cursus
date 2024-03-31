#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define INV_SIZE 4
#define MAX_GARBAGE 100

class MateriaSource : public IMateriaSource {
 private:
  AMateria* materiaTemplate_[INV_SIZE];
  int templateCount_;
  AMateria** garbageColletor_;
  int garbageCount_;
  int garbageSize_;

 public:
  MateriaSource();
  MateriaSource(const MateriaSource& obj);
  virtual ~MateriaSource();
  MateriaSource& operator=(const MateriaSource& obj);
  virtual void learnMateria(AMateria* obj);
  virtual AMateria* createMateria(std::string const& type);
  void collectGarbage(AMateria* garbage);
  int isInGarbage(AMateria* m);
};

#endif