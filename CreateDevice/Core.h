#pragma once
#include "Window.h"

class Core : public Window
{
public:
    virtual bool  Init();
    virtual bool  Frame();
    virtual bool  Render();
    virtual bool  Release();
    bool  Run();
private:
    virtual bool  EngineInit();
    virtual bool  EngineFrame();
    virtual bool  EngineRender();
    virtual bool  EngineRelease();
};

