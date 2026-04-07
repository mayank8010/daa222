#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adj;

    // Add friendship
    void addFriend(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Show friends
    void showFriends(int u)
    {
        cout << "Friends of user " << u << ": ";

        for(auto &f : adj[u])
            cout << f << " ";

        cout << endl;
    }

    // BFS for mutual friends
    vector<int> getMutualFriends(int u)
    {
        vector<int> result;
        unordered_set<int> visited;
        queue<int> q;

        q.push(u);
        visited.insert(u);

        int level = 0;

        while(!q.empty() && level <= 2)
        {
            int size = q.size();

            while(size--)
            {
                int curr = q.front();
                q.pop();

                for(auto &nbr : adj[curr])
                {
                    if(!visited.count(nbr))
                    {
                        visited.insert(nbr);
                        q.push(nbr);

                        if(level == 1)
                            result.push_back(nbr);
                    }
                }
            }
            level++;
        }

        return result;
    }
};

#endif
