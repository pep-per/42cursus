#include "ScavTrap.hpp"

int main() {
  ScavTrap robot1("Robot1");
  robot1.attack("Enemy1");

  ScavTrap robot2("Robot2");
  robot2.takeDamage(50);
  robot2.attack("Enemy2");
  robot2.beRepaired(100);
  robot2.attack("Robot1");
  robot1.takeDamage(200);
  robot1.beRepaired(200);
  robot1.attack("Enemy3");

  ScavTrap robot3("Robot3");
  robot3.guardGate();
  return 0;
}
