#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h";

class gameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(gameScene);
};
#endif // __GAME_SCENE_H__