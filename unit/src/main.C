//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

<<<<<<< HEAD
#include "gen_sensor_devApp.h"
=======
#include "GenSensorDevApp.h"
>>>>>>> 187cb9c02c41830508e4077dbe0c9f427fab19ff
#include "gtest/gtest.h"

// Moose includes
#include "Moose.h"
#include "MooseInit.h"
#include "AppFactory.h"

#include <fstream>
#include <string>

<<<<<<< HEAD
=======
PerfLog Moose::perf_log("gtest");

>>>>>>> 187cb9c02c41830508e4077dbe0c9f427fab19ff
GTEST_API_ int
main(int argc, char ** argv)
{
  // gtest removes (only) its args from argc and argv - so this  must be before moose init
  testing::InitGoogleTest(&argc, argv);

  MooseInit init(argc, argv);
<<<<<<< HEAD
  registerApp(gen_sensor_devApp);
=======
  registerApp(GenSensorDevApp);
>>>>>>> 187cb9c02c41830508e4077dbe0c9f427fab19ff
  Moose::_throw_on_error = true;
  Moose::_throw_on_warning = true;

  return RUN_ALL_TESTS();
}
