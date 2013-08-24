#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int A[100];

int compare(const void* arg1,const void* arg2){
	int* e1 = (int*) arg1;
	int* e2 = (int*) arg2;
	return *e2 - *e1;
}

int cal(){
	int total = 0;
	int n=0;
	for(int k=1;;k++){
		for(int i=0;i<K;i++){
			total += A[n]*k;
			++n;
			if(n == N)
				return total;
		}
	}
	return -1;
}

int main() {
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
	qsort(A,N,sizeof(int),compare);
	cout<<cal()<<endl;

	return 0;
}
