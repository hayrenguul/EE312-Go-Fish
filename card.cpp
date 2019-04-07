#include "card.h"

using namespace std;

    Card::Card()
    {
	myRank = 1;
	mySuit = spades;
    }

    Card::Card(int rank, Suit s)
    {
	myRank = rank;
	mySuit = s;
    }

    string Card::toString() 
    {
	string rank = rankString(myRank);
	string suit = suitString(mySuit);
	string card = rank + suit;
	return card;	
    }

    string Card::suitString(Suit s) const
    {
	if(s == spades) {
	    return "s";
	}
	if(s == hearts) {
	    return "h";
	}
	if(s == diamonds) {
	    return "d";
	}
	if(s == clubs) {
	    return "c";
	}
    }

    bool Card::sameSuitAs(const Card& c) 
    {
		
    }

    int Card::getRank() 
    {
	return myRank;
    }

    string Card::rankString(int r) 
    {
	if(r == 1) {
	    return "A";
	}
	if(r == 2) {
	    return "2";
	}
	if(r == 3) {
	    return "3";
	}
	if(r == 4) {
	    return "4";
	}
	if(r == 5) {
	    return "5";
	}
	if(r == 6) {
	    return "6";
	}
	if(r == 7) {
	    return "7";
	}
	if(r == 8) {
	    return "8";
	}
	if(r == 9) {
	    return "9";
	}
	if(r == 10) {
	    return "10";
	}
	if(r == 11) {
	    return "J";
	}
	if(r == 12) {
	    return "Q";
	}
	if(r == 13) {
	    return "K";
	}
    }
    
    bool Card::operator == (const Card& rhs)
    {
    
    }

    bool Card::operator != (const Card& rhs)
    {

    }
