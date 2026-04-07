#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "user.h"

// Calculate Jaccard Similarity
double jaccardSimilarity(const unordered_set<string>& a,
                         const unordered_set<string>& b)
{
    int intersection = 0;

    for(auto &x : a)
    {
        if(b.count(x))
            intersection++;
    }

    int unionSize = a.size() + b.size() - intersection;

    if(unionSize == 0)
        return 0;

    return (double)intersection / unionSize;
}

// Age similarity
double ageSimilarity(int age1, int age2)
{
    int diff = abs(age1 - age2);

    // Normalize age difference
    return 1.0 / (1 + diff);
}

// Location similarity
double locationSimilarity(string loc1, string loc2)
{
    if(loc1 == loc2)
        return 1.0;
    else
        return 0.0;
}

// Final weighted score
double calculateScore(User &u1, User &u2)
{
    double interestWeight = 0.6;
    double locationWeight = 0.2;
    double ageWeight = 0.2;

    double interestScore = jaccardSimilarity(u1.interests, u2.interests);
    double locScore = locationSimilarity(u1.location, u2.location);
    double ageScore = ageSimilarity(u1.age, u2.age);

    double finalScore =
        (interestWeight * interestScore) +
        (locationWeight * locScore) +
        (ageWeight * ageScore);

    return finalScore;
}

#endif
