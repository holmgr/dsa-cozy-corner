# Contributing

This is a set of guidelines for contributing, and not strict rules.
Use your best judgment and feel free to propose changes to this document in a pull request.

General tips for making a contribution:
- Have well commented code. All public methods/functions should have decent comments
- Please include unit tests so that the correctness of the implementation can be validated

#### Table Of Contents

[How Can I Contribute?](#how-can-i-contribute)
  * [What will be accepted?](#what-will-be-accepted)
  * [Pull Requests](#pull-requests)

[Styleguides](#styleguides)
  * [Git Commit Messages](#git-commit-messages)
  * [C/C++ Styleguide](#cc-styleguide)
  * [Documentation Styleguide](#documentation-styleguide)

## How Can I Contribute?

### What will be accepted?
Any new data structure or algorithm welcome in this repository as long as it is not already implemented.
So please make a quick pass of the repository before you start writing any code.
Then it is only a matter of making sure that the code you submit adhear to the guidelines as best as possible.

### Pull requests

* Make sure to follow the appropriate styleguides
* Ensure that the changes passes the test suite
* **If new code has been added, make sure appropriate unit tests included**
* Document new code based on the [Documentation Styleguide](#documentation-guidelines)
* Ensure that existing documentation has has been corrected if it affected
* **Do not mix code changes with white space cleanup**
* Keep your pull requests limited to a single issue

## Styleguides

### Git Commit Messages
Commit messages should be formatted according to the seven rules outlined in [How to Write a Git Commit Message](http://chris.beams.io/posts/git-commit/). Following is a summary of the mentioned rules, use the resource for further details:

* Separate subject from body with a blank line
* Limit the subject line to 50 characters
* Capitalize the subject line
* Do not end the subject line with a period
* Use the imperative mood in the subject line
* Wrap the body at 72 characters
* Use the body to explain _what_ and _why_ vs. _how_

Hopefully these rules are self explanatory, however the _imperative mood_ may need some examples.
The following simple rule outlined in [How to Write a Git Commit Message](http://chris.beams.io/posts/git-commit/) helps you format your Git commit subject line correctly every time:

A properly formed Git commit subject line should always be able to complete the following sentence:

> If applied, this commit will _your subject line here_

For example, the following imperative-mood subject lines completes:

* If applied, this commit will refactor subsystem X for readability
* If applied, this commit will fix typo in getting started documentation

Whereas non-imperative forms results in:

* If applied, this commit will fixed bug with Y
* If applied, this commit will changing behavior of X

### C/C++ Styleguide
The C/C++ source code should be written in accordance with the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
**Clangformat** is included which makes it much easier to ensure that the above mentioned standard is followed.
Simply run:

    make clanformat

in the build directory to format the source/test .h and .cpp files

### Documentation Styleguide
Inline source code documentation (comments) should follow the above mentioned Google styleguide, see [Google C++ Style Guide: Comments](https://google.github.io/styleguide/cppguide.html#Comments) for reference.

