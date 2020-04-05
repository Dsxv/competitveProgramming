#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int vis[n+1] = {} ;
	queue<pair<int,int>> q ;
	q.push({0,0}) ;
	int target = n ;
	while(q.size()){
		int cur = q.front().first ;
		int d = q.front().second ;
		if(cur == target){
			cout << d ;
			return 0 ;
		}
		q.pop() ;
		for(int i = cur ; i <= n && i <= (cur + a[cur]) ; i++){
			if(!vis[i]){
				q.push({i,d+1}) ;
				vis[i] = 1 ;
			}
		}
	}
	cout << -1 ;
	return 0 ;
}

