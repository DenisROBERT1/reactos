
remove_definitions(-D_WIN32_WINNT=0x502)
add_definitions(-D_WIN32_WINNT=0x601)

add_definitions(
    -D_WINE)

spec2def(msxml2.dll msxml2.spec)
add_typelib(msxml2_tlb.idl)

list(APPEND SOURCE
    main.c
    ${CMAKE_CURRENT_BINARY_DIR}/msxml2.def)

add_library(msxml2 MODULE ${SOURCE} msxml2.rc)
set_module_type(msxml2 win32dll)
set_source_files_properties(msxml2.rc PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/msxml2_tlb.tlb)
target_link_libraries(msxml2 wine)
add_importlibs(msxml2 msxml3 msvcrt kernel32)
add_dependencies(msxml2 stdole2)
add_cd_file(TARGET msxml2 DESTINATION reactos/system32 FOR all)
set_wine_module(msxml2)
