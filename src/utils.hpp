#pragma once

struct windowProperties{

    int width = 1280;
    int height = 720;
    const char* title = "Hello!";
    ImVec4 clear_color  = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    windowProperties(int width, int height, const char* title, ImVec4 clear_color){
        this->width = width;
        this->height = height;
        this->title = title;
        this->clear_color = clear_color;
    }
};
