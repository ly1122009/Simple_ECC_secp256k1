# Author: LyNC
# File: CMake
# Content: Config Cmake 

set(EXECUTABLE_SOURCE "main.cc")

# Define executable file
add_executable(Executable ${EXECUTABLE_SOURCE})

# Liên kết với thư viện GMP và GMPXX
target_link_libraries(Executable PUBLIC ${LIBRARY_NAME} GMP::gmp GMP::gmpxx)

############################################
# Link some target library
target_link_libraries(Executable PUBLIC Library)


