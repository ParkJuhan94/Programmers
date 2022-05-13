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
    bool answer = true;
    int i, j, flag = 0;
    sort(phone_book.begin(), phone_book.end());

    for (i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i+1].find(phone_book[i]) == 0) {
            return false;
        }
    }



    return answer;
}
