# @ledgerhq/ledger-core

Ledger Core Library cross-platform C++ bindings for NodeJS.

## Usage

For usage example, see [live-common/src/libcore](https://github.com/LedgerHQ/ledger-live-common/tree/master/src/libcore).

## Install

```
yarn add @ledgerhq/ledger-core
```

## Prerequisite

It currently only works with **Node 12**.

### On Linux

You also need to have **g++-7** installed and set up as default. Here is a way to set it up in Debian (root):

```sh
echo "deb http://ftp.us.debian.org/debian testing main contrib non-free" > /etc/apt/sources.list.d/gcc7.list
apt-get update
apt-get install -t testing g++-7
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 700 --slave /usr/bin/g++ g++ /usr/bin/g++-7
```
