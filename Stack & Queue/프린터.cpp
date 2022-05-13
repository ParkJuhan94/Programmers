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

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;    
    queue<pair<int, int>> que;    
    priority_queue <int> prio_que;

    for (int i = 0; i < priorities.size(); i++) {
        //큐에 들어온 순서와 중요도를 넣음
        que.push(make_pair(i, priorities[i]));
        //우선순큐에 넣음
        prio_que.push(priorities[i]);
    }
    //큐가 빌때까지 반복
    while (!que.empty()) {
        int index = que.front().first;
        int value = que.front().second;
        que.pop();
        //우선순위 1순위와 현재값이 같다면
        if (prio_que.top() == value) {
            //우선순위큐 pop
            prio_que.pop();
            //하나가 나갔으므로 countW
            count++;
            //현재 나간것이 원하는것과 같다면
            if (index == location) {
                //현재 카운터를 리턴
                answer = count;
                break;
            }
        }
        //우선순위 1순위와 현재값이 같지않다면 큐 뒤에 넣기
        else
            que.push(make_pair(index, value));
    }
    return answer;
}
