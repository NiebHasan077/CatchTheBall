#ifndef PRINTTEXT_H_INCLUDED
#define PRINTTEXT_H_INCLUDED


#include <string>
#include <GL/glut.h>

#ifndef SIMPLE_DRAW_TEXT_NO_TIMING
#include <vector>
#include <chrono>
#include <limits>
#include <functional>
#endif

class SimpleDrawText
{
public:
#ifndef SIMPLE_DRAW_TEXT_NO_TIMING
  void addText(const std::string& text, const int duration = std::numeric_limits<int>::max())
  {
    addText(text, m_textColorR, m_textColorG, m_textColorB, duration);
  }

  void addText(const std::string& text, const float r, const float g, const float b, const int duration = std::numeric_limits<int>::max())
  {
    m_lines.push_back({ text, r, g, b, duration, false, std::chrono::steady_clock::now() });
  }

  void render()
  {
    std::vector<int> linesToRemove;
    for (size_t row = 0; row < m_lines.size(); row++)
    {
      auto &line = m_lines[row];
      std::string text;
      float r, g, b;
      int duration;
      bool init;
      std::chrono::steady_clock::time_point time;
      std::tie(text, r, g, b, duration, init, time) = line;
      drawText(text, 0, m_screenHeight - (row + 1) * m_lineHeight, r, g, b);
      if (duration != std::numeric_limits<int>::max())
      {
        if (init)
        {
          auto now = std::chrono::steady_clock::now();
          std::chrono::duration<float> fs = now - time;
          std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(fs);
          duration -= (unsigned int)d.count();
          if (duration < 0)
            linesToRemove.insert(linesToRemove.begin(), row);
        }
        else
        {
          std::get<5>(line) = true;
          time = std::chrono::steady_clock::now();
        }
      }
    }

    for (int index : linesToRemove)
      m_lines.erase(m_lines.begin() + index);
  }
#endif

  void drawText(const std::string& text, const unsigned int x, const unsigned int y, const float r, const float g, const float b)
  {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, m_screenWidth, 0, m_screenHeight, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(r, g, b);
    glRasterPos2i(x, y);
    for (const char c : text)
      glutBitmapCharacter(m_glutFont, (int)c);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
  }

  unsigned int m_screenWidth = 800;
  unsigned int m_screenHeight = 600;
  float m_textColorR = 1.0f;
  float m_textColorG = 1.0f;
  float m_textColorB = 1.0f;
  //void* m_glutFont = GLUT_BITMAP_9_BY_15;
  void* m_glutFont = GLUT_BITMAP_TIMES_ROMAN_24;
  unsigned int m_lineHeight = 15;
#ifndef SIMPLE_DRAW_TEXT_NO_TIMING
private:
  std::vector<std::tuple<std::string, float, float, float, int, bool, std::chrono::steady_clock::time_point>> m_lines;
#endif
};



#endif // PRINTTEXT_H_INCLUDED
