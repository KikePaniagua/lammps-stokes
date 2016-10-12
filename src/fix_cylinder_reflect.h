/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(cylinder/reflect,FixCylinderReflect)

#else

#ifndef LMP_FIX_CYLINDER_REFLECT_H
#define LMP_FIX_CYLINDER_REFLECT_H

#include "fix.h"

namespace LAMMPS_NS {

class FixCylinderReflect : public Fix {
 public:
  FixCylinderReflect(class LAMMPS *, int, char **);
  virtual ~FixCylinderReflect();
  int setmask();
  void init();
  void post_integrate();

 protected:
  int nwall;
  int wallwhich[6],wallstyle[6];
  double coord0[6];
  char *varstr[6];
  int varindex[6];
  int varflag;
  double xscale,yscale,zscale;
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Illegal ... command

Self-explanatory.  Check the input script syntax and compare to the
documentation for the command.  You can use -echo screen as a
command-line option when running LAMMPS to see the offending line.

E: Wall defined twice in fix cylinder/reflect command

Self-explanatory.

E: Cannot use fix cylinder/reflect in periodic dimension

Self-explanatory.

E: Cannot use fix cylinder/reflect zlo/zhi for a 2d simulation

Self-explanatory.

E: Variable name for fix cylinder/reflect does not exist

Self-explanatory.

E: Variable for fix cylinder/reflect is invalid style

Only equal-style variables can be used.

W: Should not allow rigid bodies to bounce off relecting walls

LAMMPS allows this, but their dynamics are not computed correctly.

*/