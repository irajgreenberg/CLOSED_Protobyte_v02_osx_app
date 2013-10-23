//
//  ProtoPlasm.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "ProtoPlasm.h"

using namespace ijg;


ProtoPlasm::ProtoPlasm(ProtoBaseApp* baseApp):
baseApp(baseApp), appWidth(1024), appHeight(764), appTitle("Protobyte App")
{
    initSFMLInit();
    initSFMLRun();
}

ProtoPlasm:: ProtoPlasm(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* baseApp):
baseApp(baseApp), appWidth(appWidth), appHeight(appHeight), appTitle(appTitle) {
    initSFMLInit();
    initSFMLRun();
}


void ProtoPlasm::initSFMLInit(){
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    
    // create the window
    window = new sf::Window(sf::VideoMode(appWidth, appHeight), appTitle, sf::Style::Default, settings);
    window->setVerticalSyncEnabled(true);
    
    
    // Implementation defined by derived user class implemention
    baseApp->setup();
    
    // create world
    world = ProtoWorld::getInstance(appWidth, appHeight);
    //world.setWorldView(ProtoWorld::QUAD_VIEW);
    world->setWorldView(ProtoWorld::SINGLE_VIEW);
    world->setWorldRotSpeed(Vec3f(1.3, 0, 0));
    
    std::unique_ptr<ijg::ProtoCamera> camera1(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 0, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera2(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 180, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera3(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(-50, 30, 30), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera4(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 124, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    
    camera1->setProjection(40.0f, appWidth/appHeight, .1, 1000);
    camera2->setProjection(60.0f, appWidth/appHeight, .1, 1000);
    camera3->setProjection(110.0f, appWidth/appHeight, .1, 1000);
    camera4->setProjection(60.0f, appWidth/appHeight, .1, 1000);
    
    //camera1->setViewPort(0, 0, window.getSize().x/2, window.getSize().y/2);
    //    camera2->setViewPort(0, window.getSize().y/2, window.getSize().x/2, window.getSize().y/2);
    //    camera3->setViewPort(window.getSize().x/2, window.getSize().y/2, window.getSize().x/2, window.getSize().y/2);
    //    camera4->setViewPort(window.getSize().x/2, 0, window.getSize().x/2, window.getSize().y/2);
    //
    //   world.add(std::move(camera1));
    //    world.add(std::move(camera2));
    //    world.add(std::move(camera3));
    //    world.add(std::move(camera4));
    
    camera1->setViewPort(0, 0, appWidth, appHeight);
    world->add(std::move(camera1));
    
    
    // test spline curve
    int controlPts = 20;
    std::vector<Vec3> cps;
    float x=0, y=-1, z=0;
    float t = 0;
    for (int i = 0; i < controlPts; i++) {
        //rand() % 100;  // v1 in the range 0 to 99
        x = ProtoMath::random(-1, 1);
        y = ProtoMath::random(-1, 1);
        z = ProtoMath::random(-1, 1);
        //std::cout << "x = " << x << std::endl;
        //std::cout << "y = " << y << std::endl;
        //std::cout << "( " << x << ", " << y << ", " << z << " )" << std::endl;
        //z = cos(t)*.5;
        //x = sin(t)*.5;
        //y+=.1;
        cps.push_back(Vec3f(x, y, z));
        t += ProtoMath::DOUBLE_PI/controlPts*2;
        //cps.push_back(Vec3f(-.9+ + i*.5, sin(i*M_PI/180.0)*5, 0));
    }
    //cps.push_back(Vec3f(-1, 0, .1));
    //cps.push_back(Vec3f(1, 0, .1));
    //cps.push_back(Vec3f(1, -1, .1));
    //cps.push_back(Vec3f(-1, -1, .1));
    
    //    std::unique_ptr<ProtoLight> lt0(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt1(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt2(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt3(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt4(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt5(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt6(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt7(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt8(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt9(new ProtoLight());
    //    std::unique_ptr<ProtoLight> lt10(new ProtoLight());
    //
    //    world.add(std::move(lt0));
    //    world.add(std::move(lt1));
    //    world.add(std::move(lt2));
    //    world.add(std::move(lt3));
    //    world.add(std::move(lt4));
    //    world.add(std::move(lt5));
    //    world.add(std::move(lt6));
    //    world.add(std::move(lt7));
    //    world.add(std::move(lt8));
    //    world.add(std::move(lt9));
    //    world.add(std::move(lt10));
    
    
    ProtoLight* lt0_ptr = new ProtoLight();
    lt0_ptr->setShininess(15.0);
    lt0_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    lt0_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    lt0_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    lt0_ptr->setPosition(Vec3f(0, 0, -2.0));
    
    world->add(lt0_ptr);
    
    ProtoLight* lt1_ptr = new ProtoLight();
    lt1_ptr->setShininess(15.0);
    lt1_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    lt1_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    lt1_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    lt1_ptr->setPosition(Vec3f(-2, 2, 2.0));
    
    world->add(lt1_ptr);
    
    
    //world.setLights();
    
    
    
    
    
    std::unique_ptr<ProtoGeom3> sphere(new ProtoSphere(Vec3f(0,0,0), Vec3f(0,0,0), ProtoDimension3f(.3,.3,.3),
                                                       ProtoColor4f(.2, .5, .7, 1.0), 15, 15));
    
    //world->add(std::move(sphere));
    
    
    
    
    int interpDetail = 25;
    float smoothness = .5;
    ProtoSpline3 spline(cps, interpDetail, false, smoothness);
    
    //ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, .1, 3);
    
    std::unique_ptr<ProtoGeom3> tube(new ProtoTube(Vec3f(0,0,0),Vec3f(0,0,0), ProtoDimension3f(1.5,1.5,1.5), ProtoColor4f(.6, .5, .7, 1.0), spline, .09, 20, ProtoTransformFunction(ProtoTransformFunction::SINUSOIDAL, ProtoTuple2f(.05, 1.2), 1), true));
    
    //world->add(std::move(tube));
    
    
}

void ProtoPlasm::initSFMLRun(){
    
    // clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // run the main loop
    bool running = true;
    while (running)
    {
        baseApp->draw();
        
        
        // handle events
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "event.size = " << event.size.width << std::endl;
                std::cout << "event.size = " << event.size.height << std::endl;
                std::cout << "event.mouseButton.x = " << event.mouseButton.x << std::endl;
                std::cout << "event.mouseButton.y = " << event.mouseButton.y << std::endl;
                baseApp->mousePressed();
            }
            
            if (event.type == sf::Event::Closed)
            {
                baseApp->onClosed();
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                //glViewport(0, 0, event.size.width/4.0, event.size.height/4.0);
                //world.updateCanvasSize(event.size.width, event.size.height);
                
                //                    std::cout << event.size.width  << std::endl;
                //                    std::cout << event.size.height  << std::endl;
            }else if (event.type == sf::Event::KeyPressed)
            {
                baseApp->keyPressed();
                if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape) {
                    running = false;
                    window->close();
                }
            }
        }
        
        
        // clear the buffers
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // draw...
        // user defined now in derived class
        
        //world->run();
        //glTranslatef(0,0,-.1);
        //spline.display();
        
        // end the current frame (internally swaps the front and back buffers)
        window->display();
    }
    
    
}

