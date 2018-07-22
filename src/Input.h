#include "twotriangles.h"

typedef enum {
    IB_LEFT,
    IB_RIGHT,
    IB_MIDDLE,
    IB_UNDEFINED
} INPUTBUTTONTYPE;

struct MouseEvent {
    INPUTBUTTONTYPE _button;
    glm::vec2 _coords;
    bool _shiftPressed;
    bool _cntrlPressed;
    bool _altPressed;
};

struct KeyEvent {
    int _key;
    bool _shiftPressed;
    bool _cntrlPressed;
    bool _altPressed;
};

class Input {
public:
	static Input *Instance() {
		static Input inst;
		return &inst;
	}

protected:
	Input();
	~Input();

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

public:
	void Initialize(GLFWwindow *pWindow);
	void SetMouseOffset(double fOffsetX, double fOffsetY);
	bool IsKeyPressed(int key);

    void RegisterOnMousePressCallback(std::function<void(MouseEvent*)> fn) {
        m_onMousePressCallbacks.push_back(fn);
    }
    void RegisterOnMouseReleaseCallback(std::function<void(MouseEvent *)> fn) {
        m_onMouseReleaseCallbacks.push_back(fn);
    }
    void RegisterOnKeyCallback(std::function<void(KeyEvent*)> fn) {
        m_onKeyCallbacks.push_back(fn);
    }

	GLFWwindow *m_window;
    float m_mouseSensitivity;
    glm::vec2 m_mousePosition;
    glm::vec2 m_mouseScroll;
	bool m_leftMouseDown;
	bool m_rightMouseDown;

    // callbacks
    std::vector<std::function<void(MouseEvent*)>> m_onMousePressCallbacks;
    std::vector<std::function<void(MouseEvent*)>> m_onMouseReleaseCallbacks;
    std::vector<std::function<void(KeyEvent*)>> m_onKeyCallbacks;
};

