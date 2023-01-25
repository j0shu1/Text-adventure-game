#include "pch.h"
#include "director.h"
#include "character.h"
#include <iostream>
#include <string>

bool isPlaying = true;
std::string action;
Player player = Player();
Enemy enemy = Enemy();

void director::print(std::string toPrint, bool useEndl = true)
{
	if (useEndl)
	{
		std::cout << toPrint << std::endl;
	}
	else
	{
		std::cout << toPrint;
	}
}

std::string director::input(std::string prompt)
{
	std::string response;
	std::cout << prompt;
	std::cin >> response;
	return response;
}


void director::StartGame()
{
	while (isPlaying)
	{
		DoInput();
		DoUpdate();
		DoOutput();
	}
}

void director::DoInput()
{
	action = input("Enter your action (hit): ");
}

void director::DoUpdate()
{
	if (action == "hit")
	{
		enemy.hit(player.getDamage());
		player.hit(enemy.getDamage());
	}
}

void director::DoOutput()
{
	if (action == "hit")
	{
		if (enemy.getHealth() > 0)
		{
			print("Enemy hit! Enemy hitpoints: ", false);
			print(std::to_string(enemy.getHealth()));

			print("Enemy hit you! Your health is now ", false);
			print(std::to_string(player.getHealth()));
		}
		else
		{
			print("Enemy defeated!");
		}

		print("");
	}
	if (enemy.getHealth() <= 0)
	{
		print("You leveled up to level ", false);
		print(std::to_string(player.getLevel() + 1) + "\n");

		enemy.reset(player.getLevel());
		player.levelUp();
	}
	else if (player.getHealth() <= 0)
	{
		print("You died! ");
		print("You made it to level ", false);
		print(std::to_string(player.getLevel()));
		print("Game over.");
		isPlaying = false;
	}
}