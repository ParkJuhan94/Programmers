/*
https://programmers.co.kr/learn/courses/30/lessons/17682

����� ����
����	dartResult	answer	����
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
int index = 0;      //�߿�. score�� ���° ��ȸ������ ������.
int score[3];
string bonus[3];
string opt[3];

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();

    //���� ���
    for (i = 0; i < len; i++) {
        if (dartResult[i] == '0') {
            if (dartResult[i - 1] == '1') {     //������ 10�� ��
                score[index] = 10;
                index++;
            }
            else {      //������ 0�� ��
                score[index] = 0;
                index++;
            }
        }
        else if (dartResult[i] == '1') {
            if (dartResult[i + 1] == '0') {     //������ 10�� ��
                //���
            }
            else {      //������ 1�� ��
                score[index] = 1;
                index++;
            }
        }
        else if ('2' <= dartResult[i] && dartResult[i] <= '9') {
            score[index] = dartResult[i] - '0';
            index++;
        }
    }

    //���ʽ� ��� + �ɼ� ���
    index = 0;
    for (i = 0; i < len; i++) {
        if (dartResult[i] == 'S') {     //1�����̶� index�� �÷���
            index++;
        }
        else if (dartResult[i] == 'D') {    //������ 2����
            score[index] = score[index] * score[index];
            index++;
        }
        else if (dartResult[i] == 'T') {    //������ 3����
            score[index] = score[index] * score[index] * score[index];
            index++;
        }

        int optIndex = index - 1;

        if (dartResult[i] == '*') {
            if (optIndex == 0) {       //��Ÿ���� ù ��° ��ȸ���� ���� ��
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

    //���� ��� 
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