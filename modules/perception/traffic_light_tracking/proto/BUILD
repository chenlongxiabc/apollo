load("//tools:apollo_package.bzl", "apollo_package")
load("//tools/proto:proto.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "trafficlights_tracking_component_proto",
    srcs = ["traffic_light_tracking_component.proto"],
    deps = [
        "//modules/perception/common/proto:plugin_param_proto",
    ],
)

apollo_package()