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
    int smallNum = 8;
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
    /*for (int i = 0; i < SIZE; i++ ){
        //for (int j = i+1; j < SIZE; j++){
        if (myCards[i].getRank() == 13){
            long card1 = (rand() % smallNum);
            Card swap = myCards[i];
            Card swap2 = myCards[card1];
            Card temp2 = swap;
            myCards[card1] = swap2;
            myCards[i] = temp2;
        }
    }
     */
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
        Card c(0, spades);
        return c;
    }


}

int Deck::size() 	const
{
    int size = SIZE - 1 - myIndex;
    return size;
}