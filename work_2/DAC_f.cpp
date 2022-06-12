#include <cstdio>
#include <vector>

using namespace std;
int cou=0;

class Solution {
public:
   int Fibonacci(int n) {
      if (n == 1 || n == 2)
         return 1;
      else
        cou++;
         return Fibonacci(n - 1) + Fibonacci(n - 2);
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

