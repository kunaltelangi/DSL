#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> a){
	vector<int> temp;
	temp.push_back(0);
	for(auto i : a){
		for(int j = 0;j<i.size();j++){
			if(!binary_search(begin(temp),end(temp),i[j]))temp.push_back(i[j]);
		}
	}
	
	cout<<endl;
	cout<<"BFS"<<endl;
	for(auto i : temp)cout<<i<<" ";
}

void dfs(vector<vector<int>> a){
	
}
	
int main(){
	cout<<"ENter the total number of node: ";
	int n;
	cin>>n;
	vector<vector<int>> a;
	for(int i = 0;i<n;i++){
		int m;
		cout<<"Enter the total nodes connected to "<<i<<": ";
		cin>>m;
		vector<int> temp(m);
		for(int j = 0;j<m;j++)cin>>temp[j];
		a.push_back(temp);
	}
	cout<<endl;
	cout<<"GRAPH"<<endl;
	int k = 0;
	for(auto i : a){
		cout<<k++<<" -> ";
		for(int j = 0;j<i.size();j++)cout<<i[j]<<" ";
		cout<<endl;
	}
	bfs(a);
	return 0;
}
