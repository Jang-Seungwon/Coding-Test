#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int answer;
    if(num_list.size() >= 11){
        answer = 0;
       for(auto a : num_list){
            answer += a;
        } 
    }
    else{
        answer = 1;
        for(auto a : num_list){
            answer *= a;
        }
    }
    return answer;
}