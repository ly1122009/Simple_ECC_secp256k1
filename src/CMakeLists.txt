set(SORUCE_LIST "common.cc" "point.cc" "ellipticCurve.cc")
# Define include path
add_library(${LIBRARY_NAME} STATIC ${SORUCE_LIST})