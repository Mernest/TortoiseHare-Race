//Ernest Majdalani, ID: 40021641
//This program uses pointers in order to simulate a race between a turtle and a hare, their positions are shown by
// the letters T and H
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int END_RACE = 70;

void moveTortoise(int *);
void moveHare(int *);

int main() {

	srand(time(0));

	int T = 1;
	int H = 1;
	bool win = false;


	cout << "BANG !!" << endl << "AND THEY'RE OFF !!!!!" << endl << endl;

	while (T != END_RACE && H != END_RACE) {
		for (int i = 0; i < pow(2, 20); ++i);
		moveTortoise(&T);
		moveHare(&H);

		if (T > H) {
			cout << setw(H) << 'H' << setw(T - H) << 'T';
		}
		else if (H > T) {
			cout << setw(T) << 'T' << setw(H - T) << 'H';
		}
		else if (T == H) {
			cout << setw(T) << "OUCH !!!";
		}
		
		else if (T >= END_RACE || H >= END_RACE)
			win = true;
		cout << endl;

	}
	cout << T << " " << H << endl;
	if (T > H) {
		cout << "TORTOISE WINS!!!" << endl;
	}
	else if (H > T)
		cout << "HARE WINS !!! " << endl;
	else if (T==H)
		cout << "TIE" << endl;
}



//Tortoise movement
void moveTortoise(int *Tptr) {

	int T_prob = 1 + rand() % 10; // generates random numbers between 1 and 10 to establish the frequencies for each movement

	if (T_prob >= 1 && T_prob <= 5) { // fast plod
		*Tptr += 3;
	}
	else if ((T_prob == 6 || T_prob == 7) && *Tptr>=7) { // slip
		*Tptr -= 6;
	}
	else
		*Tptr += 1; // slow pod
	if (*Tptr > END_RACE) {
		*Tptr = END_RACE;
	}
}

// Hare movement
void moveHare(int *Hptr) {

		int H_prob = 1 + rand() % 10;

		if (H_prob == 1 || H_prob == 2) { // big hop
			*Hptr += 9;
		}
		else if (H_prob == 3 && *Hptr >=13) { // big slip
			*Hptr -= 12;
		}
		else if (H_prob >= 4 && H_prob <= 6) { // small hop
			*Hptr += 1;
		}
		else if ((H_prob == 7 || H_prob == 8) &&  *Hptr >=3) { // small slip
			*Hptr -= 2;
		}
		else
		{
			; // sleep, does nothing
		}
		if (*Hptr > END_RACE) {
			*Hptr = END_RACE;
		}
	}


