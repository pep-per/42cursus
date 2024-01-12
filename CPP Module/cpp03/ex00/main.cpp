#include "ClapTrap.hpp"

int main() {
  ClapTrap robot1("Robot1");
  robot1.attack("Enemy1");
  robot1.attack("Enemy2");
  robot1.attack("Enemy3");
  robot1.attack("Enemy4");
  robot1.attack("Enemy5");
  robot1.attack("Enemy6");
  robot1.attack("Enemy7");
  robot1.attack("Enemy8");
  robot1.attack("Enemy9");
  robot1.attack("Enemy10");
  robot1.attack("Enemy11");

  ClapTrap robot2("Robot2");
  robot2.takeDamage(2);
  robot2.takeDamage(3);
  robot2.takeDamage(1);
  robot2.takeDamage(5);
  robot2.takeDamage(2);
  robot2.beRepaired(5);

  ClapTrap robot3("Robot3");
  robot3.beRepaired(5);
  robot3.beRepaired(3);
  robot3.beRepaired(12);
  robot3.beRepaired(100);
  robot3 = robot2;
  robot3.attack("Enemy12");
  return 0;
}
