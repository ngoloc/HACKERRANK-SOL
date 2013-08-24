#include <iostream>
//#include <fstream>
using namespace std;
//ifstream fin("in.txt");

int C[50001];
int TailMax[50001];
int N;
long long A[50001];

void process(){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>C[i];

	TailMax[N] = C[N];
	for(int i=N-1;i>=1;i--)
		TailMax[i] = max(C[i],TailMax[i+1]);

	A[0] = 0;
	for(int i=1;i<N;i++)
	{
		if(C[i]<TailMax[i+1])
			A[i] = A[i-1] + (TailMax[i+1] - C[i]);
		else
			A[i] = A[i-1];
	}
	cout<<A[N-1]<<endl;
}

int main() {
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
		process();
	return 0;
}
