#include "glhelper.h"

#include <chrono>

#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
//#include "stb_image_write.h"

void _check_gl_error(const char *file, int line) {
  GLenum err (glGetError());

  while(err!=GL_NO_ERROR) {
    std::string error;
    switch(err) {
      case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
      case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
      case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
      case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
      case GL_STACK_UNDERFLOW:        error="GL_STACK_UNDERFLOW";     break;
      case GL_STACK_OVERFLOW:         error="GL_STACK_OVERFLOW";      break;
    }
    std::cerr << "GL_" << error.c_str() <<" - "<<file<<":"<<line<< std::endl;
    err=glGetError();
  }
}

namespace glhelper
{
  // return content of file filename
  std::string read_file(const std::string& filename)
  {
    std::ifstream ifs; 
    ifs.open(filename.c_str());
    if(!ifs)
    {
      std::cerr << "-------------------------\n";
      std::cerr << "Error reading file: " << filename << std::endl;
      std::cerr << "-------------------------\n";
    }
    return std::string((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
  }

  // return id of the compiled shader
  GLuint compile_shader(const char* shader_content, GLenum shader_type)
  {
    GLint success;
    char log[128];

    GLuint shader_id = glCreateShader(shader_type);

    glShaderSource(shader_id, 1, &shader_content, nullptr);
    glCompileShader(shader_id);

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      glGetShaderInfoLog(shader_id, 128, nullptr, log);
      std::cerr << "-------------------------\n";
      std::cerr << "Error compiling shader: \n" << log << "\n" << shader_content << std::endl;
      std::cerr << "-------------------------\n";

    }
    return shader_id;
  } 

  void check_error_link(GLuint program_id)
  {
    GLint success;
    char log[128];

    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if(!success)
    {
      glGetProgramInfoLog(program_id, 128, nullptr, log);
      std::cerr << "-------------------------\n";
      std::cerr << "Error linking program: \n" << log << std::endl;
      std::cerr << "-------------------------\n";
    }
  }

  // return id of the gpu program
  GLuint create_program(const std::string& vs_content,
      const std::string& fs_content)
  {

    GLuint vs_id = compile_shader(vs_content.c_str(),GL_VERTEX_SHADER);
    GLuint fs_id = compile_shader(fs_content.c_str(),GL_FRAGMENT_SHADER);

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vs_id);
    glAttachShader(program_id, fs_id);

    glLinkProgram(program_id);
    check_error_link(program_id);
    glDeleteShader(vs_id);
    glDeleteShader(fs_id);

    return program_id;
  }

  GLuint create_program(const std::string& vs_content,
      const std::string& gs_content,
      const std::string& fs_content)
  {
    GLuint vs_id = compile_shader(vs_content.c_str(),GL_VERTEX_SHADER);
    GLuint gs_id = compile_shader(gs_content.c_str(),GL_GEOMETRY_SHADER);
    GLuint fs_id = compile_shader(fs_content.c_str(),GL_FRAGMENT_SHADER);

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vs_id);
    glAttachShader(program_id, gs_id);
    glAttachShader(program_id, fs_id);

    glLinkProgram(program_id);
    check_error_link(program_id);
    glDeleteShader(vs_id);
    glDeleteShader(gs_id);
    glDeleteShader(fs_id);

    return program_id;
  }

  GLuint create_program(const std::string& vs_content,
      const std::string& tcs_content,
      const std::string& tes_content,
      const std::string& fs_content)
      {
      GLuint vs_id = compile_shader(vs_content.c_str(),GL_VERTEX_SHADER);
      GLuint tcs_id = compile_shader(tcs_content.c_str(),GL_TESS_CONTROL_SHADER);
      GLuint tes_id = compile_shader(tes_content.c_str(),GL_TESS_EVALUATION_SHADER);
      GLuint fs_id = compile_shader(fs_content.c_str(),GL_FRAGMENT_SHADER);

      GLuint program_id = glCreateProgram();
      glAttachShader(program_id, vs_id);
      glAttachShader(program_id, tcs_id);
      glAttachShader(program_id, tes_id);
      glAttachShader(program_id, fs_id);

      glLinkProgram(program_id);
      check_error_link(program_id);
      glDeleteShader(vs_id);
      glDeleteShader(tcs_id);
      glDeleteShader(tes_id);
      glDeleteShader(fs_id);

      return program_id;
      }


  GLuint create_program_from_file(
      const std::string& vs_file,
      const std::string& fs_file)
  {
    return create_program(read_file(vs_file), read_file(fs_file));
  }

  GLuint create_program_from_file(const std::string& vs_file,
      const std::string& tcs_file,
      const std::string& tes_file,
      const std::string& fs_file)
      {
      return create_program(
          read_file(vs_file),
          read_file(tcs_file),
          read_file(tes_file),
          read_file(fs_file));
      }

  GLuint create_program_from_file(
      const std::string& vs_file,
      const std::string& gs_file,
      const std::string& fs_file)
  {
    return create_program(read_file(vs_file), read_file(gs_file), read_file(fs_file));
  }

  void set_uniform_mat4(GLuint program, std::string name, glm::mat4 mat)
  {
    GLint id = glGetUniformLocation(program, name.c_str());

    GLint current_prog_id;
    glGetIntegerv(GL_CURRENT_PROGRAM, &current_prog_id);
    glUseProgram(program);
    if (id != -1)
      glUniformMatrix4fv(id, 1, GL_FALSE, &mat[0][0]);
    glUseProgram(current_prog_id);
  }

  /*GLuint load_texture(std::string filename)
  {
    GLuint texture_id;
    unsigned char* im;
    int w;
    int h;
    load_image(filename, im, w, h);

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, im);
    stbi_image_free(im);
    return texture_id;
  }*/

  /*void load_image(const std::string& filename, unsigned char*& image, int& w, int& h)
  {
    int comp;
    stbi_set_flip_vertically_on_load(true);
    image = stbi_load(filename.c_str(), &w, &h, &comp, 4);
    if(image == nullptr)
      std::cerr << "Error image : " << filename << std::endl;
  }*/

  /*void print_screen(int w, int h, std::string filename)
  {
    if(filename.empty())
    {
      std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      filename.resize(30);
      auto size = std::strftime(&filename[0], filename.size(), "%Y%m%d_%H%M%S", std::localtime(&now));
      filename.resize(size);
    }
    unsigned char* pixels = new unsigned char[3 * w* h];
    glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    stbi_flip_vertically_on_write(true);

    if(filename.substr(filename.find_last_of(".")+1) != "png")
      filename += ".png";

    stbi_write_png(filename.c_str(), w, h, 3, pixels, 3 * w );
    delete [] pixels;
  }*/
}
