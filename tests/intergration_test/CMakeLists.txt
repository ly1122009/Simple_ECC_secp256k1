if(ENABLE_TESTING)
    set(TEST_MAIN "intergration_tests")
    set(TEST_SOURCES "main.intergration_test.cc")
    set(TEST_INCLUDES "./")

    add_executable(${TEST_MAIN} ${TEST_SOURCES})
    target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES})
    target_link_libraries(${TEST_MAIN} PUBLIC ${LIBRARY_NAME} Catch2::Catch2)
endif(ENABLE_TESTING)

