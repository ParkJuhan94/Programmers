#include <iostream> 
#include <string> 
#include <vector>
#include <unordered_map> 
using namespace std; 

string solution(vector<string> participant, vector<string> completion) { 
  string answer = ""; 
  unordered_map<string, int> map; 
  
  /*
	name.find("one")
	키 값이 "one"인 원소의 iterator 리턴
	찾는 값이 없다면 name.end() 리턴
	*/
  
  for (auto player : participant) { 
    if (map.end() == map.find(player)) 
      map.insert(make_pair(player, 1)); 
    else map[player]++; 
  } 
  
  for (auto player : completion) 
    map[player]--;
  
  for(auto player : participant) 
    if (map[player] > 0) { 
      answer = player; 
      break;
    } 
  return answer; 
}
