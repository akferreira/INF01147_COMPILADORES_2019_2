cmake_minimum_required(VERSION 3.0)

project(etapa3_prj LANGUAGES C)

add_executable(etapa3_prj ast.c)

install(TARGETS etapa3_prj RUNTIME DESTINATION bin)
