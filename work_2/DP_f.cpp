#include <cstdio>
#include <vector>

using namespace std;
int cou=0;
class Solution {
public:
   int Fibonacci(int n) {
      vector<int> r(n, 0);
      r[0] = r[1] = 1;
      for (int i = 2; i < n; i++) {
         r[i] = r[i - 1] + r[i - 2];
         cou++;
      }
      return r[n - 1];
   }
};

int main() {
   int n;
   printf("please enter n:\n");
   scanf("%d",&n);
   Solution s;
   int sum = s.Fibonacci(n);
   printf("sum=%d\n", sum);
   printf("基本操作的次数为：%d", cou);
   return 0;
}
