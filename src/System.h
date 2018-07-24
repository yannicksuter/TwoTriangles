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

    bool initialize(int width, int height, int samples, bool fullscreen);
    bool run(Renderer*);

    inline bool isFullscreen() { return m_fullscreen; }
    inline bool isRetina() { return m_retina; }
    inline int getScreenWidth() { return m_screenWidth; }
    inline int getScreenHeight() { return m_screenHeight; }
    inline int getWidth() { return m_width; }
    inline int getHeight() { return m_height; }
    inline GLuint getSampling() { return m_samples; }

private:
    GLFWwindow* m_window;
    bool m_fullscreen;
    GLuint m_samples;
    bool m_retina;
    int m_width, m_height;
    int m_screenWidth, m_screenHeight;
};

