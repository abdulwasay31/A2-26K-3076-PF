#include <stdio.h>
int main()
{
 int seats[20][30];
 int rows, cols, k;
 int i, j, d, s, r;
 int mid, count, rowFree, total;
 int found = 0, foundRow = 0, start = 0;
 printf("Enter number of rows: ");
 scanf("%d", &rows);
 while (rows < 1 || rows > 20)
 {
 printf("Invalid. Enter rows (1-20): ");
scanf("%d", &rows);
 }
 printf("Enter number of seats per row: ");
 scanf("%d", &cols);
 while (cols < 1 || cols > 30)
 {
 printf("Invalid. Enter seats (1-30): ");
 scanf("%d", &cols);
 }
 printf("Enter seat status (0 = available, 1 = booked):\n");
 for (i = 0; i < rows; i++)
 {
 for (j = 0; j < cols; j++)
 {
 scanf("%d", &seats[i][j]);
 while (seats[i][j] != 0 && seats[i][j] != 1)
 {
 printf("Enter only 0 or 1: ");
 scanf("%d", &seats[i][j]);
}
 }
 }
 printf("\nSeating plan:\n ");
 for (j = 0; j < cols; j++)
 printf("%3d", j);
 printf("\n");
 for (i = 0; i < rows; i++)
 {
 printf("R%-3d", i);
 for (j = 0; j < cols; j++)
 {
 if (seats[i][j] == 0)
 printf("%3c", '_');
 else
 printf("%3c", 'X');
 }
 printf("\n");
 }
 total = 0;
 printf("\nFree seats per row:");
 for (i = 0; i < rows; i++)
 {
 rowFree = 0;
 for (j = 0; j < cols; j++)
 {
 if (seats[i][j] == 0)
 rowFree++;
 }
 printf(" %d", rowFree);
 total = total + rowFree;
 }
 printf(" Total free: %d\n", total);
printf("\nEnter number of customers in the group: ");
 scanf("%d", &k);
 while (k <= 0 || k > cols)
 {
 printf("Invalid group size. Enter between 1 and %d: ", cols);
 scanf("%d", &k);
 }
 mid = rows / 2;
 for (d = 0; d < rows && found == 0; d++)
 {
 for (s = 0; s < 2 && found == 0; s++)
 {
 if (s == 1 && d == 0)
 continue;
 if (s == 0)
 r = mid - d;
 else
r = mid + d;
 if (r < 0 || r >= rows)
 continue;
 count = 0;
 for (j = 0; j < cols && found == 0; j++)
 {
 if (seats[r][j] == 0)
 {
 count++;
 if (count == k)
 {
 found = 1;
 foundRow = r;
 start = j - k + 1;
 }
 }
 else
 count = 0;
 }
 }
 }
 if (found == 1)
 {
 for (j = start; j < start + k; j++)
 seats[foundRow][j] = 1;
 total = total - k;
 printf("\nGroup of %d seated in Row %d, Seats %d to %d\n", k, foundRow, start, start + k - 1);
 printf("\nUpdated seating plan:\n ");
for (j = 0; j < cols; j++)
 printf("%3d", j);
 printf("\n");
 for (i = 0; i < rows; i++)
 {
 printf("R%-3d", i);
 for (j = 0; j < cols; j++)
 {
 if (seats[i][j] == 0)
 printf("%3c", '_');
 else
 printf("%3c", 'X');
 }
 printf("\n");
 }
 printf("\nRemaining available seats: %d\n", total);
 }
 else
 {
 printf("\nSorry, no row has %d consecutive available seats.\n", k);
 printf("Seating plan is unchanged.\n");
 }
 return 0;
}
