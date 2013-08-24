#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
//ifstream fin("test.in");

struct point{
	int x;
	int y;
};

int W,H,N,Q;
point P[100000];

int compare(const void* arg1,const void* arg2){
	point* p1 = (point*)arg1;
	point* p2 = (point*)arg2;
	if(p1->x>p2->x)
		return 1;
	if(p1->x<p2->x)
		return -1;
	return 0;
}

bool inside(point p,point top_left,point bottom_right){
	if(p.x>top_left.x&&p.x<bottom_right.x&&p.y>bottom_right.y&&p.y<top_left.y)
		return true;
	return false;
}

int bs(int val,int begin,int end){
	if(begin==end)
		return begin;
	int mid = (begin+end)/2;
	if(P[mid].x>=val)
		return bs(val,begin,mid);
	return bs(val,mid+1,end);
}

bool exist_tree(point top_left,point bottom_right){
	int left_index = bs(top_left.x+1,0,N);
	int right_index = bs(bottom_right.x,0,N);
	for(int i=left_index;i<right_index;i++)
		if(inside(P[i],top_left,bottom_right))
			return true;
	return false;
}

int find_house(point p,int begin,int end) {
	point top_left,bottom_right;
	int length;
	if(begin==end)
		length = begin;
	else
		length = (begin+end)/2;

	top_left.x = p.x - length;
	top_left.y = p.y + length;

	bottom_right.x = p.x + length;
	bottom_right.y = p.y - length;

	if(begin==end) {
		if(exist_tree(top_left,bottom_right))
			return (begin-1)*2;
		return begin*2;
	}

	if(exist_tree(top_left,bottom_right))
		return find_house(p, begin, length);

	return find_house(p, length+1,end);
}

int main() {
	cin>>W>>H>>N>>Q;
	for(int i=0;i<N;i++)
		cin>>P[i].x>>P[i].y;
	qsort(P,N,sizeof(point),compare);
	for(int i=0;i<Q;i++){
		point p;
		cin>>p.x>>p.y;
		int max_length = min(min(H-p.y,p.y),min(W-p.x,p.x));
		cout<<find_house(p,1,max_length)<<endl;
	}
	return 0;
}
