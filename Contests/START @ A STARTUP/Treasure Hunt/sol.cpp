#include <iostream>
#include <algorithm>
//#include <fstream>
#include <queue>
using namespace std;
//ifstream cin("test.in");
int A[6][6];
int B[6][6];

struct cell{
	int r;
	int c;
};

bool search(int r,int c,queue<cell>& Q){
	cell tc;
	tc.r = r;
	tc.c = c;
	Q.push(tc);
	B[r][c] = true;
	int val = A[r][c];
	int ten_d = val/10;
	int unit_d = val%10;
	if(ten_d==r&&unit_d==c)
		return true;
	if(B[ten_d][unit_d])
		return false;
	return search(ten_d,unit_d,Q);
}

int main() {
	for(int i=1;i<=5;i++)
		fill(B[i]+1,B[i]+6,false);

	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			cin>>A[i][j];

	queue<cell> Q;
	bool found = search(1,1,Q);
	if(found)
	{
		while(!Q.empty()){
			cell tc = Q.front();
			Q.pop();
			cout<<tc.r<<" "<<tc.c<<endl;
		}
		return 0;
	}

	cout<<"NO TREASURE";
	return 0;
}
