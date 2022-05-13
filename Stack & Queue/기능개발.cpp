#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

  //  peogress마다 소요일수를 계산 후 q에 저장
    for (int i = 0; i < progresses.size(); i++) {
        int res = 100 - progresses[i];
        if (res % speeds[i] != 0) res += speeds[i];
        q.push(res / speeds[i]);
    }

  //  cnt = 0 이고 day는 while 들어가자마자 else로 빠져서 cnt++ 됨. 자기 자신을 카운트 하는 것.
    int day = q.front();
    int cnt = 0;
    while (!q.empty()) {
      //  앞의 progress중 가장 큰 값이 day에 있고, day보다 큰 값이 처음 나오면
        if (day < q.front()) {
            answer.push_back(cnt);
            day = q.front();
            cnt = 0;
        }
          //  앞의 progress중 가장 큰 값이 day에 있고, day보다 작거나 같은 값이 나오면
        else {
            cnt++;
            q.pop();
        }
    }

    if (cnt != 0) answer.push_back(cnt);
    return answer;
}
