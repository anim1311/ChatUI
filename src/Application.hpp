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

    const char* emojis[4] = {"😀","😂","😍","😎"};
    int selectedEmoji = 0;
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
        makeChatWindow();
    };


private:

    void makeChatWindow(){




        ImGui::Begin("Chat", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize );

        makeMenubar();


        ImGui::BeginChild("Chat", ImVec2(0.0f, 0.42f * (this->windowProps.height)), ImGuiChildFlags_Border| ImGuiChildFlags_AutoResizeY );

        for(int i = 0;i<this->messages.size();i++){

            ImGui::BeginChild(i+1, ImVec2(0.0f,0.0f), ImGuiChildFlags_Border| ImGuiChildFlags_AutoResizeX|ImGuiChildFlags_AutoResizeY|ImGuiChildFlags_AlwaysUseWindowPadding );
            ImGui::TextColored(selfMessageColor,messages[i].c_str());
            ImGui::EndChild();
        }

        ImGui::EndChild();

        ImGui::InputTextMultiline("Message: ", this->buffer, MAX_BUFFER,ImVec2(-1.0f,0.02f * (this->windowProps.height)),ImGuiInputTextFlags_AllowTabInput) ;
        if(ImGui::Button("Send",ImVec2(-1.0f,-1.0f)) ){
            if(strlen(this->buffer) > 0){
                sendMessage();
            }
        }
        // Add a slection for all teh emojis
        ImGui::ListBox("Emojis", &this->selectedEmoji, this->emojis, 4, 4);

        ImGui::End();
    }

    void sendMessage(){
        this->messages.push_back(this->buffer);
        memset(this->buffer, 0, MAX_BUFFER);
    }

    void makeMenubar(){

        
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("Change Color")){
                
                ImGui::OpenPopup("Color", ImGuiPopupFlags_AnyPopup);
                if(ImGui::BeginPopup("Color")){
                    ImGui::ColorPicker4("Color", (float*)&selfMessageColor);
                    ImGui::EndPopup();
                }
            }
            ImGui::EndMenu();
        }
        
    }
};

