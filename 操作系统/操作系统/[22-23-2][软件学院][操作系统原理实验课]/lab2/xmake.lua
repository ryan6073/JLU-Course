set_languages("c11")

target("processor_scheduling")
    set_kind("binary")
    add_files("src/processor_scheduling.c")
    add_links("pthread", "m")
