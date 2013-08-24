#include <iostream>
//#include <fstream>
using namespace std;
//ifstream cin("test.in");
#define INF 1000000
int N,R;
int A[40][40];

int main() {
	cin>>N>>R;
	for(int i=0;i<N;i++)
		fill(A[i],A[i]+N,INF);

	for(int i=0;i<R;i++){
		int u,v;
		cin>>u>>v;
		if(u!=v)
			A[u][v] = 1;
	}
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(A[i][j]>A[i][k]+A[k][j])
					A[i][j] = A[i][k]+A[k][j];
	bool found = false;
	for(int i=0;i<N;i++)
		if(A[i][i]!=INF){
			found = true;
			break;
		}
	if(found)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
