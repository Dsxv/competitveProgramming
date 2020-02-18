#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<pair<int,string>> v ;

void nope(){
	cout << "NO\n" ;
}

bool repeat(string s , int n , int i , int& dis , int k , bool check){
	int val = max(0LL,n-i) ;
	if(val == 0) return false ;
	if(!check){
		if((dis + val) >= k){
			while((dis + val) > k) val-- ;
			v.push_back({val,s}) ;
			return true ;
		} else {
			dis += val ;
			v.push_back({val,s}) ;
		}
	} else {
		int sz = s.size() ;
		if((dis + val*sz) >= k){
			int x = (k-dis)/sz ;
			int y = (k-dis)%sz ;
			string temp = s.substr(0,y) ;
			if(x) v.push_back({x,s}) ;
			if(temp.size()) v.push_back({1,temp}) ;
			return true ;
		} else {
			dis += val*sz ;
			v.push_back({val,s}) ;
		}
	}
	return false ;
}

void solve(){
	int n , m , k ;
	cin >> n >> m >> k ;
	int dis = 0;
	if(k > 4*n*m - 2*n - 2*m) 
		{nope() ; return ;}
	cout << "YES\n" ;
	if(repeat("R",m,1,dis,k,false)) return ;
	if(repeat("L",m,1,dis,k,false)) return ;
	for(int i = 1 ; i < n ; i++){
		v.push_back({1,"D"}) ;
		dis++ ;
		if(dis == k) return ;
		if(repeat("RUD",m,1,dis,k,true)) return ;
		if(repeat("L",m,1,dis,k,false)) return ;
	}
	if(repeat("U",n,1,dis,k,false)) ;
}

int32_t main(){
	solve() ;
	if(v.size()){
		int x = v.size() ;
		assert(x <= 3000) ;
		cout << x << endl ;
		int sum = 0 ;
		for(auto i : v){
			sum += i.first*(i.second.size()) ;
			cout << i.first << " " << i.second << '\n' ;
		} 
		//cout << sum ;
	}
	return 0 ;
}

