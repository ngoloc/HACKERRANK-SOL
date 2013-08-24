#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
//ifstream cin("test.in");
int N,M;
int A[100000];
int D[100000];
int K[100000];

int compare(const void* arg1,const void* arg2){
	int* e1 = (int*) arg1;
	int* e2 = (int*) arg2;
	return *e2 - *e1;
}

int BS1(int begin,int end,int val){
	if(begin==end)
		return begin;
	int mid = (begin+end)/2;
	if(A[mid]>=val)
		return BS1(mid+1,end,val);
	return BS1(begin,mid,val);
}

int BS2(int begin,int end,int val){
	if(begin==end)
		return begin;
	int mid=(begin+end)/2;
	if(K[mid]>val)
		return BS2(mid+1,end,val);
	return BS2(begin,mid,val);
}

int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<M;i++)
		cin>>D[i];
	qsort(A,N,sizeof(int),compare);
	qsort(D,M,sizeof(int),compare);
	fill(K,K+N,0);

	for(int i=0;i<M;i++){
		int pos1 = BS1(0,N-1,D[i]);
		if(A[pos1]<D[i])
			--pos1;
		int pos2 = BS2(0,pos1,K[pos1]);
		++K[pos2];
	}
	cout<<K[0]<<endl;
	return 0;
}
