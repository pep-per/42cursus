#include "Character.hpp"

Character::Character() : name_("Nobody"), inventoryCount_(0) {
  for (int i = 0; i < INV_SIZE; i++) {
    this->inventory_[i] = NULL;
  }
}

Character::Character(const std::string& name)
    : name_(name), inventoryCount_(0) {
  for (int i = 0; i < INV_SIZE; i++) {
    this->inventory_[i] = NULL;
  }
}

Character::Character(const Character& obj) { *this = obj; }

Character::~Character() {
  for (int i = 0; i < INV_SIZE; i++) {
    if (this->inventory_[i] != NULL) {
      delete this->inventory_[i];
    }
  }
}

Character& Character::operator=(const Character& obj) {
  if (this != &obj) {
    for (int i = 0; i < INV_SIZE; i++) {
      if (this->inventory_[i] != NULL) {
        delete this->inventory_[i];
        this->inventory_[i] = NULL;
      }
    }
    for (int i = 0; i < INV_SIZE; i++) {
      if (obj.inventory_[i] != NULL)
        this->inventory_[i] = obj.inventory_[i]->clone();
    }
    this->name_ = obj.name_;
    this->inventoryCount_ = obj.inventoryCount_;
  }
  return *this;
}

std::string const& Character::getName() const { return this->name_; }

void Character::equip(AMateria* m) {
  if (m == NULL) {
    throw std::runtime_error("Invalid materia");
  } else if (m->getSource() == NULL) {
    delete m;
    throw std::runtime_error("Invalid materia");
  } else if (m->getSource()->isInGarbage(m)) {
    throw std::runtime_error("Invalid materia. It is in garbage");
  } else if (this->inventoryCount_ < INV_SIZE) {
    for (int i = 0; i < INV_SIZE; i++) {
      if (this->inventory_[i] == m) {
        std::cout << "Materia already equipped" << std::endl;
        return;
      }
    }
    int idx = findEmptySlot();
    if (idx != INV_EMPTY) {
      this->inventory_[idx] = m;
      this->inventoryCount_++;
    }
  } else {
    m->getSource()->collectGarbage(m);
    std::cout << "Inventory is full. Materia discarded" << std::endl;
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    if (this->inventory_[idx] != NULL) {
      this->inventory_[idx]->getSource()->collectGarbage(this->inventory_[idx]);
      this->inventory_[idx] = NULL;
      this->inventoryCount_--;
    } else {
      std::cout << "No materia in this slot" << std::endl;
    }
  } else {
    std::cout << "Invalid inventory index" << std::endl;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4) {
    if (this->inventory_[idx] != NULL) {
      this->inventory_[idx]->use(target);
    } else {
      std::cout << "No materia in this slot" << std::endl;
    }
  } else {
    std::cout << "Invalid inventory index" << std::endl;
  }
}

int Character::findEmptySlot() {
  for (int i = 0; i < INV_SIZE; i++) {
    if (this->inventory_[i] == NULL) {
      return i;
    }
  }
  return INV_EMPTY;
}