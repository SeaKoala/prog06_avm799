// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void turn(Deck &d, Player &p1, Player &p2, ofstream &myFile);



int main( )
{
    ofstream myFile ("gofish_results.txt");
    if (myFile.is_open()) {
        int numCards = 7;
        Player p1("Alec");
        Player p2("Jacob");
        Deck d;  //create a deck of cards

        d.shuffle();
        dealHand(d, p1, numCards);
        dealHand(d, p2, numCards);

        while (p1.checkAndBook());
        while (p2.checkAndBook());

        myFile << p1.getName() << ": HAND: " << p1.showHand() << endl;
        myFile << p1.getName() << ": BOOKS: " << p1.getNumPairs() << endl;
        myFile << p2.getName() << ": HAND: " << p2.showHand() << endl;
        myFile << p2.getName() << ": BOOKS: " << p2.getNumPairs() << endl;


        myFile << "----------------------------------START GAME \n";
        turn(d, p1, p2, myFile);
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++) {
        p.addCard(d.dealCard());
    }
}
   
void turn(Deck &d, Player &p1, Player &p2, ofstream &myFile){
    static int drawCount = 0;
    Card c1;
    int giveCount =0;
    if(p1.handEmpty()){
        c1 = d.dealCard();
        drawCount++;
        if(c1.getRank() == 0){
            p1.checkAndBook();
            myFile << "----------------------------------GAME OVER \n";
            myFile << p1.getName() << ": BOOKS: " << p1.getNumPairs() << endl;
            myFile << p2.getName() << ": BOOKS: " << p2.getNumPairs() << endl;
            if(p1.getNumPairs() > p2.getNumPairs()){
                myFile << p1.getName() << " WINS!!\n";
            }
            else if (p1.getNumPairs() < p2.getNumPairs()){
                myFile << p2.getName() << " WINS!!\n";
            }
            else{
                myFile << "IT'S A TIE!!\n";
            }
            myFile.close();
            exit(EXIT_SUCCESS);
        }
        myFile<<  p1.getName() <<": Drew a " << c1.toString() <<endl;
        p1.addCard(c1);
        while(p1.checkAndBook());
        myFile << p1.getName() << ": HAND: " << p1.showHand() << endl;
        myFile << p1.getName() << ": BOOKS: " << p1.getNumPairs() << endl;
        myFile << "----------------------------------END TURN \n";
        turn(d, p2, p1, myFile);
    }
    else {
        c1 = p1.chooseCardFromHand();
        myFile << p1.getName() << ": Do you have any " << c1.rankString(c1.getRank()) << "'s\n";
        if (p2.rankInHand(c1)) {
            while (p2.rankInHand(c1)) {
                Card c2 = p2.removeCardFromHand(c1);
                p1.addCard(c2);
                while (p1.checkAndBook());
            }
            myFile << p2.getName() << " gave a " << c1.getRank() << endl;
            myFile << p1.getName() << ": HAND: " << p1.showHand() << endl;
            myFile << p1.getName() << ": BOOKS: " << p1.getNumPairs() << endl;
            myFile << "----------------------------------GO AGAIN \n";
            turn(d, p1, p2, myFile);
        } else {
            myFile << p2.getName() << ": Go Fish!\n";
            c1 = d.dealCard();
            drawCount++;
            myFile << p1.getName() << ": Drew a " << c1.toString() << endl;
            p1.addCard(c1);
            while (p1.checkAndBook());
        }
        myFile << p1.getName() << ": HAND: " << p1.showHand() << endl;
        myFile << p1.getName() << ": BOOKS: " << p1.getNumPairs() << endl;
        myFile << "----------------------------------END TURN \n";
        turn(d, p2, p1, myFile);
    }
}