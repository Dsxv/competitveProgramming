#include <bits/stdc++.h>
using namespace std ;

#define int long long

map<string , map<string , int>> mp ;

void lower( string &s){
	for(auto &i : s){
		i = tolower(i) ;
	}
}

int32_t main(){
	int n;
	cin >> n ;
	while(n--){
		string a , b , c ;
		cin >> a >> b >> c ;
		lower(a) ;
		lower(c) ;
		mp[c][a] = 1 ;
	}
	string start = "polycarp" ;
	queue<pair<string,int>> q ;
	q.push({start , 1}) ;
	int md = 0 ;
	while(q.size()){
		string f = q.front().first ;
		int d = q.front().second ;
		md = max(d,md) ;
		q.pop() ;
		for(auto i : mp[f]){
			q.push({i.first,d+1}) ;
		}
	}
	cout << md ;
	return 0 ;
}

