#include "Calculation.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

cocos2d::Scene* Calculation::createScene()
{
	auto sceneCalculation = cocos2d::Scene::create();
	auto layer = Calculation::create();
	sceneCalculation->addChild(layer);
	return sceneCalculation;
}

bool Calculation::init()
{
	if (!Layer::init())
		return false;

	//int number = randomNumber();
	//std::stringstream ss;
	//ss << number;
	//std::string str = ss.str();

	int number2 = randomNumber();
	std::stringstream ss2;
	ss2 << number2;
	std::string str2 = ss2.str();

	std::string str = "1";

	auto label = cocos2d::Label::createWithSystemFont("Calculation", "Arial", 30);
	label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));
	this->addChild(label, 1);

	//auto label2 = cocos2d::Label::createWithSystemFont("1+1=?", "Arial", 30);
	auto label2 = cocos2d::Label::createWithSystemFont(str + " + " + str2, "Arial", 30);
	label2->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY()));
	this->addChild(label2, 2);

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* evnt)
	{
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		{
			randomNumber();

			break;
		}
		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

int Calculation::randomNumber()
{
	int rNumber = rand() % 100;

	return rNumber;
}