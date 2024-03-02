#pragma once

#include "App.hpp"
#include <iostream>
#include <vector>


#define MAX_BUFFER 1024
class Application : public App
{

private:
    char buffer[MAX_BUFFER];
    std::vector<std::string> messages;


    ImVec4 selfMessageColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

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
        makeSidePanel();
        makeChatWindow();
    };


private:

    void makeChatWindow(){




        ImGui::Begin("Chat Window", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize );



        ImGui::BeginChild("Chat", ImVec2(0.0f, 0.42f * (this->windowProps.height)), ImGuiChildFlags_Border| ImGuiChildFlags_AutoResizeY );

        printMessages();

        ImGui::EndChild();

        ImGui::InputTextMultiline("Message: ", this->buffer, MAX_BUFFER,ImVec2(-1.0f,0.02f * (this->windowProps.height)),ImGuiInputTextFlags_AllowTabInput) ;
        if(ImGui::Button(ICON_FA_ENVELOPE " Send",ImVec2(-1.0f,-1.0f)) ){
            if(strlen(this->buffer) > 0){
                sendMessage();
            }
        }

        ImGui::End();
    }

    void sendMessage(){
        this->messages.push_back(this->buffer);
        memset(this->buffer, 0, MAX_BUFFER);
    }


    void printMessages(){
        for(int i = 0;i<this->messages.size();i++){

            ImGui::BeginChild(i+1, ImVec2(0.0f,0.0f), ImGuiChildFlags_Border| ImGuiChildFlags_AutoResizeX|ImGuiChildFlags_AutoResizeY|ImGuiChildFlags_AlwaysUseWindowPadding|ImGuiChildFlags_FrameStyle );
            ImGui::TextColored(selfMessageColor,messages[i].c_str());
            ImGui::EndChild();
        }
    }
    void makeSidePanel(){
        ImGui::Begin("Contacts", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize );
        for (char i = 'A'; i < 'Z'; i++)
        {
            std::string name = "Anirudh" + std::string(1, i);

            ImGui::Selectable(name.c_str());
        }
        
        ImGui::End();
    }
};

