target_sources(strumpack
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/FrontHIP.hip
  ${CMAKE_CURRENT_LIST_DIR}/FrontFactory.cpp
  ${CMAKE_CURRENT_LIST_DIR}/Front.cpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontDense.cpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontDense.hpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontHSS.cpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontHSS.hpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontBLR.cpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontBLR.hpp
  ${CMAKE_CURRENT_LIST_DIR}/FrontFactory.hpp
  ${CMAKE_CURRENT_LIST_DIR}/Front.hpp)

install(FILES
  FrontFactory.hpp
  DESTINATION include/sparse/fronts)

if(STRUMPACK_USE_MPI)
  target_sources(strumpack
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontMPI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontMPI.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontDenseMPI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontDenseMPI.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontHSSMPI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontHSSMPI.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontBLRMPI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontBLRMPI.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ExtendAdd.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ExtendAdd.hpp)
endif()

if(STRUMPACK_USE_CUDA OR STRUMPACK_USE_HIP OR STRUMPACK_USE_SYCL)
  target_sources(strumpack
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPU.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPU.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPUKernels.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPUStructs.hpp)
  install(FILES
    FrontGPUStructs.hpp
    DESTINATION include/sparse/fronts)
endif()

if(STRUMPACK_USE_MAGMA)
  target_sources(strumpack PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontMAGMA.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontMAGMA.cpp)
endif()

if(STRUMPACK_USE_CUDA)
  target_sources(strumpack PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontCUDA.cu
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPUSPD.cu
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPUSPD.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontGPUSPD.hpp)
endif()

if(STRUMPACK_USE_SYCL)
  target_sources(strumpack PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontSYCL.cpp)
endif()

if(STRUMPACK_USE_ZFP OR STRUMPACK_USE_SZ3)
  target_sources(strumpack
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontLossy.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontLossy.hpp)
endif()

if(STRUMPACK_USE_BPACK)
  target_sources(strumpack
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/FrontHODLR.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontHODLR.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontHODLRMPI.cpp
    ${CMAKE_CURRENT_LIST_DIR}/FrontHODLRMPI.hpp)
endif()
