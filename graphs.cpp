#include "solution.hpp"
#include "solutionOne.hpp"
#include "solutionTwo.hpp"
#include "solutionThree.hpp"
#include "solutionFour.hpp"
#include "solutionFive.hpp"

using namespace std;

class SolutionTwentySix{
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths){
		vector<vector<int>> graph(n,vector<int>());
		for(const auto& it: paths){
			graph[it[0]-1].push_back(it[1]-1);
			graph[it[1]-1].push_back(it[0]-1);
		}
		vector<int> flowers(n,0);
		for(int i=0; i<n; i++){
			vector<bool> used(5,false); 
			for(int neighbor: graph[i]) used[flowers[neighbor]]=true;
			for(int f=1; f<=4; f++){
				if(!used[f]){
					flowers[i]=f;
					break;
				}
			}
		}
		return flowers;
	}
};

class SollutionTwentySeven{
public:
	vector<int> findOrder(int n, vector<vector<int>>& prerequisites){
		vector<int> courses;
		if(n<=0) return {};

		//1.initialize the graph
		unordered_map<int,int> inDegree;
		unordered_map<int,vector<int>> graph;
		for(int i=0; i<n; i++){
			inDegree[i]=0;
			graph[i]={};
		}

		//2.build the graph
		for(int i=0; i<prerequisites.size(); i++){
			int parent=prerequisites[i][1];
			int child=prerequisites[i][0];
			graph[parent].push_back(child);
			inDegree[child]=inDegree[child]+1;
		}

		//3.find all sources, cursos que no tienen prerequisitos
		queue<int> sources;
		for(auto it=inDegree.begin(); it!=inDegree.end(); it++){
			if(it->second==0) sources.push(it->first);
		}

		//4.add it to the courses and subtract one
		while(!sources.empty()){
			int vertex=sources.front();
			sources.pop();
			courses.push_back(vertex);
			vector<int> children=graph[vertex];
			for(int child: children){
				inDegree[child]=inDegree[child]-1;
				if(inDegree[child]==0) sources.push(child);
			}
		}
		if(courses.size()!=n) courses.clear();
		return courses;
	}
};

class SolutionTwentyEight{
public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes){
		vector<vector<int>> graph(n+1,vector<int>());
		for(const auto& it: dislikes){
			graph[it[0]].push_back(it[1]);
			graph[it[1]].push_back(it[0]);
		}
		vector<int> hate(n+1,-1);
		for(int i=1; i<=n; i++){
			if(hate[i]== -1){
				queue<int> q;
				q.push(i);
				hate[i]=0;
				while(!q.empty()){
					int node=q.front();
					q.pop();
					for(int neighbor: graph[node]){
						if(hate[neighbor]== -1){
							hate[neighbor]=1-hate[node];
							q.push(neighbor);
						}else if(hate[neighbor]==hate[node]) return false;
					}
				}
			}
		}
		return true;
	}
};

class SolutionTwentyNine{
public:
	int find(vector<int>& parent, int a){
		if(a==parent[a]) return a;
		return parent[a]=find(parent,parent[a]);
	}
	void Union(vector<int>& parent, int a, int b){
		int p1=find(parent,a);
		int p2=find(parent,b);
		parent[p1]=p2;
	}
	bool equationsPossible(vector<string>& equations){
		vector<int> parent(26);
		for(int i=0; i<26; i++){
			parent[i]=i;
		}
		for(int i=0; i<equations.size(); i++){
			if(equations[i][1]=='!') continue;
			Union(parent,equations[i][0]-'a',equations[i][3]-'a');
		}
		for(int i=0; i<equations.size(); i++){
			if(equations[i][1]=='=') continue;
			if(find(parent,equations[i][0]-'a')==find(parent,equations[i][3]-'a')){
				return false;
			}
		}
		return true;
	}
};

int main(){
	cout<<"hi"<<endl;
	return 0;
}