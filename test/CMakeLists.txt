# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(imageviewerTests LANGUAGES CXX)

# ---- Tests ----

add_executable(imageviewer_test source/imageviewer_test.cpp)
target_link_libraries(imageviewer_test PRIVATE imageviewer_lib)
target_compile_features(imageviewer_test PRIVATE cxx_std_17)

add_test(NAME imageviewer_test COMMAND imageviewer_test)

# ---- End-of-file commands ----

add_folders(Test)
