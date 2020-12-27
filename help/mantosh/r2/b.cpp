#include <bits/stdc++.h>
using namespace std ;

#define int long long

double nthTerm(double input1 , double input2 , int input3){
	double r = input2 / input1 ;
	double a = input1 / r ;

 	char charray[200];
    double ans = a * pow(r , input3 - 1) ;
    sprintf(charray, "%2.3f", ans);
    char* c = &charray[0];
	double a1 = 0 , a2 = 0 ;
	int l = 0 ;
	while(c[l] != '.') l++ ;
	l++ ;
	while(c[l]) {
		a1 *= 10 ;
		a1 += c[l] - '0' ;
		l++ ;
	}
	l = 0 ;
	while(c[l] != '.') {
		a2 *= 10 ;
		a2 += c[l] - '0' ;
		l++ ;
	}
	a2 += a1 / (double)1000 ;
	return a2 ;
}

int32_t main(){
	double a ,b ;
	int n ;
	cin >> a >> b >> n ;
	cout << nthTerm(a , b , n) ;
	return 0 ;
}

