j-incunabulum
=============

`ji.c` is the "J incunabulum", a small prototype for an array language interpreter:

> One summer weekend in 1989, Arthur Whitney visited Ken Iverson at Kiln Farm and produced — on
> one page and in one afternoon—an interpreter fragment on the AT&T 3B1 computer. I studied this 
> interpreter for about a week for its organization and programming style; and on Sunday, 
> August 27, 1989, at about four o'clock in the afternoon, wrote the first line of code that
> became the implementation described in this document.
-- Roger Hui, [An Implementation of J](http://www.jsoftware.com/jwiki/Doc/An%20Implementation%20of%20J)

The code was rather cryptic to begin with and no longer compiles on modern C compilers.

`mj.c` is a partial rewrite that I created in modern C to try and understand the code.
I did my best to emulate the style of the original code, but with more comments, and a
little more whitespace.

Although the code is terse and may seem unreadable at first, it can be understood with 
a little effort. It may help to understand that the code was written for and by people
who were very familiar with array-centric languages (APL) and who came from a strong 
mathematical background. Indeed, one of the main reasons for adopting a style like this
is that it meakes it easier to reason about and manipulate the code algebraically.

---

For an interesting interview with Arthur Whitney, see : http://queue.acm.org/detail.cfm?id=1531242

For more on the J language, see http://jsoftware.com/
