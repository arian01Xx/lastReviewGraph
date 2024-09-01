#ifndef SOLUTION_TWO_HPP
#define SOLUTION_TWO_HPP

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

class SolutionTwentyTwo{
public:
	bool isBipartite(vector<vector<int>>& graph){
		int n=graph.size();
		vector<int> color(n,-1);
		for(int i=0; i<n; i++){
			if(color[i]== -1){
				queue<int> q;
				q.push(i);
				color[i]=0;
				while(!q.empty()){
					int node=q.front();
					q.pop();
					for(int neighbor: graph[node]){
						if(color[neighbor]==-1){
							color[neighbor]==1-color[node];
							q.push(neighbor);
						}else if(color[neighbor]==color[node]){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
};

#endif