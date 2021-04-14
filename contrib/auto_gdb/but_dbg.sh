#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.but/butd.pid file instead
but_pid=$(<~/.but/testnet3/butd.pid)
sudo gdb -batch -ex "source debug.gdb" butd ${but_pid}
