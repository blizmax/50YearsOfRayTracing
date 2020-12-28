/**
 * 50 Years of Ray tracing
 *
 * GitHub: https://github.com/neil3d/50YearsOfRayTracing
 *
 * Created by yanliang.fyl, 2020
 */

#pragma once
#include <glm/glm.hpp>

namespace RTKit2 {

class MyMaterial;
class MySceneObject;

struct HitRecord {
  bool isLight = false;
  float t = 0;
  glm::vec3 pt = {0, 0, 0};
  glm::vec3 normal = {0, 1, 0};
  glm::vec2 uv = {0, 0};
  MyMaterial* mtl = nullptr;
  MySceneObject* obj = nullptr;
};
}  // namespace RTKit2
