#include "twotriangles.h"

inline const GLubyte *BUFFER_OFFSET(size_t bytes)  {
    return reinterpret_cast<const GLubyte *>(0) + bytes;
}

Renderer::Renderer() {
    m_vertexArrayObject = 0;
    m_vertexBufferObject = 0;
}

Renderer::~Renderer() {
    destroy();
}

bool Renderer::initialize() {
    if (!initShaderProgram() || !initFullScreenQuad()) {
        return false;
    }
    return true;
}

void Renderer::destroy() {
    if (m_vertexArrayObject) {
        glDeleteVertexArrays(1, &m_vertexArrayObject);
        m_vertexArrayObject = 0;
    }

    if (m_vertexBufferObject) {
        glDeleteBuffers(1, &m_vertexBufferObject);
        m_vertexBufferObject = 0;
    }

    glUseProgram(0);
    m_shader.destroy();
}

void Renderer::render() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_shader.enable();
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
    glBindVertexArray(0);
    m_shader.disable();
}

bool Renderer::initFullScreenQuad() {
    // Setup the full screen quad geometry as a triangle strip.
    // The vertex positions are in normalized device coordinates (NDC).
    //
    // In NDC:
    //  (-1,  1) is always the top-left corner of the viewport.
    //  (-1, -1) is always the bottom-left corner of the viewport.
    //  ( 1,  1) is always the top-right corner of the viewport.
    //  ( 1, -1) is always the bottom-right corner of the viewport.
    //
    //	v0---v2
    //	|   / |
    //	| /   |
    //	v1---v3

    float quad[] = {
            -1.0f, 1.0f,    // v0 - top left corner
            -1.0f, -1.0f,    // v1 - bottom left corner
            1.0f, 1.0f,    // v2 - top right corner
            1.0f, -1.0f    // v3 - bottom right corner
    };

    // Create the vertex array object for the full screen quad.

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    // Create the Vertex Buffer Object for the full screen quad.

    glGenBuffers(1, &m_vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

    // Map the generic vertex attributes used by the full screen quad's shader
    // program to the full screen quad's vertex data stored in the vertex
    // buffer object.

    m_shader.vertexAttribPointer("PositionNDC", 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    m_shader.enableVertexAttribArray("PositionNDC");

    glBindVertexArray(0);
    return true;
}

bool Renderer::initShaderProgram() {
    if (!m_shader.loadVertexShader("shaders/shader.vert")) {
        LOG_FATAL("Error loading vertex shader: %s.", m_shader.lastError().c_str());
        return false;
    }

    if (!m_shader.loadFragmentShader("shaders/shader.frag")) {
        LOG_FATAL("Error loading fragment shader: %s.", m_shader.lastError().c_str());
        return false;
    }

    if (!m_shader.link()) {
        LOG_FATAL("Error linking shader: %s.", m_shader.lastError().c_str());
        return false;
    }

    return true;
}