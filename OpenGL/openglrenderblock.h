#ifndef OPENGLRENDERBLOCK_H
#define OPENGLRENDERBLOCK_H OpenGLRenderBlock

#include <KUniquePointer>
#include <OpenGLUniformBufferObject>
#include <glm/mat4x4.hpp>

class KMatrix4x4;
class KSize;

class OpenGLRenderBlockPrivate;
class OpenGLRenderBlock : public OpenGLUniformBufferObject
{
public:

  // Constructors / Destructor
  OpenGLRenderBlock();
  ~OpenGLRenderBlock();

  // Render Block Properties
  void setViewMatrix(const KMatrix4x4 &view);
  void setPerspective(float fovy, float aspectRatio, float nearPlane, float farPlane);
  void setPerspectiveMatrix(const KMatrix4x4 &perspective);
  void setNearFar(float nearPlane, float farPlane);
  void setDimensions(int width, int height);
  void setDimensions(const KSize &size);

  // Access Render Block Properties
  const glm::mat4 &worldToView() const;
  const glm::mat4 &viewToWorld() const;
  const glm::mat4 &worldToPersp() const;
  const glm::mat4 &perspToWorld() const;
  const glm::mat4 &viewToPersp() const;
  const glm::mat4 &perspToView() const;
  float nearPlane() const;
  float farPlane() const;
  float diffPlane() const;
  float sumPlane() const;
  int width() const;
  int height() const;

  // Public Methods
  void update();
  void allocate();
  bool dirty() const;

private:
  KUniquePointer<OpenGLRenderBlockPrivate> m_private;
};

#endif // OPENGLRENDERBLOCK_H