#pragma once
#include "framework/MyRenderer.h"

class WhittedRayTracer : public MyRenderer {
 public:
  virtual void _renderThread(MyScene::Ptr scene, MyCamera::Ptr camera) override;

 private:
  Ray _generateViewRay(int x, int y);
  Ray _generateReflectionRay(const glm::vec3& dir, const glm::vec3& point, const glm::vec3& normal);

  glm::vec3 _rayShading(Ray ray, MyScene* pScene, int depth);

  // cache camera frame
  glm::vec3 mEyePos;
  glm::vec3 mFocalPlaneH, mFocalPlaneV, mFocalPlaneLeftTop;
};