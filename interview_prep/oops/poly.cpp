#include <bits/stdc++.h>
using namespace std ;

#define int long long

class A{
	public :
		void show(){
			cout << "Show A\n" ;
		}
		virtual void print(){
			cout << "Print A\n" ;
		}
		~A(){
			cout << "Destructor A" ;
		}
} ;

class B : public A{
	public : 
		b()
		void show(){
			A :: show () ;			
		}
		void print(){
			cout << "Print B" ;
		}
		~B(){
			cout << "hello" ;
		}
} ;

int32_t main(){
	return 0 ;
}

