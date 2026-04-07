#include "recommendation.h"
#include "token.h"
#include "graph.h"

int main()
{
    // Users
    User u1(1,"Mayank",21,"Delhi",{"coding","gym","music"},10);
    User u2(2,"Rahul",22,"Delhi",{"coding","sports"},10);
    User u3(3,"Aman",20,"Mumbai",{"gaming","coding"},10);
    User u4(4,"Riya",21,"Delhi",{"music","coding"},10);

    vector<User> users = {u1,u2,u3,u4};

    Graph g;

    cout << "\n--- USER PROFILE ---\n";
    u1.display();

    cout << "\n--- RECOMMENDATIONS ---\n";

    vector<User> rec = recommendUsers(u1, users, 3);

    for(auto &u : rec)
    {
        if(deductToken(u1, 1))
        {
            cout << "Recommended: " << u.name << endl;
        }
    }

    cout << "\nTokens left: " << u1.tokens << endl;

    cout << "\n--- SEND REQUEST ---\n";

    if(deductToken(u1, 2))
    {
        g.addFriend(u1.id, u4.id);
        mutualMatchReward(u1, u4);

        cout << "Friend added: " << u4.name << endl;
    }

    cout << "\n--- FRIEND LIST ---\n";
    g.showFriends(u1.id);

    cout << "\n--- MUTUAL FRIENDS ---\n";

    vector<int> mutual = g.getMutualFriends(u1.id);

    for(auto &m : mutual)
        cout << "Mutual Friend ID: " << m << endl;

    cout << "\n--- DAILY LOGIN ---\n";
    dailyLoginReward(u1);

    cout << "Tokens now: " << u1.tokens << endl;

    cout << "\n--- WEEKLY RESET ---\n";
    weeklyReset(u1);

    cout << "Final tokens: " << u1.tokens << endl;

    return 0;
}
