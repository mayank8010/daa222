#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

struct User {
    int id;
    string name;
    int age;
    string location;
    unordered_set<string> interests;
    int tokens;

    // Constructor
    User() {}

    User(int id, string name, int age, string location,
         vector<string> intr, int tokens)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->location = location;
        this->tokens = tokens;

        for(auto &i : intr)
            interests.insert(i);
    }

    // Display user info
    void display()
    {
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Location: " << location << "\n";
        cout << "Interests: ";

        for(auto &i : interests)
            cout << i << " ";

        cout << "\nTokens: " << tokens << "\n\n";
    }

    // Add interest
    void addInterest(string interest)
    {
        interests.insert(interest);
    }

    // Remove interest
    void removeInterest(string interest)
    {
        if(interests.count(interest))
            interests.erase(interest);
    }
};

#endif
