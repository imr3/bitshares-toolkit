file(GLOB HEADERS "include/bts/app/*.hpp")

add_library( bts_app 
             api.cpp
             application.cpp
             plugin.cpp
           )

target_link_libraries( bts_app bts_chain fc bts_db bts_net bts_time bts_utilities )
target_include_directories( bts_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( application.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)
