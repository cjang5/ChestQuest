 /*                     ___________________________
				  	   / _________________________ \
                      / / i  II          i  II    \ \  
					  | | i  II             II    | |
					  | |_i__II_____________II____| |
				 	  |____________.---.____________|
					  |  _________/  O  \_________  |
					  | |     i  |  /_\  |  i     | |
					  | |  i      \_____/   i     | |
					  | |__i______________________| |
					  |_____________________________|
	        
            *****************************************************
		      _____     _     _    _______     _____     _______
             / ___ \   | |   | |  |  _____|   / ___ \   |__   __|
            | |   |_|  | |___| |  | |__       \ \__|_|     | |
 		    | |    _   |  ___  |  |  __|      _\___ \      | |
		    | |___| |  | |   | |  | |_____   | |___\ \     | |
		     \_____/   |_|   |_|  |_______|   \_____/      |_|   
			                       v0.0.1a
		    *****************************************************                */

#include "stdafx.h"
#include <iostream>
#include "Random.h" //for random number generation
#include "Events.h" //for random events
#include <string>	//for strings
#include "Character.h" //for characters

//forward declarations
void startNewGame();
void exitGame();
void getNextCommand();

//Global(?) Variables
bool isGameRunning = false;		//to check if the game is running
bool isChestPresent = false;	//check if there is a chest present currently
int chestNo = 0;				//current Chest number you are on

//Yes or No for yes or no related functions
string YesOrNo() {
}
//exiting the game
void exitGame() {
	exit(0);
}

//STRUCTS (IN THE PROCESS OF MOVING TO CLASSES)

Character player; //player (YOU)

//Inventory
class Inventory {
private:
	unsigned int gold;			//the amount of gold you have
	unsigned int numPotions;	//the amount of potions you have; Currently in 0.0.1a only one type of potion - heals 10HP (WHEN HP IS IMPLEMENTED)
public:
	unsigned int getGold() {	//getter for inventory's gold amount
		return gold;
	}

	unsigned int getNumPotions() {	//getter for inventory's potions amount
		return numPotions;
	}

	void addGold(int x) {
		gold += x;
	}

	void addPotion(int x) {
		numPotions += x;
	}

	void initialize() {		//initialize inventory
		gold = 0;
		numPotions = 0;
	}

	//TODO: Stats, e.g: STR, INT, DEF, etc...
};

Inventory inv; //Main inventory

//Chests
struct chestObject {
	int type;
	/* Chest Types (0.0.1a)
	1		"Normal"
	2		"Metal"
	3		"Treasure"
	*/

	int status; 
	/*Statuses (0.0.1a)
	1		"Unlocked" OR "Openable"
	2		"Locked" - Requires a Key to open
	*/

	//bool isFinished;
	//TODO: Prefixes, Content Tiers...
};

int getChestType(chestObject c) {
	return c.type;
}

int getChestStatus(chestObject c) {
	return c.status;
}

//generate random chest
chestObject randChest() { //completely random; no parameters
	using namespace std;

	chestObject c;
	c.type = Random(1, 3);	//randomize chest's type
	chestNo++;				//increment total number of chests

	cout << "You found a chest! This is Chest #" << chestNo << endl;
	
	isChestPresent = true;	//alert that there is currently a chest to be opened

	return c;
}

//chestObject randChest(); //TODO: Generator with parameters

chestObject currentChest;	//Main Chest object; the one that is in front of you

//Looting Chests
void lootChest(chestObject cc) {
	using namespace std;

	//loot variables (Gold, Potions, etc...)
	unsigned int rGold;		//rGold = "Received Gold"
	unsigned int rPotions;	//rPotions = "Received Potions"

	//Determine how much gold/potions based on chest's type (rarity) **TEMPORARY TIER NAMES
	switch (cc.type) {
	case 1:		//first tier = 'Normal' Chest; (1-50 Gold) ; (0-1 Potions)
		rGold = Random(1, 50);
		rPotions = Random(0, 1);
		break;
	case 2:		//second tier = 'Metal' Chest; (25-100 Gold) ; (1-3 Potions)
		rGold = Random(25, 100);
		rPotions = Random(1, 3);
		break;
	case 3:		//third tier = 'Treasure' Chest; (50-250) Gold) ; (3-5 Potions)
		rGold = Random(50, 250);
		rPotions = Random(3, 5);
		break;
	}
	
	inv.addGold(rGold);					//add the gold found to your inventory 
	if (rGold > 0)						//Tell the player how much gold they found if amount > 0
		cout << "You found: " << rGold << " gold pieces from the chest!" << endl;
	
	inv.addPotion(rPotions);		//add the number of potions found (if any) to the inventory
	if (rPotions == 1)
		cout << "You found a potion!" << endl;
	else if (rPotions > 1)
		cout << "You found: " << rPotions << " potions!" << endl;

	cout << endl;

	//after chest is looted
	isChestPresent = false;
}

