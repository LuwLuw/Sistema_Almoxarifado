include("${CMAKE_CURRENT_LIST_DIR}/cmake/ExportAsposeTarget.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/FixFilePathPrefix.cmake")

# if component list empty find all dependences
set(_find_all_dependencies FALSE)
if (NOT Asposecpplib_FIND_COMPONENTS)
    set(_find_all_dependencies TRUE)
endif()

FindExportFile(_exportFilename "${CMAKE_CURRENT_LIST_DIR}/lib/")
if (DEFINED _exportFilename)
    include("${CMAKE_CURRENT_LIST_DIR}/lib/${_exportFilename}")
    unset(_exportFilename)
endif()

if (DYNAMIC_ICU)
include("${CMAKE_CURRENT_LIST_DIR}/src/cmake/FindCpplibs.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/src/cmake/3rdPartyLibs.cmake")
# Get the lists of ICU binaries and export them through variable as Aspose dependencies
find_icu()

set(ASPOSECPPLIB_DEPENDENCIES_DEBUG "")
set(ASPOSECPPLIB_DEPENDENCIES_RELEASE "")

set(INDEX 0)
list(LENGTH ICU_BINARIES_DEBUG NUM_OF_BINARIES)
while (INDEX LESS NUM_OF_BINARIES)
  list(GET ICU_BINARIES_DEBUG ${INDEX} ICU_BINARY_DEBUG )
  list(GET ICU_BINARIES_RELEASE ${INDEX} ICU_BINARY_RELEASE )
  get_filename_component(ICU_BINARY_FNAME_DEBUG ${ICU_BINARY_DEBUG} NAME)
  get_filename_component(ICU_BINARY_FNAME_RELEASE ${ICU_BINARY_RELEASE} NAME)
  list(APPEND ASPOSECPPLIB_DEPENDENCIES_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/${ICU_BINARY_FNAME_DEBUG}")
  list(APPEND ASPOSECPPLIB_DEPENDENCIES_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/${ICU_BINARY_FNAME_RELEASE}")
  math(EXPR INDEX "${INDEX} + 1")
endwhile()
endif()

add_library(CodePorting.Translator.Cs2Cpp.Framework INTERFACE IMPORTED)
set_target_properties(CodePorting.Translator.Cs2Cpp.Framework PROPERTIES INTERFACE_LINK_LIBRARIES "Aspose::CodePorting.Translator.Cs2Cpp.Framework")

get_target_property(cs2cpp_defines CodePorting.Translator.Cs2Cpp.Framework INTERFACE_COMPILE_DEFINITIONS)
if (cs2cpp_defines MATCHES "^FORCE_BUILD_DEBUG=1" OR cs2cpp_defines MATCHES ";FORCE_BUILD_DEBUG=1")
    set(FORCE_BUILD_DEBUG, 1)
endif()
