#include <stdio.h>
void inputReadings(int temp[][48], int sensors, int readings)
{
 int i, j;
 for (i = 0; i < sensors; i++)
 {
 printf("Sensor %d:\n", i + 1);
 for (j = 0; j < readings; j++)
 {
 printf(" Reading %d: ", j + 1);
 scanf("%d", &temp[i][j]);
 }
 }
}
float analyzeSensor(int r[], int n, int num)
{
 int i, total = 0, max = r[0], min = r[0];
 int critical = 0, warning = 0, streak = 0, longest = 0;
 float avg;
 for (i = 0; i < n; i++)
 {
 total = total + r[i];
 if (r[i] > max)
 max = r[i];
 if (r[i] < min)
 min = r[i];
if (r[i] >= 40)
 critical++;
 else if (r[i] >= 35)
 warning++;
 if (r[i] >= 35)
 {
 streak++;
 if (streak > longest)
 longest = streak;
 }
 else
 streak = 0;
 }
 avg = (float)total / n;
 printf("Sensor %d: Total=%d Avg=%.2f Max=%d Min=%d\n", num, total, avg, max, min);
 printf(" Critical=%d Warning=%d Longest hot streak=%d\n", critical, warning, longest);
 return avg;
}
int highestAverage(float avg[], int sensors)
{
 int i, best = 0;
 for (i = 1; i < sensors; i++)
 {
 if (avg[i] > avg[best])
 best = i;
 }
 return best + 1;
}
int main()
{
 int temp[10][48];
 float avg[10];
 int sensors, readings, i, best;
printf("Enter number of sensors (1-10): ");
 scanf("%d", &sensors);
 while (sensors < 1 || sensors > 10)
 {
 printf("Invalid. Enter again: ");
 scanf("%d", &sensors);
 }
 printf("Enter number of hourly readings (1-48): ");
 scanf("%d", &readings);
 while (readings < 1 || readings > 48)
 {
 printf("Invalid. Enter again: ");
 scanf("%d", &readings);
 }
 inputReadings(temp, sensors, readings);
 printf("\n");
 for (i = 0; i < sensors; i++)
 avg[i] = analyzeSensor(temp[i], readings, i + 1);
 best = highestAverage(avg, sensors);
 printf("\nHighest average: Sensor %d (%.2f)\n", best, avg[best - 1]);
 return 0;
}
