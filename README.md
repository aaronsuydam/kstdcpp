# kstdcpp

This project started out of my systems programming course this semester. My professor asked us to write some device drivers
using the Linux kernel. I did some research and found that (for some very good reasons), you couldn't write kernel space
programs in pure C++. Exceptions, stack unwinding, differences in memory allocation functions, Linus hates C++, etc. etc.

However.

Being stubborn, as I can be sometimes, I thought "what if I wrote my program in C++ and then just exposed a C api to the kernel?"
So I looked into it, and it turns out that in kernel space, you can't use C++ standard library features, period, again for the 
aforementioned reasons. I think this puts me as an (admittedly beginner) kernel-space developer at a serious disadvantage. 
No smart pointers. No vectors. No algorithms. No std::copy/std::move, to name a few.None of the building blocks of some of the best C++ work that I've done so far. None of the peace of mind that comes from having a tried and true, tested to heaven and back library on which to build arguably the most important pieces of software in the world, second to the kernel: drivers.

## PLEASE READ

Now, to be clear: this library is USE AT YOUR OWN RISK. I'm a college student who's doing this for fun in my spare time. 
I thought it might be useful to others, which is why it is on GitHub, but I take NO RESPONSIBILITY for you blowing up your machine
by using it. I am definitely relying on GitHub Copilot and ChatGPT for the things I don't understand (read: an absolute ton of this
was generated by AI or was significantly contributed to by it). Here's what this library is: a genuine attempt (for as long as 
I remain motivated) at making my life easier in kernel space. It is not a perfectly implemented, no-compromises, well-maintained,
fully-compliant C++ stdlib implementation.

That would be crazy.

But if that interests you, feel free to use this code as a starting point. That's the beauty of open source code. 

Hope this makes your life easier.

Aaron





# Notes to Self
Deleted enum {false = 0, true = 1} from stddef.h
Deleted typedef _Bool bool; from types.h
