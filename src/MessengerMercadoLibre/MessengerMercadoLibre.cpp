/**
* Copyright (c) 2015 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <string>
#include <MessengerInterface.h>
#include <ComponentInterface.h>
class MessengerMercadoLibre : public MessengerInterface, public ComponentInterface
{
    public:
        MessengerMercadoLibre();
        virtual ~MessengerMercadoLibre();
        std::string say();

        //ComponentInterface:
        bool implements(std::string interfaceName);
        void* getInstance();
        void release();

    private:
        int referenceCounter;
        bool implemented;
};

MessengerMercadoLibre::MessengerMercadoLibre() : referenceCounter(0){}

MessengerMercadoLibre::~MessengerMercadoLibre(){}

std::string MessengerMercadoLibre::say()
{
    return "Este es un mensaje de Mercado Libre...";
}

//ComponentInterface:
bool MessengerMercadoLibre::implements(std::string interfaceName)
{
    return (interfaceName == "ComponentInterface" || interfaceName == "MessengerInterface") ?
        implemented = true
            : implemented = false;
}

void* MessengerMercadoLibre::getInstance()
{
    if(implemented) {  referenceCounter++;  return this; }
    return NULL;
}

void MessengerMercadoLibre::release()
{
    referenceCounter--;
    if(referenceCounter <= 0) delete this;
}

extern "C" ComponentInterface* create();

ComponentInterface* create()
{
    return (ComponentInterface*) new MessengerMercadoLibre();
}