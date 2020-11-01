#include <bits/stdc++.h>
using namespace std ;

#define int long long

pair<int,int> getHM(string h){
	if(h.size() != 5) return {-1 , -1} ;
	if(!isdigit(h[0]) || !isdigit(h[1]) || !isdigit(h[3]) || !isdigit(h[4])) return {-1 , -1} ;
	if(h[2] != '.') return {-1 , -1} ;
	int hour = (h[0] - '0') * 10 + (h[1] - '0') ;
	int minute = (h[3] - '0') * 10 + (h[4] - '0') ;
	if(hour >= 24 || minute >= 60) return {-1 , -1} ;
	return {hour , minute} ;
}

void addTime(pair<int,int> &p , int x){
	int val = p.second + x ;
	p = { (p.first + val / 60 ) % 24 , val % 60 } ;
}

string solve(pair<int,int> &p){
	string ans = "" ;
	if(p.first < 10) ans += "0" ;
	ans += to_string(p.first) ;
	ans += "." ;
	if(p.second < 10) ans += "0" ;
	ans += to_string(p.second) ;
	return ans ;
}

int32_t main(){
	string h ;
	cin >> h ;
	pair<int,int> p = getHM(h) ;
	if(p.first == -1){
		cout << "INVALID INPUT" ;
		return 0 ;
	}
	int ar[6] = {0 , 4 , 5 , 6 , 4 , 3} ;
	for(int i = 0 ; i < 6 ; i++){
		addTime(p , ar[i]) ;
		cout << solve(p) << " " ;
	}
	return 0 ;
}

