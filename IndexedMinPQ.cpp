#include <cstdio>
#include <iostream>

/*
 Indexed Min Priority Queue
 Supports insertion in O(long N), deletion of any key
 in O(log N)
and changes to key values in O(log N) where N is th number of elements
in PQ

*/

using namespace std;

class MinIndexedPQ {
	int Nmax, currN;
	int *index;//checks whether the element in the index is present
	int *keys; //holds the key based on which PQ is formed
	int *heap; //is the heap which contains the index of the minHeap
	void swap( int i, int j) {
		int t=heap[i];
		heap[i] = heap[j];
		heap[j]=t;
		index[heap[i]]=i;
		index[heap[j]]=j;
	}
	void bubbleUp(int k) {
		while(k>1 && keys[heap[k/2]] > keys[heap[k]]) {
			swap(k,k/2);
			k = k/2;
		}
	}
	void bubbleDown(int k) {
		int j;
		while (2*k <= currN) {
			j = 2*k;
			if( j < currN && keys[heap[j]] >keys[heap[j+1]])
				j++;
			if(keys[heap[k]] <= keys[heap[j]])
				break;
			swap(k,j);
			k=j;

		}
	}
public:
	MinIndexedPQ(int Max) {
		this->Nmax = Max;
		currN =0;
		keys = new int[Max + 1];
		index = new int[Max +1];
		for(int i=0; i <= this->Nmax; i++) {
			index[i] = -1;
		}
	}

	~MinIndexedPQ() {
		delete[] index;
	}
	int deleteMin() {
		int min = heap[1];
		swap(1,currN--);
		bubbleDown(1);
		index[min] = -1;
		 heap[currN+1] = -1;
		 return min;
	}
	int minIndex() {
		return heap[1];
	}
	int minKey() {
		return keys[heap[1]];
	}
	bool isEmpty() {
		return currN == 0;
	}
	bool contains(int i) {
		return index[i] != -1;
	}
	int keyOf (int i) {
		return keys[i];
	}
	void changeKey(int i, int key) {
		keys[i] =key;
		bubbleUp(index[i]);
		bubbleDown(index[i]);
	}
	int size() {
		return this->currN;
	}
	void decreaseKey(int i, int key) {
		keys[i]=key;
		bubbleUp(index[i]);
	}
	void increaseKey(int i,int key) {
		keys[i]=key;
		bubbleDown(index[i]);
	}
	// delete the key associated with index i
	void deleteKey(int i) {
		int ind =index[i];
		swap(ind,currN--);
		bubbleUp(ind);
		bubbleDown(ind);
		index[i]=-1;

	}
	void insert(int i,int key) {
		currN++;
		index[i] = currN;
		keys[i]  = key;
		heap[currN]  = i; //reverse mapping
		bubbleUp(currN);

	}
};


int main()
{
// test case

MinIndexedPQ pq(10);
	for (int i=0; i<10; i++)
		pq.insert(i,20-i);
	cout<<pq.minKey()<<" "<<pq.size()<<endl;
	pq.deleteKey(7);
	cout<<pq.minKey()<<" "<<pq.size()<<endl;
	pq.deleteMin();
	cout<<pq.minKey()<<" "<<pq.size()<<endl;
	return 0;
}
