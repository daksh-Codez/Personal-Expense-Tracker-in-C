//This code is Written by: Daksh Goswami ( A CS Major Student at Galgotias University )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    int id;
    float amount;
    char category[30];
    char description[100];
    char date[15];
    char type[10];
};
    struct Transaction transactions[100];

int main() {
    int choice;
    int count = 0;
        printf("===============================\n");
        printf("   PERSONAL EXPENSE TRACKER\n");
        printf("===============================\n");

        while (1) {
            printf("\n1. Add Income\n");
            printf("2. Add Expense\n");
            printf("3. View Transactions\n");
            printf("4. Search Transaction\n");
            printf("5. View Balance\n");
            printf("6. Monthly Summary\n");
            printf("7. Exit\n");

            printf("\nEnter your choice: ");
                scanf("%d", &choice);

            switch (choice) {
                case 1:
                    if (count >= 100) {
                        printf("Transaction limit reached!\n");
                            break;
                    }
                    printf("Add Income selected.\n");
                        transactions[count].id = count + 1;
                    printf("\nEnter income amount: ");
                        scanf("%f", &transactions[count].amount);
                    printf("Enter category: ");
                        scanf("%29s", transactions[count].category);
                    printf("Enter description: ");
                        scanf(" %99[^\n]", transactions[count].description);
                    printf("Enter date (DD-MM-YYYY): ");
                        scanf("%14s", transactions[count].date);

                    strcpy(transactions[count].type, "Income");
                        count++;

                    printf("\nIncome added successfully!\n");
                        break;  
                case 2:
                    if (count >= 100) {
                        printf("Transaction limit reached!\n");
                            break;
                    }
                    printf("Add Expense selected.\n");
                        transactions[count].id = count + 1;
                    printf("\nEnter expense amount: ");
                        scanf("%f", &transactions[count].amount);
                    printf("Enter category: ");
                        scanf("%29s", transactions[count].category);
                    printf("Enter description: ");
                        scanf(" %99[^\n]", transactions[count].description);
                    printf("Enter date (DD-MM-YYYY): ");
                        scanf("%14s", transactions[count].date);

                    strcpy(transactions[count].type, "Expense");
                        count++;

                    printf("\nExpense added successfully!\n");
                        break;
                case 3:
                    printf("View Transactions selected.\n");
                    printf("\n========== ALL TRANSACTIONS ==========\n");
                    
                    if (count == 0) {
                        printf("No transactions found!\n");
                    } else {
                        printf("\nID\tTYPE\t\tAMOUNT\t\tCATEGORY\n");
                        printf("--------------------------------------------------\n");     
                            for (int i = 0; i < count; i++) {
                                printf("%d\t%-12s\t%.2f\t%s\n",
                                    transactions[i].id,
                                    transactions[i].type,
                                    transactions[i].amount,
                                    transactions[i].category
                                );
                        }
                        printf("\nTotal Transactions: %d\n", count);
                    }
                        break;
                case 4: {
                    printf("Search Transaction selected.\n");
                        
                        int searchID;
                        int found = 0;
                            printf("\nEnter Transaction ID: ");
                                scanf("%d", &searchID);
                            for (int i = 0; i < count; i++) {
                                if (transactions[i].id == searchID) {
                                            printf("\nTransaction Found!\n");
                                    printf("\nID          : %d", transactions[i].id);
                                    printf("\nType        : %s", transactions[i].type);
                                    printf("\nAmount      : %.2f", transactions[i].amount);
                                    printf("\nCategory    : %s", transactions[i].category);
                                    printf("\nDescription : %s", transactions[i].description);
                                    printf("\nDate        : %s\n", transactions[i].date);
                                        found = 1;
                                    break;
                                }
                            }
                                if (found == 0) {
                                    printf("\nTransaction not found!\n");
                                } 
                        break;
                    }
                case 5: {
                    printf("View Balance selected.\n");
                        
                        float totalIncome = 0;
                        float totalExpense = 0;
                        float balance;
                        for (int i = 0; i < count; i++) {
                            if (strcmp(transactions[i].type, "Income") == 0) { totalIncome += transactions[i].amount;
                            } else { 
                                totalExpense += transactions[i].amount;
                            }
                        }                       
                        balance = totalIncome - totalExpense;

                        printf("\n========== ACCOUNT SUMMARY ==========\n");
                        printf("\nTotal Income   : %.2f", totalIncome);
                        printf("\nTotal Expenses : %.2f", totalExpense);
                        printf("\nAvailable Balance : %.2f\n", balance);    
                            break;
                    }
                case 6: {
                    printf("Monthly Summary selected.\n");

                        int month, year;
                        int transactionMonth, transactionYear;
                        float monthlyIncome = 0;
                        float monthlyExpense = 0;

                        printf("\nEnter month (MM): ");
                            scanf("%d", &month);
                        printf("Enter year (YYYY): ");
                            scanf("%d", &year);

                        for (int i = 0; i < count; i++) {
                            sscanf(transactions[i].date, "%*d-%d-%d", &transactionMonth, &transactionYear);
                            if (transactionMonth == month && transactionYear == year) {
                                if (strcmp(transactions[i].type, "Income") == 0) { monthlyIncome += transactions[i].amount;
                                } else { 
                                    monthlyExpense += transactions[i].amount;
                                }
                            }
                        }
                        printf("\n========== MONTHLY SUMMARY ==========\n");
                        printf("\nMonthly Income   : %.2f", monthlyIncome);
                        printf("\nMonthly Expenses : %.2f", monthlyExpense);
                        printf("\nMonthly Balance  : %.2f\n",
                            monthlyIncome - monthlyExpense);
                                break;
                    }
                case 7:
                    printf("Thank you for using Expense Tracker!\n");
                        exit(0);
                default:
                        printf("Invalid choice! Please try again.\n");
            }
}
    return 0;
}