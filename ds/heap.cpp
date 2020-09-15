#include <bits/stdc++.h>
using namespace std ;

#define int long long

void max_heapify(int * a , int cur , int size){
	if(cur >= size) return ;
	int l = 2*cur + 1 ;
	int r = 2*cur + 2 ;
	int largest = cur ;
	if(l < size && a[l] > a[cur]){
		largest = l ;
	}
	if(r < size && a[r] > a[largest]){
		largest = r ;
	}
	if(largest != cur){
		swap(a[cur] , a[largest]) ;
		max_heapify(a , largest , size) ;
	}
}

int32_t main(){
	int n; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	for(int i = n / 2 ; i >= 0 ; i--){
		max_heapify(a,i,n) ;
	}
	for(int i = n - 1 ; i >= 1 ; i--){
		swap(a[0] , a[i]) ;
		max_heapify(a,0,i) ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		cout << a[i] << " " ;
	}
	return 0 ;
}

