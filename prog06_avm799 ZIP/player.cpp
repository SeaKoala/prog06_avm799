//
// Created by Alec Mehra on 11/8/2019.
//

#include "player.h"
#include <string>
#include <stdlib.h>

using namespace std;

Player::Player() = default;

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

bool Player::rankInHand(Card c) const {
    for(int i =0; i<myHand.size(); i++){
        if(c.getRank() == myHand[i].getRank()){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    return myHand[(rand()%myHand.size())];
}

bool Player::cardInHand(Card c) const {
    for(int i =0; i<myHand.size(); i++){
        if(c.toString() == myHand[i].toString()){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    Card temp;
        for(int i =0; i<myHand.size(); i++){
            if(c.getRank() == myHand[i].getRank()){
                temp = myHand[i];
//                cout << temp.toString()<<endl;
                myHand.erase(myHand.begin()+i);
                return temp;
            }
        }
    return Card();
}

string Player::showHand() const {
    string retVal ="";
    for(int i =0; i<myHand.size(); i++){
        retVal = retVal + myHand[i].toString() +", ";
    }
    return retVal;
}

string Player::showBooks() const {
    string retVal ="";
    for(int i =0; i<myBook.size(); i++){
        retVal = retVal + myBook[i].toString() +", ";
    }
    return retVal;
}

int Player::getHandSize() const {
    return myBook.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

bool Player::checkAndBook() {
    for(int i =0; i<myHand.size(); i++){
        for(int j =i+1; j<myHand.size(); j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                bookCards(myHand[i], myHand[j]);
                return true;
            }
        }
    }
    return false;
}

bool Player::handEmpty() {
    return(myHand.empty());
}

int Player::getNumPairs() {
    return(getBookSize()/2);
}
