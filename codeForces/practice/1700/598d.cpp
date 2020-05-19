#include <bits/stdc++.h>
using namespace std ;

struct DSU{
	vector<int> parent , val ;
	int N ;
	DSU(){
		N = 10;
	}
	DSU(int n){
		N = n ;
		parent.resize(n) ;
		val.resize(n) ;
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return true ;
	}
} dsu(1000*1000) ;


bool visited[1000][1000] ;
string s[1000] ;
int n , m ;
int xx[4] = {0,0,1,-1} ;
int yy[4] = {1,-1,0,0} ;
map<int,int> mp ;
int oned(int x , int y){
	return x*m + y ;
}


void dfs(int si , int sj , int stx , int sty){
	dsu.merge(oned(si,sj),oned(stx,sty)) ;
	for(int i = 0 ; i < 4 ; i++){
		int xi = xx[i] + si ;
		int yi = yy[i] + sj ;
		if(xi >= 0 && xi < n && yi >= 0 && yi < m && !visited[xi][yi]){
			if(s[xi][yi] == '.') {
				visited[xi][yi] = 1 ;
				dfs(xi,yi,stx,sty) ;
			} else {
				mp[oned(stx,sty)]++;
			}
		}
	}
}

int32_t main(){
	int q ;
	cin >> n >> m >> q ;	
	for(int i = 0 ; i < n ; i++) cin >> s[i] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '.' && !visited[i][j]){
				visited[i][j] = 1 ;
				dfs(i,j,i,j) ;
				mp[dsu.gp(oned(i,j))] = mp[oned(i,j)] ;
			}
		}
	}
	while(q--){
		int x , y ;
		cin >> x >> y ;
		x-- , y--;
		cout << mp[dsu.gp(oned(x,y))] << '\n' ;
	}
	return 0 ;
}


