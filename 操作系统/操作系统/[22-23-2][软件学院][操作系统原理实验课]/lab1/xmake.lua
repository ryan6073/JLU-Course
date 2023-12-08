set_languages("c11")

target("fork")
    set_kind("binary")
    add_files("src/fork.c")

target("clone")
    set_kind("binary")
    add_files("src/clone.c")
    add_links("pthread")
    add_defines("_GNU_SOURCE")
