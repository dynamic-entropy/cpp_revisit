#include <iostream>
#include<chrono>
#include<thread>
#include<climits>
using namespace std;

typedef unsigned long long ull;

void evenSum(int from, int to, ull *evenResult){
	*evenResult =0;
	for(int i=from; i<=to; i++)
		if(!(i&1)) *evenResult += i;
}

void oddSum(int from, int to, ull *oddResult){
	*oddResult=0;
	for(int i=from; i<= to; i++)
		if(i&1) *oddResult += i;
}

int main(){

	int from=0, to=999999999;
	ull evenResult=0, oddResult=0;
	cout<<INT_MAX<<endl;
	auto startTime = std::chrono::high_resolution_clock::now();
	std::thread t1(evenSum, from, to, (&evenResult));
	std::thread t2(oddSum, from, to, (&oddResult));
	t1.join();
	t2.join();
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	cout<<"Threading Results : "<<endl;
	cout<<"Odd Sum = "<<oddResult<<endl;
	cout<<"Even Sum = "<<evenResult<<endl;
	cout << "Sec: " << duration.count()/1000000 << endl<<endl;

 	startTime = std::chrono::high_resolution_clock::now();
	evenSum(from, to, &evenResult);
	oddSum(from, to, &oddResult);
	endTime = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	cout<<"Non threaded (Single Main Thread) results : "<<endl;
	cout<<"Odd Sum = "<<oddResult<<endl;
	cout<<"Even Sum = "<<evenResult<<endl;
	cout << "Sec: " << duration.count()/1000000 << endl;

	}
