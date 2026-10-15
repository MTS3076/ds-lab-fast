#include<iostream>
using namespace std;

void range(int n){
	if (n==0){
		return;
	}
	range(n-1);
	cout<<n<<" ";
	
}
int main(){
	range(5);
	
}
