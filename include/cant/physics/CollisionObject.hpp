
#ifndef CANTINA_PHYSICS_COLLISIONOBJECT_HPP
#define CANTINA_PHYSICS_COLLISIONOBJECT_HPP

#pragma once

#include <cant/common/types.hpp>

#include <cant/physics/PhysicalCollider.hpp>
#include <cant/physics/PhysicalShape.hpp>

#include <cant/physics/StaticObject.hpp>

#include <cant/common/macro.hpp>
CANTINA_PHYSICS_NAMESPACE_BEGIN

template <size_u dim, typename T>
class CollisionObject : public StaticObject<dim, T>, public Collidable<dim, T>
{
   public:
    /** -- typedef -- **/
    typedef typename Positionable<dim, T>::Position        Position;

    typedef PhysicalCollider<dim, T> Collider;
    typedef PhysicalShape<dim, T>    Shape;

    /** -- methods -- **/
    CANT_EXPLICIT
    CollisionObject(UPtr<Shape> shape);
    // applying work of forces on the object
    // and so update its state.
    // should only be called by the simulation.

    // Kinetic through Collidable
    // nothing to do here, basically.

    // Collidable
    WPtr<Collider>
      getCollider() const override;
    CANT_NODISCARD bool
      isStatic() const override
    {
        return true;
    }

   private:
    /** -- methods -- **/

    /** -- fields -- **/
    ShPtr<Collider> m_collider;

    Stream<WPtr<Collider>> m_inContactColliders;
};

CANTINA_PHYSICS_NAMESPACE_END
#include <cant/common/undef_macro.hpp>

#include <cant/physics/CollisionObject.inl>

#endif  // CANTINA_PHYSICS_COLLISIONOBJECT_HPP
