cc_library(
  strip_include_prefix = "",
  include_prefix = "atena",
  name = "core",
  srcs = glob(["core/*.cc"]),
  hdrs = glob(["core/*.h"]),
  copts = ["-I/usr/local/include"],
  deps = [":entities"],
  visibility = ["//visibility:public"],
)

cc_library(
  strip_include_prefix = "",
  include_prefix = "atena",
  name = "entities",
  srcs = glob(["entities/*.cc"]),
  hdrs = glob(["entities/*.h"]),
  copts = ["-I/usr/local/include"],
  deps = [
    ":input",
    ":math",
    ":textures",
  ],
  visibility = ["//visibility:public"],
)

cc_library(
  strip_include_prefix = "",
  include_prefix = "atena",
  name = "input",
  srcs = glob(["input/*.cc"]),
  hdrs = glob(["input/*.h"]),
  copts = ["-I/usr/local/include"],
  deps = [":math"],
  visibility = ["//visibility:public"],
)

cc_library(
  strip_include_prefix = "",
  include_prefix = "atena",
  name = "math",
  srcs = glob(["math/*.cc"]),
  hdrs = glob(["math/*.h"]),
  copts = ["-I/usr/local/include"],
  visibility = ["//visibility:public"],
)

cc_library(
  strip_include_prefix = "",
  include_prefix = "atena",
  name = "textures",
  srcs = glob(["textures/*.cc"]),
  hdrs = glob(["textures/*.h"]),
  copts = ["-I/usr/local/include"],
  visibility = ["//visibility:public"],
)
