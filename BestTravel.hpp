#pragma once
#include <vector>
#include <set>
#include <iostream>

using std::vector;
using std::set;
using std::cout;


class BestTravel
{
    public:
        BestTravel(int target,  int townsVisited, vector<int>& distances);
        ~BestTravel();

        vector<vector<int> > allSubsets(vector<int> distances);
        void fillSubsetsWithSets(vector<int>& distances, set<vector<int> >& subsets, vector<int> subset, int i);
        void caclulateResult(int target,  int townsVisited, vector<int>& distances);
        bool entryValid(int townsVisited, int size);
        bool isBestSum(int target, int i, int townsVisited);
        bool initialEntry(int i, int townsVisited);
        void resetSubsetSum();
        void sumSubset(int i, int j);
        vector<vector<int> > fromSetToVector(set<vector<int> > subsets);

        void printBestSum();
        int getBestSum() const;
    private:
        BestTravel();
        int _bestSum;
        vector<vector<int> > _subsets;
        int _sumOfValuesInSubset;
};