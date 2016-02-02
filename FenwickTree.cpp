#include<cstdio>
#include<iostream>
#include<vector>

// 1111 is responsible for sums from 15 to 14+1 {1111 - 0001 +1}
//14 1110 is responsisble for sums from 14 to 12+1{1110 - 0010 +1} 
using namespace std;

class FenwickTree
{
	vector<int> tree;
	FenwickTree(const vector<int>& Arg)
	{
	    tree.resize(Arg.size());
	    for( int i=0; i< tree.size(); i++)
	       increase(i,Arg[i]);
	}

	void increase ( int i, int delta)
	{ 
	   for (; i <(int) tree.size(); i |= i+1)
	      tree[i]+=delta;
	}

	int getsum(int left, int right) {
	   return get(right) - get(left-1);	
	
    }
	int get(int ind)
	{
		int sum=0;
		while(ind>=0)
		{
			sum += tree[ind];
			ind -= ind &(-ind);// ind &= ind +1; ind--;	
		}
		return sum;
	}
 
 		
}
