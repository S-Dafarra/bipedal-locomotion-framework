# Copyright (C) 2020 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.

if(FRAMEWORK_COMPILE_Estimators)

  set(H_PREFIX include/BipedalLocomotion/Estimators)
  add_bipedal_locomotion_library(
    NAME                   Estimators
    SOURCES                src/RecursiveLeastSquare.cpp
    PUBLIC_HEADERS         ${H_PREFIX}/RecursiveLeastSquare.h
    SUBDIRECTORIES         tests
    PUBLIC_LINK_LIBRARIES  BipedalLocomotion::ParametersHandler BipedalLocomotion::System Eigen3::Eigen)

  add_bipedal_locomotion_library(
    NAME                   FloatingBaseEstimators
    SOURCES                src/FloatingBaseEstimator.cpp
    PUBLIC_HEADERS         ${H_PREFIX}/FloatingBaseEstimatorParams.h ${H_PREFIX}/FloatingBaseEstimatorIO.h ${H_PREFIX}/FloatingBaseEstimator.h
    PUBLIC_LINK_LIBRARIES  iDynTree::idyntree-high-level iDynTree::idyntree-core iDynTree::idyntree-model BipedalLocomotion::System Eigen3::Eigen)

endif()
