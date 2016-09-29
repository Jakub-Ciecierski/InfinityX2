#ifndef PROJECT_FBO_RENDERER_H
#define PROJECT_FBO_RENDERER_H

class Mesh;
class Program;

namespace ifx {

class Window;
class FBO;

/**
 * The viewport does not need to be changed since the window's dimensions
 * are used.
 * Creates FBO with Color and Depth buffers.
 * Allows for post-processing effects.
 */
class FBORenderer {
public:

    FBORenderer(Window* window);

    ~FBORenderer();

    Program* program(){return program_;}

    void SetProgram(Program* program);

    void Bind();

    void Render();
    void Render(Program* program);

private:
    void initFBO(Window* window);
    void initScreenMesh();

    FBO* fbo_;

    /**
     * The quad mesh which will render the screen.
     */
    Mesh* screenMesh_;

    Program* program_;
};
}

#endif //PROJECT_FBO_RENDERER_H
