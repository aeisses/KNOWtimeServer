{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc", "interface.cc", "lib/service.cc", "lib/database.cc", "lib/route.cc", "lib/trip.cc" ],
      "include_dirs": ["vendor/libpqxx/include", "/usr/include/postgresql", "lib"],
      "libraries": [ "-L../vendor/libpqxx/lib", "-lpqxx", "-lpq" ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions", "-fno-rtti"],
      "cflags_cc+": ["-frtti", "-fPIC"] 
    }
  ]
}
