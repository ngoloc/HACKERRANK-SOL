#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int A[100000];

bool bs(int val,int begin,int end){
    if(begin==end){
        if(A[begin]==val)
            return true;
        return false;
    }
    int mid = (begin+end)/2;
    if(A[mid]>=val)
        return bs(val,begin,mid);
    return bs(val,mid+1,end);
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N);
    int ret = 0;
    for(int i=0;i<N;i++)
        if(bs(A[i]+K,0,N-1))
            ret++;
    cout<<ret<<endl;
    return 0;
}