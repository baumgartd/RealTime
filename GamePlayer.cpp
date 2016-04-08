/*
 * GamePlayer.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: cs3844
 */

#include "GamePlayer.h"
#include <pthread.h>
#include <unistd.h>
#include "GPIO.h"
#include <ctime>

using namespace std;

void GamePlayer::lightOff(){
	light->setValue(GPIO::LOW);
}

void GamePlayer::lightOn(){
	light->setValue(GPIO::HIGH);
}

GamePlayer::GamePlayer(int port1,int port2){

	button = new GPIO(port1);
	button->setDirection(GPIO::INPUT);
	light = new GPIO(port2);
	light->setDirection(GPIO::OUTPUT);
	elapsedTime = 0;
	this->thread = 0;

}


void GamePlayer::run(){
	time_t now = 0;
	time_t after = 0;
	if(light->waitForEdge() == 1){
		now = time(0);
	}
	if(button->waitForEdge() == 1){
		light->setValue(GPIO::HIGH);
		after = time(0);
	}
	elapsedTime = after - now;
}


GamePlayer::~GamePlayer(){
	delete(button);
	delete(light);
}

long GamePlayer::getElapsedTime(){
	return elapsedTime;
}

void *startGamePlayer(void *instance){
	GamePlayer *thisInstance = static_cast<GamePlayer*>(instance);
	thisInstance->run();
	return NULL;
}

void GamePlayer::start(){
	pthread_create(&thread, NULL, &startGamePlayer, this);
}

pthread_t GamePlayer::getThread(){
	return thread;
}

