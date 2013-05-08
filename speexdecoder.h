#ifndef SPEEX_DECODER_H
#define SPEEX_DECODER_H

void	speex_decoder_start(int sample_rate);
int		speex_decoder_decode(unsigned char* src, int len, unsigned char* out, int outlen);
void 	speex_decoder_stop();

#endif