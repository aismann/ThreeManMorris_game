/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto gameName = Label::createWithTTF("Nine men Morris", "fonts/Marker Felt.ttf", 48);
    if (gameName == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        gameName->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - gameName->getContentSize().height));

        this->addChild(gameName, 1);
    }


    auto menuItem1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::loadGameScreen, this));
    auto menuItem2 = MenuItemFont::create("Exit game", CC_CALLBACK_1(HelloWorld::exitGame, this));

    menuItem1->setPosition(Point(origin.x + visibleSize.width / 2, visibleSize.height/2));
    menuItem2->setPosition(Point(origin.x + visibleSize.width / 2, visibleSize.height / 2 - 80.0f));

    auto *menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

void HelloWorld::loadGameScreen(Ref *pSender)
{
    //Director::getInstance()->end();
    CCLOG("Loading game...");
}

void HelloWorld::exitGame(Ref* pSender)
{
    Director::getInstance()->end();
}