/**
 * A Brief History of Ray tracing
 *
 * GitHub: https://github.com/neil3d/RayTracingHistory
 *
 * Created by yanliang.fyl, 2020
 */

#pragma once
#include <random>

#include "framework/TiledRenderer.h"

namespace RayTracingHistory {

class BilliardScene;
class PinholeCamera;

class DistributedRayTracer : public TiledRenderer {
 public:
  virtual void _tileRenderThread(Tile tile, MyScene::Ptr scene,
                                 MyCamera::Ptr camera) override;
  virtual std::string getInfo() const override;

 private:
  glm::vec3 _traceRay(const Ray& ray, BilliardScene* pScene, int depth,
                      const glm::vec2 xi);

  glm::vec3 _shade(const glm::vec3& dir, const HitRecord& shadingPoint,
                   BilliardScene* pScene, const glm::vec2 xi);

 private:
};

}  // namespace RayTracingHistory
