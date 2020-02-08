#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 25 ;
bool gp[N][N] ;

int dx[4] = {1,-1,0,0} ;
int dy[4] = {0,0,1,-1} ;
struct pt{
	int x ,y , d ;
	pt(int a , int b , int c){
		x = a , y = b , d = c ;
	}
} ;

int solve(int x , int y , int n , int m){
	int ans = 0 ;
	queue<pt> q ;
	q.push(pt(x,y,0)) ;
	map<pair<int,int>,int> visited ;
	visited[{x,y}] = 1;
	while(q.size()){
		x = q.front().x ;
		y = q.front().y ;
		int d = q.front().d ;
		ans = max(ans,d) ;
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int x1 = x + dx[i] , y1 = y + dy[i] ;
			if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue ;
			if(gp[x1][y1] && !visited.count({x1,y1})){
				q.push(pt(x1,y1,d+1)) ;
				visited[{x1,y1}] = 1 ;
			}
		}
	}
	return ans ;
} 

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++) cin >> s[i] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			gp[i][j] = (s[i][j] == '.') ;
		}
	}
	int mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!gp[i][j]) continue ;
			mx = max(mx,solve(i,j,n,m)) ;
		}
	}
	cout << mx ;
				
	return 0 ;
}

