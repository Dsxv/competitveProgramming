#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 10 ;

int a[N] ;

void recur(int n , int dis , queue<pair<int,int>>& q , int cur){
	if((n + cur) > N) return ;
	if(a[n + cur] == -1) {
		a[n + cur] = dis + 1 ; 
		q.push({n + cur , dis + 1}) ;
	}
	recur(n , dis , q , cur*10 + 4) ;
	recur(n , dis , q , cur*10 + 5) ;
}

int32_t main(){
	for(int i = 0 ; i < N ; i++) a[i] = -1 ;
	queue<pair<int,int>> q ;
	q.push({0 , 0}) ;
	while(q.size()){
		int cur = q.front().first ;
		int d = q.front().second ;
		q.pop() ;
		recur(cur , d , q , 4) ;
		recur(cur , d , q , 5) ;
	}
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		cout << a[n] << '\n' ;
	}
	return 0 ;
}

