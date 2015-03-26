#ifndef KAABBBOUNDINGVOLUME_H
#define KAABBBOUNDINGVOLUME_H KAabbBoundingVolume

#include <KMath>
#include <KAbstractBoundingVolume>
class KColor;
class KHalfEdgeMesh;
class KTransform3D;

class KAabbBoundingVolumePrivate;
class KAabbBoundingVolume : public KAbstractBoundingVolume
{
public:

  // Construction Methods
  enum Method
  {
    MinMaxMethod
  };

  // Constructors & Destructor
  KAabbBoundingVolume();
  KAabbBoundingVolume(KAabbBoundingVolume const &rhs);
  template <typename It, typename Accessor = Karma::DefaultAccessor<KVector3D const>>
  KAabbBoundingVolume(It begin, It end, Accessor accessor = Karma::DefaultAccessor<KVector3D const>());
  KAabbBoundingVolume(KAabbBoundingVolume const &a, KAabbBoundingVolume const &b);
  KAabbBoundingVolume(KHalfEdgeMesh const &mesh, Method method);
  KAabbBoundingVolume(KAabbBoundingVolume const &a, KVector3D const &offset);
  ~KAabbBoundingVolume();

  // Virtual Implementation
  Karma::MinMaxKVector3D const &extents() const;
  KVector3D const &minExtent() const;
  KVector3D const &maxExtent() const;
  KVector3D maxAxis() const;
  KVector3D minAxis() const;
  KVector3D center() const;
  void shiftCenter(const KVector3D &tr);
  void encompassPoint(const KVector3D &vector);
  void setMinMaxBounds(Karma::MinMaxKVector3D const &minMax);
  void draw(KTransform3D &t, const KColor &color) const;
  void makeCube();
  bool contains(const KVector3D &pos) const;
  KAabbBoundingVolume copyOffset(float x, float y, float z);
  void scale(float k);

private:
  void constructPrivate();
  KAabbBoundingVolumePrivate *m_private;
};

template <typename It, typename Accessor>
KAabbBoundingVolume::KAabbBoundingVolume(It begin, It end, Accessor accessor)
{
  constructPrivate();
  setMinMaxBounds(Karma::findMinMaxBounds(begin, end, accessor));
}

#endif // KAABBBOUNDINGVOLUME_H
