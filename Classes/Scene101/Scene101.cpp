#include "Scene101.h"

#define HOME_BACKGROUND "scene101/s101bgimg.png"

USING_NS_CC;

Scene* Scene101::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Scene101::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Scene101::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size size;

	//以 Sprite 作為背景
	Sprite *bkimage = Sprite::create(HOME_BACKGROUND);  // 使用 create 函式,給予檔名即可
	bkimage->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y)); // 位置通常放置在螢幕正中間
	this->addChild(bkimage, 0);

	// 自行增加 sprite 將 bean01.png 到螢幕正中間


	// create and initialize a label, add a label shows "Scene 101"
	auto label = Label::createWithTTF("Scene 101", "fonts/Marker Felt.ttf", 32);
	label->setAlignment(cocos2d::TextHAlignment::CENTER); // 預設靠左對齊
	label->setWidth(100);	// 設定每行文字的顯示寬度
	size = label->getContentSize();
	label->setPosition(Vec2(origin.x + visibleSize.width - size.width / 2 - 10, origin.y + visibleSize.height - size.height / 2 - 10));
	this->addChild(label, 1);

	this->_sceneno = 101;
	strcpy(this->_cSceneNo, "Scene 101");

	//一般(非中文字)文字的顯示方式
	auto label1 = Label::createWithBMFont("fonts/couriernew32.fnt", "Scene 101");
	size = label1->getContentSize();
	label1->setColor(Color3B::WHITE);
	label1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - size.height));
	this->addChild(label1, 1);

	// 中文字的顯示方式
	auto strings = FileUtils::getInstance()->getValueMapFromFile("scene101/strings.xml");
	std::string str1 = strings["chinese1"].asString();
	std::string str2 = strings["chinese2"].asString();
	auto label2 = Label::createWithBMFont("fonts/hansans48.fnt", str1);
	auto label3 = Label::createWithBMFont("fonts/hansans48.fnt", str2);
	size = label2->getContentSize();
	label2->setColor(Color3B(255, 238, 217));
	label2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 80 - size.height));
	this->addChild(label2, 1);

	label3->setColor(Color3B(250, 251, 170));
	size = label3->getContentSize();
	label3->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 140 - size.height));
	this->addChild(label3, 1);

	// add Return Button
	this->returnbtn = Sprite::create("scene101/returnbtn.png");
	size = returnbtn->getContentSize();
	this->returnbtn->setPosition(Vec2(origin.x + size.width / 2 + 5, origin.y + visibleSize.height - size.height / 2 - 5));
	Point pos = returnbtn->getPosition();
	this->rectReturn = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	this->addChild(returnbtn, 1);

	// add Replay Button
	this->replaybtn = Sprite::create("scene101/replaybtn.png");
	size = replaybtn->getContentSize();
	this->replaybtn->setPosition(Vec2(origin.x + size.width / 2 + 90, origin.y + visibleSize.height - size.height / 2 - 5));
	pos = replaybtn->getPosition();
	this->rectReplay = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	this->addChild(replaybtn, 1);

	// add Cuber Button
	this->cuberbtn = Sprite::create("scene101/cuberbtn1.png");
	size = cuberbtn->getContentSize();
	this->cuberbtn->setPosition(Vec2(origin.x + visibleSize.width - size.width / 2, origin.y + visibleSize.height - size.height / 2 - 60));
	pos = cuberbtn->getPosition();
	this->rectCuber = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	this->addChild(cuberbtn, 1);

	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(Scene101::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(Scene101::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(Scene101::onTouchEnded, this);		//加入觸碰離開事件

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器
	this->schedule(CC_SCHEDULE_SELECTOR(Scene101::doStep));

	return true;
}

void Scene101::doStep(float dt)  // OnFrameMove
{

}

bool  Scene101::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (rectCuber.containsPoint(touchLoc)) {

	}
	if (rectReplay.containsPoint(touchLoc)) {

	}
	if (rectReturn.containsPoint(touchLoc)) {
		unscheduleAllCallbacks();
		Director::getInstance()->end();
	}

	return true;
}

void  Scene101::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{


}

void  Scene101::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{



}