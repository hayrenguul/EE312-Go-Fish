#include <iostream>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <fstream>
using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main() {

    ofstream goFish;
    goFish.open ("go_fish_results.txt");
    Deck d;
    int numCards = 7;
    int flag = 0;
    Player p1("Joe");
    Player p2("Jane");

//    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    Card deal;
//    p1.checkHandForPair();

    //  p2.checkHandForPair();

    while (p1.getBookSize() +  p2.getBookSize() != 26){

        goFish << p1.getName() <<" has : " << p1.showHand() << endl;
        goFish << p2.getName() <<" has : " << p2.showHand() << endl;
        p1.checkHandForPair();
        p2.checkHandForPair();
        if(p1.getHandSize() == 0) {
            deal = d.dealCard();
            if(deal.getRank() != 0) {
                p1.addCard(deal);
            }
            else{
                flag =1;
            }
        }

        if (flag != 1){
            Card check = p1.chooseCardFromHand();
            string ask = check.toString();  //string to add to file
            goFish << p1.getName() << " asks - Do you have a " << check.rankString(check.getRank()) << "?\n";
            if ( p2.rankInHand(check)){	//not crashing in rank in hand
                goFish << p2.getName() << " says - Yes I have a " << check.rankString(check.getRank()) << ".\n";
                Card add = p2.removeCardFromHand(check);	//ok
                //p1.addCard(add);
                p1.bookCards(check, add);
                p1.removeCardFromHand(check);
                //p1.removeCardFromHand(add);
                cout << p1.showBooks() << endl;
                cout << p1.showHand() << endl;
            }
            else{
                goFish << p2.getName() << " says - Go Fish!\n";
                Card deal = d.dealCard();
                if(deal.getRank() != 0) {
                    p1.addCard(deal);
                }
                p1.checkHandForPair();
                cout << p1.showHand() << endl;
                cout << p1.showBooks() << endl;
/*
                deal = d.dealCard();
                if(deal.getRank() != 0) {  //means deck wasn't empty
                    p1.addCard(deal);
		}
                deal = d.dealCard();
                if(deal.getRank() != 0) {  //means deck wasn't empty
                    p1.addCard(deal);
		}
            }
             if (p1.checkHandForPair()){	//check this
                Card add2 = p1.removeCardFromHand(deal);	//check this
                p1.bookCards(deal, add2);
                p1.removeCardFromHand(deal);
                p1.removeCardFromHand(add2);
             }
*/
            }
        }


        if(p2.getHandSize() == 0) {
            deal = d.dealCard();
            if(deal.getRank() != 0) {
                p2.addCard(deal);
            }
            else{
                flag = 1;
            }
        }
        if ( flag != 1){
            Card check2 = p2.chooseCardFromHand();
            string ask2 = check2.toString();  //string to add to file
            goFish << p2.getName() << " asks - Do you have a " << check2.rankString(check2.getRank()) << "?\n";
            if ( p1.rankInHand(check2)){
                goFish << p1.getName() << " says - Yes I have a " << check2.rankString(check2.getRank()) << ".\n";
                Card add = p1.removeCardFromHand(check2);
                //p2.addCard(add);
                p2.bookCards(check2, add);
                p2.removeCardFromHand(check2);
                //p2.removeCardFromHand(add);
                cout << p2.showHand() << endl;
                cout << p2.showBooks() << endl;
            }
            else{
                cout << p1.getName() << " says - Go Fish!\n";
                Card deal = d.dealCard();
                if (deal.getRank() != 0){
                    p2.addCard(deal);

                }
                //p2.addCard(deal);
                p2.checkHandForPair();
                cout << p2.showHand() << endl;
                cout << p2.showBooks() << endl;
/*
	        check2 = d.dealCard();
                if(check2.getRank() != 0) {  //means deck wasn't empty
   		    p2.addCard(check2);
	        }
		check2 = d.dealCard();
                if(deal.getRank() != 0) {  //means deck wasn't empty
 		    p2.addCard(check2);
		}
*/

                /*         if (p2.checkHandForPair()){
                             Card add2 = p2.removeCardFromHand(deal);
                             p2.bookCards(deal, add2);
                             p2.removeCardFromHand(deal);
                             p2.removeCardFromHand(add2);
                         }
             */
            }
            cout << p1.showHand() << endl;
            cout << p1.showBooks() << endl;
            cout << p2.showHand() << endl;
            cout << p2.showBooks() << endl;
        }
    }



    int p1_score = p1.getBookSize();
    int p2_score = p2.getBookSize();
    if(p1_score > p2_score) {
        goFish << p1.getName() << " is the winner!\n";
    }
    else {
        goFish << p2.getName() << " is the winner!\n";
    }
    goFish.close();

    return EXIT_SUCCESS;
}




void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


