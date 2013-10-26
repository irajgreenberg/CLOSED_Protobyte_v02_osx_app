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
    //std::cout << "in base class cstr" << std::endl;
}

// get handle to world
void ProtoBaseApp::setWorld(std::unique_ptr<ProtoWorld> world){
    this->world = std::move(world);
}

// ownerhship was passed from Protoplasm to BaseApp, so BaseApp must start World rendering loop
void ProtoBaseApp::runWorld() {
    world->run();
}


void ProtoBaseApp::add(std::unique_ptr<ProtoGeom3> geom){
    world->add(std::move(geom));
}

void ProtoBaseApp::add(std::unique_ptr<ProtoLight> lt){
     world->add(std::move(lt));
}

void ProtoBaseApp::add(std::unique_ptr<ProtoCamera> cam){
    world->add(std::move(cam));
}


// EVENTS
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

// EXPERMENTS
void ProtoBaseApp::toroid(){
    add(std::move(std::unique_ptr<ProtoToroid>(new ProtoToroid(Vec3f(0, 0, -400), Vec3f(0, ProtoMath::PI/3.0,0), Dim3f(20.3, 20.3, 20.3),ProtoColor4f(.5, .2, .3, 1), 75, 75, .9, .2))));
}


