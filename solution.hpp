#ifndef SOLUTION_HPP
#define SOLUTION_HPP

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

class SolutionTwenty{
public:
	int minScore(int n, vector<vector<int>> roads){
		vector<vector<pair<int,int>>> adj(n+1);
		//crear lista de adyacencia
		for(const auto& road: roads){
			int u=road[0], v=road[1], dist=road[2]; //una forma mas simplificada
			adj[u].emplace_back(v,dist);
			adj[v].emplace_back(u,dist);
		}
		int result=INT_MAX;
		vector<bool> visited(n+1,false);
		queue<int> q;
		q.push(1);
		visited[1]=true;

		while(!q.empty()){
			int city=q.front();
			q.pop();
			for(const auto& [neighbor,dist]: adj[city]){
				result=min(result,dist);
				if(!visited[neighbor]){
					visited[neighbor]=true;
					q.push(neighbor);
				}
			}
		}
		return result;
	}
};

#endif