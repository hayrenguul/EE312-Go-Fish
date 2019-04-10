#include <iostream>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main() {

    Deck d;
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

//    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    while (p1.getHandSize() != 0 && p2.getHandSize() != 0){
         Card check = p1.chooseCardFromHand();
         string ask = check.toString();  //string to add to file

         if ( p2.rankInHand(check)){
             Card add = p2.removeCardFromHand(check);
             p1.addCard(add);
             p1.bookCards(check, add);
             p1.removeCardFromHand(check);
             p1.removeCardFromHand(add);
         }
         else{
             Card deal = d.dealCard();
             p1.addCard(deal);
             if (p1.checkHandForPair()){
                Card add2 = p1.removeCardFromHand(deal);
                p1.bookCards(deal, add2);
                p1.removeCardFromHand(deal);
                p1.removeCardFromHand(add2);

             }
         }

        Card check2 = p2.chooseCardFromHand();
        string ask2 = check2.toString();  //string to add to file

        if ( p1.rankInHand(check2)){
            Card add = p1.removeCardFromHand(check2);
            p2.addCard(add);
            p2.bookCards(check2, add);
            p2.removeCardFromHand(check2);
            p2.removeCardFromHand(add);
        }
        else{
            Card deal = d.dealCard();
            p2.addCard(deal);
            if (p2.checkHandForPair()){
                Card add2 = p2.removeCardFromHand(deal);
                p2.bookCards(deal, add2);
                p2.removeCardFromHand(deal);
                p2.removeCardFromHand(add2);

            }
        }
    }

    return EXIT_SUCCESS;
}




void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}