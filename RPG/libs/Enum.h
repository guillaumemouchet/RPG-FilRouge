#ifndef ENUM_HPP
#define ENUM_HPP

using namespace std;

namespace HE_ARC::RPG
{
    enum accept
    {
        oui = 0,
        non = 1,
        jeter = 2
    };
    enum CLASS
    {
        warrior = 0,
        wizard = 1,
        necromancer = 2

    };

    enum aAzazel
    {
       
        brimstorm = 1,
        cBrimstorm = 6,

        doubleslash = 2,
        cDoubleslash = 3,

        apocalypse = 3,
        cApocalypse = 5,
    };

    enum aGoblin
    {
        steal = 0,
        cSteal = 4,

        rallye = 1,
        cRallye = 5,

        slingshot = 2,
        cSlingshot = 4
    };

    enum aUndead
    {
        poisongrip= 2,
        cPoisongrip = 4,

        manadrain = 0,
        cManadrain = 3,
        
        riseundead = 1,
        cRiseundead = 4,
        mRiseundead = 4,
    };
    
    enum aNecromancer
    {

        cataclysme = 0,
        cCataclysme = 5,
        mCataclysme = 6
    };

    enum aWarrior
    {
        rampage = 0,
        cRampage = 4, //constante de dégat du sort

        shieldbash = 1,
        cShieldbash = 2,

        taunt = 2,
        cTaunt = 3
    };

    enum aWizard
    {
        fireball = 0,
        cFireball = 3,
        mFireball = 3,

        blizzard = 1,
        cBlizzard =4,
        mBlizzard = 5,

        leech = 2,
        cLeech = 4,
        mLeech = 8
    };

    enum hAction
    {
        attack =0,
        backpack =1,
        concede =2
    };

    enum timer
    {
        lTime = 3000,
        sTime = 500
    };

}

#endif