function(FixFilePathPrefix FILE PATH PREFIX OUTFILE)
    MESSAGE("FILE: ${FILE}")
    MESSAGE("PATH: ${PATH}")
    MESSAGE("PREFIX: ${PREFIX}")
    MESSAGE("OUTFILE: ${OUTFILE}")

    # Convert file contents into a CMake list (where each element in the list
    # is one line of the file)
    FILE(READ "${FILE}" contents)
    STRING(REPLACE "${PATH}" "${PREFIX}" contents "${contents}")
    FILE(WRITE "${OUTFILE}" "${contents}")
endfunction()
