[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 10
    ny = 10
  []
  
  [Variables]
    [temperature]
    []
  []
  
  [Kernels]
    [diff]
      type = Diffusion
      variable = temperature
    []
  []
  
  [BCs]
    [./left]
      type = DirichletBC
      variable = temperature
      boundary = left
      value = 300
    [../]
    [./right]
      type = DirichletBC
      variable = temperature
      boundary = right
      value = 305
    [../]
  []
  
  [Postprocessors]
    [input_signal_pp]
      type = ElementAverageValue
      variable = temperature
    []
    [general_sensor_pp]
      type = GeneralSensorPostprocessor
      input_signal = input_signal_pp
      noise_std_dev_function = '0.1'
      delay_function = '0.3'
      drift_function = '0.0001*exp(-t)'
      efficiency_function = '0.8*exp(-0.1*t)'
      signalToNoise_function = '0.7*exp(-0.1*t)'
      uncertainty_std_dev_function = '0.1'
      proportional_weight = 0
      integral_weight = 1
    []
  []
  
  [Executioner]
    type = Transient
    num_steps = 5
    nl_abs_tol = 1e-8
  []
  
  [Outputs]
    csv = true
  []
