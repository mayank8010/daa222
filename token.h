#ifndef TOKEN_H
#define TOKEN_H

#include "user.h"

// Check if user has enough tokens
bool hasEnoughTokens(User &u, int cost)
{
    return (u.tokens >= cost);
}

// Deduct tokens
bool deductToken(User &u, int cost)
{
    if(hasEnoughTokens(u, cost))
    {
        u.tokens -= cost;
        return true;
    }
    else
    {
        cout << "Insufficient tokens for user: " << u.name << "\n";
        return false;
    }
}

// Add tokens
void addToken(User &u, int amount)
{
    u.tokens += amount;
}

// Daily reward
void dailyLoginReward(User &u)
{
    cout << "Daily login reward given to " << u.name << "\n";
    addToken(u, 2);
}

// Mutual match reward
void mutualMatchReward(User &u1, User &u2)
{
    cout << "Mutual match reward given\n";
    addToken(u1, 3);
    addToken(u2, 3);
}

// Weekly reset logic
void weeklyReset(User &u)
{
    if(u.tokens < 5)
    {
        cout << "Weekly reset applied\n";
        u.tokens = 5;
    }
}

#endif
