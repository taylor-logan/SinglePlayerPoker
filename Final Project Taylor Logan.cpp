/*
Name:Taylor Logan
Final Project
Date: 04/22/2020
Description: This is a one person poker game. The player bets and is dealt a random hand of cards and awarded chips based on the outcome.
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;

class card
{
	public:
		int number;
		string suit;
};

class deckofcards : public card
{
	public:
		const int ranks[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		const string suits[5] = {"D", "H", "S", "C"};
		int i;
		int j;
		int k;
		card deck[37];
		deckofcards()
		{
			i = 0;
			j = 0;
			k = 0;
		}
		void assign()
		{
			for (i = 0 ; i < 9 ; i ++)
			{
				for ( j = 0 ; j < 4 ; j++)
				{
					deck[k].number = ranks[i];
					deck[k].suit = suits[j];
					k = k + 1;
				}
			}
		}
		
};

class game : public deckofcards
{
	public:
		int t;
		int random;
		card temp;
		int chips;
		int choice;
		int bet;
		int games;
		int wins;
		int losses;
		int winnings;
		int winflag;
		int flag;
		card hand[4];
		game()
		{
			t = 0;
			random = 0;
			chips = 100;
			flag = 1;
			winflag = 1;
			games = 0;
			wins = 0;
			losses = 0;
		}
		
		void shuffle()
		{
			for (t = 0 ; t < 36 ; t++ )
			{
				random = t + (rand() % (36 - t));
				
				temp.number = deck[t].number;
				deck[t].number = deck[random].number;
				deck[random].number = temp.number;
				temp.suit = deck[t].suit;
				deck[t].suit = deck[random].suit;
				deck[random].suit = temp.suit;
			}
		}
		void deal()
		{
			hand[0].number = deck[0].number;
			hand[0].suit = deck[0].suit;
			hand[1].number = deck[1].number;
			hand[1].suit = deck[1].suit;
			hand[2].number = deck[2].number;
			hand[2].suit = deck[2].suit;
			hand[3].number = deck[3].number;
			hand[3].suit = deck[3].suit;
			
			cout<<"May the odds be in your favor :)"<<endl<<endl;
			cout<<"Your hand is..."<<endl;
			cout<<hand[0].number<<hand[0].suit<<"    "<<hand[1].number<<hand[1].suit<<"    "<<hand[2].number<<hand[2].suit<<"    "<<hand[3].number<<hand[3].suit<<endl;
		}
		void startgame()
		{
			if (chips > 0)
			{
				cout<< "Bank Balance: $"<< chips <<endl;
				cout<< "________________________"<<endl<<endl;
				cout<< "Play a hand?"<<endl<<"(1) Yes"<<endl<<"(2) No"<<endl;
				cin>>choice;
			}
			else
			{
				cout<<"Sorry! Out of chips! Better Luck Next Time!"<<endl;
				choice = 2;
			}
		}
		void betting()
		{
			cout<<"How many chips would you like to bet? [0,"<<chips<<"]"<<endl;
			cin>>bet;
			while (flag != 0)
			{
				if ((bet > 0) && (bet <= chips))
					{
						chips = chips - bet;
						flag = 0;					
					}
				else
					{
						cout<<"Invalid Option"<<endl;
						cout<<"How many chips would you like to bet? [0,"<<chips<<"]"<<endl;
						cin>>bet;
						flag = 1;
					}
			}
		}
		void fourofakind()
		{
			if ((hand[0].number == hand[1].number) && (hand[1].number == hand[2].number) && (hand[2].number == hand[3].number))
			{
				chips = bet + (400*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have four of a kind!"<<endl;
			}
		}
		void straightflush()
		{
			for (i = 0 ; i < 4 ; i++)
			{
				for(j = i + 1 ; j < 4 ; j++)
				{
					if (hand[i].number > hand[j].number)
					{
						temp.number = hand[i].number;
						hand[i].number = hand[j].number;
						hand[j].number = temp.number;
						temp.suit = hand[i].suit;
						hand[i].suit = hand[j].suit;
						hand[j].suit = temp.suit;
					}
				}
			}
			if (((hand[0].number + 1) == hand[1].number) && ((hand[1].number + 1) == hand[2].number) && ((hand[2].number + 1) == hand[3].number))
			{
				if ((hand[0].suit.compare(hand[1].suit) == 0) && (hand[1].suit.compare(hand[2].suit) == 0) && (hand[2].suit.compare(hand[3].suit) == 0))
				{
					chips = chips + bet + (bet*300);
					winflag = 0;
					wins = wins + 1;
					cout<<"You have a straight flush!"<<endl;
				}
			}
		}
		void flush()
		{
			if ((hand[0].suit.compare(hand[1].suit) == 0) && (hand[1].suit.compare(hand[2].suit) == 0) && (hand[2].suit.compare(hand[3].suit) == 0))
				{
					chips = chips + bet + (bet*250);
					winflag = 0;
					wins = wins + 1;
					cout<<"You have a flush!"<<endl;
				}
		}
		
		void straight()
		{
			for (i = 0 ; i < 4 ; i++)
			{
				for(j = i + 1 ; j < 4 ; j++)
				{
					if (hand[i].number > hand[j].number)
					{
						temp.number = hand[i].number;
						hand[i].number = hand[j].number;
						hand[j].number = temp.number;
						temp.suit = hand[i].suit;
						hand[i].suit = hand[j].suit;
						hand[j].suit = temp.suit;
					}
				}
			}
			
			if (((hand[0].number + 1) == hand[1].number) && ((hand[1].number + 1) == hand[2].number) && ((hand[2].number + 1) == hand[3].number))
			{
				chips = chips + bet + (200*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have a straight!"<<endl;
			}
		}
		void threeofakind()
		{
			if ((hand[0].number == hand[1].number) && (hand[1].number == hand[2].number) && (hand[2].number != hand[3].number))
			{
				chips = chips + bet + (150*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have three of a kind!"<<endl;
			}
			else if ((hand[0].number == hand[2].number) && (hand[2].number == hand[3].number) && (hand[3].number != hand[1].number))
			{
				chips = chips + bet + (150*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have three of a kind!"<<endl;
			}
			else if ((hand[1].number == hand[2].number) && (hand[2].number == hand[3].number) && (hand[3].number != hand[0].number))
			{
				chips = chips + bet + (150*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have three of a kind!"<<endl;
			}
			else if ((hand[1].number == hand[3].number) && (hand[3].number == hand[0].number) && (hand[0].number != hand[2].number))
			{
				chips = chips + bet + (150*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have three of a kind!"<<endl;
			}
		}
		void twopair()
		{
			if ((hand[0].number == hand[1].number) && (hand[2].number == hand[3].number) && (hand[0].number != hand[3].number))
			{
				chips = chips + bet + (100*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two pair!"<<endl;
			}
			else if ((hand[1].number == hand[2].number) && (hand[0].number == hand[3].number) && (hand[1].number != hand[3].number))
			{
				chips = chips + bet + (100*bet);
				winflag = 0;
				cout<<"You have two pair!"<<endl;
			}
			else if ((hand[1].number == hand[3].number) && (hand[0].number == hand[2].number) && (hand[1].number != hand[0].number))
			{
				chips = chips + bet + (100*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two pair!"<<endl;
			}
		}
		
		void twoofakind()
		{
			if ((hand[0].number == hand[1].number) && (hand[0].number != hand[2].number) && (hand[0].number != hand[3].number) && (hand[2].number != hand[3].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
			else if ((hand[0].number == hand[2].number) && (hand[0].number != hand[1].number) && (hand[0].number != hand[3].number) && (hand[1].number != hand[3].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
			else if ((hand[0].number == hand[3].number) && (hand[0].number != hand[2].number) && (hand[0].number != hand[1].number) && (hand[1].number != hand[2].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
			else if ((hand[1].number == hand[3].number) && (hand[1].number != hand[2].number) && (hand[0].number != hand[1].number) && (hand[0].number != hand[2].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
			else if ((hand[1].number == hand[2].number) && (hand[1].number != hand[3].number) && (hand[0].number != hand[1].number) && (hand[0].number != hand[3].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
			else if ((hand[2].number == hand[3].number) && (hand[1].number != hand[2].number) && (hand[2].number != hand[0].number) && (hand[1].number != hand[0].number))
			{
				chips = chips + bet + (1*bet);
				winflag = 0;
				wins = wins + 1;
				cout<<"You have two of a kind!"<<endl;
			}
		}
		void bubkiss()
		{
			if (winflag == 1)
			{
				cout<<"Sorry! You Lost! You got ~bubkiss~"<<endl;
				losses = losses + 1;
			}
		}
		void count()
		{
			if (choice == 1)
			{
				games = games + 1;
			}
		}
		void finalreport()
		{
			winnings = chips - 100;
			cout<<"Thanks for playing!"<<endl;
			cout<<"You played "<<games<<" times and won "<<wins<<" bets!"<<endl;
			cout<<"You lost "<<losses<<" "<<endl;
			cout<<"Your net earnings were $"<<winnings<<endl;
		}
};







int main()
{
	srand(time(NULL));
	game poker;
	poker.assign();
	cout<< "Single Player Poker Game" <<endl;
	poker.startgame();
	poker.count();
	while (poker.choice != 2)
	{
		if (poker.choice == 1)
		{
			poker.flag = 1;
			poker.betting();
			poker.shuffle();
			poker.deal();
			poker.fourofakind();
			poker.straight();
			poker.straightflush();
			poker.flush();
			poker.threeofakind();
			poker.twopair();
			poker.twoofakind();
			poker.bubkiss();
			poker.startgame();
			poker.count();
			poker.winflag = 1;
		}
		else
		{
			cout<<"Invalid Option"<<endl;
			poker.startgame();
		}
	}
	
	if (poker.choice == 2)
	{
		poker.finalreport();
	}
	
}



	


