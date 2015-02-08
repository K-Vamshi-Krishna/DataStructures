#include<cstdio>
#include<iostream>
#include<cstream>

/*

Implement Segment tree data structures


getsum(node,l,r) 
{
	if range of node is within l and r
		return value in doe
	else if range of node is commpleterly outside l and r
	return 0
	else
		getSum(node's left child,l,r)+getSum(node's right child,l,r)
}

*/


class SegmentTree
{
	int *arr;
	int *st;
	int size;
	int n;
	public:
	SegmentTree(int *, int);
    int getSum(int beg,int end);
	int updateValue(int n ,int i,int new_val);
};

int SegmentTree::getSumUtil(int ss,int se, int qs,int qe,int idx)
{
	if ( qs <= ss && qe >= se)
	     return st[idx];
    int mid = ss+ (se-ss)/2;
	return getSumUtil(ss,mid,qs,qe,2*idx+1)+
		   getSumUtil(mid+1,se,qs,qe,2*idx+2);
	
}


SegmentTree::constructSt(int beg,int end,int idx)
{
	if (beg ==end)
	{
		st[idx]=arr[beg];
	}
	else
	{
		int mid = beg + ( end-beg)/2;
		st[idx]=constructSt(beg,mid,idx*2+1) +
				constructSt(mid+1,end,idx*2+2);
	}
}
SegmentTree::SegmentTree(int arr[],int n)
{
	int x =(int)(ceil(log2(n))); // height of tree
	this->size=2*(int)pow(2,x)-1;
	this->n=n;
	this->arr = new int[n];
	for( int i=0; i< n; i++)
		this->arr[i]=arr[i];
	this->st = new int[this->size];
	constructSt(0,n-1,0); // beg,end, idx
	
}
int SegmentTree::getSum(int beg, int end)
{
	return this->getSumUtil(0,this->n,beg,end,0);
}

int main()
{
}
