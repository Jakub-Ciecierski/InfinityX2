#ifndef DUCK_SHADER_LOADER_H
#define DUCK_SHADER_LOADER_H

#include <shaders/shader.h>
#include <shaders/shaders/fragment_shader.h>
#include <shaders/shaders/vertex_shader.h>
#include <shaders/shaders/tess_control_shader.h>
#include <shaders/shaders/tess_eval_shader.h>

/*
 * Logic behind loading Shaders from files
 */
class ShaderLoader {
private:

    std::string getShaderCode(const GLchar* path);
public:

    ShaderLoader();

    ~ShaderLoader();

    VertexShader loadVertexShader(const GLchar* path);
    FragmentShader loadFragmentShader(const GLchar* path);
    TessControlShader loadTessControlShader(const GLchar *path);
    TessEvalShader loadTessEvalShader(const GLchar *path);
};


#endif //DUCK_SHADER_LOADER_H
