#pragma once
#include"System.h"
#include<fstream>

class GameSerializer
{
public:
	static void save(const System& system, const string& filename);
	static void load(System& system, const string& filename);
};

