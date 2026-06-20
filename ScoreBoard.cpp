#include "ScoreBoard.h"
#include"Player.h"
#include<print>
#include<algorithm>
#include<iostream>

void ScoreBoard::showScoreboard(const vector<shared_ptr<User>>& users) const
{
    vector<Player*> players;

    for (const auto& user : users) 
    {
        if (user->getType() == UserType::Player)
        {
            players.push_back(static_cast<Player*>(user.get()));
        }
    }

    sort(players.begin(), players.end(),
        [](const Player* a, const Player* b) 
        {
            if (a->checkScore() != b->checkScore())
            {
                return a->checkScore() > b->checkScore();
            }
            if (a->checkBalance() != b->checkBalance())
            {
                return a->checkBalance() > b->checkBalance();
            }
            return a->getId() < b->getId();
        });

    cout << "=== SCOREBOARD ===\n";
    unsigned rank = 1;
    for (const auto p : players) 
    {
        println("{}. {} | Score: {} | Balance: {}", rank++, p->getUsername(), 
            p->checkScore(), p->checkBalance());
    }
}
