#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string course;
    int result = 0;
    int curr_result = 0;
    cin >> n;
    vector<int> aKeys = {};
    map<int,vector<string>> all_course = {};
    map<int,string>::iterator it;
    for(int i = 0; i < n; i++){
        vector<string> stu_course = {};
        aKeys.push_back(i);
        for(int j = 0; j < 5; j++){
            cin >> course;
            stu_course.push_back(course);
        }
        sort(stu_course.begin(),stu_course.end());
        all_course[aKeys[i]] = stu_course;
    }
    map<vector<string>, int> course_count;
    for (const auto& pair : all_course) {
        course_count[pair.second]++;
    }

    int max_count = 0;
    for (const auto& pair : course_count) {
        max_count = max(max_count, pair.second);
    }
    if (max_count == 1){
        cout << n;
    }
    else{
        cout << max_count <<endl;
    }
    return 0;

}