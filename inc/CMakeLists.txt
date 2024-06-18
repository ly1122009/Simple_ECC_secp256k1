# Link some target library
target_include_directories(${LIBRARY_NAME} PUBLIC "./")

if (ENABLE_WARNINGS)
    target_set_warnings(
        ${LIBRARY_NAME}
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()