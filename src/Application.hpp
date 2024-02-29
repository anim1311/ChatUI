#pragma once

#include "App.hpp"
#include <iostream>

class Application : public App
{
public:
    Application(windowProperties windowProps)
        : App(windowProps)
    {

    }

    ~Application()
    {
        
    }
    void run(){
        this->startUp();
        while(!this->shouldClose()){
            this->update();
            this->render();
        }

    }
    void startUp() override{
        // place something that you want to run at the start of the application
    };
    void loop() override{
        // place something that you want to run every frame

        makeChatwindow();
    };


private:

    void makeChatwindow(){
        ImGui::Begin("Chat", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse );

        

        ImGui::End();
    }
};

