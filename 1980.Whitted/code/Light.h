#pragma once
#include "geometry/Ray.h"

struct MyLight {
  float ambient = 0.1f;  // ambient
  float intensity = 2.0f;

  virtual Ray generateShadowRay(const glm::vec3& shadingPt) = 0;
  virtual float shadingIntensity(const glm::vec3& shadingPt,
                                 const glm::vec3& normal,
                                 const glm::vec3& viewDir, float Kd, float Ks,
                                 float n) = 0;
};

struct PointLight : public MyLight {
  glm::vec3 pos;

  PointLight(const glm::vec3& inPos) : pos(inPos) {}

  virtual Ray generateShadowRay(const glm::vec3& shadingPt) override {
    glm::vec3 L = glm::normalize(pos - shadingPt);
    return Ray(shadingPt, L);
  }

  virtual float shadingIntensity(const glm::vec3& shadingPt,
                                 const glm::vec3& normal,
                                 const glm::vec3& viewDir, float Kd, float Ks,
                                 float n) override {
    glm::vec3 L = glm::normalize(pos - shadingPt);
    glm::vec3 H = glm::normalize(L - viewDir);
    float NdotH = glm::dot(normal, H);
    float NdotL = glm::dot(normal, L);

    float I = Kd * std::max(0.0f, NdotL) + Ks * std::powf(NdotH, n);
    return ambient + intensity * I;
  }
};
