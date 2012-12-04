// Copyright (c) 2011 GeometryFactory (France). All rights reserved.
// All rights reserved.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Philipp Möller

#ifndef CGAL_INTERSECTION_TRAITS_D_H
#define CGAL_INTERSECTION_TRAITS_D_H

#include <CGAL/Intersection_traits.h>

#if !(CGAL_INTERSECTION_VERSION < 2)

namespace CGAL {
  
  CGAL_INTERSECTION_TRAITS_2(Line_d, Line_d, Point_d, Line_d)

  CGAL_INTERSECTION_TRAITS_2(Segment_d, Line_d, Point_d, Segment_d)
  CGAL_INTERSECTION_TRAITS_2(Line_d, Segment_d, Point_d, Segment_d)

  CGAL_INTERSECTION_TRAITS_2(Segment_d, Segment_d, Point_d, Segment_d)

  CGAL_INTERSECTION_TRAITS_2(Ray_d, Line_d, Point_d, Ray_d)
  CGAL_INTERSECTION_TRAITS_2(Line_d, Ray_d, Point_d, Ray_d)

  CGAL_INTERSECTION_TRAITS_2(Ray_d, Segment_d, Point_d, Segment_d)
  CGAL_INTERSECTION_TRAITS_2(Segment_d, Ray_d, Point_d, Segment_d)

  CGAL_INTERSECTION_TRAITS_3(Ray_d, Ray_d, Point_d, Segment_d, Ray_d)

  CGAL_INTERSECTION_TRAITS_2(Hyperplane_d, Line_d, Point_d, Line_d)
  CGAL_INTERSECTION_TRAITS_2(Line_d, Hyperplane_d, Point_d, Line_d)

  CGAL_INTERSECTION_TRAITS_2(Hyperplane_d, Ray_d, Point_d, Ray_d)
  CGAL_INTERSECTION_TRAITS_2(Ray_d, Hyperplane_d, Point_d, Ray_d)

  CGAL_INTERSECTION_TRAITS_2(Hyperplane_d, Segment_d, Point_d, Segment_d)
  CGAL_INTERSECTION_TRAITS_2(Segment_d, Hyperplane_d, Point_d, Segment_d)
}

#endif // !(CGAL_INTERSECTION_VERSION < 2)

#endif /* CGAL_INTERSECTION_TRAITS_D_H */
