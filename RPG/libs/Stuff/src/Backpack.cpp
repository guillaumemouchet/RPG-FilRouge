#include "..\include\Backpack.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{

    /**
    *@brief Vérifie si le sac à dos n'est pas vide
    */
    bool Backpack::isNotEmpty() const
    {
        return (not (this->mStack.empty()));
    }
    /**
    *@brief Enlève l'élément tout en haut du sac à dos
    */
    IObject* Backpack::unPack()
    {
        IObject *topStack = this->mStack.top();
        this->mStack.pop();
        return topStack;
    }
    /**
    *@brief met sur le haut du sac à dos l'objet passé en paramètre
    *@param _pObject pointeur sur un objet 
    */
    void Backpack::pack(IObject * _pObject)
    {
        this->mStack.push(_pObject);
    }
}