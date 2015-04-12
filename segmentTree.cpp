#include<cstdio>
#include<iostream>
#include<cmath>
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
using namespace std;

class SegmentTree
{
	int *arr;
	int *st;
	int size;
	int n;
	int getSumUtil(int,int,int,int,int);
	void getValueUtil(int,int,int,int,int);
    int constructSt(int,int,int);
	public:
	SegmentTree(int *, int);
    int getSum(int beg,int end);
	void updateValue(int i,int new_val);
};

int SegmentTree::getSumUtil(int ss,int se, int qs,int qe,int idx)
{
	//cout <<" "<<idx<<endl;
	if ( qs <= ss && qe >= se)
	   return st[idx];
    
	if ( se <qs || ss > qe)
		return 0;
	int mid = ss+ (se-ss)/2;
	return getSumUtil(ss,mid,qs,qe,2*idx+1)+
		   getSumUtil(mid+1,se,qs,qe,2*idx+2);
	
}

void SegmentTree::getValueUtil(int ss,int se,int idx,int diff,int index)
{
	if( idx <ss || idx > se)
		return;
	st[index]=st[index]+diff;
	if(se!=ss)
	{
		int mid = ss+(se-ss)/2;
		getValueUtil(ss,mid,idx,diff,2*index+1);
		getValueUtil(mid+1,se,idx,diff,2*index+2);
	}
}
int SegmentTree::constructSt(int beg,int end,int idx)
{
	if (beg ==end)
	{
		st[idx]=arr[beg];
		cout <<" construct St "<<st[idx] <<" "<<idx <<" "<<beg<<endl;
		return st[idx];
	}
	else
	{
		int mid = beg + ( end-beg)/2;
		st[idx]=constructSt(beg,mid,idx*2+1) +
				constructSt(mid+1,end,idx*2+2);
		cout <<" construct St "<<st[idx] <<" "<<idx<<endl;
		return st[idx];
	}
}
SegmentTree::SegmentTree(int arr[],int n)
{
	int x =(int)(ceil(log2(n))); // height of tree
	this->size=2*(int)pow(2,x)-1;
	cout << this->size<<endl;
	this->n=n;
	this->arr = new int[n];
	for( int i=0; i< n; i++)
		this->arr[i]=arr[i];
	this->st = new int[this->size];
	constructSt(0,n-1,0); // beg,end, idx
	cout<<"Constructed Segment Tree"<<endl;
	for ( int i=0; i < this->size; i++)
	 cout<<st[i]<<" ";
}
int SegmentTree::getSum(int beg, int end)
{
	return this->getSumUtil(0,n-1,beg,end,0);
}
void SegmentTree::updateValue(int idx,int value)
{
	if(idx <0 || idx > n-1) {
		printf("invalid input\n");
		return;
	}
	int diff= value - arr[idx];
	arr[idx]=value;
	this->getValueUtil(0,n-1,idx,diff,0);
}

int main()
{
int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    SegmentTree st(arr, n);
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n", st.getSum( 1, 3));
 
    // Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
    //st.updateValue(1,10);
 
    return 0;
}
