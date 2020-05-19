#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10;
int id[N] ;

bool check(int a , int b){
	return id[a] < id[b] ;
}

int32_t main(){
	int  n;
	cin >> n; 
	vector<int> G[n] ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		a[i]-- ;
		id[a[i]] = i ;
	}
	for(int i = 0 ; i < n ; i++){
		sort(G[i].begin() , G[i].end() , check) ;
	}
	vector<int> v ;
	queue<int> q ;
	q.push(0) ;
	int visited[n] = {} ;
	visited[0] = 1 ;
	while(q.size()){
		int start = q.front() ;
		v.push_back(start) ;
		q.pop() ;
		for(int i : G[start]){
			if(!visited[i]) {
				q.push(i) ;
				visited[i] = 1 ;
			}
		}
	}
	cout << (a==v?"Yes":"No") ;
	return 0 ;
}

