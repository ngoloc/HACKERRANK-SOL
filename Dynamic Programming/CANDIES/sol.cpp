#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int left;
    int right;
};

node A[100000];
int P[100000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>P[i];
        A[i].left = 1;
        A[i].right = 1;
    }
    for(int i=1;i<N;i++)
        if(P[i]>P[i-1])
            A[i].left = A[i-1].left + 1;
    for(int i=N-2;i>=0;i--)
        if(P[i]>P[i+1])
            A[i].right = A[i+1].right + 1;
    int sum = 0;
    for(int i=0;i<N;i++)
        sum += max(A[i].left,A[i].right);
    cout<<sum<<endl;
    return 0;
}
