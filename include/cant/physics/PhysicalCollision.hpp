
#ifndef CANTINA_PHYSICS_PHYSICALCOLLISION_HPP
#define CANTINA_PHYSICS_PHYSICALCOLLISION_HPP

#pragma once

#include <cant/common/memory.hpp>
#include <cant/common/types.hpp>

#include <cant/physics/Movable.hpp>
#include <cant/physics/Positionable.hpp>

#include <cant/physics/PhysicalCollider.hpp>

#include <cant/common/macro.hpp>
CANTINA_PHYSICS_NAMESPACE_BEGIN

template <size_u dim, typename T>
class PhysicalCollision
{
   public:
    /** -- typedefs -- **/
    typedef PhysicalCollider<dim, T>   Collider;
    typedef typename PhysicalCollider<dim, T>::Position Position;
    typedef typename PhysicalCollider<dim, T>::Vector   Vector;
    typedef typename PhysicalCollider<dim, T>::Intersection Intersection;

    typedef Pair<ShPtr<Collider>, ShPtr<Collider>> CollisionPair;

    /** -- structs -- **/
    enum ContactPhase
    {
        eEnter = 0,
        eStay  = 1,
        eLeave = 2,
    };

    // see:
    // https://www.myphysicslab.com/engine2D/collision-en.html
    struct Contact
    {
        // vectors from centre of mass to contact point in Object coordinates of max collider.
        Position rap;

        // normals
        Vector n;

        // no angular velocity for now.

        // velocities of impact points of min and max colliders
        Vector vbp;
        Vector vap;

        T e;

        // impulse
        T impulse;
    };

    /** -- methods -- **/
    CANT_EXPLICIT
    PhysicalCollision(CollisionPair pair, Intersection intersection);

    CANT_NODISCARD ShPtr<Collider> &
                   getColliderMax();
    CANT_NODISCARD ShPtr<Collider> &
                   getColliderMin();

    CANT_NODISCARD bool
      haveSameColliders(PhysicalCollision const & other) const;

    void
      setPhase(ContactPhase phase);
    CANT_NODISCARD ContactPhase
      getPhase() const;

    CANT_NODISCARD CANT_INLINE Contact const & getContact() const;
    CANT_NODISCARD CANT_INLINE Intersection const & getIntersection() const;

   private:
    /** -- methods -- **/
    void
      computeContact();

    void
      sortColliders();

    /** -- fields -- **/
    CollisionPair m_pair;
    Intersection m_intersection;

    ContactPhase m_phase;

    Contact m_contact;

    // constants
    static CANT_CONSTEXPR T c_restitution = static_cast<T>(0.);  // dimensionless.
};

CANTINA_PHYSICS_NAMESPACE_END
#include <cant/common/undef_macro.hpp>

#include <cant/physics/PhysicalCollision.inl>

#endif  // CANTINA_PHYSICS_PHYSICALCOLLISION_HPP