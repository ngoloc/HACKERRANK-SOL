#include <iostream>
#include <vector>
//#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
//ifstream cin("test.in");
int N,M;
struct edge{
	int u;
	int v;
};

bool E[101][101];
vector<edge> ve;
bool B[101];
bool check_even(int u){
	fill(B,B+N+1,false);
	queue<int> Q;
	Q.push(u);
	B[u] = true;
	int n = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		n++;
		for(int v=1;v<=N;v++)
			if(E[u][v]&&!B[v]){
				B[v] = true;
				Q.push(v);
			}
	}
	if(n%2==0)
		return true;
	return false;
}

int main() {
	cin>>N>>M;
	for(int i=0;i<=N;i++)
			fill(E[i],E[i]+N+1,false);

	for(int i=0;i<N;i++){
		int u,v;
		cin>>u>>v;
		E[u][v] = true;
		E[v][u] = true;
		edge e;
		e.u = u;
		e.v = v;
		ve.push_back(e);
	}
	int n=0;
	for(int i=0;i<ve.size();i++)
	{
		int u = ve[i].u;
		int v = ve[i].v;
		E[u][v] = false;
		E[v][u] = false;
		if(check_even(u))
			n++;
		else {
			E[u][v] = true;
			E[v][u] = true;
		}
	}
	cout<<n<<endl;
	return 0;
}
