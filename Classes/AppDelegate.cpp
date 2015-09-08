#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameMainScene.h"

using namespace cocos2d;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) {
        glview = GLView::create("proj_DDM");
        director->setOpenGLView(glview);
    }

    director->setDisplayStats( false );
	director->setAnimationInterval( 1.f / 60.f );

	glview->setDesignResolutionSize( 1280, 720, ResolutionPolicy::SHOW_ALL );

	auto firstScene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 1.0f, true);
	auto scene = TransitionFade::create(1.5f, firstScene, Color3B::BLACK);
	director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
