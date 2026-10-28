#include <stdio.h>
int sumDivisors(int x)
{
 int i, sum = 0;
 for (i = 1; i <= x / 2; i++)
 {
 if (x % i == 0)
 sum = sum + i;
 }
 return sum;
}
int main()
{
 int n, a, b, count = 0;
 printf("Enter n: ");
 scanf("%d", &n);
 printf("Amicable pairs up to %d:\n", n);
 for (a = 2; a <= n; a++)
 {
 b = sumDivisors(a);
 if (b > a && b <= n && sumDivisors(b) == a)
 {
 printf("(%d, %d)\n", a, b);
 count++;
 }
 }
 if (count == 0)
 printf("No amicable pairs found.\n");
 else
 printf("Total pairs: %d\n", count);
 return 0;
}
