#pragma once

#include "cocos2d.h"

class Calculation : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	int randomNumber();
	CREATE_FUNC(Calculation);
};