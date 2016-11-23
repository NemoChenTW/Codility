/*
 * main.cpp
 *
 *  Created on: Nov 23, 2016
 *      Author: peter
 */

/*
		A zero-indexed array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is also moved to the first place.

		For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7]. The goal is to rotate array A K times; that is, each element of A will be shifted to the right by K indexes.

		Write a function:

		vector<int> solution(vector<int> &A, int K);

		that, given a zero-indexed array A consisting of N integers and an integer K, returns the array A rotated K times.

		For example, given array A = [3, 8, 9, 7, 6] and K = 3, the function should return [9, 7, 6, 3, 8].

		Assume that:

		N and K are integers within the range [0..100];
		each element of array A is an integer within the range [−1,000..1,000].
		In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


vector<int> solution(vector<int> &A, int K)
{
	// write your code in C++11 (g++ 4.8.2)

	int length = A.size();

	if(length == 0 || K == 0)
		return A;

	while(K >= length)
	{
		K-=length;
	}

	rotate(A.rbegin(), A.rbegin() + K, A.rend());

    return A;
}


void showVector(const vector<int> &A)
{
	for(auto i = A.begin(); i != A.end(); i++)
	{
		cout << (*i);

		if(i + 1 != A.end())
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}
}

int main()
{
	vector<int> caseA = {1, 2, 3, 4, 5};

	showVector(caseA);

	cout << "Rotate 3:" << endl;
	solution(caseA, 3);
	showVector(caseA);

	return 0;
}
