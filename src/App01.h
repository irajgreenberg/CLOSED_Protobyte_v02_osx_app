//
//  App01.h
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __Protobyte_dev_v02__App01__
#define __Protobyte_dev_v02__App01__

#include "ProtoBaseApp.h"
#include <iostream>

#include "ProtoVerletSurface.h"

using namespace ijg;

class App01 : public ProtoBaseApp {

private:
    std::unique_ptr<ProtoToroid> toroid2;
    std::shared_ptr<ProtoVerletBall> ball1;
    std::shared_ptr<ProtoVerletBall> ball2;
    std::unique_ptr<ProtoVerletStick> stick;
    
    /* vector of balls (1d will store 2d data)
     need to be shared_ptrs because balls are
     connected to multiple lines */
    std::vector< std::shared_ptr<ProtoVerletBall> >  balls;
    
    // vector of sticks
    std::vector< std::unique_ptr<ProtoVerletStick> >  sticks;
    
    
    std::unique_ptr<ProtoVerletSurface> verletSurf;

public:
    App01();
    void init();
    void run();
    
    // Mouses/Key Events
    void keyPressed();
    void mousePressed();
    void mouseRightPressed();
    void mouseReleased();
    void mouseRightReleased();
    void mouseMoved();
    void mouseDragged();
    
    // window events
    void onResized();
    void onClosed();


    
    
};

#endif /* defined(__Protobyte_dev_v02__App01__) */
