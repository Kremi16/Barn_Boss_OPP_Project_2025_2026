#pragma once
#include"User.h"
#include<vector>
#include<memory>

class ScoreBoard
{
public:
	void showScoreboard(const vector<shared_ptr<User>>& users) const;
};

