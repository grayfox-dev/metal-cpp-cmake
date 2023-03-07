# Get all project dir
FILE(GLOB sample_projects ${CMAKE_CURRENT_SOURCE_DIR}/learn-metal/*)
FILE(GLOB heavy_metal_project ${CMAKE_CURRENT_SOURCE_DIR}/heavy-metal/*)

# For each project dir, build a target
FOREACH(project ${sample_projects})
    IF(IS_DIRECTORY ${project})
        # Get project name and all sources
        get_filename_component(project-name ${project} NAME)
        FILE(GLOB ${project}-src ${project}/*.cpp)

        # Create executable and link target
        add_executable(${project-name} ${${project}-src})
        target_link_libraries(${project-name} METAL_CPP)

        message(STATUS "Adding ${project-name}")
    ENDIF()
ENDFOREACH()


# For each project dir, build a target
FOREACH(subproject ${heavy_metal_project})
    IF(IS_DIRECTORY ${subproject})
        # Get subproject name and all sources
        get_filename_component(subproject-name ${subproject} NAME)
        FILE(GLOB ${subproject}-src ${subproject}/*.cpp)

        # Create executable and link target
        add_executable(${subproject-name} ${${subproject}-src})
        target_link_libraries(${subproject-name} METAL_CPP)

        message(STATUS "Adding ${subproject-name}")
    ENDIF()
ENDFOREACH()
