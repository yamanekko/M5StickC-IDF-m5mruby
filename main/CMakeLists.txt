set(COMPONENT_SRCS "main.cpp")
set(COMPONENT_ADD_INCLUDEDIRS "")

register_component()

#
# mrbc
#
set(MRUBY_APP_HEADER_FILE "${COMPONENT_PATH}/app_ruby.h")
set(MRUBY_APP_RUBY_FILE   "${COMPONENT_PATH}/app.rb")
set(MRBC_COMMAND_PATH "${PROJECT_PATH}/components/m5mruby/mruby/bin/mrbc")

if(EXISTS ${MRBC_COMMAND_PATH} AND EXISTS ${MRUBY_APP_RUBY_FILE})

  # build app_ruby.h
  add_custom_command(
    OUTPUT ${MRUBY_APP_HEADER_FILE}
    COMMAND ${CMAKE_COMMAND} -E env ${MRBC_COMMAND_PATH} -o ${MRUBY_APP_HEADER_FILE} -Bruby_code ${MRUBY_APP_RUBY_FILE}
    COMMENT "compiling with mrbc..."
    MAIN_DEPENDENCY ${MRUBY_APP_RUBY_FILE}
    VERBATIM
  )

  # add a target using mrbc
  add_custom_target(compile_ruby
                    DEPENDS ${MRUBY_APP_HEADER_FILE})
  add_dependencies(${COMPONENT_NAME} compile_ruby)
endif()
