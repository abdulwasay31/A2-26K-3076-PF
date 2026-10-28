#include <stdio.h>
#include <string.h>
#define TOTAL_BOOKS 4
#define MAX_BORROW 3
#define STUDENT 1
#define FACULTY 2
void displayMenu();
void registerMember(char name[], int *studentID, int *memberType);
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks);
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
 int borrowedBookIDs[], int *borrowedCount, int memberType);
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine);
void displayMemberRecord(char name[], int studentID, int memberType,
 int borrowedBookIDs[], int borrowedCount,
 float totalFine, float fineAfterWaiver);
int main()
{
 int bookIDs[TOTAL_BOOKS] = {101, 102, 103, 104};
char bookTitles[TOTAL_BOOKS][50] = {"Programming in C", "Data Structures",
 "Database Systems", "Computer Networks"};
 int availableCopies[TOTAL_BOOKS] = {5, 3, 0, 4};
 char name[50] = "";
 int studentID = 0, memberType = 0;
 int borrowedBookIDs[MAX_BORROW];
 int borrowedCount = 0;
 float totalFine = 0, fineAfterWaiver = 0;
 int registered = 0;
 int choice;
 do
 {
 displayMenu();
 if (scanf("%d", &choice) != 1)
 {
 while (getchar() != '\n')
 ;
 choice = 0;
 }
 switch (choice)
 {
 case 1:
 if (registered)
 printf("A member is already registered.\n");
 else
 {
 registerMember(name, &studentID, &memberType);
 registered = 1;
 }
 break;
 case 2:
 displayBooks(bookIDs, bookTitles, availableCopies, TOTAL_BOOKS);
 break;
case 3:
 if (!registered)
 printf("Please register a member first (option 1).\n");
 else
 borrowBook(bookIDs, bookTitles, availableCopies, TOTAL_BOOKS,
 borrowedBookIDs, &borrowedCount, memberType);
 break;
 case 4:
 if (!registered)
 printf("Please register a member first (option 1).\n");
 else
 fineAfterWaiver += returnBook(bookIDs, availableCopies, TOTAL_BOOKS,
 borrowedBookIDs, &borrowedCount,
 memberType, &totalFine);
 break;
 case 5:
 if (!registered)
 printf("Please register a member first (option 1).\n");
 else
 displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
 borrowedCount, totalFine, fineAfterWaiver);
 break;
 case 6:
 printf("Thank you. Goodbye!\n");
 break;
 default:
 printf("Invalid choice! Please select 1-6.\n");
 }
 } while (choice != 6);
 return 0;
}
void displayMenu()
{
 
 printf("1. Register Member\n");
 printf("2. Display Available Books\n");
 printf("3. Borrow a Book\n");
 printf("4. Return a Book\n");
 printf("5. Display Member Record\n");
 printf("6. Exit\n");
 printf("Enter your choice: ");
}
void registerMember(char name[], int *studentID, int *memberType)
{
 printf("Enter name: ");
 scanf(" %49[^\n]", name);
 printf("Enter student ID: ");
 scanf("%d", studentID);
 printf("Membership type (1 = Student, 2 = Faculty): ");
 scanf("%d", memberType);
 while (*memberType != STUDENT && *memberType != FACULTY)
 {
 printf("Invalid type! Enter 1 for Student or 2 for Faculty: ");
 scanf("%d", memberType);
 }
 if (*memberType == STUDENT)
 printf("Registered as Student (can keep books for 14 days).\n");
 else
 printf("Registered as Faculty (can keep books for 30 days).\n");
}
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)
{
 int i;

 printf("| ID | Title | Copies |\n");

 for (i = 0; i < totalBooks; i++)
 printf("| %-3d | %-20s | %-6d |\n", bookIDs[i], bookTitles[i], availableCopies[i]);

}
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
 int borrowedBookIDs[], int *borrowedCount, int memberType)
{
 int id, days, i, index = -1, allowed;
 if (*borrowedCount >= MAX_BORROW)
 {
 printf("Limit reached! You can borrow a maximum of %d books at a time.\n", MAX_BORROW);
 return;
 }
 printf("Enter book ID: ");
 scanf("%d", &id);
 printf("Enter number of days you want to keep the book: ");
 scanf("%d", &days);
 while (days <= 0)
 {
 printf("Days must be positive. Enter again: ");
 scanf("%d", &days);
 }
 for (i = 0; i < totalBooks; i++)
 {
 if (bookIDs[i] == id)
 index = i;
 }
 if (index == -1)
 {
 printf("Invalid book ID!\n");
 return;
 }
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
 int borrowedBookIDs[], int *borrowedCount, int memberType)
{
 int id, days, i, index = -1, allowed;
 if (*borrowedCount >= MAX_BORROW)
 {
 printf("Limit reached! You can borrow a maximum of %d books at a time.\n", MAX_BORROW);
 return;
 }
 printf("Enter book ID: ");
 scanf("%d", &id);
 printf("Enter number of days you want to keep the book: ");
 scanf("%d", &days);
 while (days <= 0)
 {
 printf("Days must be positive. Enter again: ");
 scanf("%d", &days);
 }
 for (i = 0; i < totalBooks; i++)
 {
 if (bookIDs[i] == id)
 index = i;
 }
 if (index == -1)
 {
 printf("Invalid book ID!\n");
 return;
 }
if (availableCopies[index] == 0)
 {
 printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[index]);
 return;
 }
 for (i = 0; i < *borrowedCount; i++)
 {
 if (borrowedBookIDs[i] == id)
 {
 printf("You have already borrowed this book.\n");
 return;
 }
 }
 if (memberType == STUDENT)
 allowed = 14;
 else
 allowed = 30;
 borrowedBookIDs[*borrowedCount] = id;
 (*borrowedCount)++;
 availableCopies[index]--;
 printf("You borrowed \"%s\".\n", bookTitles[index]);
 if (days > allowed)
 printf("Note: your membership allows only %d days. Fine applies after that.\n", allowed);
}
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)
{
 int id, days, i, pos = -1, bookIndex = -1, allowed, extra, rate;
 float fine = 0, payable = 0;
 char code[20];
 if (*borrowedCount == 0)
 {
 printf("You have no borrowed books to return.\n");
 return 0;
 }
 printf("Enter book ID to return: ");
scanf("%d", &id);
 for (i = 0; i < *borrowedCount; i++)
 {
 if (borrowedBookIDs[i] == id)
 pos = i;
 }
 if (pos == -1)
 {
 printf("You have not borrowed this book!\n");
 return 0;
 }
 printf("Enter actual number of days the book was kept: ");
 scanf("%d", &days);
 while (days <= 0)
 {
 printf("Days must be positive. Enter again: ");
 scanf("%d", &days);
 }
 for (i = 0; i < totalBooks; i++)
 {
 if (bookIDs[i] == id)
 bookIndex = i;
 }
 availableCopies[bookIndex]++;
 if (memberType == STUDENT)
 {
 allowed = 14;
 rate = 20;
 }
 else
   {
 allowed = 30;
 rate = 10;
 }
 if (days > allowed)
 {
 extra = days - allowed;
 fine = extra * rate;
 *totalFine = *totalFine + fine;
 printf("Returned %d day(s) late. Fine: Rs. %.2f\n", extra, fine);
 printf("Enter membership code for a 50%% waiver (or any text to skip): ");
 scanf("%19s", code);
 if (strcmp(code, "LIB2026") == 0)
 {
 payable = fine / 2;
 printf("Code accepted. 50%% waiver applied.\n");
 }
 else
 {
 payable = fine;
 printf("Incorrect code. No waiver applied.\n");
 }
 printf("Fine payable for this return: Rs. %.2f\n", payable);
 }
 else
 {
 printf("Book returned on time. No fine.\n");
 }

 for (i = pos; i < *borrowedCount - 1; i++)
 borrowedBookIDs[i] = borrowedBookIDs[i + 1];
 (*borrowedCount)--;
 return payable;
}
void displayMemberRecord(char name[], int studentID, int memberType,
 int borrowedBookIDs[], int borrowedCount,
 float totalFine, float fineAfterWaiver)
{
 int i;
 printf("\n===== MEMBER RECORD =====\n");
 printf("Name: %s\n", name);
 printf("Student ID: %d\n", studentID);
 printf("Membership type: %s\n", memberType == STUDENT ? "Student" : "Faculty");
 printf("Currently borrowed books: ");
 if (borrowedCount == 0)
 printf("None");
 for (i = 0; i < borrowedCount; i++)
 printf("%d ", borrowedBookIDs[i]);
 printf("\n");
 printf("Total fine before waiver: Rs. %.2f\n", totalFine);
 printf("Final fine payable: Rs. %.2f\n", fineAfterWaiver);
}
