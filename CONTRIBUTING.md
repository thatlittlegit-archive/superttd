# Contributing Guide
First, thanks for taking the time to contribute! We really appreciate it -
we're not many people.

The following is a set of guidelines for contributing to SuperTTD. We hate
to hinder you, so as long as your contribution follows these guidelines and
we approve it will merge!
### The Code of Conduct
We use the [Contributor Convent](/CODE_OF_CONDUCT.md) as our Code of Conduct.
If you contribute, you're expected to follow and uphold the Code.

### Your First Contribution
Is it your first time on GitHub? Great! We're happy your contributing to us and
the open-source community.

Find an issue that you can help with. Typically one marked as
"contributions-welcome" is an easy issue to get started with. Make your change,
and follow the [PR instructions](#making-a-pull-request-pr). Thanks!

## Design Decisions
Sometimes, we might take design decisions, such as designing the code with
OOP, or taking on technical debt. We'll let you know if your violating one,
however if a file DESIGN\_DECISIONS.md exists you're expected to read it.

## Filing an Issue :bug:
Following the guide depicted below should get your issue noticed. The first
step might make it so you don't need to file one!

1. **Check if an issue already exists.** GitHub Issues has a built-in search
bar. Make certain to remove `is:open` if you are checking for duplicates!
2. **Determine if your issue is related to code.** We only use Issues for
code issues and bugs. If you are having trouble playing the game, consider
if you should go on a forum or subreddit for players instead of filing an
issue. If you thing something is overpowered, or overpower*ing*, it might be
worth filing a bug.
3. **Follow the issue template.** It's there for a reason. Fill it out, one
hundred percent. It confirms that we have the information we need to help
you.
4. **Make a great title.** We can change it if necessary, but it's best you
get it right the first time.
5. **Post it!** Put it up for the world to see!
4. **Don't abandon your issue.** We might need help with getting more
information, or instructions to reproduce. Make sure you check on it every few
days.
5. **Profit!** :cash:

## Making a Pull Request (PR) :merge:
A Pull Request is a request to merge (pull) your code into our repository. As
long as you follow these steps, you shouldn't have any problems. You might,
though, and as such we'll try our best to help.

1. **Follow the PR template.** It's there for a reason.
2. **Make a great title, with a reference to the issue number.** A great
example is: `Make the code compile by adding a semicolon (#32)`.
3. **Fix the files to comply with the EditorConfig.** Until we get
`clang-format`, this is the best way for us to check the styleguide.
4. **Send it up!** Up, up and away!
5. **Don't abandon your issue.** We might need to respond to it.
6. **Profit!** :cash:

## Styleguide
### C++ Code
```cpp
/* (c) 2017 thatlittlegit, PinguPenguin and contributors.
 * This file is from the SuperTTD project.
 *
 * --- legal stuff, see spriteman.cpp for an example ---
 */
#include <string>
//      ^ spaces in preprocessor directives

// If you use something (like a string) more than twice, use the
// `using` keyword
using std::string;

// using namespace std;
//        ^ don't use `using namespace`

// Put classes (not global functions!) in namespaces.
namespace SuperTTD {
	void Sprite::construct(string argFilename, unsigned int argWorld, string argId) {
//	                                          ^ spaces between arguments
		filename = argFilename;
		        ^ ^ spaces in assignment

		try {
			associated = reloadSprite();
		} catch (const std::invalid_argument& e) {}
		//     ^ space in catch
	}
}

//          \/ camelCase
void functionName() {
//              \/ space before brackets
	if (true) {
	//^ space after if
		return false;	
// ^ tab indentation
	} else {
//       ^    ^ padding on the elses
	}
}
```
There's probably more to be added. Make a PR!

### Git Commit Messages
* Present tense. *Add <feature>*, not *Added <feature>*
* First line no more than 50 characters
* Use a non-imperative mood, *Add feature that moves the mouse* not *Add feature to move the mouse*.
<hr />
*Inspired by Atom's guide*
