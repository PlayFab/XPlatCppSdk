#/bin/bash

set -e

# this can possibly show some odd failures with json, 
# ignore them. calabash may rely on an older version of json,
# but the newer one works just fine
bundle

bundle exec calabash-ios download
