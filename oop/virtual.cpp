#include <bits/stdc++.h>
using namespace std ;

#define int long long

class X{
	public : 
	void display(){
		cout << "X\n" ;
	}
	virtual void show(){
		cout << "show X\n" ;
	}
} ;

class Y : public X{
	public :
		void display(){
			cout << "Y\n" ;
		}
		void show(){
			cout << "show Y\n" ;
		}
} ;

int32_t main(){
	X a ;
	X *ptr = &a ;
	Y b ;
	ptr = &b ;
	ptr->show() ;
	ptr->display() ;
	return 0 ;
}

