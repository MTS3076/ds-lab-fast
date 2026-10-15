#include<iostream>
using namespace std;

int sum(int n){
	if (n==0){
		return 0;
	}
	int x = n % 10;
	n = n / 10;
	return x + sum(n);	
}
int main(){
	cout <<	sum(346);	
}
