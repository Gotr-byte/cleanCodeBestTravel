#include "BestTravel.hpp"

BestTravel::BestTravel(int target,  int townsVisited, vector<int>& distances):_bestSum(-1), _sumOfValuesInSubset(0)
{
    _subsets = allSubsets(distances);
    if (entryValid(townsVisited, distances.size()))
    {
        caclulateResult(target, townsVisited, distances);
    }
}
BestTravel::~BestTravel(){}

vector<vector<int> > BestTravel::allSubsets(vector<int> distances)
{
    set<vector<int> > subsets;
    vector<int> subset;

    sort(distances.begin(), distances.end());
    fillSubsets(distances,  subsets, subset, 0);
    return (fromSetToVector(subsets));
}

void BestTravel::caclulateResult(int target,  int townsVisited, vector<int>& distances)
{
  
    for (int i = 0; i < _subsets.size(); i++) {
        for (int j = 0; j < _subsets[i].size(); j++)
        {
            sumSubset(i, j);
        }
        if (initialEntry(i, townsVisited))
        {
            _bestSum = _sumOfValuesInSubset;
        }
        else if(isBestSum(target, i, townsVisited))
        {
            _bestSum = _sumOfValuesInSubset;
        }
        resetSumSubset();
    }
}

vector<vector<int> > BestTravel::fromSetToVector(set<vector<int> > subsets)
{
    vector<vector<int> > subsetsToSend;
    while (!subsets.empty())
    {
        subsetsToSend.push_back(*subsets.begin());
        subsets.erase(subsets.begin());
    }
    return(subsetsToSend);
}

bool BestTravel::entryValid(int townsVisited, int size)
{
    return(townsVisited <= size);
}

void BestTravel::fillSubsets(vector<int>& distances,
           set<vector<int> >& subsets,
           vector<int> subset, int i)
{
    if (i >= distances.size())
    {
        subsets.insert(subset);
        return;
    }
    fillSubsets(distances, subsets, subset, i + 1);
    subset.push_back(distances[i]);
    fillSubsets(distances, subsets, subset, i + 1);
}

void BestTravel::sumSubset(int i, int j)
{
    _sumOfValuesInSubset = _sumOfValuesInSubset + _subsets[i][j];
}

void BestTravel::resetSumSubset()
{
    _sumOfValuesInSubset = 0;
}  

bool BestTravel::initialEntry(int i, int townsVisited)
{
    return(i == 0 && _subsets[i].size() == townsVisited);
}

bool BestTravel::isBestSum(int target, int i, int townsVisited)
{
    return (_sumOfValuesInSubset < target && _sumOfValuesInSubset > _bestSum && _subsets[i].size() == townsVisited);
}


int BestTravel::getBestSum()const
{
    return (_bestSum);
}

void BestTravel::printBestSum()
{
    cout << "Best sum equals: " << _bestSum << "\n";
}