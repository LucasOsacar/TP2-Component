/**
* Copyright (c) 2015 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <string>
#include <MessengerInterface.h>
#include <ComponentInterface.h>
class MessengerEbay : public MessengerInterface, public ComponentInterface
{
    public:
        MessengerEbay();
        virtual ~MessengerEbay();
        std::string say();

        //ComponentInterface:
        bool implements(std::string interfaceName);
        void* getInstance();
        void release();

    private:
        int referenceCounter;
        bool implemented;
};

MessengerEbay::MessengerEbay() : referenceCounter(0){}

MessengerEbay::~MessengerEbay(){}

std::string MessengerEbay::say()
{
    return "This is an message of Ebay";
}

//ComponentInterface:
bool MessengerEbay::implements(std::string interfaceName)
{
    return (interfaceName == "ComponentInterface" || interfaceName == "MessengerInterface") ?
        implemented = true
            : implemented = false;
}

void* MessengerEbay::getInstance()
{
    if(implemented) {  referenceCounter++;  return this; }
    return NULL;
}

void MessengerEbay::release()
{
    referenceCounter--;
    if(referenceCounter <= 0) delete this;
}

extern "C" ComponentInterface* create();

ComponentInterface* create()
{
    return (ComponentInterface*) new MessengerEbay();
}

