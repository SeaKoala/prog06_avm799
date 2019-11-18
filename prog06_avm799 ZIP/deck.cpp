//
// Created by Alec Mehra on 11/8/2019.
//

#include "deck.h"
#include <ctime>
#include <stdlib.h>

Deck::Deck(){
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    for(int i =0; i<13; i++){
        myCards[4*i] = Card(i+1, Card::spades);
        myCards[4*i+1] = Card(i+1, Card::diamonds);
        myCards[4*i+2] = Card(i+1, Card::clubs);
        myCards[4*i+3] = Card(i+1, Card::hearts);
    }
    myIndex = 52;
}

Card Deck::dealCard() {
    myIndex--;
    if(myIndex>=0){
        return myCards[myIndex];
    }
    else{
        return Card(0, Card::spades);
    }
}

void Deck::shuffle() {
    int r1;
    int r2;
    for(int i=0; i< 52; i++){
        r1 = (rand()%52);
        r2 = (rand()%52);
//        cout<< "swapping: ";
//        cout<<myCards[r1].toString()<< ", ";
//        cout<<myCards[r2].toString()<<endl;
        Card c1 = myCards[r1];
        myCards[r1] = myCards[r2];
        myCards[r2] = c1;
    }
}

int Deck::size() const {
    return 0;
}
