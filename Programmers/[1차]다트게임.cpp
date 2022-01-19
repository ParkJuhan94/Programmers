/*
https://programmers.co.kr/learn/courses/30/lessons/17682

입출력 예제
예제	dartResult	answer	설명
1	1S2D*3T	37	11 * 2 + 22 * 2 + 33
2	1D2S#10S	9	12 + 21 * (-1) + 101
3	1D2S0T	3	12 + 21 + 03
4	1S*2T*3S	23	11 * 2 * 2 + 23 * 2 + 31
5	1D#2S*3S	5	12 * (-1) * 2 + 21 * 2 + 31
6	1T2D3D#	-4	13 + 22 + 32 * (-1)
7	1D2S3T*	59	12 + 21 * 2 + 33 * 2
*/
#include <iostream>
#include <string>

using namespace std;
int i;
int index = 0;      //중요. score의 몇번째 기회인지를 저장함.
int score[3];
string bonus[3];
string opt[3];

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();

    //점수 계산
    for (i = 0; i < len; i++) {
        if (dartResult[i] == '0') {
            if (dartResult[i - 1] == '1') {     //점수가 10일 때
                score[index] = 10;
                index++;
            }
            else {      //점수가 0일 때
                score[index] = 0;
                index++;
            }
        }
        else if (dartResult[i] == '1') {
            if (dartResult[i + 1] == '0') {     //점수가 10일 때
                //비움
            }
            else {      //점수가 1일 때
                score[index] = 1;
                index++;
            }
        }
        else if ('2' <= dartResult[i] && dartResult[i] <= '9') {
            score[index] = dartResult[i] - '0';
            index++;
        }
    }

    //보너스 계산 + 옵션 계산
    index = 0;
    for (i = 0; i < len; i++) {
        if (dartResult[i] == 'S') {     //1제곱이라서 index만 늘려줌
            index++;
        }
        else if (dartResult[i] == 'D') {    //점수를 2제곱
            score[index] = score[index] * score[index];
            index++;
        }
        else if (dartResult[i] == 'T') {    //점수를 3제곱
            score[index] = score[index] * score[index] * score[index];
            index++;
        }

        int optIndex = index - 1;

        if (dartResult[i] == '*') {
            if (optIndex == 0) {       //스타상이 첫 번째 기회에서 나올 때
                score[optIndex] *= 2;
            }
            else if (optIndex >= 1) {
                score[optIndex - 1] *= 2;
                score[optIndex] *= 2;
            }
        }
        else if (dartResult[i] == '#') {
            score[optIndex] *= -1;
        }
    }

    //최종 계산 
    for (auto s : score) {
        answer += s;
    }

    return answer;
}

int main() {
    string str;
    
    cin >> str;
    cout << solution(str) << endl;   
}