
set( clLazyFile_SRCS
  lazyDataSectionReader.cc
  lazyFileReader.cc
  lazyInstMgr.cc
  p21HeaderSectionReader.cc
  sectionReader.cc
  lazyP21DataSectionReader.cc
  )

set( SC_CLLAZYFILE_HDRS
  headerSectionReader.h
  lazyFileReader.h
  lazyP21DataSectionReader.h
  p21HeaderSectionReader.h
  lazyDataSectionReader.h
  lazyInstMgr.h
  lazyTypes.h
  sectionReader.h
  instMgrHelper.h
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${SC_SOURCE_DIR}/src/cleditor
  ${SC_SOURCE_DIR}/src/cldai
  ${SC_SOURCE_DIR}/src/clstepcore
  ${SC_SOURCE_DIR}/src/clutils
  ${SC_SOURCE_DIR}/src/base
  ${SC_SOURCE_DIR}/src/base/judy/src
  )

if(BUILD_SHARED_LIBS)
  set(_libdeps stepcore stepdai steputils base stepeditor)
  SC_ADDLIB(steplazyfile SHARED SOURCES ${clLazyFile_SRCS} LINK_LIBRARIES ${_libdeps})
  if(WIN32)
    target_compile_definitions(steplazyfile PRIVATE SC_LAZYFILE_DLL_EXPORTS)
  endif()
  SC_ADDEXEC(lazy_test SOURCES lazy_test.cc LINK_LIBRARIES steplazyfile stepeditor NO_INSTALL)
  target_compile_definitions(lazy_test PRIVATE NO_REGISTRY)
endif()

if(BUILD_STATIC_LIBS)
  set(_libdeps stepcore-static stepdai-static steputils-static base-static stepeditor-static)
  SC_ADDLIB(steplazyfile-static STATIC SOURCES ${clLazyFile_SRCS} LINK_LIBRARIES ${_libdeps})
  target_compile_definitions(steplazyfile-static PRIVATE SC_STATIC)
  SC_ADDEXEC(lazy_test-static SOURCES lazy_test.cc LINK_LIBRARIES steplazyfile-static stepeditor-static NO_INSTALL)
  target_compile_definitions(lazy_test-static PRIVATE SC_STATIC)
  target_compile_definitions(lazy_test-static PRIVATE NO_REGISTRY)
endif()

if(MSVC)
  add_compile_options("/Zi")
endif(MSVC)

install(FILES ${SC_CLLAZYFILE_HDRS}
  DESTINATION ${INCLUDE_DIR}/stepcode/cllazyfile)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

