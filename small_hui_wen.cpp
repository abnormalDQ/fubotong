#include <vector>
#include <iostream>
#include<math.h>

using namespace std;
//数字反转，123->321
int reverse(int n){
	int count=0;
	int result = 0;
	while(n){
		result = 10*result + (n%10);
		n = n/10;
		++count;
	}
	return result;
}
//返回比n大的最小回文数
//left_reverse > right -> right= left_reverse
//example:n=1234,left=12, right=34
//	left+1=13,right=reverse(left)=31
//	result = left + right = 1331
//example:n=12934,left=12, right=34, leftMiddle=129
//	left_middle + 1=130, right=reverse(left_middle)=031
//	result = left_middle/10 + right = 13031
int fun(int n){
	cout << "n:"<<n <<endl;
	vector<int> table;
	int temp = n;
	while(temp){
		table.push_back(temp%10);
		temp = temp/10;
	}
	int middleSize = table.size()/2;
	int model = pow(10,middleSize);
	int left = n / model;
	int right = n % model;


	if(table.size()%2 == 1){
		left = n / (model*10);
	}

	int leftReverse = reverse(left);
    //left include middle.example:n=123,left=12
	if(table.size()%2 == 1){
		left = left*10 + table[middleSize];
	}

	if(leftReverse < right){
		if(table.size()%2 == 1){
			++left;
			leftReverse = reverse(left);
			left = left/10;
			model *= 10;
		}
		else{
			++left;
			leftReverse = reverse(left);
			
		}
	}
	else{
		if(table.size()%2 == 1){
			left = left * 10 + table[middleSize];
		}
	}
	return left * model + leftReverse; 
}

int main(){
	int n= 123;
	cout << "reverse:"<<reverse(n)<<endl;
	n= 1233;
	cout << "fun:"<<fun(n)<<endl;
	n= 12933;
	cout << "fun:"<<fun(n)<<endl;
	cin >> n;
	return 0;
}