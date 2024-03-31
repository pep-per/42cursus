#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void check() { system("leaks ex03"); }

int main() {
  // atexit(check);
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  std::cout << std::endl
            << "======================= MY TEST ======================="
            << std::endl;
  try {
    for (int i = 0; i < 5; i++) {
      me->use(i, *bob);
    }
    for (int i = 0; i < 104; i++) {
      me->equip(src->createMateria("ice"));
      me->unequip(2);
    }
    std::cout << std::endl
              << "================ Full Inventory Error ================"
              << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));  // full
    AMateria* tmp1 = src->createMateria("ice");
    me->equip(tmp1);  // full
    me->equip(tmp1);  // invalid
    // me->unequip(3);
    // me->equip(tmp1);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl
            << "========= Materia without MateriaSource Error ========="
            << std::endl;
  try {
    me->equip(new Ice());
    me->use(2, *bob);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl
            << "================== Null Pointer Error =================="
            << std::endl;
  try {
    me->equip(NULL);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl
            << "================= Unequip Errror ================="
            << std::endl;
  try {
    me->unequip(5);
    me->unequip(0);  // Should be empty
    me->unequip(0);  // No materia in this slot
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl
            << "================= MateriaSource Error ================="
            << std::endl;
  IMateriaSource* src1 = new MateriaSource();
  AMateria* tmp3 = src1->createMateria("cure");  // Not learned
  src1->learnMateria(new Ice());
  tmp3 = src1->createMateria("ce");  // Unknown type

  delete src1;
  delete tmp3;

  delete bob;
  delete me;
  delete src;

  return 0;
}