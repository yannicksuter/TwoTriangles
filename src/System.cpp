//
// Created by Yannick Suter on 21.07.18.
//

#include "twotriangles.h"

System::System() {
    m_window = NULL;
    m_retina = false;
}

System::~System() {
    glfwTerminate();
}

bool System::Initialize(int width, int height, int samples, bool fullscreen) {
    m_width = width;
    m_height = height;
    m_fullscreen = fullscreen;
    m_samples = samples;

    // initialise GLFW
    if (!glfwInit()) {
        LOG_FATAL("Failed to initialize GLFW.");
        return false;
    }

    return true;
}

void System::Run() {
    // todo
}
