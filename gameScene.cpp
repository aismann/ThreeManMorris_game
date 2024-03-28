#include "gameScene.h"

USING_NS_CC;

Scene* gameScene::createScene()
{
    return gameScene::create();
}

bool gameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto player1Lives = Label::createWithTTF("Player1: ", "fonts/Marker Felt.ttf", 24);
    player1Lives->setPosition(Vec2(origin.x + player1Lives->getWidth()*2,
            origin.y + visibleSize.height - player1Lives->getHeight()*2));

    this->addChild(player1Lives, 1);

    auto player2Lives = Label::createWithTTF("Player2: ", "fonts/Marker Felt.ttf", 24);
    player2Lives->setPosition(Vec2(origin.x + visibleSize.width - player2Lives->getWidth() * 2,
        origin.y + visibleSize.height - player2Lives->getHeight() * 2));

    this->addChild(player2Lives, 1);
    return true;
}

void gameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}