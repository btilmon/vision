# Install script for directory: /home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/QR"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/MetisSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SparseCholesky"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Core"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/CholmodSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/StdList"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SparseLU"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SVD"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Eigen"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/LU"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/IterativeLinearSolvers"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/OrderingMethods"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/QtAlignedMalloc"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/StdDeque"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SparseQR"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SuperLUSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Sparse"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/PardisoSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Cholesky"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SparseCore"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/UmfPackSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/PaStiXSupport"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Dense"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/StdVector"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Jacobi"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Geometry"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Eigenvalues"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/Householder"
    "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/SPQRSupport"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/bjt/Documents/research/vision/libs/eigen-3.3.7/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

