#!/bin/bash
# PJC C03 by Rafał Pocztarski
# https://github.com/rsp/rsp-pjc-c03
# https://gitlab.com/rsp/rsp-pjc-c03

fail () {
  echo TEST FAILED
  exit 1
}
echo =====
echo RUNTIME TESTS
echo testing z01 output
cmp z01-t.txt <(./z01) || fail
echo testing z02 output
# cmp z02-t.txt <(./z02) || fail
echo testing z03 output
cmp z03-t.txt <(./z03) || fail
echo testing z04 output
cmp z04-t.txt <(./z04) || fail
echo testing z05 output
cmp z05-t.txt <(./z05) || fail
echo ALL TESTS PASSED
