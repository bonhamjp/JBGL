#include "ColorTools.h"

namespace DataGarden
{
  glm::vec4 ColorFromHex(int hexValue)
  {
    glm::vec4 rgbColor;

    rgbColor.x = (float)(((hexValue >> 16) & 0xFF) / 255.0); // Extract the RR byte
    rgbColor.y = (float)(((hexValue >> 8) & 0xFF) / 255.0);  // Extract the GG byte
    rgbColor.z = (float)(((hexValue)&0xFF) / 255.0);         // Extract the BB byte
    rgbColor.w = 1.0f;

    return rgbColor;
  }
} // namespace DataGarden
