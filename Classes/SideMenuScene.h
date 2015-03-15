//
//  SideMenuScene.h
//  Sidemenu
//
//  Created by MAEDAHAJIME on 2015/03/07.
//
//

#ifndef __Sidemenu__SideMenuScene__
#define __Sidemenu__SideMenuScene__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class SideMenuScene : public cocos2d::Layer
{
protected:
    // addLayer
    void addLayer(Ref *pSender);
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    MenuItemImage* backButton;
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu01(Ref *pSender);
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu02(Ref *pSender);
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushMenu03(Ref *pSender);
    
    CREATE_FUNC(SideMenuScene);
};

#endif /* defined(__Sidemenu__SideMenuScene__) */
