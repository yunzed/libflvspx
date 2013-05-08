#ifndef SPEEX_ENCODER_H
#define SPEEX_ENCODER_H

void	speex_encoder_start(int sample_rate);
int		speex_encoder_encode(unsigned char* src, int len, unsigned char* out, int outlen);
void 	speex_encoder_stop();

#endif