#ifndef SOLUTION_FOUR_HPP
#define SOLUTION_FOUR_HPP

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class SolutionTwentyFour{
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k){
		unordered_map<int, vector<pair<int,int>>> adjacency;
		for(const auto& time: times){
			int src=time[0]; 
			int dst=time[1];
			int t=time[2];
			adjacency[src].emplace_back(dst,t);
		}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		pq.emplace(0,k);
		set<int> visited;
		int delays=0;
		while(!pq.empty()){
			auto[time,node]=pq.top();
			pq.pop();
			if(visited.count(node)) continue;
			visited.insert(node);
			for(const auto& neighbor: adjacency[node]){
				int neighborNode=neighbor.first;
				int neighborTime=neighbor.second;
				if(!visited.count(neighborNode)){
					pq.emplace(time+neighborTime,neighborNode);
				}
			}
		}
		return visited.size() == n ? delays: -1;
	}
};

#endif