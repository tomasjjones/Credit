#include <cs50.h>
#include <stdio.h>
#include <unistd.h>


int main(void)
{

    long cardnum, cardnumtemp, cardnumsingle;
    int DigitTotal = 0;
    int Phase1Addition = 0;
    int Phase2Addition = 0;
    int Phase1Last, Phase2Last;

    cardnum = get_long("Please enter card number: \n");
    //zero total on loop
    DigitTotal = 0;
    //Set temp card num
    cardnumtemp = cardnum;
    
    while (cardnumtemp > 0)
    {
        cardnumsingle = cardnumtemp % 10;
    
        if ((DigitTotal + 1) % 2 == 0)
        {
            //for holding the final number for checking first digits
            Phase1Last = cardnumsingle;
            //*2 and add individual digits
            cardnumsingle = cardnumsingle * 2;
    
            while (cardnumsingle > 0)
            {
                Phase1Addition = Phase1Addition + cardnumsingle % 10;
                cardnumsingle /= 10;
            }
        }
    
        else
        {
            Phase2Last = cardnumsingle;
            Phase2Addition = Phase2Addition + cardnumsingle;
    
        }
        
        cardnumtemp /= 10;
        DigitTotal++;
    }
    
    

    if ((Phase1Addition + Phase2Addition) % 10 == 0)
    {
        if (DigitTotal == 15)
        {
            //check if 1st and second numbers match
            if ((Phase1Last == 4 || Phase1Last == 7) && Phase2Last == 3)
            {
                printf("AMEX\n");
            }
                
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
             
        else
        {
                
            //mastercard 16 digits 51 52 53 54 55
            if ((Phase2Last == 1 || Phase2Last == 2 || Phase2Last == 3 || Phase2Last == 4 || Phase2Last == 5) && Phase1Last == 5 
                && DigitTotal == 16)
            {
                printf("MASTERCARD\n");
            }
            
            else if ((Phase1Last == 4 && DigitTotal == 16) || (Phase2Last == 4 && DigitTotal == 13))
            {
                printf("VISA\n");
            }
            
            else
            {
                printf("INVALID\n");
                return 0;
            }
        } 
    }  
    
    else
    {
        printf("INVALID\n");
        return 0;
    }

}
