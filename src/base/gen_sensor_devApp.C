#include "gen_sensor_devApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
gen_sensor_devApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

gen_sensor_devApp::gen_sensor_devApp(InputParameters parameters) : MooseApp(parameters)
{
  gen_sensor_devApp::registerAll(_factory, _action_factory, _syntax);
}

gen_sensor_devApp::~gen_sensor_devApp() {}

void 
gen_sensor_devApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<gen_sensor_devApp>(f, af, s);
  Registry::registerObjectsTo(f, {"gen_sensor_devApp"});
  Registry::registerActionsTo(af, {"gen_sensor_devApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
gen_sensor_devApp::registerApps()
{
  registerApp(gen_sensor_devApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
gen_sensor_devApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gen_sensor_devApp::registerAll(f, af, s);
}
extern "C" void
gen_sensor_devApp__registerApps()
{
  gen_sensor_devApp::registerApps();
}
