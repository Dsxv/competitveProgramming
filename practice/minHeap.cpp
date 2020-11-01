#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct cell{
	int row , col , val ;
	cell(int x , int y , int z){
		row = x , col = y , val = z ;
	}
} ;

struct minHeap{
	vector<cell> heapArr ;
	int size ;
	
	minHeap(){
		heapArr.clear() ;
		size = 0 ;
	}
	
	void heapify(int cur = 0){
		int l = 2*cur + 1 ;
		int r = 2*cur + 2 ;
		int smallest = cur ;
		if(l < size && heapArr[l].val < heapArr[cur].val) smallest = l ;
		if(r < size && heapArr[r].val < heapArr[smallest].val) smallest = r ;
		if(smallest != cur){
			swap(heapArr[cur] , heapArr[smallest]) ;
			heapify(smallest) ;
		}
	}
	
	int parent(int x){
		return x - 1 >> 1 ;
	}

	void push(cell x){
		heapArr.push_back(x) ;
		size++ ;
		int cur = size - 1 ;
		while(cur && heapArr[parent(cur)].val > heapArr[cur].val){
			swap(heapArr[cur] , heapArr[parent(cur)]) ;
			cur = parent(cur) ;
		}
	}
	
	cell top(){
		return heapArr[0] ;
	}
	
	void pop(){
		swap(heapArr[0] , heapArr.back()) ;
		heapArr.pop_back() ;
		size-- ;
		heapify() ;
	}
} ;

int32_t main(){
	minHeap pq ;
	int n ;
	cin >> n ;
	return 0 ;
}

