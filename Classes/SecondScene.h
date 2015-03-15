//
//  SecondScene.h
//  Sidemenu
//
//  Created by MAEDAHAJIME on 2015/03/07.
//
//

#ifndef __Sidemenu__SecondScene__
#define __Sidemenu__SecondScene__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class SecondScene : public cocos2d::Layer
{
protected:
    // addLayer
    void addLayer(Ref *pSender);
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(SecondScene);
    
    void makeBackground();
    
    MenuItemImage* backButton;
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu01(Ref *pSender);
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu02(Ref *pSender);
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu03(Ref *pSender);
};

#endif /* defined(__Sidemenu__SecondScene__) */
