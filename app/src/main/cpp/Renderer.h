#pragma once

#include <GLES/egl.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>

class Renderer {
public:
  explicit Renderer(android_app *app);
  ~Renderer();

  void do_frame();

private:
  EGLDisplay display{};
  EGLConfig config{};
  EGLSurface surface{};
  EGLContext context{};

  GLuint vao{}, vbo{};
  GLuint program{};
};
