#include "pch.h"
#include <iostream>
#include "director.h"

using namespace winrt;
using namespace Windows::Foundation;

director gameDirector = director();
int main()
{
    gameDirector.StartGame();
}
