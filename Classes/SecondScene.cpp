//
//  SecondScene.cpp
//  Sidemenu
//
//  Created by MAEDAHAJIME on 2015/03/07.
//
//

#include "SecondScene.h"
#include "SideMenuScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

Scene *SecondScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SecondScene::create();
    scene->addChild(layer);
    return scene;
}

bool SecondScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    // バックグラウンド
    makeBackground();
    
    //画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();

    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    //サイドメニューボタンを設置
    // ボタンを押した時にメソッドを呼び出す.h = void pushStart01(Ref *pSender); 宣言必要
    backButton = MenuItemImage::create("Back.png",  //表示
                                       "BackSelected.png",  //タップ時の画像
                                       CC_CALLBACK_1(SecondScene::addLayer, this));
    
    backButton->setPosition(Vec2(winSize.width /2 - 260 ,winSize.height/2 + 510));
    
    //create menu, it's an autorelease object
    auto menu = Menu::create(backButton, NULL);
    
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 1);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    return true;
}

#define kModalLayerPriority -1

void SecondScene::addLayer(Ref *pSender)
{
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    //backButtonを非表示に
    backButton->setVisible(false);
    
    //////////////////////////////
    // layerの生成
    auto layer = Layer::create();
    
    // モーダルレイヤ ここから
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch *touch,Event*event)->bool{
        return true;
    };
    
    auto dip = layer->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    dip->setPriority(listener, kModalLayerPriority);
    // モーダルレイヤ ここまで
    
    auto size = Director::getInstance()->getVisibleSize();
    ui::ScrollView* sc = ui::ScrollView::create();
    sc->setContentSize(size);
    sc->setBackGroundColor(Color3B(245, 245, 220)); //
    sc->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    sc->setBounceEnabled(true);
    sc->setDirection(ui::ScrollView::Direction::VERTICAL);
    sc->setContentSize(Size(400,size.height));
    sc->setInnerContainerSize(Size(400, sc->getContentSize().height + 400 ));
    //透明度を変更(0~255)
    sc->setOpacity(120);
    
    sc->setPosition(Vec2(0,size.height - sc->getContentSize().height ));
    
    auto Sprite00 = Sprite::create("menu.png");
    Sprite00->setPosition(Vec2(Sprite00->getContentSize().width / 2.0f,
                               sc->getContentSize().height - Sprite00->getContentSize().height + 400));
    sc->addChild(Sprite00,1);
    
    
    auto button00 = MenuItemImage::create("menu01.png",  // 通常状態の画像
                                          "menu00-hover.png",  // 押下状態の画像
                                          CC_CALLBACK_1(SecondScene::pushMenu01, this));
    
    auto button01 = MenuItemImage::create("menu02.png",  // 通常状態の画像
                                          "menu00-hover.png",  // 押下状態の画像
                                          CC_CALLBACK_1(SecondScene::pushMenu02, this));
    
    auto button02 = MenuItemImage::create("menu03.png",  // 通常状態の画像
                                          "menu00-hover.png",  // 押下状態の画像
                                          CC_CALLBACK_1(SecondScene::pushMenu03, this));
    
    button00->setPosition(Vec2(button00->getContentSize().width / 2.0f,
                               sc->getContentSize().height - button00->getContentSize().height + 300));
    button01->setPosition(Vec2(button01->getContentSize().width / 2.0f,
                               sc->getContentSize().height - button01->getContentSize().height + 200));
    button02->setPosition(Vec2(button02->getContentSize().width / 2.0f,
                               sc->getContentSize().height - button02->getContentSize().height + 100));
    
    //メニューを作成 自動解放オブジェクト
    auto menu = Menu::create(button00, button01, button02, NULL);
    
    menu->setPosition(Point::ZERO);
    // メニューを追加
    sc->addChild(menu, 1);
    
    layer->addChild(sc, 1);
    
    addChild(layer, 2); // Z = 2 背景の文字の上に表示
}

// pushStart01ボタン
void SecondScene::pushMenu01(Ref *pSender)
{
    CCLOG("pushMenuボタン01");
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = SideMenuScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
    
}

// pushStart02ボタン
void SecondScene::pushMenu02(Ref *pSender)
{
    CCLOG("pushMenuボタン02");
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = SecondScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}

// pushStart03ボタン
void SecondScene::pushMenu03(Ref *pSender)
{
    CCLOG("pushMenuボタン03");
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = SecondScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}

void SecondScene::makeBackground()
{
    //画面の座標関係の詳しい説明はここhttp://www.cocos2d-x.org/wiki/Coordinate_System
    //画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::ORANGE,
                                         winSize.width,
                                         winSize.height);
    //バックグランドカラー追加 第2引数は表示順
    this->addChild(background, 0);
    
    //タイトルを設置
    auto lbl_title = Label::createWithSystemFont
    ("Second", "HiraKakuProN-W6", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    this->addChild(lbl_title,1);
}