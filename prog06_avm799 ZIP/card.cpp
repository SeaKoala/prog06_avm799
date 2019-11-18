//
// Created by Alec Mehra on 11/8/2019.
//

#include "card.h"
#include <cstdlib>

Card::Card() {
    this->myRank = 1;
    this->mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    this->myRank = rank;
    this->mySuit = s;
}

string Card::toString() const {
    return this->rankString(this->myRank) + this->suitString(this->mySuit);
}

bool Card::sameSuitAs(const Card &c) const {
    return (this->mySuit == c.mySuit);
}

int Card::getRank() const {
    return this->myRank;
}

string Card::suitString(Card::Suit s) const {
    if(s == spades){
        return "s";
    }
    if(s == hearts){
        return "h";
    }
    if(s == clubs){
        return "c";
    }
    if(s == diamonds){
        return "d";
    }
    else
        return "fail";
}

string Card::rankString(int r) const {
    char ret [1];
    if(r == 1){
        return "A";
    }
    if(r ==2){
        return "2";
    }
    if(r ==3){
        return "3";
    }
    if(r ==4){
        return "4";
    }
    if(r ==5){
        return "5";
    }
    if(r ==6){
        return "6";
    }
    if(r ==7){
        return "7";
    }
    if(r ==8){
        return "8";
    }
    if(r ==9){
        return "9";
    }
    if(r ==10){
        return "10";
    }
    if(r == 11){
        return "J";
    }
    if(r == 12){
        return "Q";
    }
    if(r == 13){
        return "K";
    }
    else
        return "fail";
}

bool Card::operator==(const Card &rhs) const {
    return (this->myRank == rhs.myRank);
}

bool Card::operator!=(const Card &rhs) const {
    return (this->myRank != rhs.myRank);
}
