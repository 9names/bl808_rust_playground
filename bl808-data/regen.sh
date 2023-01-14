#!/bin/sh
cargo build --bin svd_generator --release
target/release/svd_generator > generated/BL808.svd
#xmllint --format --nocompact bl808.svd > bl808_formatted.svd
#xmllint --format --nocompact bl808_generated.svd > bl808_generated_formatted.svd
