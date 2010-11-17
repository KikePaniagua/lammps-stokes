/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef IMPROPER_CLASS

ImproperStyle(umbrella,ImproperUmbrella)

#else

#ifndef LMP_IMPROPER_UMBRELLA_H
#define LMP_IMPROPER_UMBRELLA_H

#include "stdio.h"
#include "improper.h"

namespace LAMMPS_NS {

class ImproperUmbrella : public Improper {
 public:
  ImproperUmbrella(class LAMMPS *);
  ~ImproperUmbrella();
  void compute(int, int);
  void coeff(int, char **);
  void write_restart(FILE *);
  void read_restart(FILE *);

 private:
  double *kw, *w0, *C;

  void allocate();
};

}

#endif
#endif
