#include "ScavTrap.hpp"


int main()
{
	ScavTrap *a = new ScavTrap("1");

	a->attack("2");
	a->guardGate();
	a->takeDamage(10);

	ScavTrap *b = new ScavTrap(*a);
	b->attack("3");
	b->guardGate();
	b->takeDamage(30);
	b->beRepaired(10);

	a->takeDamage(10);

	ScavTrap t;
	t = *a;

	a->takeDamage(10);
	t.takeDamage(10);

	t = t;
	t.takeDamage(10);
	a->takeDamage(10);
	delete b;
	delete a;

}