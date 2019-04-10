//
// Created by Maldo on 4/8/2019.
//

#include "deck.h"

#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck()
{
    int i = 0;
    myIndex = 0;
    for(int suit = 0; suit < 4; suit++) {
        for(int rank = 1; rank < 14; rank++) {
            Card c(rank, (Suit) suit);
            myCards[i] = c;
            i++;
        }
    }
}

void Deck::shuffle()
{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int swapNum = 300;
    int numCards = SIZE - 1;
    while(swapNum > 0){
        long card1 = (rand() % numCards);
        long card2 = (rand() % numCards);
        Card c1 = myCards[card1];
        Card c2 = myCards[card2];
        Card temp = c1;
        myCards[card1] = c2;
        myCards[card2] = temp;
        swapNum--;
    }
    myIndex = 0;
}

Card Deck::dealCard()
{
    if (myIndex < SIZE){
        Card c = myCards[myIndex];
        myIndex++;
        return c;
    }
    else{
        cout << "deck empty" << endl;
    }


}

int Deck::size() 	const
{
    int size = SIZE - 1 - myIndex;
    return size;
}