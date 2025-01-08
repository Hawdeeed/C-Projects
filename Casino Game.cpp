
 # include<iostream>
# include<stdio.h>
# include<time.h>
# include<stdlib.h>

using namespace std;
//prototyping of functions

void user_details(string& Name, int& NIC, string& adrs, int& initialblnc, char& x, int Num, int Y, int X);
void gamefunc(int& betnum, int& betamount, int& Num, int& players, int& me, int& rollnum, int& balance, int& X1, int& Y1);
void goldentable(int& betnum, int& betamount, int& Num, int& players, int& me, int& rollnum, int& initialblnc, int& X1, int& Y1);

int main() {
	//Declarations and initializations

	string name = "";
	int nic = 0;
	string address = "";
	int intblnc = 0;
	char a = 'y';
	int tbl_num;

	//Using function for random values
	srand((time(0)));
	tbl_num = 1 + rand() % 5;                                       // For random table numbers(Total 5 tables)

	int noofplayers = 1 + rand() % 5;                               // For random no of players(5)

	int myplayer = 1 + rand() % 5 % noofplayers;                    // For choosing my random number in players 

	int rollingnum = 1 + rand() % 6;                                // For the numbers of dice(total 6)

	int betnum = 1 + rand() % 6;                                    // For betting dice number

	int betamount = 1 + rand() % 100;                               // For betting amount number


	user_details(name, nic, address, intblnc, a, tbl_num, noofplayers, myplayer);      // Function for taking user details

	int bet_number = 0;
	int bet_amount = 0;

	gamefunc(bet_number, bet_amount, tbl_num, noofplayers, myplayer, rollingnum, intblnc, betnum, betamount);   // Function for playing on simple table

	while (true) {     // For the repetition of a function

		char j = ' ';
		char k = ' ';
		char l = ' ';
		float tax = (intblnc * 0.05);    // For deducting 5percent of tax from remaining amount
		cout << endl;
		if (bet_number == rollingnum) {

			cout << "Do you want to play a Golden table?[Y/N] " << endl;
			cout << "If yes then you must have to play 3 rounds " << endl;
			cin >> j;

			if (j == 'Y' || j == 'y')             // If you press (Y or y) to play game
			{

				goldentable(bet_number, bet_amount, tbl_num, noofplayers, myplayer, rollingnum, intblnc, betnum, betamount);    // Function for playing on golden table
				for (int i = 2; i <= 3; i++)
				{
					cout << "Round " << i << endl;
					goldentable(bet_number, bet_amount, tbl_num, noofplayers, myplayer, rollingnum, intblnc, betnum, betamount); //For the repetition of Golden table function
				}

				cout << "Do you want to transfer your remaining balance in a bank?[y/n] (cost 5 percent tax)" << endl;
				cin >> k;
				if (k == 'Y' || k == 'y') {                                           //For transfer money in bank
					cout << "Your remaining amount after deduction of 5% tax -> $" << intblnc - tax << endl;
					break;
				}
				else if (k == 'N' || k == 'n') {                   //For no transfer money in bank
					cout << "Your remaining amount is " << intblnc << endl;

				}
			}
			else if (j == 'N' || j == 'n')        // If you press (N , n) to get out from the game
				{
					cout << "Do you want to transfer your remaining balance in a bank?[y/n] (Cost 5 percent tax )" << endl;
					cin >> l;
					if (l == 'Y' || l == 'y') {
						cout << "Your remaining amount after deduction of 5% tax -> $" << intblnc - tax << endl;
						break;
					}
					else if (l == 'N' || l == 'n') {
						break;

					}

				}
			}
		
		else                      //Back to the first function
		{
			cout << "Do you want to proceed? [Y/N]" << endl;
			char t;
			cin >> t;
			if (t == 'Y' || t == 'y')
			{
				gamefunc(bet_number, bet_amount, tbl_num, noofplayers, myplayer, rollingnum, intblnc, betnum, betamount);
			}
			if (t == 'N' || t == 'n')
			{
				break;                                       // Using break to terminate the game
			}
		}
	}

	return 0;
}
void user_details(string& Name, int& NIC, string& adrs, int& initialblnc, char& x, int Num, int Y, int X) // Function for user's detail
{
	cout << "Welcome to the game house :] " << endl;
	cout << "New to the house [y/n]" << endl;                          // asking if you are a new or an old player
	cin >> x;
	if (x == 'y' || x == 'Y' )              // If user press (y or Y ) as a new player
	{                                                                  // Asking for required details
		cout << "You need to signup first" << endl;
		cout << "Enter your name -> ";
		cin >> Name;
		cout << endl;
		cout << "Enter your NIC number -> ";
		cin >> NIC;
		cout << endl;
		cout << "Enter your address -> ";
		cin >> adrs;
		cout << endl;
		cout << "Enter your initial balance -> $";
		cin >> initialblnc;
		cout << endl;
		cout << "SignUp Successful " << endl;
		cout << endl;
	}
	else if (x == 'n'  || x == 'N' )                // If user press (n or N ) as an old player
	{
		cout << "Welcome back :]" << endl;
		cout << "Enter your NIC number -> " << endl;
		cin >> NIC;
		cout << endl;
		cout << "Enter your initial balance -> $";
		cin >> initialblnc;
		cout << endl;
		cout << "SignUp Successful " << endl;
		cout << endl;

	}
}
void gamefunc(int& betnum, int& betamount, int& Num, int& players, int& me, int& rollnum, int& initialblnc, int& X1, int& Y1)   // Function for simple table
{
	//Tables and players are assigning here randomly
	Num = 1 + rand() % 5;
	players = 1 + rand() % 5;                               // For random no of players(5)

	me = 1 + rand() % 5 % players;                    // For choosing my random number in players
	cout << "You're playing on table " << Num << " with  " << players << " players" << endl;
	cout << "You're player " << me << endl;
	int a = me;            // declare and initialize a = X
	cout << "Round Begins :]" << endl;
	rollnum = 1 + rand() % 5;
	cout << rollnum;

	int won[6] = {};      // declairing and initializing an array
	for (int i = 1; i <= players + 1; i++)
	{
		if (i != a)
		{
			X1 = 1 + rand() % 5;      // For the changing of random values for every player
			Y1 = 1 + rand() % 100;    // For the changing of random values for every player
			cout << "Number for player -> " << i << " is -> " << X1 << endl;            // Giving different random betting numbers to players (b/w 1 to 6 number)
			cout << "Betting amount of player -> " << i << " is -> $" << Y1 << endl;    // Giving different random betting amount  to players (b/w 1 to 100 dollar)
			if (X1 == rollnum)              // If player's betting number matches to the rolling number
			{
				won[i] = true;
			}
		}
		// Ask user for betting number and amount 
		else if (i == a)
		{
			cout << "Number for player -> " << a << " is -> ";
			cin >> betnum;
			cout << endl;
			cout << "Betting amount of player " << i << " is -> $";
			cin >> betamount;


			if (betnum == rollnum)
			{
				won[i] = true;
			}
		}
		cout << endl;
	}
	cout << "Number on the rolling -> " << rollnum << endl;    // Giving a random rolling number (b/w 1 to 6)
	if (betnum == rollnum)              // If user's betting num matches to rolling number
	{
		cout << "You Won :]" << endl;
		cout << "Round End" << endl;
		initialblnc = initialblnc + (2 * betamount);    // In simple table the betting amount is multiplying with 2
		cout << "Your remaining amount is -> $" << initialblnc;
	}
	else                          // If rolling number isn't matches to yours or if matches to anyother player's betting number
	{
		cout << "You lose :[" << endl;
		initialblnc = (initialblnc - betamount);
		cout << "Your remaining amount is -> $" << initialblnc << endl;
		cout << "Players who won: ";
		for (int i = 1; i <= players + 1; i++)
		{
			if (won[i])
			{
				cout << "Player -> " << i << endl;
			}
		}
		cout << endl;
		cout << "Round End" << endl;
	}
}
void goldentable(int& betnum, int& betamount, int& Num, int& players, int& me, int& rollnum, int& initialblnc, int& X1, int& Y1)   //Function for golden table
{
	Num = 1 + rand() % 5;
	players = 1 + rand() % 5;                               // For random no of players(5)

	me = 1 + rand() % 5 % players;                    // For choosing my random number in players

	//Tables and players are assigning here randomly

	cout << "You're playing on table " << Num << " with  " << players << " players" << endl;

	cout << "You're player " << me << endl;
	int a = me;
	cout << "Round Begins :]" << endl;
	rollnum = 1 + rand() % 5;
	int won[6] = {};                   // declairing and initializing an array
	for (int i = 1; i <= players + 1; i++)
	{
		if (i != a)
		{
			X1 = 1 + rand() % 5;        // For the changing of random values for every player
			Y1 = 1 + rand() % 100;      // For the changing of random values for every player

			cout << "Number for player -> " << i << " is -> " << X1 << endl;           // Giving different random betting numbers to players (b/w 1 to 6 number)
			cout << "Betting amount of player -> " << i << " is -> $" << Y1 << endl;    // Giving different random betting amoubt to players (b/w 1 to 100 dollors)
			if (rollnum == X1)          // If player's betting number matches to the rolling number
				won[i] = true;
		}
		// Ask user for betting number and amount 
		else if (i == a)
		{
			cout << "Number for player -> " << a << " is -> ";
			cin >> betnum;
			cout << endl;
			cout << "Betting amount of player -> $" << i << " is -> ";
			cin >> betamount;
		}
		cout << endl;
	}
	cout << "Number on the rolling -> " << rollnum << endl;     // Giving a random rolling number (b/w 1 to 6)
	if (betnum == rollnum)                                      // If user's betting num matches to rolling number
	{
		cout << "You Won :]" << endl;
		cout << "Round End" << endl;
		initialblnc = initialblnc + (4 * betamount);            // In golden table the betting amount is multiplying with 4
		cout << "Your remaining amount is -> $" << initialblnc;
		cout << endl;
	}
	else                              // If rolling number isn't matches to yours or if matches to anyother player's betting number
	{
		cout << "You lose :[" << endl;
		initialblnc = (initialblnc - betamount);
		cout << "Your remaining amount is -> $" << initialblnc;
		cout << endl;
		cout << "Players who won : ";
		for (int i = 1; i <= players + 1; i++)
		{
			if (won[i])
			{
				cout << "Player -> " << i << endl;
			}
		}
		cout << endl;
		cout << "Round End" << endl;
	}
}
