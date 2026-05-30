find_program(LATEXMK latexmk)

if(NOT LATEXMK)
    message(FATAL_ERROR "latexmk not found. Install latexmk (z.B. texlive oder MiKTeX).")
endif()

# ------------------------------------------------------------
# Pfade
set(GENERATOR_EXE
    $<TARGET_FILE:CppTemplate_Sort_and_Struct_Visualisation>
)

set(GENERATED_TEX
    ${CMAKE_SOURCE_DIR}/bin/tex/output.tex
    ${CMAKE_SOURCE_DIR}/bin/tex/output_jamie.tex
)

set(OUT_PDF
    ${CMAKE_SOURCE_DIR}/bin/pdf/output.pdf
    ${CMAKE_SOURCE_DIR}/bin/pdf/output_jamie.pdf
)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/tex ${CMAKE_SOURCE_DIR}/bin/pdf)

# ------------------------------------------------------------
# Schritt 1: C++ erzeugt *.tex
add_custom_command(
    OUTPUT ${GENERATED_TEX} # Zieldatei
    # Starte CMake als Hilfsprogramm (scheinbar sicherer für die Arbeit auf den Verzeichnissen, gerad bei Leerzeichen/Sonderzeichen)
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/bin/tex $<TARGET_FILE:CppTemplate_Sort_and_Struct_Visualisation>
    DEPENDS CppTemplate_Sort_and_Struct_Visualisation
    COMMENT "Generating output.tex"
)

# ------------------------------------------------------------
# Schritt 2: LaTeX kompiliert *.tex direkt
add_custom_command(
    OUTPUT ${OUT_PDF}
    COMMAND ${LATEXMK} -pdf -quiet
            -output-directory=${CMAKE_SOURCE_DIR}/bin/pdf
            ${GENERATED_TEX}
    COMMAND ${LATEXMK}  # Aufräumen temporerer Logfiles
            -c
            -output-directory=${CMAKE_SOURCE_DIR}/bin/pdf
            ${GENERATED_TEX}
    DEPENDS ${GENERATED_TEX}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/pdf
    COMMENT "Building PDF from generated LaTeX"
)

# ------------------------------------------------------------
# META TARGET
add_custom_target(doc ALL   # ALL = wird automatisch gebaut
    DEPENDS ${OUT_PDF}
)