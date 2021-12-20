set(Sources
  CGInterface.cpp
  Cube.cpp
  CubeMesh.cpp
  CubeNewtonSolver.cpp
  EigenCG.cpp
  Material.cpp
  QuasistaticSolveResult.cpp
  StableNeoHookean.cpp
  TetMesh.cpp
)

set(Headers
  CGInterface.h
  CGSolverType.h
  Cube.h
  CubeMesh.h
  CubeNewtonSolver.h
  EigenCG.h
  InitialMesh.h
  LineSearches.h
  LocalHessianLocation.h
  Material.h
  QuasistaticSolveResult.h
  Settings.h
  StableNeoHookean.h
  TetMesh.h
  TetNewtonSolver.h
)

add_library(cubesim ${Headers} ${Sources})

set(EIGEN3_INCLUDE_DIR
"../ext/eigen3")
target_include_directories(cubesim SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIR})