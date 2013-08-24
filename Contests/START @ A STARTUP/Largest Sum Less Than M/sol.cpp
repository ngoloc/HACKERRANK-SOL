#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
//ifstream cin("test.in");
int n,k,M;
int d[100];

int A[100][100][3000];
int P[3000];
int PM[3000][3000];

int p(int k,int n){
	if(PM[k][n]!=-1)
		return PM[k][n];

	if(k>n){
		PM[k][n] = 0;
		return 0;
	}

	if(k==n){
		PM[k][n] = 1;
		return 1;
	}

	PM[k][n] = (p(k+1,n) + p(k,n-k))%1000000007;
	return PM[k][n];
}

int main() {
	cin>>n>>k>>M;
	for(int i=1;i<=n;i++)
		cin>>d[i];

	for(int i=0;i<=k;i++)
		for(int j=0;j<M;j++)
			A[0][i][j] = 0;

	for(int i=1;i<M;i++)
		fill(PM[i]+1,PM[i]+M,-1);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int u=1;u<M;u++)
				if(i-1>=j&&u-d[i]>=0)
					A[i][j][u] = max(A[i-1][j][u],A[i-1][j-1][u-d[i]] + d[i]);
				else if(i==j&&u-d[i]>=0)
					A[i][i][u] = A[i-1][i-1][u-d[i]] + d[i];

	int Z = A[n][k][M-1];

	cout<<Z<<endl<<p(1,Z);
	return 0;
}
