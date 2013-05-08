#include "speexencoder.h"
#include "speex/speex.h"

SpeexBits bits;
void* speex_encoder;

void	speex_encoder_start(int sample_rate) {	
	speex_bits_init(&bits);
	speex_encoder = speex_encoder_init(&speex_nb_mode);		
	speex_encoder_ctl(speex_encoder, SPEEX_SET_SAMPLING_RATE, &sample_rate);	
}

int	speex_encoder_encode(unsigned char* src, int inlen, unsigned char*dest, int outlen) {
	int len = 0;
	speex_bits_reset(&bits);
	speex_encode_int(speex_encoder, (short*)src, &bits);
	len = speex_bits_write(&bits, dest, outlen);
	return len;
}

void 	speex_encoder_stop() {
	speex_bits_destroy(&bits);
	speex_encoder_destroy(speex_encoder);
}