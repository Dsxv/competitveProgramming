#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct line{
	int m , c ;
	line(){
		m = 0 , c = 0 ;
	}
	line(int m , int c){
		this->m = m ; this->c = c;
	}
} ;

int eval(int x , line l){
	return x*l.m + l.c ;
}

long double intersectX(line a , line b){
	return (long double) (b.c - a.c) / (long double) (a.m - b.m) ;
}

vector<long double> points ; // intersectX between lines
vector<line> v ; // current lines

void insert(line l){
	if(v.empty()){
		v.push_back(l) ;
		return ;
	}
	while(points.size() && 
			intersectX(l , v[v.size() - 2]) <= intersectX(v.back() , v[v.size() - 2])){
		v.pop_back() ;
		points.pop_back() ;
	} // at least 1 size of v will remain
	points.push_back(intersectX(l , v.back())) ;
	v.push_back(l) ;
}

int query(int x){
	int id = lower_bound(points.begin() , points.end() , x) - points.begin() ;
	return eval(x , v[id]) ;
}
	
int32_t main(){
	line l ;
	int n ;
	cin >> n ;
	int a , b , c ;
	cin >> a >> b >> c ;
	int sum[n+1] = {} ;
	for(int i = 1 ; i <= n ; i++){
		int x ; cin >> x ;
		sum[i] = sum[i-1] + x ;
	}
	insert(l) ;
	int dp[n+1] = {} ;
	for(int i = 1 ; i <= n ; i++){
		dp[i] = query(-2*a*sum[i]) + sum[i]*(a*sum[i] + b) + c  ;
		l.m = sum[i] ;
		l.c = a*sum[i]*sum[i] - b*sum[i] + dp[i] ;
		insert(l) ;
	}
	cout << dp[n] ;
	return 0 ;
}


