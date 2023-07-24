#include <string>
#include <vector>

using namespace std;

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int days = 0;
    for (int i=1; i<a; i++) {
        days += month[i];
    }
    days += b-1;
    answer = day[days%7];
    return answer;
}