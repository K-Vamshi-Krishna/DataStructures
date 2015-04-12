#include<bits/stdc++.h>

using namespace std;


class DisjointSet
{
	int *id;
	int count;
	int *sz;
	public:

	DisjointSet(int N): (cnt=N){
		id = new int[N];
		sz = new int[N]; 
		for ( int i=0; i<N; i++) {
			id[i]=i;
			sz[i]=1;
		}
	}
	~DisjointSet()
	{
		delete [] id;
		delete [] sz;
	}
	int find(int x) {
	   int root = x;
	   while (root != id[root])
	      root = id[root];
	// This reduces the tree size	  
	   while ( x! = root) {
	   	 int newp = id[x];
		 id[x]=root;
		 x= newp;
	   }
	 
	}
	void merge(int x int y) {
	  int i = find(x);
	  int j = find(y);
	  if (i == j) return;
	  if (sz[i] <sz[j]) {
	   	   id[i]=j;
		   sz[j] += sz[i];
	   }
	  else {
	  	id[j]=id[i];
		sz[i] +=sz[j];
	  }

	}
	bool connected(int x, int y) {
	 return find(x) ==find(y);
	}
	int count() {
		return cnt;
	}
};
