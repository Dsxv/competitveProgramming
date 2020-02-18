#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int  n;
int ans = 0 ;
void dfs(map<int,int>* g , int* ok , int start , vector<int>& dis ,int d = 1 , int parent = -1){
	if(ok[start]) dis[d]++ ;
	for(auto i : g[start]){
		if(i.first != parent){
			dfs(g ,ok,i.first,dis,d+1,start) ;
		}
	}
}

int solve(vector<int>& v){
	int l = v.size() ;
	if(l < 3) return 0 ;
	vector<int> temp(l-1,0) ;
	for(int i = l-2 ; i >= 0 ; i--){
		temp[i] = temp[i] + v[i+1] ;
	}
	for(int i = 0 ; i < l - 1 ; i++){
		temp[i] = v[i]*temp[i] ;
	}
	int vvans = 0 ;
	vector<int> temp2(l-2,0) ;
	for(int i = l - 3 ; i >= 0 ; i--){
		temp2[i] = temp2[i] + temp[i+1] ;
	}
	for(int i = 0 ; i < l - 1 ; i++){
		vvans += temp2[i]*v[i] ;
	}
	return vvans ;
}
	

void bfs(int* visited , int start , int* ok , map<int,int>* g) {
	if(visited[start]) return ;
	visited[start] = 1 ;
	int l = g[start].size() ;
	if(l > 2){
		vector<vector<int>> dis(l,vector<int>(n+2,0)) ;
		int x = 0 ;
		for(auto i : g[start]){
			dfs(g,ok,i.first,dis[x]) ;
			x++ ;
		}

		for(int i = 0 ; i < n + 2 ; i++){
			vector<int> temp ;
			for(int j = 0 ; j < l ; j++){
				if(dis[j][i]) temp.push_back(dis[j][i]) ;
				cout << dis[i][j] << " " ;
			} 
			cout << endl ;
			ans += solve(temp) ;
		}
	}
	for(auto i : g[start]){
		bfs(visited,i.first,ok,g) ;
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		ans = 0 ;
		cin >> n ;
		int ok[n] ;
		map<int,int> g[n] ;
		int visited[n] = {} ;
		for(int i = 0 ; i < n-1; i++) {
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f][s] = 1 ;
			g[s][f] = 1 ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> ok[i] ;
		}
		bfs(visited,0,ok,g) ;
		cout << ans << endl;
	}
	return 0 ;
}

