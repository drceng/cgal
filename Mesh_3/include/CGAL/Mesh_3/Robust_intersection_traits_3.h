// Copyright (c) 2009 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description : 
//******************************************************************************

#ifndef CGAL_MESH_3_ROBUST_INTERSECTION_TRAITS_3_H
#define CGAL_MESH_3_ROBUST_INTERSECTION_TRAITS_3_H

#include <CGAL/Cartesian_converter.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>


namespace CGAL {

namespace Mesh_3 {


template < typename K_ >
class Robust_intersection_3
{
public:
  typedef typename K_::FT                             FT;
  
  typedef typename K_::Triangle_3                       Triangle_3;
  typedef typename K_::Line_3                       Line_3;
  typedef typename K_::Ray_3                       Ray_3;
  typedef typename K_::Segment_3                       Segment_3;
  
  template<typename T1, typename T2>
  struct Result {
    typedef typename K_::Intersect_3::template Result<T1, T2>::Type Type;
  };
  
  typedef Exact_predicates_exact_constructions_kernel   EK;
  typedef Cartesian_converter<typename K_::Kernel, EK>    To_exact;
  typedef Cartesian_converter<EK, typename K_::Kernel>    Back_from_exact;
  
  template<class T1, class T2>
  typename Result<T1, T2>::Type
  operator() (const T1& t, const T2& s) const
  {
    // Switch to exact
    To_exact to_exact;
    Back_from_exact back_from_exact;
    EK::Intersect_3 exact_intersection = EK().intersect_3_object();
    
    // Cartesian converters have an undocumented, optional< variant > operator
    return typename Result<T1, T2>::Type(back_from_exact(exact_intersection(to_exact(t), to_exact(s))));
  }
};



/**
 * @struct Robust_intersection_traits_3
 */
template<class K_>
struct Robust_intersection_traits_3
: public K_
{
  typedef Robust_intersection_3<K_> Intersect_3;
  typedef Robust_intersection_traits_3<K_> Kernel;
  Intersect_3
  intersect_3_object() const
  {
    return Intersect_3();
  }
  
};


} // end namespace Mesh_3
  
} //namespace CGAL

#endif // CGAL_MESH_3_ROBUST_INTERSECTION_TRAITS_3_H
