#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10;
int n ;
vector<int> G[N] ;
map<int,int> mp[N] ;
vector<int> total ;
int a[N] ;

int dfs(int start , int parent){
	int sum = 0;
	for(auto i : G[start]){
		if(i != parent){
			sum += max(0LL,dfs(i,start)) ;
		}
	}
	sum += a[start] ;
	mp[parent][start] = sum ;
	return sum ;
}

void ff(int start , int parent = -1){
	for(auto i : G[start]){
		if(i != parent){
			total[i] = mp[start][i] +
				max(0LL,total[start] - max(0LL,mp[start][i])) ;
			ff(i,start) ;
		}
	}
}

void solve(int start = 0){
	int ans = 0 ;
	for(auto i : G[start]){
		ans += max(0LL,dfs(i,start)) ;
	}
	total[start] = ans + a[start] ;
	ff(start) ;	
}

int32_t main(){
	cin >> n ;
	total.resize(n) ;
	for(int i = 0 ; i < n ; i++) {
		int x ; cin >> x ;
		if(x) a[i]++ ;
		else a[i]-- ;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	solve() ;
	for(auto i : total) cout << i << " " ;
	return 0 ;
}

