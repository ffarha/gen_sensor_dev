//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "gen_sensor_devTestApp.h"
#include "gen_sensor_devApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
gen_sensor_devTestApp::validParams()
{
  InputParameters params = gen_sensor_devApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

gen_sensor_devTestApp::gen_sensor_devTestApp(InputParameters parameters) : MooseApp(parameters)
{
  gen_sensor_devTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

gen_sensor_devTestApp::~gen_sensor_devTestApp() {}

void
gen_sensor_devTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  gen_sensor_devApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"gen_sensor_devTestApp"});
    Registry::registerActionsTo(af, {"gen_sensor_devTestApp"});
  }
}

void
gen_sensor_devTestApp::registerApps()
{
  registerApp(gen_sensor_devApp);
  registerApp(gen_sensor_devTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
gen_sensor_devTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gen_sensor_devTestApp::registerAll(f, af, s);
}
extern "C" void
gen_sensor_devTestApp__registerApps()
{
  gen_sensor_devTestApp::registerApps();
}
