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

bool System::initialize(int width, int height, int samples, bool fullscreen) {
    m_width = width;
    m_height = height;
    m_fullscreen = fullscreen;
    m_samples = samples;

    // initialise GLFW
    if (!glfwInit()) {
        LOG_FATAL("Failed to initialize GLFW.");
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, m_samples);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_window = glfwCreateWindow(m_width, m_height, "TwoTriangles", NULL, NULL);
    if (m_window == NULL) {
        LOG_FATAL("Failed to open GLFW window.");
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_window);

    // initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        LOG_FATAL("Failed to initialize GLEW.");
        glfwTerminate();
        return false;
    }

    // initialize input manager
    Input::Instance()->initialize(m_window);

    // initialize viewport
    glfwGetFramebufferSize(m_window, &m_screenWidth, &m_screenHeight);
    if (m_width != m_screenWidth || m_height != m_screenHeight) {
        LOG_MSG("Retina screen detected!");
        m_retina = true;
    }

    glViewport(0, 0, m_screenWidth, m_screenHeight);
    glEnable(GL_DEPTH_TEST);

    LOG_MSG("Output config: %dx%d,%dx fullscreen=%s", m_screenWidth, m_screenHeight, m_samples, m_fullscreen ? "true" : "false");
    LOG_MSG("GL_VENDOR/RENDERER: %s, %s", (char*)glGetString(GL_VENDOR), (char*)glGetString(GL_RENDERER));
    LOG_MSG("GL_VERSION: %s", (char*)glGetString(GL_VERSION));
    LOG_MSG("GL_SHADING_LANGUAGE_VERSION: %s", (char*)glGetString(GL_SHADING_LANGUAGE_VERSION));

    int drawBufferCount = 0;
    glGetIntegerv(GL_MAX_DRAW_BUFFERS, &drawBufferCount);
    LOG_MSG("Deferred rendering: max buffer count [%d]", drawBufferCount);

    return true;
}

bool System::run(Renderer *pRenderer) {
    GLfloat deltaTime = 0;
    GLfloat totalTime = 0;
    GLfloat currentTime = (GLfloat)glfwGetTime();
    GLfloat lastTime = currentTime;

    if (!pRenderer->initialize()) {
        LOG_FATAL("Failed to initialize renderer.");
        return false;
    }

    while (!glfwWindowShouldClose(m_window)) {
        currentTime = (GLfloat)glfwGetTime();
        if (!Input::Instance()->isKeyPressed(GLFW_KEY_SPACE)) {
            deltaTime = currentTime - lastTime;
            totalTime += deltaTime;
            lastTime = currentTime;
        } else {
            lastTime = currentTime;
        }

        // process events
        glfwPollEvents();

        // render
        glViewport(0, 0, m_screenWidth, m_screenHeight);
        pRenderer->render();

        glfwSwapBuffers(m_window);
    }

    return true;
}
