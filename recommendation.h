#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "similarity.h"

// Max heap comparator
struct Compare {
    bool operator()(pair<double, User> &a, pair<double, User> &b)
    {
        return a.first < b.first;
    }
};

// Top K recommendation
vector<User> recommendUsers(User &current,
                            vector<User> &users,
                            int k)
{
    priority_queue<pair<double, User>,
                   vector<pair<double, User>>,
                   Compare> pq;

    for(auto &u : users)
    {
        if(u.id == current.id) continue;

        double score = calculateScore(current, u);
        pq.push({score, u});
    }

    vector<User> result;

    while(k-- && !pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

#endif
