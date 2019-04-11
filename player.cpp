//
// Created by Maldo on 4/8/2019.
//

#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Player::addCard(Card c)		//fine
{
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)	//fine
{
    myBook.push_back(c1);
    myBook.push_back(c2);

}
//optional
//bool Player::checkHandForBook(Card &c1, Card &c2)
//{

//optional
bool Player::rankInHand(Card c) const		//this is fine
{
    vector<Card>::const_iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++){
        if ( it->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const				//this is fine
{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int sizeHand = myHand.size();
    long card1 = (rand() % sizeHand);
    Card c = myHand.at(card1);

    return c;
}

bool Player::cardInHand(Card c) const		//fine
{
    vector<Card>::const_iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++){
        if ( *it == c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c)
{
    Card c2;
    vector<Card>::iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++){
        if ( it->getRank() == c.getRank()){
            c2 = *it;
            myHand.erase(it);
            return c2;	//new
        }
    }
//new:
   //c2 = *it;
   // myHand.erase(it);
   //return c2;
}

string Player::showHand() const
{
    string hand;
    vector<Card>::const_iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++){
        Card c = *it;
        string c_s = c.toString();
        hand = hand + " " + c_s;
    }
    hand = hand + "\n";
    return hand;
}

string Player::showBooks() const
{
    string book;
    vector<Card>::const_iterator it;
    for (it = myBook.begin(); it != myBook.end(); it++){
        Card c = *it;
        string c_s = c.toString();
        book = book + " " + c_s;
    }
    book = book + "\n";
    return book;
}

int Player::getHandSize() const
{
    return myHand.size();
}

int Player::getBookSize() const
{
    return ((myBook.size())/2);
}
//optional
void Player::checkHandForPair()		//remove
{
    vector<Card>::iterator i;
    vector<Card>::iterator j;
    for (i = myHand.begin(); i != myHand.end(); i++){
        for (j = i+1; j != myHand.end(); j++){
            if (i->getRank() == j->getRank()){
                myBook.push_back(*i);
                myBook.push_back(*j);
                myHand.erase(j);
                myHand.erase(i);
                return;
            }
        }
    }
    return;
}
//optional
bool Player::sameRankInHand(Card c) const
{

}
