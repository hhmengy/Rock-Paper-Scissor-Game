// simple rock paper scissors game that simulates three ways of playing, 1 player
//,2player, or only computers. 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

//basic player class to derive other classes from
class Player
{
	public:
		virtual string getGuess(){
			return "paper";
		}
		string name;
};


//class for the human player
class HumanPlayer: public Player
{
	public:
		virtual string getGuess();
		HumanPlayer(string nname);
		//string name;
};

//gets humans rock paper or scissors
string HumanPlayer::getGuess()
{
	int num;
	cout << "Enter 0 for rock, 1 for paper, or 2 for scissors: ";
	cin >> num;
	
	while ((num !=1) && (num!=2) && (num!=0))
	{
		cout <<"Error: Your entry was invalid, try again!";
		cout << "\nEnter 0 for rock, 1 for paper, or 2 for scissors: ";
		cin >> num;
	}
	
	if(num==0)
		return "rock";
	if (num==1)
		return"paper";
	if (num ==2);
		return "scissors";
	
}

//assigns human players string
HumanPlayer::HumanPlayer(string nname)
{
name=nname;	
}

//computer player's class
class ComputerPlayer: public Player
{
	public:
	ComputerPlayer(string nname);
	virtual string getGuess();
	//string name;
	
};

//assigns computers string
ComputerPlayer::ComputerPlayer(string nname)
{
	
	name=nname;
		
}

//gets computers guess
string ComputerPlayer::getGuess()
{
	
	int num=rand()%3;
	if(num==0)
	return "rock";
	if (num==1)
	return"paper";
	if (num ==2);
	return "scissors";
}

void takeTurn (Player & player1, Player & player2);
//take turn function takes in two players and has them play rock paper scissors

int main(){
	char cont;
	do{
		string ans;
		HumanPlayer p1("human1"), p2("human2");
		ComputerPlayer c1("computer1"),c2("computer2");
		
		//playing rock paper scissors
		srand(125);
		cout << "Type 'HvH' for 2 player, 'HvC' for 1 player, or 'CvC' for only computers: ";
		cin >> ans;
		if(ans == "HvH" || ans == "HVH" || ans == "hvh" || ans == "hVh")
		{
			takeTurn(p1,p2);	
		}
		else if(ans == "HvC" || ans == "HVC" || ans == "hvc" || ans == "hVc")
		{
			takeTurn(p1,c2);
		}
		else
		{
			takeTurn(c1, c2);
		}
		//asking user if they want to continue
		cout << "Play again (Enter 'y' or 'Y'): ";
		cin >> cont;
	}
	while(cont == 'y' || cont == 'Y');

	return 0;
}

void takeTurn (Player & player1, Player & player2) {
	string p1 = player1.name;
	string p2 = player2.name;
	string p1turn = player1.getGuess();
	string p2turn = player2.getGuess();
	if (p1turn == p2turn)
		cout << "Both Guessed: " << p1turn << " No winner!\n\n";
	else if (p1turn == "rock" && p2turn == "scissors" ) {
		cout << p1 << " wins!\n";
		cout << "rock beats scissors!\n\n";
	}
	else if (p1turn == "scissors" && p2turn == "paper"){
		cout << p1 << " wins!\n";
		cout << "scissors beats paper!\n\n";
	}
	else if (p1turn == "paper" && p2turn == "rock"){
		cout << p1 << " wins!\n";
		cout << "paper beats rock!\n\n";
	}
	else if (p1turn == "scissors" && p2turn == "rock"){
		cout << p2 << " wins!\n";
		cout << "rock beats scissors!\n\n";
	}
	else if (p1turn == "paper" && p2turn == "scissors"){
		cout << p2 << " wins!\n";
		cout << "scissors beats paper!\n\n";
	}
	else {
		cout << p2 << " wins!\n";
		cout << "paper beats rock!\n\n";
	}
	return;
} // end takeTurn
