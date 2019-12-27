#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
vector<int> G[N] ;

void dfs(int start , int* v , int d = 0 , int parent = -1 ){
	v[start] = d ;
	for(auto i : G[start]){
		if(i == parent) continue ;
		dfs(i,v,d+1,start) ;
	}
}

int32_t main(){
	int n , u , v ;
	cin >> n >> u >> v ;
	u-- , v-- ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f, s ;
		cin >>f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	int v1[n] = {0} , v2[n] = {0} ;
	dfs(u,v1) ;
	dfs(v,v2) ;
	int ans = 0 ;
	//for(int i = 0 ;  i < n ; i++) cout << v1[i] << " " ;
	//cout << endl ;
	//for(int i = 0 ; i < n ; i++) cout << v2[i] << " " ;
	//cout << endl ;
	for(int i = 0 ; i < n ; i++){
		if(v1[i] < v2[i]){
			ans = max(v2[i]-1, ans) ;
			// v2[i] vo place hai jaha murderer late pahuchega ,
			// marne se just pehle v1 wala leaf pe hoga
			// v2[i] leaf hai jispe marne ke pehle v1 khada hoga 
			// jisme v1 ka next step hoga parent of leaf pe jana jaha v2
			// khada hoga ya pahuchne wala hoga aur marr jaega ( atm hatya karlega bc lel)
		}
	}
	cout << ans;
	return 0 ;
}

