#include "GenSensorDevApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
GenSensorDevApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

GenSensorDevApp::GenSensorDevApp(InputParameters parameters) : MooseApp(parameters)
{
  GenSensorDevApp::registerAll(_factory, _action_factory, _syntax);
}

GenSensorDevApp::~GenSensorDevApp() {}

void 
GenSensorDevApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<GenSensorDevApp>(f, af, s);
  Registry::registerObjectsTo(f, {"GenSensorDevApp"});
  Registry::registerActionsTo(af, {"GenSensorDevApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
GenSensorDevApp::registerApps()
{
  registerApp(GenSensorDevApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
GenSensorDevApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GenSensorDevApp::registerAll(f, af, s);
}
extern "C" void
GenSensorDevApp__registerApps()
{
  GenSensorDevApp::registerApps();
}
