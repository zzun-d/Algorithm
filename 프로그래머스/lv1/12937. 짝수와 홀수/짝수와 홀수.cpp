#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    return num & 1 ? answer = "Odd" : answer = "Even";
}