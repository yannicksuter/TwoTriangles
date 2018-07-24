#include "twotriangles.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize();
    void destroy();
    void render();

protected:
    bool initFullScreenQuad();
    bool initShaderProgram();

    GLuint m_vertexArrayObject;
    GLuint m_vertexBufferObject;
    Shader m_shader;
};
