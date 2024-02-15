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
    type = HeatConduction
    variable = temperature
  []
  [heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
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
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '18 0.466 80' # W/m*K, J/kg-K, kg/m^3 @ 296K
  []
[]

[Problem]
  type = FEProblem
[]

[Postprocessors]
  [input_signal_pp]
    type = ElementAverageValue
    variable = temperature
  []
  [general_sensor_pp]
    type = GeneralSensorPostprocessor
    input_signal = input_signal_pp
    #time = time_pp
    #noise_mean = 1
    #noise_std_dev = 0.1
    noise_std_dev_function = '0'
    delay_function = '0.3'
    drift_function = '0.0001*t'
    efficiency_function = '0.8'
    signalToNoise_function = '0.0'
    uncertainty_std_dev_function = '0.1'
  []
[]

[Executioner]
  type = Transient
  dt = 1
  num_steps = 5
  nl_abs_tol = 1e-8
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  csv = true
[]