void startNewGame() {
	isGameRunning = true;

	//initialize inventory
	inv.initialize();

	//initialize character
	player.initialize();

	//generate first chest
	currentChest = randChest();
	isChestPresent = true;

	getNextCommand();
}

//character actions
void usePotion() { //COMPLETE THIS LATER WHEN MONSTERS OR DAMAGE ARE IMPLEMENTED;; no point in potions if you cant get hurt!!
	using namespace std;
	if (inv.getNumPotions() > 0) {
		cout << "You use a potion." << endl;
		inv.addPotion(-1);
		player.addHP(5); //placeholder for potion healing value. TODO: Different types of potions with different effects.
	} else {
		cout << "You have no potions to use!" << endl;
	}
}

//getNextCommand
void getNextCommand() {
	using namespace std;

	getAnotherCommand:  //goto reference to get another command if 'n' is not initiated
	
	char command;		//the variable that holds the player's commands. *TODO: Upgrade to 'string' commands. (0.0.3a ALPHA?)

	//chest Commands
	if (isChestPresent) {
	getChestCommand:
		cout << "Would you like to open this chest? (y/n)" << endl;
		cin >> command;
		switch (command) {
		//YES
		case 'y': case 'Y':
			lootChest(currentChest);
			break;
		//NO
		case 'n': case 'N':
			cout << "Okay then, moving on!" << endl;
			isChestPresent = false;
			//TODO: Random event messages e.g: "You stubbed your toe", "You slipped on mud!", etc...
			break;
		default :
			cout << "Not a valid option dude, you either open the chest or don't, jeez." << endl;
			goto getChestCommand;
			break;
		}
	} 

	cout << "Type in an action: ";

	cin >> command;
	switch (command) {
	//continue
	int chanceForEvent; //forward declaration
	case 'c': case 'C':
		//random event
		//chanceForEvent = Random(1, 3);
		//if (chanceForEvent == 1)
		randomEvent;
		
		//get a new chest
		currentChest = randChest();
		goto getAnotherCommand;
		break;
	//check version number
	case '!': 
		cout << "Current version is: v0.0.1 ALPHA" << endl;
		goto getAnotherCommand;
		break;
	//help
	case 'h': case 'H': 
		if (isGameRunning) {
			cout << "\t\"!\"\tCheck version number of CHEST." << endl;
			cout << "\t\"c\"\tContinue on your journey opening chests." << endl;
			cout << "\t\"s\"\tCheck your character's current status." << endl;
			cout << "\t\"x\"\tExit the game." << endl;
		} else {
			cout << "\t\"!\"\tCheck version number of CHEST." << endl;
			cout << "\t\"n\"\tStart a new game." << endl;
			cout << "\t\"x\"\tExit the game." << endl;
		}
		//add more couts when more commands are made
		goto getAnotherCommand;
		break;
	//start a new game
	case 'n': 
		if (isGameRunning == false)
			startNewGame();
		else
			cout << "Already started a game; invalid command." << endl;
			goto getAnotherCommand;
		break;
	//exit game
	case 'x': case 'X': 
		cout << "Goodbye!" << endl;
		exitGame();
		break;
	//TEMPORARY: Generate random number
	case 'r':
		for (int i = 0; i < 100; i++) {
			cout << Random(1, 3) << " ";
			if (i % 20 == 0)
				cout << endl;
		}
		cout << endl;
		goto getAnotherCommand;
		break;
	//status - Gold count, potion count, etc...
	case 's': case 'S':
		cout << "\tGOLD: " << inv.getGold() << endl;
		cout << "\tPOTIONS: " << inv.getNumPotions() << endl;
		goto getAnotherCommand;
		break;
	//Default
	default :
		cout << "No such command." << endl;
		goto getAnotherCommand;
		break;
	}
}

int main() {
	using namespace std;

	//welcome screen
	cout << "Welcome to CHEST QUEST!" << endl;
	cout << "Type \"!\" to check version number." << endl;
	cout << "Type \"n\" to start a new game." << endl << endl;
	
	getNextCommand();

	return 0;
}