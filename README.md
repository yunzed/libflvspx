speex support for flash.
==========

Try to make libspeex works for Flash, compile it with FLasCC.

You will need to install FlasCC and FLEXSDK to compile this, modify and recompile with:
make lib FLASCC=/path/to/flascc FLEX=/path/to/flex.

If the make failed, please read Makefile.common, there is a hardcode asc2.jar full path.
