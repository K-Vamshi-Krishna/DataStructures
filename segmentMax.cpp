#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
/*
In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)

*/

#define inf 0x7fffffff

class SegmentTree {
	int * tree;
    int N;
	int Max;
 public:	
	SegmentTree(int arr[],int N) {
		this->N = N;
		Max =; 
		tree = new int[Max];
		buildTree(arr, 1, 0, N-1);
	}
	void update(int start, int end, int value);
	int query(int start, int end);
	
	private:

	void buildTree(int * arr,int stIndex, int a, int b) {
		if (a>b) return;

		if (a==b) {
			tree[stIndex] =arr[a];
			return;
		}
		buildTree(arr,stIndex*2,a,(a+b)/2);
		buildTree(arr,stIndex*2+1,1+(a+b)/2,b);

		tree[stIndex]=max(tree[stIndex*2],tree[stIndex*2+1]);//merge
	}
   void updateTree (int stIndex,int a, int b, int i,int j, int value) {
   	 	if ( a > b || a > j || b < i) 
			return;
		if (a == b) {
			tree[stIndex] += value;
			return;
		}
		int leftIndex = stIndex *2;
		int rightIndex = leftIndex + 1;
		updateTree (leftIndex, a, (a+b)/2,i,j,value);
		updateTree (rightIndex, 1+(a+b)/2,b,i,j,value);
	tree[stIndex] = max(tree[leftIndex],tree[rightIndex]);
}
  int queryTree (int stIndex, int a, int b, int i, int j) {
  	if (a > b || a > j || b < i) return -inf;
	if (a >= i && b <= j) // current segme
	 	return tree[stIndex];
	int leftIndex = stIndex*2;
	int rightIndex = stIndex*2;
	int q1 = queryTree (leftIndex,a, (a+b)/2,i,j);
	int q2 = queryTree (rightIndex,1+(a+b)/2,b,i,j);
	int res = max(q1,q2);
	return res;
  }

};

int main()
{
 	int arr[120];


	for ( int i=0; i< 120; i++)
	arr[i]=1;
	SegmentTree st(arr,120);

}
