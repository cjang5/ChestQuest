#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
	private:
	//attributes
	int HP;	//health points

public:
	void initialize() {		//initialize player values at start of a new game
		HP = 10;
	}

	void addHP(int x) {		//Add or remove HP from damage, etc.
		HP += x;
	}
};

#endif           