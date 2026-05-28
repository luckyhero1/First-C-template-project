find_program(LATEXMK latexmk)

if(NOT LATEXMK)
    message(FATAL_ERROR "latexmk not found. Install MiKTeX or TeX Live.")
endif()

# ------------------------------------------------------------
# Pfade
# ------------------------------------------------------------
set(GENERATOR_EXE
    $<TARGET_FILE:CppTemplate_Sort_and_Struct_Visualisation>
)

set(GENERATED_TEX
    ${CMAKE_SOURCE_DIR}/bin/output.tex
    ${CMAKE_SOURCE_DIR}/bin/output_jamie.tex
)

set(OUT_PDF
    ${CMAKE_BINARY_DIR}/output.pdf
    ${CMAKE_BINARY_DIR}/output_jamie.pdf
)

# ------------------------------------------------------------
# STEP 1: C++ erzeugt output.tex
# ------------------------------------------------------------
add_custom_command(
    OUTPUT ${GENERATED_TEX}
    COMMAND $<TARGET_FILE:CppTemplate_Sort_and_Struct_Visualisation>
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    DEPENDS CppTemplate_Sort_and_Struct_Visualisation
    COMMENT "Generating output.tex"
)

# ------------------------------------------------------------
# STEP 2: LaTeX kompiliert output.tex direkt
# ------------------------------------------------------------
add_custom_command(
    OUTPUT ${OUT_PDF}
    COMMAND ${LATEXMK} -pdf -interaction=nonstopmode
            -output-directory=${CMAKE_BINARY_DIR}
            ${GENERATED_TEX}
    DEPENDS ${GENERATED_TEX}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    COMMENT "Building PDF from generated LaTeX"
)

# ------------------------------------------------------------
# META TARGET
# ------------------------------------------------------------
add_custom_target(doc ALL
    DEPENDS ${OUT_PDF}
)