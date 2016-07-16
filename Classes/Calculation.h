#pragma once

#include "cocos2d.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (rand)
#include <cstdlib> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (srand)
#include <time.h>
#include <random>


class Calculation : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	int randomNumber();
	int getCorrectAnswerPlus(int number, int number2);
	int getCorrectAnswerMinus(int number, int number2);
	std::string convertIntToString(int number);
	bool checkTheAnswer(int playerAnswer, int correctAnswer);

	CREATE_FUNC(Calculation);
};