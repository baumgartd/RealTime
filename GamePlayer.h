/*
 * GamePlayer.h
 *
 *  Created on: Apr 8, 2016
 *      Author: cs3844
 */

#ifndef GAMEPLAYER_H_
#define GAMEPLAYER_H_
#include <pthread.h>
#include "GPIO.h"
using namespace exploringBB;

class GamePlayer {
private:
	GPIO *button;
	long elapsedTime;
	GPIO *light;
	pthread_t thread;

public:
	GamePlayer(int,int);
	~GamePlayer();
	long getElapsedTime();
	pthread_t getThread();
	void run();
	void start();
	friend void *startGamePlayer(void*);
	void lightOff();
	void lightOn();

};
#endif /* GAMEPLAYER_H_ */
