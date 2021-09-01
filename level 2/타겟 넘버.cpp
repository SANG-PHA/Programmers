#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> nums, int& answer, int target, int depth = 0, int sum = 0)
{
    // 종료 조건
    if(depth == nums.size() - 1)
    {
        if(sum + nums[depth] == target)
            answer++;
        if(sum - nums[depth] == target)
            answer++;
        return;
    }
    
    // 계속 진행
    DFS(nums, answer, target, depth + 1, sum + nums[depth]);
    DFS(nums, answer, target, depth + 1, sum - nums[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, answer, target);
    return answer;
}
