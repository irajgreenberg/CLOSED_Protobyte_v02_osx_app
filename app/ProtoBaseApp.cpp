//
//  ProtoBaseApp.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/26/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "ProtoBaseApp.h"

using namespace ijg;

// required call by subclass cstr
ProtoBaseApp::ProtoBaseApp() {
   // world = ProtoWorld::getInstance();
    std::cout << "in ProtoBaseApp CSTR"<<std::endl;
    //world = ProtoWorld::getInstance();
}

void ProtoBaseApp::setAppWindowDetails(int appWidth, int appHeight, std::string appTitle){
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->appTitle = appTitle;
    //world = ijg::ProtoWorld::getInstance(appWidth, appHeight);
    // ProtoWorld
    //world = ijg::ProtoWorld::getInstance(windowX, windowY);
    //std::cout << "world = " << world << std::endl;
    
    
}

void ProtoBaseApp::add(ProtoGeom3* geom){
    //world = ProtoWorld::getInstance();
    world->add(geom);
}


void ProtoBaseApp::keyPressed(){}
 void ProtoBaseApp::mousePressed(){}
 void ProtoBaseApp::mouseRightPressed(){}
 void ProtoBaseApp::mouseReleased(){}
 void ProtoBaseApp::mouseRightReleased(){}
 void ProtoBaseApp::mouseMoved(){}
 void ProtoBaseApp::mouseDragged(){}

// window events
 void ProtoBaseApp::onResized(){}
 void ProtoBaseApp::onClosed(){}

