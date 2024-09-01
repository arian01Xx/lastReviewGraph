#ifndef SOLUTION_FIVE_HPP
#define SOLUTION_FIVE_HPP

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

class SolutionTwentyFive{
public:
	int networkBecomeIdle(vector<vector<int>>& edges, vector<int>& patience){
		int n=patience.size();
		vector<vector<int>> graph(n);
		vector<int> time(n,-1);
		for(const auto& edge: edges){
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		queue<int> q;
		q.push(0);
		time[0]=0;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			for(auto child: graph[node]){
				if(time[child]== -1){
					//de esa forma se registra el tiempo transcurrido
					time[child]=time[node]+1; 
					q.push(child);
				}
			}
		}
		int res=0;
		for(int i=1; i<n; i++){
			int extraPayload=(time[i]*2-1)/patience[i];
			int lastOut=extraPayload*patience[i];
			int lastInt=lastOut+time[i]*2;
			res=max(res,lastInt);
		}
		return res+1;
	}
};

#endif