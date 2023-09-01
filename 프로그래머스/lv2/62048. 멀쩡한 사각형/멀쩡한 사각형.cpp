using namespace std;

long long solution(int w,int h) {
    long long answer = 0;

    double a = (double)h/w;
    for (int i=1; i<w; i++) {
        answer += (int)(h-a*i)*2;
    }
    
    return answer;
}
