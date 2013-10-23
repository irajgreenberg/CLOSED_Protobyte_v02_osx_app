//
//  ProtoPlasm.h
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//



#ifndef __Protobyte_dev_v02__ProtoPlasm__
#define __Protobyte_dev_v02__ProtoPlasm__

#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "ProtoBaseApp.h"

namespace ijg {
    
    class ProtoPlasm{
        
    public:
        explicit ProtoPlasm(ProtoBaseApp* p);
        ProtoPlasm(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* p);
       
        
    private:
        ProtoPlasm(); // prohibit default
        
        void initSFMLInit();
        void initSFMLRun();
        
        ProtoWorld* world;
        sf::Window* window;
        ProtoBaseApp* baseApp;
        
        int appWidth;
        int appHeight;
        std::string appTitle;
    };
}

#endif /* defined(__Protobyte_dev_v02__ProtoPlasm__) */
