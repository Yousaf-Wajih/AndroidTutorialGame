#pragma once

#include <memory>
#include <GLES/egl.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>

#include "glm/glm.hpp"
#include "Texture.h"

struct DrawCommand {
  glm::mat4 transformation;
  Texture *texture;
};

class Renderer {
public:
  explicit Renderer(android_app *app);
  ~Renderer();

  void do_frame(const std::vector<DrawCommand> &cmds);

  glm::ivec2 get_size() const { return {width, height}; }

  glm::mat4 get_projection() const { return projection; }

private:
  EGLDisplay display{};
  EGLConfig config{};
  EGLSurface surface{};
  EGLContext context{};

  GLuint vao{}, vbo{}, ebo{};
  GLuint program;
  GLint projection_location, model_location;

  int width, height;
  glm::mat4 projection;
  std::unique_ptr<Texture> white;
};
