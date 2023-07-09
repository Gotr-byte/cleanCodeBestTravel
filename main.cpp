#include "BestTravel.hpp"

int findBestSum(int target, int townsVisited, vector<int>distances){
    BestTravel agency = BestTravel(target, townsVisited, distances);
    return(agency.getBestSum());
}

int main(){
    // int target = 174;
    int target = 230;
    int townsVisited = 3;
    vector<int> distances;
    
    // distances.push_back(50);
    // distances.push_back(55);
    // distances.push_back(57);
    // distances.push_back(58);
    // distances.push_back(60);
    distances.push_back(91);
    distances.push_back(74);
    distances.push_back(73);
    distances.push_back(85);
    distances.push_back(73);
    distances.push_back(81);
    distances.push_back(87);
    int bestSum = findBestSum(target, townsVisited, distances);
    cout << "Best sum equals: " << bestSum << "\n";
    return 0;
}