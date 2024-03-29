[Mesh]
  [gmg]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 10
    ny = 10
    #xmax = 0.304 # Length of test chamber
    #ymax = 0.0257 # Test chamber radius
  []
  coord_type = RZ
  rz_coord_axis = X
[]

[Variables]
  [temperature]
    initial_condition = 300 # Start at room temperature
  []
[]

[Kernels]
  [heat_conduction]
    type = ADHeatConduction
    variable = temperature
  []
  [heat_conduction_time_derivative]
    type = ADHeatConductionTimeDerivative
    variable = temperature
  []
[]

[BCs]
  [inlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = left
    value = 1000 # (K)
  []
  [outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = right
    value = 300 # (K)
  []
[]

[Materials]
  [steel]
    type = ADGenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '18 0.466 80' # W/m*K, J/kg-K, kg/m^3 @ 296K
  []
[]

[Problem]
  type = FEProblem
[]

[Postprocessors]
  # Volume pp
  [input_signal_pp]
    type = ElementAverageValue
    variable = temperature
    #execute_on = initial
  []
  [general_sensor_pp]
    type = GeneralSensorPostprocessor
    #execute_on = initial
    input_signal = input_signal_pp
    noise_std_dev_function = '0.5'
    delay_function = '0.3'
    drift_function = '0.0001*t'
    efficiency_function = '0.8*exp(-0.1*t)'
    signalToNoise_function = '0.7*exp(-0.1*t)'
    uncertainty_std_dev_function = '0.1'
    proportional_weight = 1
    integral_weight = 1
  []
  # Surface pp
  [input_surface_signal_pp]
    type = SideDiffusiveFluxAverage
    variable = temperature
    boundary = right
    diffusivity = 18
    #execute_on = initial
  []
  [surface_general_sensor_pp]
    type = GeneralSensorPostprocessor
    #execute_on = initial
    input_signal = input_surface_signal_pp
    noise_std_dev_function = '0.5'
    delay_function = '0.3'
    drift_function = '0.0001*t'
    efficiency_function = '0.8*exp(-0.1*t)'
    signalToNoise_function = '0.7*exp(-0.1*t)'
    uncertainty_std_dev_function = '0.1'
    proportional_weight = 1
    integral_weight = 1
  []
[]

[Executioner]
  type = Transient
  num_steps = 5
  dt = 1
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  csv = true
[]
