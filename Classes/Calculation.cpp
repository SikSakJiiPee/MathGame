#include "Calculation.h"



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

	auto label = cocos2d::Label::createWithSystemFont("Calculation", "Arial", 30);
	label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));
	this->addChild(label, 1);
	

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* evnt)
	{
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		{
			int number = randomNumber();
			std::string sNumber = convertIntToString(number);

			int number2 = randomNumber();
			std::string sNumber2 = convertIntToString(number2);

			int correctAnswer = getCorrectAnswerPlus(number, number2);
			std::string sCorrectAnswer = convertIntToString(correctAnswer);

			auto label2 = cocos2d::Label::createWithSystemFont(sNumber + " + " + sNumber2 + " = " + sCorrectAnswer, "Arial", 30);
			label2->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY()));
			this->addChild(label2, 2);

			break;
		}
		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

int Calculation::randomNumber()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(1, 100);
	auto rNumber = uni(rng);

	return rNumber;
}

int Calculation::getCorrectAnswerPlus(int number, int number2)
{
	int correctAnswer = number + number2;

	return correctAnswer;
}

int Calculation::getCorrectAnswerMinus(int number, int number2)
{
	int correctAnswer = number - number2;

	return correctAnswer;
}

std::string Calculation::convertIntToString(int intNumber)
{
	std::stringstream ss;
	ss << intNumber;
	std::string stringNumber = ss.str();

	return stringNumber;
}

bool Calculation::checkTheAnswer(int playerAnswer, int correctAnswer)
{
	if (playerAnswer == correctAnswer)
	{
		return false;
	}

	return true;
}