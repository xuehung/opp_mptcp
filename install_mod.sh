#!/bin/bash
sudo insmod ./opp_mptcp.ko
dmesg | grep opp
