#pragma once
#include <string>
class director
{
public:
	void StartGame();
private:
	void DoInput();
	void DoUpdate();
	void DoOutput();
	void print(std::string, bool);
	std::string input(std::string);
};