# Tìm thư viện GMP
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARY NAMES gmp)
find_library(GMPXX_LIBRARY NAMES gmpxx)

# Định nghĩa target imported
add_library(GMP::gmp UNKNOWN IMPORTED)
set_target_properties(GMP::gmp PROPERTIES
  IMPORTED_LOCATION "${GMP_LIBRARY}"
  INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
)

add_library(GMP::gmpxx UNKNOWN IMPORTED)
set_target_properties(GMP::gmpxx PROPERTIES
  IMPORTED_LOCATION "${GMPXX_LIBRARY}"
  INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
)

# Kiểm tra xem đã tìm thấy cả hai thư viện chưa
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP DEFAULT_MSG GMP_LIBRARY GMP_INCLUDE_DIR GMPXX_LIBRARY)
