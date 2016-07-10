#include "MainGame.h"
#include "Calculation.h"

cocos2d::Scene* MainGame::createScene()
{
	auto sceneMainGame = cocos2d::Scene::create();
	auto layer = MainGame::create();
	sceneMainGame->addChild(layer);
	return sceneMainGame;
}

bool MainGame::init()
{
	if (!Layer::init())
		return false;

	//auto director = cocos2d::Director::getInstance();

	

	auto label = cocos2d::Label::createWithSystemFont("MathGame", "Arial", 30);
	label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));
	this->addChild(label, 1);

	auto label2 = cocos2d::Label::createWithSystemFont("Press Space", "Arial", 30);
	label2->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY()));
	this->addChild(label2, 2);

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* evnt)
	{
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		{
			cocos2d::log("joo");
			auto sceneCalculation = Calculation::createScene();
			//director->pushScene(sceneCalculation);
			cocos2d::Director::getInstance()->replaceScene(sceneCalculation);

			break;
		}
		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}