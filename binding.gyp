{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc", "interface.cc" ],
      "include_dirs": ["vendor/libpqxx/include"],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions", "-fno-rtti"],
      "cflags_cc+": ["-frtti"] 
    }
  ]
}
