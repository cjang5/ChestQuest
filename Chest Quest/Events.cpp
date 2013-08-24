#include "stdafx.h"
#include <iostream>
#include "Random.h"
#include <string> //for generating messages

void randomEvent() {
	using namespace std; //for cout

	cout << "IF YOU SEE THIS, randomEvent() WORKS" << endl;
	int tier; //1 = Mundane, 2 = Helpful, 3 = Harmful
	tier = Random(1, 4);
	
	//determine what kind of message is return
	if (tier == 1) {		//Mundane
		cout << "TIER 1 EVENT" << endl;
		/*int messageList = Random(1, 10); //generate 10 (for now) messages
		switch (messageList) {
		case 1:
			cout << "You were walking through the forest when you noticed how round a rock was." << endl;
			break;
		case 2:
			cout << "A bug flies past your field of vision and you watch it until it gets lost in the trees." << endl;
			break;
		case 3:
			cout << "The clouds part and the sun shines brightly in the land." << endl;
			break;
		case 4: 
			cout << "You discover a sign." << endl; //TODO: Ask the player if they want to read it.
			break;
		case 5:
			cout << "You notice that the grass is really green." << endl;
			break;
		case 6:
			cout << "You pick your nose." << endl;
			break;
		case 7:
			cout << "You stop in your tracks to scratch your man parts." << endl;
			break;
		case 8:
			cout << "You pinch your nose because it smells like ass." << endl;
			break;
		case 9:
			cout << "You meat a lad who calls himself \"Meatboy\"...Nothing particularly super about him." << endl;
			break;
		case 10:
			cout << "You meet a guy called Kyle Goldfarb and you chuckle at his last name. lol." << endl;
			break;
		} */
	} else if (tier == 2) {	//Helpful
		cout << "TIER 2 EVENT." << endl;
	} else if (tier == 3) { //Harmful
		cout << "TIER 3 EVENT" << endl;
	} else if (tier == 4) { //mystery
		cout << "TIER 4 EVENT" << endl;
	}
}