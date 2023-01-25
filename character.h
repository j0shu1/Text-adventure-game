#pragma once
class Character
{
protected:
	int _health;
	int _damage;
public:
	int getHealth();
	virtual int getDamage();
	void setDamage(int);
	void setHealth(int);
	void hit(int);
};

class Player : public Character
{
protected:
	int _level;
	int _maxHp;
	void setMaxHp(int);
	void increaseMaxHp(int);
public:
	Player();
	int getMaxHp();
	int getLevel();
	void levelUp();
};

class Enemy : public Character
{
public:
	Enemy();
	void reset(int);
	int getDamage();
};