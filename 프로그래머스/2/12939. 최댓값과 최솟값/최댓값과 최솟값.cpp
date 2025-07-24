#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string str = "";
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            v.push_back(stoi(str));
            str = "";
        }
        else str += s[i];
    }
    if(str != "") v.push_back(stoi(str));
    
    sort(v.begin(),v.end());
    answer += to_string(v[0]) + ' '; // 정수를 문자열로 변환하여 추가
    answer += to_string(v[v.size() - 1]); // 정수를 문자열로 변환하여 추가
    
    return answer;
}