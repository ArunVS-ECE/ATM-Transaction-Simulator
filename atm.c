atm.c

#include<stdio.h>

int main()
{
    float balance=10000.00,deposit_money,withdraw_money;
    int pin=965425,iput_pin,attempt=0,choice,transactions=0;

    printf("Enter Your 6 Digit Pin: ");
    scanf("%d",&iput_pin);

    while(attempt<3)
    {
        if(pin==iput_pin)
        {
            printf("Verification Completed!\n");
            break;
        }
        else if(pin != iput_pin)
        {
            printf("Invalid Pin!\n");
            attempt++;
            
            if(attempt<3)
            {
            printf("Enter Your 6 Digit Pin: ");
            scanf("%d",&iput_pin);
            }
        }
    }
    if(attempt==3)
    {
       printf("Your Card Is Locked");
       return 0;
    }
    
do
{
    printf("\n===== ATM MENU =====\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
       
    case 1: 
      printf("Balance:%.2f",balance);
      break;
      
    case 2:
     
      printf("Enter The Amount You Want To Deposit: ");
      scanf("%f",&deposit_money);
      
      if(deposit_money>0)
      {
           balance+=deposit_money;
          printf("Transaction Completed!\nYour Balance:%.2f",balance);
          transactions++;
      }
      else
      {
          printf("Invalid Deposit");
      }
      break;
      
     case 3:
     
     
     printf("Enter The Amount You Want To Withdraw: ");
      scanf("%f",&withdraw_money);
      
      if(withdraw_money>0)
      {
      if(withdraw_money<=balance)
      {
          balance-=withdraw_money;
          printf("Transaction Completed!\nYour Balance:%.2f",balance);
          transactions++;
      }
      else
      {
          printf("Insufficient Balance");
      }
      }
      else
      {
         printf("Invalid Input");
      }
      break;

      case 4:
      printf("THANK YOU!\n");
       printf("Total Successful Transactions: %d", transactions); 
                break;

default:
    printf("Invalid Choice!");
    break;
    }
}
while(choice!=4);

return 0;
}
