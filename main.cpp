#include "Application.hpp"
#include "utils.hpp"

int main(){

    windowProperties windowProps(1280, 720, "Hello!", ImVec4(0.45f, 0.55f, 0.60f, 1.00f));

    Application app(windowProps);

    app.run();

    
    return 0;
}