/*
 * Main.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: cs3844
 */

#include "Main.h"
#include "GamePlayer.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	GamePlayer player1(68,66);
	GamePlayer player2(69,67);

	srand((unsigned)time(0));
	int random = (rand()%2);

	for(int i = 0; i < 10; i++){
		if(random == 0){
			player1.lightOn();
		}else{
			player2.lightOn();
		}
	}

	return 0;
}
