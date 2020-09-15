#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dx[8] = {0,0,-1,1,1,1,-1,-1} ;
int dy[8] = {-1,1,0,0,1,-1,1,-1} ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int x , y , x1 , y1 ;
	int n ;
	cin >> x >> y >> x1 >> y1 ;
	cin >> n ;
	set<pair<int,int>> s ;
	while(n--){
		int ri , ai , bi ;
		cin >> ri >> ai >> bi ;
		for(int j = ai , i = ri; j <= bi ; j++){
			s.insert({i,j}) ;
		}
	}
	vector<int> st = {x,y,0} ;
	queue<vector<int>> q ;
	set<pair<int,int>> visited ;
	q.push(st) ;
	while(q.size()){
		st = q.front() ;
		q.pop() ;
		if(st[0] == x1 && st[1] == y1){
			cout << st[2] ;
			return 0 ;
		}
		for(int i = 0 ; i < 8 ; i++){
			int xi = st[0] + dx[i] ;
			int yi = st[1] + dy[i] ;
			if(s.count({xi,yi}) && !visited.count({xi,yi})){
				visited.insert({xi,yi}) ;
				q.push({xi , yi , st[2] + 1}) ;
			}
		}
	}
	cout << -1 ;
	return 0 ;
}

