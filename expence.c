#include <stdio.h>
#include <stdlib.h>
float show_money();
float add_income();
float add_expence();
void exit_program();
float tot_income;
float tot_expence;
void save_balance(void) {
    FILE *fp = fopen("balance.txt", "w");
    if (fp == NULL) {
        printf("Error saving balance\n");
        return;
    }
    fprintf(fp, "%.2f %.2f", tot_income, tot_expence);
    fclose(fp);
}

int main(void) {
    int choice;
    FILE *fp = fopen("balance.txt", "r");
if (fp != NULL) {
    fscanf(fp, "%f %f", &tot_income, &tot_expence);
    fclose(fp);
    printf("Welcome back. Current balance: %.2f\n", tot_income - tot_expence);
}
    while(1) {
        printf("=====================================================\n");
        printf("\t\tFINANCE RECORDS\n");
        printf("-------------------------------------------------------\n");
    printf("Enter a choice: \n 1. Show the Amount of Money \n 2. Add the income amount \n 3. Add the Expence \n 4. Quit the program\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        show_money();
        break;
    case 2:
        add_income();
        break;
    case 3:
        add_expence();
        break;
    default: exit_program();
        break;
    }
 } 
    return 0;
}

float show_money(void) {
    FILE *fp;
    fp = fopen("expence.txt", "a");
    if (fp == NULL) {
        printf("Error Opening in File");
    }
    float money = tot_income - tot_expence;
    fprintf(fp, "Amount in NRS: %.2f\n", money);
    printf("Amount in NRS: %.2f\n", money);
    fclose(fp);
    return money;
}
float add_income(void) {
    FILE *fp;
    fp = fopen("expence.txt", "a");
    if (fp == NULL) {
        printf("Error Opening in File");
    }

  float income = 0;
  printf("Add Income: \t");
  scanf("%f", &income);
 tot_income = tot_income + income;
 save_balance();
 fprintf(fp, "Total Income : %.2f\n", tot_income);
 printf("Total Income: %.2f\n", tot_income);
 fclose(fp);
 return tot_income;
}
float add_expence(void) {
    FILE *fp;
    fp = fopen("expence.txt", "a");
    if (fp == NULL) {
        printf("Error Opening in File\n");
    }

  float expence = 0;
  printf("Add Expence: \t");
  scanf("%f", &expence);
 tot_expence = tot_expence + expence;
 save_balance();
 fprintf(fp, "Your total expence : %.2f\n ", tot_expence);
 printf("Total Expence: %.2f\n", tot_expence);
 fclose(fp);
 return tot_expence;
 
}
void exit_program(void) {
    printf("Exiting the Program...");
 exit(0);
}
