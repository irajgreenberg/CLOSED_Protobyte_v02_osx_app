//
//  App01.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "App01.h"

using namespace ijg;

App01::App01(){
    // call base class 1st
    //std::cout << "in derived class cstr" << std::endl;
}

void App01::init(){
    
    std::unique_ptr<ProtoToroid> toroid1(new ProtoToroid(Vec3f(0, 0, 0), Vec3f(15,0,0), Dim3f(1, 1, 1),ProtoColor4f(.2, .9, .6, 1), 35, 35, 1.5, .2));
    
    std::unique_ptr<ProtoToroid> toroid2(new ProtoToroid(Vec3f(0, 0, -800), Vec3f(0, ProtoMath::PI/3.0,0), Dim3f(20.3, 20.3, 20.3),ProtoColor4f(.5, .2, .3, 1), 75, 75, .9, .2));
    
    
    add(std::move(toroid1));
    add(std::move(toroid2));
    
   
    // try simplified call - tranforms not working properly this way
    glPushMatrix();
    glTranslatef(3.9f, .4f, 0);
    toroid();
    glPopMatrix();

    
    
}

// event thread runs continuously
//ProtoWorld draw independently
void App01::run(){
    
}

void App01::keyPressed(){
    
}


void App01::mousePressed(){
    //std::cout << "mousePressed" << std::endl;
}
void App01::mouseRightPressed(){
    
}
void App01::mouseReleased(){
    
}
void App01::mouseRightReleased(){
    
}
void App01::mouseMoved(){
    
}
void App01::mouseDragged(){
    
}

void App01::onResized(){
    
}
void App01::onClosed(){
   // std::cout << "in Closed" << std::endl;
}



