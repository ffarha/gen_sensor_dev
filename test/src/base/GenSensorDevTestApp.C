//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "GenSensorDevTestApp.h"
#include "GenSensorDevApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
GenSensorDevTestApp::validParams()
{
  InputParameters params = GenSensorDevApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

GenSensorDevTestApp::GenSensorDevTestApp(InputParameters parameters) : MooseApp(parameters)
{
  GenSensorDevTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

GenSensorDevTestApp::~GenSensorDevTestApp() {}

void
GenSensorDevTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  GenSensorDevApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"GenSensorDevTestApp"});
    Registry::registerActionsTo(af, {"GenSensorDevTestApp"});
  }
}

void
GenSensorDevTestApp::registerApps()
{
  registerApp(GenSensorDevApp);
  registerApp(GenSensorDevTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
GenSensorDevTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GenSensorDevTestApp::registerAll(f, af, s);
}
extern "C" void
GenSensorDevTestApp__registerApps()
{
  GenSensorDevTestApp::registerApps();
}
