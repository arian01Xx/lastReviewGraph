#ifndef SOLUTION_THREE_HPP
#define SOLUTION_THREE_HPP

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

class SolutionTwentyThree{
public:
	double maxProbability(int n, vector<vector<int>>& edges,
		                  vector<double>& succProb, int start, int end){
		vector<vector<pair<int,int>>> graph(n);
		for(int i=0; i<edges.size(); i++){
			int a=edges[i][0];
			int b=edges[i][1];
			double w= -log(succProb[i]);
			graph[a].push_back({b,w});
			graph[b].push_back({a,w});
		}
		vector<double> dist(n,numeric_limits<double>::max());
		dist[start]=0;
		priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> heap;
		heap.push({0,start});
		while(!heap.empty()){
			auto[d,u]=heap.top();
			heap.pop();
			if(d>dist[u]) continue;
			for(auto[v,w]: graph[u]){
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					heap.push({dist[v],v});
				}
			}
		}
		return dist[end]==numeric_limits<double>::max() ? 0:exp(-dist[end]);
	}
};

#endif