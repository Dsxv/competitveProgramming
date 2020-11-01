#include <bits/stdc++.h>
using namespace std ;

#define int long long

char mov[4] = {'E' , 'S' , 'W' , 'N'} ;

int getval(string& s){
	int l = 0 ;
	int val = 0 ;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '-'){
			s = s.substr(i+1) ;
			return val ;
		}
		val = val*10 + s[i] - '0' ;
	}
	return val ;
}

int setdxdy(int &dx , int&dy , int dir){
	if(dir == 0) dx = 1 , dy = 0 ;
	if(dir == 1) dx = 0 , dy = -1 ;
	if(dir == 2) dx = -1 , dy = 0 ;
	if(dir == 3) dx = 0 , dy = 1 ;
}

string setval(int cx , int cy , int dir){
	return (to_string(cx) + '-' + to_string(cy) + '-') + mov[dir] ;
}

string moveRobot(int input1 , int input2 , string input3 , string input4){
	int n = input1 , m = input2 ;
	int cx = getval(input3) , cy = getval(input3) ;
	int dx = 0 , dy = 0 ;
	int dir = 0 ;
	for(int i = 1 ; i < 4 ; i++) if(mov[i] == input3[0]) dir = i ; // set direction
	cout << cx << ":" << cy << endl ;
	for(auto i : input4){
		cout << cx << " " << cy << endl ;
		if(i == 'R'){
			dir = (dir+1)%4 ;
		}
		if(i == 'L'){
			dir = (dir-1+4)%4 ;
		}
		setdxdy(dx , dy , dir) ;
		int cnt = 0 ;
		if(i == 'm') cnt = 1 ;
		if(i == 'M') cnt = 2 ;
		int nx = cx + cnt*dx , ny = cy + cnt*dy ;
		if(nx >= 0 && ny >= 0 && nx <= n && ny <= m){
			cx = nx , cy = ny ;
		} else {
			return setval(cx , cy , dir) + "-ER" ;
		}
	}
	return setval(cx , cy , dir) ;
}

int32_t main(){
	cout << moveRobot(2 , 2 , "1-1-N" , "m R m") ;
	return 0 ;
}

