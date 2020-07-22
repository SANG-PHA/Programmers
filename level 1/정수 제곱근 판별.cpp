#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long tmp = sqrt(n);
    
    if( pow(tmp,2) == n)
        return pow(tmp+1, 2);
    else return -1;
}
