install(
    TARGETS imageviewer_exe
    RUNTIME COMPONENT imageviewer_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
