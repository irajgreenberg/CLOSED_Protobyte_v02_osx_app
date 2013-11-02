//
//  App01.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "App01.h"

#include <unistd.h>
#define GetCurrentDir getcwd

using namespace ijg;
float x = 0;
float tx = 0;
float theta = 0;
int ind = 0;
int ind2 = 0;

App01::App01(){
    // call base class 1st
    //std::cout << "in derived class cstr" << std::endl;
}

void App01::init(){
    
    // START for relative resource loading
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        std::cout << "error lodaing form relative directory" << std::endl;
        //return errno;
    }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    std::string cp = cCurrentPath; //cast char[] to string
    std::string imgName = "/stiller.raw";
    std::string url = cp+imgName;
    // END for relative resource loading
    
    
    verletSurf = std::unique_ptr<ProtoVerletSurface> (new ProtoVerletSurface(Vec3f(0,0,0),
                                                                             Vec3f(0,0,0), Dim3f(100, 100, 1), ProtoColor4f(.6, .6, .8, .2), 47, 47, .2/*.05*/, url)); // 91, 91
    toroid2 = std::unique_ptr<ProtoToroid> (new ProtoToroid(Vec3f(0, 0, 0), Vec3f(0, ProtoMath::PI/3.0,0), Dim3f(20, 20, 20),ProtoColor4f(.5, .2, .3, .2), 75, 75, .9, .2));
    glDepthMask(true);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    
    verletSurf->setMeshColor(Col4f(.8, .4, 0, .1));
}

// event thread runs continuously
//ProtoWorld draw independently
void App01::run(){
    
    //std::cout << "frameCount = " << frameCount << std::endl;
    //std::cout << "frameRate = " << frameRate << std::endl;
    //std::cout << "ind = " << ind << std::endl;
    glPushMatrix();
    glTranslatef(0, 0, -200+tx);
    tx+=.05;
    glRotatef(x+=.2, 1, 1, 0);
    //glRotatef(90, 0, 1, 0);
    //toroid2->display();
     verletSurf->flow();
    verletSurf->setMeshColor(Col4f(1.0, 1.0, 1.0, 1.0)); // not really working at present
   
    glEnable(GL_TEXTURE_2D);
    verletSurf->display(ProtoGeom3::VERTEX_BUFFER_OBJECT, ProtoGeom3::SURFACE, .1);
    glDisable(GL_TEXTURE_2D);
    verletSurf->setMeshColor(Col4f(.4, .4, .4, .2));
    verletSurf->display(ProtoGeom3::VERTEX_BUFFER_OBJECT, ProtoGeom3::WIREFRAME, .01);
    glPopMatrix();
    
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



