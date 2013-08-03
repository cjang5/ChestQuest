#include "stdafx.h"
#include <iostream>
#include "Random.h"

void randomEvent() {
	int tier; //1 = Mundane, 2 = Helpful, 3 = Harmful
	tier = Random(1, 3);
	
	//determine what kind of message is return
	if (tier == 1) {		//
		
	} else if (tier == 2) {	//

	} else if (tier == 3) { //

	}
}