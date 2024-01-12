#include "DiamondTrap.hpp"

int main() {
  DiamondTrap robot1("Robot1");
  robot1.attack("Enemy1");

  DiamondTrap robot2("Robot2");
  robot2.takeDamage(50);
  robot2.attack("Enemy2");
  robot2.beRepaired(100);
  robot2.attack("Robot1");
  robot1.takeDamage(200);
  robot1.beRepaired(200);
  robot1.attack("Enemy3");

  DiamondTrap robot3("Robot3");
  robot3.whoAmI();
  robot3.guardGate();
  robot3.highFivesGuys();

  robot3 = robot1;
  robot3.whoAmI();
  std::string hello[100];

  hello[0] = "hello";
  return 0;
}
