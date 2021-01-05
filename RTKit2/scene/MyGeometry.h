#pragma once
#include <vector>

#include "MySceneObject.h"

namespace RTKit2 {

class MyGeometry : public MySceneObject {
 public:
  typedef std::shared_ptr<MyGeometry> Ptr;

  using MySceneObject::MySceneObject;

  virtual ~MyGeometry();

  void createFromBuffers(const std::vector<glm::vec3>& vertices,
                         const std::vector<unsigned>& indices);

  void createFromObj(const std::string& assetKey, const glm::mat4& transform);

 protected:
  RTCGeometry mGeometry = nullptr;
};

}  // namespace RTKit2