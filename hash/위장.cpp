#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int i, j;
	unordered_map<string, int> map;

	for (auto clothe : clothes) {	
		map[clothe[1]] += 1;
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		answer *= (it->second + 1);
	}

	answer--;

	return answer;
}
