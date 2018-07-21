//
// Created by Yannick Suter on 21.07.18.
//

#include "twotriangles.h"

class System {
protected:
    System();
    ~System();

public:
    static System *Instance() {
        static System inst;
        return &inst;
    }

    bool Initialize(int width, int height, int samples, bool fullscreen);
    void Run();

    inline bool IsFullscreen() { return m_fullscreen; }
    inline bool IsRetina() { return m_retina; }
    inline int GetScreenWidth() { return m_screenWidth; }
    inline int GetScreenHeight() { return m_screenHeight; }
    inline int GetWidth() { return m_width; }
    inline int GetHeight() { return m_height; }
    inline GLuint GetSampling() { return m_samples; }

private:
    GLFWwindow* m_window;
    bool m_fullscreen;
    GLuint m_samples;
    bool m_retina;
    int m_width, m_height;
    int m_screenWidth, m_screenHeight;
};

