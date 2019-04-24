cmake_minimum_required(VERSION 3.8)

add_compile_definitions(PUGIXML_SUPPORT)

set(PUGIXML_SRC_DIR D:/prj/pugixml)
set(PUGIXML_BUILD_DIR "D:/prj/build-pugixml-Desktop_Qt_5_12_0_MinGW_64_bit-u041fu043e u0443u043cu043eu043bu0447u0430u043du0438u044e")

include_directories(${PUGIXML_SRC_DIR}/src)

if(${PugixmlLinkingSupport})

    target_link_libraries(Sdk ${PUGIXML_BUILD_DIR}/libpugixml.dll.a)

endif()
