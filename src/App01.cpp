//
//  App01.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "App01.h"

using namespace ijg;
float x = 0;
float theta = 0;
int ind = 0;
int ind2 = 0;

App01::App01(){
    // call base class 1st
    //std::cout << "in derived class cstr" << std::endl;
}

void App01::init(){
    
    verletSurf = std::unique_ptr<ProtoVerletSurface> (new ProtoVerletSurface(Vec3f(0,0,0),
                Vec3f(0,0,0), Dim3f(200, 200, 0), ProtoColor4f(.6, .6, .8, 1.0), 41, 41, .005));
    
    toroid2 = std::unique_ptr<ProtoToroid> (new ProtoToroid(Vec3f(0, 0, 0), Vec3f(0, ProtoMath::PI/3.0,0), Dim3f(20, 20, 20),ProtoColor4f(.5, .2, .3, 1), 75, 75, .9, .2));
    
    ball1 =  std::shared_ptr<ProtoVerletBall>(new ProtoVerletBall(Vec3f(-10, 0, 0)));
    ball2 = std::shared_ptr<ProtoVerletBall>(new ProtoVerletBall(Vec3f(10, 0, 0)));
    stick = std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(ball1, ball2, .5, Tup2f(0, 1)));
    //std::cout << stick << std::endl;
    stick->nudgeB2(Vec3f(.2, .3, .5));
    
    // verlet sheet
    int rows = 81, cols = 81;
    ind = (rows-2)/2*(cols) + cols/2;
    float w = 200;
    float h = 200;
    float cellW = w/cols;
    float cellH = h/rows;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            float x = -w/2 + cellW*j;
            float y = h/2 - cellH*i;
            balls.push_back(std::shared_ptr<ProtoVerletBall>(new ProtoVerletBall(Vec3f(x, y, 0))));
        }
    }
    
    float tension = .01;
    for(int i=0, k=0, l=0, m=0, n=0; i<rows-1; ++i){
        for(int j=0; j<cols-1; ++j){
            k = i*cols+j;
            l = (i+1)*cols+j;
            m = (i+1)*cols+j+1;
            n = i*cols+j+1;
            // corners
            // TL
            if (i==0 && j==0){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(1, 0))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(0, 1))));
                // TR
            } else  if (i==0 && j==cols-2){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(0, 1))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
                // BR
            }  else  if (i==rows-2 && j==cols-2){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, 0))));
                //BL
            } else  if (i==rows-2 && j==0){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
            } else {
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
                
            }
            
        }
    }
    //sticks.at(static_cast<int>(cols*rows/2+(cols-1)/2))->nudgeB2(Vec3f(0, 0, 102.8));
    //verletSurf->nudge(4);
    
    balls.at(4)->pos.z += 1.5;
    
}

// event thread runs continuously
//ProtoWorld draw independently
void App01::run(){
    //std::cout << "ind = " << ind << std::endl;
    glPushMatrix();
    glTranslatef(0, 0, -200);
    glRotatef(x+=.2, 1, 1, 0);
    //toroid2->display();
   
    //stick->constrainLen();
    //stick->display();
    
//    for(int i=0; i<sticks.size(); ++i){
//        sticks.at(i)->constrainLen();
//        sticks.at(i)->display();
//    }
    
     //glPushMatrix();
    //glRotatef(90, 0, 1, 0);
    verletSurf->flow();
    verletSurf->display(ProtoGeom3::VERTEX_BUFFER_OBJECT, ProtoGeom3::WIREFRAME, .2);
   // glPopMatrix();
    glPopMatrix();
    
//    ind2 = ProtoMath::random(60, ind);
//    balls.at(ind)->pos += Vec3f(cos(-theta)*ProtoMath::random(.1, .4), sin(theta)*ProtoMath::random(.1, .4), sin(theta)*ProtoMath::random(.1, 1.4));
//    theta += ProtoMath::random(4, 12)*ProtoMath::PI/180.0;
    
    
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



