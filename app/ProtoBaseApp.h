#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "../../Protobyte_v02/ProtoMath.h"
#include "../../Protobyte_v02/ProtoWorld.h"
#include "../../Protobyte_v02/ProtoVector2.h"
#include "../../Protobyte_v02/ProtoVector3.h"
#include "../../Protobyte_v02/ProtoToroid.h"
#include "../../Protobyte_v02/ProtoSpline3.h"
#include "../../Protobyte_v02/ProtoSphere.h"
#include "../../Protobyte_v02/ProtoTube.h"
#include "../../Protobyte_v02/ProtoLight.h"


#ifndef PROTO_BASEAPP_H
#define PROTO_BASEAPP_H

#include <iostream>

namespace ijg {
    
    class ProtoBaseApp {
        
    public:
        ProtoBaseApp();
        
        void setAppWindowDetails(int appWidth, int appHeight, std::string appTitle);
        
        // pure virtual funcs require override
        virtual void setup()=0;
        virtual void draw()=0;
        
        // mouse/key events
        virtual void keyPressed();
        virtual void mousePressed();
        virtual void mouseRightPressed();
        virtual void mouseReleased();
        virtual void mouseRightReleased();
        virtual void mouseMoved();
        virtual void mouseDragged();
        
        // window events
        virtual void onResized();
        virtual void onClosed();
        
        
        void add(ProtoGeom3* geom);
        
        
        
    private:
        
        
    protected:
        ProtoWorld* world;
        int appWidth;
        int appHeight;
        std::string appTitle;
        
        
    };
    
}

#endif /* defined(PROTO_BASEAPP_H) */
