#include "twotriangles.h"

Input::Input() {
	m_window = NULL;
	m_mouseSensitivity = 15.f;
	m_mouseScroll = glm::vec2(0.6f, 0.6f);
	m_leftMouseDown = false;
	m_rightMouseDown = false;
}

Input::~Input() {
}

void Input::initialize(GLFWwindow *pWindow) {
	m_window = pWindow;

    glfwSetKeyCallback(pWindow, keyCallback);
    glfwSetMouseButtonCallback(pWindow, mouseButtonCallback);
    glfwSetCursorPosCallback(pWindow, mouseCallback);
    glfwSetScrollCallback(pWindow, scrollCallback);

	// initialize cursor position to prevent jumps
    double x,y;
	glfwGetCursorPos(pWindow, &x, &y);
    m_mousePosition = glm::vec2(x,y);
}

void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (action == GLFW_RELEASE) {
        Input *inst = Input::Instance();
        if (inst->m_onKeyCallbacks.size() > 0) {
            KeyEvent event;
            event._key = key;
            event._altPressed = inst->isKeyPressed(GLFW_KEY_LEFT_ALT) || inst->isKeyPressed(GLFW_KEY_RIGHT_ALT);
            event._cntrlPressed = inst->isKeyPressed(GLFW_KEY_LEFT_CONTROL) || inst->isKeyPressed(GLFW_KEY_RIGHT_CONTROL);
            event._shiftPressed = inst->isKeyPressed(GLFW_KEY_LEFT_SHIFT) || inst->isKeyPressed(GLFW_KEY_RIGHT_SHIFT);
            for (int i = 0; i < inst->m_onKeyCallbacks.size(); i++) {
                inst->m_onKeyCallbacks[i](&event);
            }
        }
    }
}

void Input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    MouseEvent event;
    Input *inst = Input::Instance();
    event._button = IB_UNDEFINED;
    event._coords = Input::Instance()->m_mousePosition;
    event._altPressed = inst->isKeyPressed(GLFW_KEY_LEFT_ALT) || inst->isKeyPressed(GLFW_KEY_RIGHT_ALT);
    event._cntrlPressed = inst->isKeyPressed(GLFW_KEY_LEFT_CONTROL) || inst->isKeyPressed(GLFW_KEY_RIGHT_CONTROL);
    event._shiftPressed = inst->isKeyPressed(GLFW_KEY_LEFT_SHIFT) || inst->isKeyPressed(GLFW_KEY_RIGHT_SHIFT);

    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        inst->m_leftMouseDown = (action == GLFW_PRESS);
        event._button = IB_LEFT;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        inst->m_rightMouseDown = (action == GLFW_PRESS);
        event._button = IB_RIGHT;
    } 
    else if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
        event._button = IB_MIDDLE;
    }


    if (action == GLFW_PRESS) {
        for (int i = 0; i < inst->m_onMousePressCallbacks.size(); i++) {
            inst->m_onMousePressCallbacks[i](&event);
        }
    }
    if (action == GLFW_RELEASE) {
        for (int i = 0; i < inst->m_onMouseReleaseCallbacks.size(); i++) {
            inst->m_onMouseReleaseCallbacks[i](&event);
        }
    }
}

void Input::mouseCallback(GLFWwindow *window, double xpos, double ypos) {
    Input::Instance()->m_mousePosition = glm::vec2(xpos, ypos);
}

template<typename T>
inline T Clamp(T val, T min, T max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

void Input::scrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
    Input::Instance()->m_mouseScroll.x = Clamp(Input::Instance()->m_mouseScroll.x + ((float)xoffset / Input::Instance()->m_mouseSensitivity), 0.f, 1.f);
    Input::Instance()->m_mouseScroll.y = Clamp(Input::Instance()->m_mouseScroll.y + ((float)yoffset / Input::Instance()->m_mouseSensitivity), 0.f, 1.f);
}

bool Input::isKeyPressed(int key) {
	return glfwGetKey(m_window, key) == GLFW_PRESS;
}