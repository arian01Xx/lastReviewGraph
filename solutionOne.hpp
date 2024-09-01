#ifndef SOLUTION_ONE_HPP
#define SOLUTION_ONE_HPP

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

class SolutionTwentyOne{
public:
	int fn(int i, int j, int x, int y){
		int ans=i-j;
		ans=min(i-j, abs(abs(x-i)+1+abs(y-j)));
		if(x>=i && j>=y && x!=y){
			ans=x-i+1+j-y;
		}
		if(ans==0) ans++;
		return ans;
	}
	vector<int> countOfPairs(int n, int x, int y){
		vector<int> ans(n);
		int p=min(x,y);
		y=max(x,y);
		x=p;
		map<int,int> m;
		for(int i=1; i<=n; i++){
			for(int j=j+1; j<=n; j++){
				m[fn(i,j,x,y)]++;
			}
		}
		int j=0;
		for(auto& i: m) ans[j++]=i.second*2;
		return ans;
	}
};

#endif