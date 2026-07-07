#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto mainMenu = this->getChildByID("main-menu");
        if (mainMenu) {
            auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
            buttonSprite->setScale(0.4f);
            auto myButton = CCMenuItemSpriteExtra::create(
                buttonSprite, this, menu_selector(MyMenuLayer::onMyButtonClick)
            );
            mainMenu->addChild(myButton);
            mainMenu->updateLayout();
        }
        return true;
    }
    void onMyButtonClick(CCObject* sender) {
        FLAlertLayer::create("Geode Мод", "Кнопка работает!", "OK")->show();
    }
};
