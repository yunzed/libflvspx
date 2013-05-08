#include "speexdecoder.h"
#include "speex/speex.h"

SpeexBits bits;
void* speex_decoder;

void	speex_decoder_start(int sample_rate) {	
	speex_bits_init(&bits);
	speex_decoder = speex_decoder_init(&speex_nb_mode);
	speex_decoder_ctl(speex_decoder, SPEEX_SET_SAMPLING_RATE, &sample_rate);	
}

int	speex_decoder_decode(unsigned char* src, int inlen, unsigned char*dest, int outlen) {
	int len = 0;	
	speex_bits_read_from(&bits, src, inlen);
	len = speex_decode_int(speex_decoder, &bits, (short*)dest);
	
	return len;
}

void 	speex_decoder_stop() {
	speex_bits_destroy(&bits);
	speex_decoder_destroy(speex_decoder);
}