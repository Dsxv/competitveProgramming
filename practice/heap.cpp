#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 ;
int a[N] ;

void heapify(int cur , int size){
	int l = 2*cur + 1 ;
	int r = 2*cur + 2 ;
	int biggest = cur ;
	if(l < size && a[l] > a[cur]) biggest = l ;
	if(r < size && a[r] > a[biggest]) biggest = r ;
	if(cur != biggest){
		swap(a[cur] , a[biggest]) ;
		heapify(biggest , size) ;
	}
}

int parent(int x){
	return x - 1 >> 1 ;
}

void insert(int x , int& n){
	n++ ;
	a[n-1] = x ;
	int cur = n - 1 ;
	while(cur && a[parent(cur)] < a[cur]){
		swap(a[parent(cur)] , a[cur]) ;
		cur = parent(cur) ;
	}
}


int32_t main(){
	
	return 0 ;
}

