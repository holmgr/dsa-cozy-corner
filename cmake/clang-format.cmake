# Additional target to perform clang-format run, requires clang-format

# Get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)

add_custom_target(
        clangformat
        COMMAND clang-format
        -style=google
        -i
        ${ALL_SOURCE_FILES}
)
