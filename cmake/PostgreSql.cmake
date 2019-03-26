cmake_minimum_required(VERSION 3.8)

if(${PostgreSQLSupport}) # Настройки для работы с PostgreSQL
    add_compile_definitions(POSTGRESQL_SUPPORT)

    set(POSTGRESQL_DIR D:/PostgreSQL/pg11)
    include_directories(${POSTGRESQL_DIR}/include)

    #add_library(pq SHARED IMPORTED)
    #set_target_properties(pq PROPERTIES IMPORTED_LOCATION ${POSTGRESQL_DIR}/lib/libpq.lib)
    target_link_libraries(Sdk ${POSTGRESQL_DIR}/lib/libpq.a)
endif()