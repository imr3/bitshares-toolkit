file(GLOB HEADERS "include/bts/account_history/*.hpp")

add_library( bts_account_history 
             account_history_plugin.cpp
           )

target_link_libraries( bts_account_history bts_chain bts_app )
target_include_directories( bts_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( account_history_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)
