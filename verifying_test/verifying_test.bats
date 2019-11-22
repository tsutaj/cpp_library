#!/usr/bin/env bats
VERIFYING_DIR="verifying_test"
BATSLOG_DIR="./"
BATSLOG_NAME="ci_build_bats.log"

setup() {
    rm -rf ./$VERIFYING_DIR/$BATSLOG_NAME
    echo "setup ${BATS_TEST_NAME} ..." >> ./$VERIFYING_DIR/$BATSLOG_NAME
}

teardown() {
    echo "teardown ${BATS_TEST_NAME} ..." >> ./$VERIFYING_DIR/$BATSLOG_NAME
}

@test "build ci" {
    cd ./$VERIFYING_DIR
    run pwd
    echo "${output}" >> $BATSLOG_DIR/$BATSLOG_NAME

    run ./run_ci.sh
    echo "${output}" >> $BATSLOG_DIR/$BATSLOG_NAME
    cd -

    [ "${status}" -eq 0 ]
}