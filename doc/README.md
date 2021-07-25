But Core
==========

This is the official reference wallet for But digital currency and comprises the backbone of the But peer-to-peer network. You can [download But Core](https://www.butcoin.tech/downloads/) or [build it yourself](#building) using the guides below.

Running
---------------------
The following are some helpful notes on how to run But on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/but-qt` (GUI) or
- `bin/butd` (headless)

### Windows

Unpack the files into a directory, and then run but-qt.exe.

### OS X

Drag But-Qt to your applications folder, and then run But-Qt.

### Need Help?

* See the [But documentation](https://docs.butcoin.tech)
for help and more information.
* See the [But Developer Documentation](https://but-docs.github.io/) 
for technical specifications and implementation details.
* Ask for help on [But Nation Discord](http://butchat.org)
* Ask for help on the [But Forum](https://butcoin.tech/forum)

Building
---------------------
The following are developer notes on how to build But Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The But Core repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- Source Code Documentation ***TODO***
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [But Forum](https://butcoin.tech/forum), in the Development & Technical Discussion board.
* Discuss on [But Nation Discord](http://butchat.org)

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
