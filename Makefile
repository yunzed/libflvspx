include Makefile.common

TARGET = libflvspx.swc


SRCS_C = $(wildcard speex/libspeex/*.c) main.c speexencoder.c speexdecoder.c audiocodec.c


lib:
	"$(FLASCC)/usr/bin/swig" -as3 -module spxcodec -outdir . -includeall -ignoremissing -o spxcodec.c spxcodec.h
	echo "compile spxcodec.as"	
	$(AS3COMPILERARGS) -abcfuture -AS3 -import $(FLASCC_WINPATH)/sdk/usr/lib/builtin.abc -import $(FLASCC_WINPATH)/sdk/usr/lib/playerglobal.abc spxcodec.as
	
	echo "last step: link"
	"$(FLASCC)/usr/bin/gcc" -jvmopt=-Xmx1G $(BASE_CFLAGS) AudioCodec.abc $(SRCS_C) -DHAVE_CONFIG_H -I ./ -I./speex/include -I./speex -emit-swc=com.vcap.spx -o $(TARGET)
