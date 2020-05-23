#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , t ;
	cin >> n >> t ;
	int a[n+1] = {} ;
	vector<int> v[n+1] ;
	for(int i = 0 ; i < t ; i++){
		int f , s ;
		cin >> f >> s ;
		a[f]++ ;
		a[s]++ ;
		v[f].push_back(s) ;
		v[s].push_back(f) ;
	}
	a[0] = INT_MAX ;
	vector<int> visited(n+1,0) ;
	int id = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(a[id] > a[i] && a[i]){
			id = i ;
		}
	}
	int count = 0 ;
	for(int id = 1 ; id <= n ; id++){
		if(!a[id] || visited[id]) continue ;
		queue<int> q ;
		q.push(id) ;
		q.push(v[id][0]) ;
		visited[v[id][0]] = 1;
		count++ ;
		visited[id] = 1 ;
		while(q.size()){
			int x = q.front() ;
			q.pop() ;
			for(int i : v[x]){
				if(!visited[i]){
					q.push(i) ;
					visited[i] = 1 ;
					count++ ;
				}
			}
		}
	}
	cout << t - count ;
	return 0 ;
}


