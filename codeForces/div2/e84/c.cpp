#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n , m ;
map<int,char> mpx = {{-1,'U'} , {1,'D'}} ;
map<int,char> mpy = {{-1,'L'} , {1,'R'}} ;
string solve(pair<int,int> p , pair<int,int> q , int& x , int& y){
	int x1 = q.first - p.first ;
	int y1 = q.second - p.second ;
	//cout << p.first  << " " << p.second << endl ;
	string a = "" , b = "" ;
	if(y1){
		b = string(abs(y1),mpy[y1/abs(y1)]) ;
	}
	if(x1) {
		a = string(abs(x1),mpx[x1/abs(x1)]) ;
	}
	x = x1 , y = y1 ;
	return a+b ;
}

int32_t main(){
	int k ;
	cin >> n >> m >> k ;
	pair<int,int> p[k] , q[k];
	for(int i = 0 ; i < k ; i++){
		cin >> p[i].first >> p[i].second ;
		p[i].first-- , p[i].second-- ;
	}
	for(int i = 0 ; i < k ; i++){
		cin >> q[i].first >> q[i].second ;
		q[i].first-- , q[i].second-- ;
	}
	if(n == 1){
		cout << 2*m - 2<< endl ;
		string s = string(m-1,'R') + string(m-1,'L');
		cout << s << endl ;
		return 0 ;
	}
	if(m == 1){
		cout << 2*n - 2 << endl ;
		cout << (string(n-1,'D') + string(n-1,'U')) ;
		return 0 ;
	}
	int x = 0 , y = 0 ;
	string s = "" ;
	for(int i = 0 ; i < k ; i++){
		//cout << i << endl ;
		s += solve(p[i],q[i],x,y) ;
		for(int j = i+1 ; j < k ; j++){
			p[j].first = min(n-1, max(0LL,p[j].first+x)) ;
			p[j].second = min(m-1, max(0LL,p[j].second+y)) ;
		}
	}
	cout << s.size() << endl ;
	cout << s ;
	return 0 ;
}

