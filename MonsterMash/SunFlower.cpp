#include "SunFlower.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>

SunFlower::SunFlower()
{
	m_name = "Killer Flower";
	m_maxHealth = m_health = 115;
}

void SunFlower::Update(TargetList& targetList)
{
	if (targetList.size() > 0)
	{
		if (m_health >= 40)
		{
			Creature* target = targetList[rand() % targetList.size()];
			while (true)
			{
				if (target->GetHealth() <= 0)
				{
					Creature* target = targetList[rand() % targetList.size()];
				}
				else
				{
					break;
				}
			}
			if (target != this)
			{
				int numberOfTimes = rand() % 15 + 3;
				std::cout << "PETAL SPRAY!!\n";
				for (size_t i = 0; i < numberOfTimes; i++)
				{
					std::cout << " Pew Pew " << target->GetName() << " got hit...\n";
					target->ApplyDamage(this, { 5, DamageType::RANGED, Element::NONE });
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

			}
		}
		else
		{
			m_health += 40;
			std::cout << m_name << " has just healed 40 health. It now has "<< m_health << " health left.\n" ;
		}
		
	}
}

void SunFlower::ApplyDamage(Creature* attacker, const DamageInfo& info)
{
	if (info.amount > 50)
	{
		std::cout << m_name << " is so bright that it put the attacker off, and made it do less damage.\n\n";
		DamageInfo info2(info);
		info2.amount /= 2;
		Creature::ApplyDamage(attacker, info2);
	}
	else
	{
		Creature::ApplyDamage(attacker, info);
	}
}

SunFlower::~SunFlower()
{
}
