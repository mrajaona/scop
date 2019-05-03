#include "exit.h"

void    ft_exit(t_data *scop, int status)
{
    glDeleteTextures(N_TEXTURES, scop->textures);

    glDeleteProgram(scop->shaderProgram);
    glDeleteShader(scop->fragmentShader);
    glDeleteShader(scop->vertexShader);

    glDeleteBuffers(1, &(scop->ebo));
    glDeleteBuffers(1, &(scop->vbo));

    glDeleteVertexArrays(1, &(scop->vao));

    glfwTerminate();
    exit(status);
}
