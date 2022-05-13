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

bool solution(vector<string> phone_book) { 
	// 1. HashMap을 만든다. 
	unordered_map<string, int> map; 

	for (int i = 0; i < phone_book.size(); i++)
		map[phone_book[i]] = 1;
	
	// 2. 모든 전화번호의 substring이 HashMap에 존재하는지 확인한다. 
	for (int i = 0; i < phone_book.size(); i++) { 
		for (int j = 0; j < phone_book[i].size() - 1; j++) { 
			string phone_number = phone_book[i].substr(0, j + 1); 

		//String이라는 Key가 현재 hash_map에 존재하는지 확인하는 동작이 이게 전부다		
		if (map[phone_number]) 
			return false; 
		}
	} 
	
	// 3. 여기까지 오면 접두어가 없다는 것이다. 
	return true; 
}
