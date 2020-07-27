#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void swap(string& str, int start, int end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}
	bool IsExist(vector<string>& result, string& str) {
		for (auto it = result.begin(); it < result.end(); it++) {
			if (*it == str)
				return true;
		}
		return false;
	}

	void PermutationHelper(string& str, int start, vector<string>& result) {
		if (start == str.length() - 1) {
			//判断是否重复,再插入
			if (!IsExist(result, str))
				result.push_back(str);
		}
		for (int i = start; i < str.length(); i++) {
			swap(str, start, i);
			PermutationHelper(str, start + 1, result);
			swap(str, start, i);
		}
	}
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.length() > 0) {
			PermutationHelper(str, 0, result);
			sort(result.begin(), result.end());
		}
		return result;
	}
};

class Solution {
public:
	struct less {
		bool operator()(int a, int b) {
			return a < b;
		}
	};
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (input.empty() || k <= 0 || k > input.size()) {
			return result;
		}
		priority_queue<int, vector<int>, less> pq;//默认情况下,优先级队列为大堆
		for (int i = 0; i < input.size(); i++) {
			if (i < k) {
				pq.push(input[i]);
			}
			else {
				if (input[i] < pq.top()) {
					pq.pop();
					pq.push(input[i]);
				}
			}
		}
		for (int i = 0; i < k; i++) {
			result.push_back(pq.top());
			pq.pop();
		}
		return result;
	}
};
	