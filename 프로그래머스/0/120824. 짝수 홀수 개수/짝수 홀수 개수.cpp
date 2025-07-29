#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int m = 0;
    int n = 0;
    for(auto i : num_list){
        if(i % 2 == 0) m++;
        else n++;
    }
    answer.push_back(m);
    answer.push_back(n);
    return answer;
}