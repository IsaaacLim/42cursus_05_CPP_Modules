#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void clap_trap(void)
{
	std::cout << "=============== ClapTrap ===============" << std::endl;

	ClapTrap ct_p1("CT_PLAYER1");

	ct_p1.attack("ENEMY1");
	ct_p1.takeDamage(5);
	ct_p1.beRepaired(2);

	ClapTrap ct_p2(ct_p1);
	ct_p2.setName("CT_PLAYER2");
	ct_p2.takeDamage(3);

	std::cout << "HitPoints remaining: CT_PLAYER1(" << ct_p1.getHitPoints() << ") CT_PLAYER2(";
	std::cout << ct_p2.getHitPoints() << ")" << std::endl;
}

void scav_trap(void)
{
	std::cout << "\n=============== ScavTrap ===============" << std::endl;
	ScavTrap st_p1("ST_PLAYER1");
	st_p1.attack("ENEMY1");
	st_p1.takeDamage(6);
	st_p1.beRepaired(4);

	ScavTrap st_p2(st_p1);
	st_p2.setName("ST_PLAYER2");
	st_p2.takeDamage(10);
	st_p2.guardGate();

	std::cout << "HitPoints remaining: ST_PLAYER1(" << st_p1.getHitPoints() << ") ST_PLAYER2(";
	std::cout << st_p2.getHitPoints() << ")" << std::endl;
}

void frag_trap(void)
{
	std::cout << "\n=============== FragTrap ===============" << std::endl;
	FragTrap ft_p1("FT_PLAYER1");
	ft_p1.attack("ENEMY1");
	ft_p1.takeDamage(20);
	ft_p1.beRepaired(33);

	FragTrap ft_p2(ft_p1);
	ft_p2.setName("FT_PLAYER2");
	ft_p2.takeDamage(100);
	ft_p2.highFivesGuys();

	std::cout << "HitPoints remaining: FT_PLAYER1(" << ft_p1.getHitPoints() << ") FT_PLAYER2(";
	std::cout << ft_p2.getHitPoints() << ")" << std::endl;
}

int main(void)
{
	clap_trap();
	scav_trap();
	frag_trap();

	std::cout << "\n=============== DiamondTrap ===============" << std::endl;
	DiamondTrap *dt_p1 = new DiamondTrap("DT_PLAYER1");
	dt_p1->whoAmI();
	dt_p1->attack("ENEMY1");
	dt_p1->guardGate();
	dt_p1->highFivesGuys();
	delete dt_p1;

	DiamondTrap dt_p2("DT_PLAYER2");
	dt_p2.whoAmI();
	dt_p2.attack("ENEMY1");

	return 0;
}
