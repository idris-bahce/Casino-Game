//Simple betting game
//"Jack Queen King"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play(){

    int cash = 100;
    int bet;
    char *cart = (char*)malloc(3 * sizeof(char));
    cart[0] = 'J';
    cart[1] = 'Q';
    cart[2] = 'K';

    
    while (1)
    {
        srand(time(NULL));

        for (int i = 0; i < 5; i++)
        {
            int x = rand() % 3;
            int y = rand() % 3;
            char temp = cart[x];
            cart[x] = cart[y];
            cart[y] = temp; 
        }
        
        if (cash <= 0)
        {
            printf("You have lost all your money!\n");
            break;
        }
        printf("Please enter your amount!\n");
        if(scanf("%d", &bet) != 1 || bet > cash){
            
            continue;
        }
        getchar();

        printf("Shaffling the cards..\n");
        printf("What is the position of the Queen?(1, 2 or 3?):");

        int guess;
        scanf("%d", &guess);
        getchar();
        if (!(guess >= 1 && guess <= 3) )
        {
            printf("Invalid input!\n");
            continue;
        }
        if (cart[guess - 1] == 'Q')
        {
            cash += bet * 3;
            printf("True! Your cash is %d\n", cash);
        }else
        {
            cash -= bet;
            printf("False! Your cash is %d\n", cash);
        }
             

    }
    
    free(cart);

}

int main(){

    printf("**Welcome to virtual casino.**\n");
    printf("You have 100$.\n");

    play();

    

    return 0;
}