<a href="https://discord.gg/9x7gKH899g"><img src="https://img.shields.io/discord/833791711217844244.svg?style=flat&label=Join%20Community&color=7289DA" alt="Join Community Badge"/></a>

  
# What is But?
<img src="https://coinpaprika.com/coin/butk-butkoin/logo.png" width="150">
ButKoin is a decentralized secure cryptocurrency that is easy to mine devoid from 51% attack and it provide easy means of transactions between individuals. It is a Multi-algorithm coin. ButKoin uses a Smartnode collateral and reward system that prevent hyperinflation.

# Supported Algorithms



| Algorithm   | GPU CPU Asic|
| ----------- | ----------- |
| Ghostrider  | CPU         |
| Yespower    | CPU         |
| Lyra2z330   | GPU         |
| Sha256      | Asic        |
| Scrypt      | Asic        |

License
-------

But Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is done in separate branches.
[Tags](https://github.com/but/but/tags) are created to indicate new official,
stable release versions of But Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).



Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

[![Butkoin/but](https://gitee.com/Butkoin/but/widgets/widget_card.svg?colors=4183c4,ffffff,ffffff,e3e9ed,666666,9b9b9b)](https://gitee.com/Butkoin/but)
