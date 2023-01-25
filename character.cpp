#include "pch.h"
#include "character.h"


// CHARACTER CLASS METHODS
int Character::getHealth()
{
	return _health;
}
int Character::getDamage()
{
	srand((unsigned)time(NULL));
	return rand() % _damage + 1;
}
void Character::setHealth(int number)
{
	_health = number;
}
void Character::setDamage(int number)
{
	_damage = number;
}
void Character::hit(int number)
{
	_health -= number;
}


// Player constuctor
Player::Player() : Character()
{
	_maxHp = 13;
	_health = _maxHp;
	_damage = 3;
	_level = 1;
}

// Enemy constructor
Enemy::Enemy() : Character()
{
	_health = 10;
	_damage = 2;
}


// PLAYER METHODS
int Player::getMaxHp()
{
	return _maxHp;
}

int Player::getLevel()
{
	return _level;
}

void Player::setMaxHp(int newMaxHp)
{
	this->_maxHp = newMaxHp;
}

void Player::increaseMaxHp(int increase)
{
	this->_maxHp += increase;
}

void Player::levelUp()
{
	_level++;
	this->increaseMaxHp(2);
	this->setHealth(_maxHp);
	_damage += 1;
}

// ENEMY METHODS
void Enemy::reset(int playerLevel)
{
	srand((unsigned) time(NULL));
	setHealth(rand() % (10 * playerLevel) + 10);
	setDamage((rand() % playerLevel) + 4);
}
// Override getDamage() from Character class
int Enemy::getDamage()
{
	srand((unsigned)time(NULL));
	return ((rand() % _damage) + (rand() % _damage)) / 2;
}
