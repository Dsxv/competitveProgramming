#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
map<int,int> G[N] ;

pair<int,int> comp(pair<int,int> p , pair<int,int> cur) {
	if(p.second > cur.second) return p ;
	return cur ;
}

pair<int,int> dfs(int st , int d = 0  , int p = -1){
	pair<int,int> cur = {st,d} ;
	//cout << st + 1<< ":  " ; 
	for(auto i : G[st]){
		if(i.first != p){
			cur = comp(cur,dfs(i.first,d+1,st)) ;
			//cout << i.first + 1 << " " ;
		}
	}
	return cur ;
}

bool solve_utl(vector<int>& v , int st , int des, int p = -1){
	if(st == des) return true;
	for(auto i : G[st]){
		if(i.first == p) continue ;
		v.push_back(i.first) ;
		if(solve_utl(v,i.first,des,st)) return true ;
		v.pop_back() ;
	}
	return false ;
}

vector<int> solve(int st , int des) {
	vector<int> v ;
	v.push_back(st) ;
	solve_utl(v,st,des) ;
	return v ;
}

void del(int f , int s){
	G[f].erase(s) ;
	G[s].erase(f) ;
}
void add(int f , int s){
	G[f][s] = 1 ;
	G[s][f] = 1 ;
}

int32_t main(){
	int n ;
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++) {
		int f ,s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f][s] = 1 ;
		G[s][f] = 1 ;
	}
	int x = dfs(0).first ;
	int y = dfs(x).first ;
	vector<int> way = solve(x,y) ;
	reverse(way.begin(),way.end()) ;
	//for(auto i : way) cout << i << " " ; cout << endl ;
	//int x = 0 , y = 5 ;
	//vector<int> way = {0,1,2,3,5} ;
	pair<int,int> ans = {-1,INT_MIN} ;
	n = way.size() ;
	for(int i = 0 ; i < n ; i++){
		if(i == 0 || i == n-1) continue ;
		del(way[i-1],way[i]) ;
		del(way[i],way[i+1]) ;
		//cout << i+1 << "-" ;
		ans = comp(ans,dfs(i)) ;
		//cout << i+1 << " : " << ans.second << endl ;
		add(way[i],way[i+1]) ;
		add(way[i],way[i-1]) ;
	}
	//cout << ans.second << endl ;
	cout << ans.second + n - 1 << endl;
	cout << x+1 << " " << ans.first + 1 << " " << y+1 ;
	return 0 ;
}

