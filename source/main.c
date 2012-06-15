#include <feos.h>
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

u8 newline = '\n';
u8 framebuf[256][256];

int main(int argc, const char *argv[]) {
  QRinput *stream;
  QRcode  *code;
  unsigned char *data;
  int x, y, i;
  s32 scale;

  FeOS_DirectMode();

  videoSetMode(MODE_5_2D);
  bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
  BG_PALETTE[0] = RGB15(31, 31, 31);
  BG_PALETTE[1] = RGB15( 0,  0,  0);

  stream = QRinput_new();
  QRinput_setVersion(stream, 1);
  QRinput_setErrorCorrectionLevel(stream, QR_ECLEVEL_L);

  for(i = 1; i < argc; i++) {
    QRinput_append(stream, QR_MODE_8, strlen(argv[i]), (u8*)argv[i]);
    QRinput_append(stream, QR_MODE_8, 1, &newline);
  }

  code = QRcode_encodeInput(stream);
  QRinput_free(stream);

  memset(framebuf, 0, sizeof(framebuf));
  data = code->data;
  for(y = 0; y < code->width; y++) {
    for(x = 0; x < code->width; x++) {
      framebuf[y][x] = (*data++)&1;
    }
  }

  scale = ((code->width<<8)+171)/172;
  bgSetScale(3, scale, scale);
  QRcode_free(code);

  swiWaitForVBlank();
  memcpy(bgGetGfxPtr(3), framebuf, sizeof(framebuf));

  do {
    swiWaitForVBlank();
  } while(!(keysDown()&KEY_B));

  FeOS_ConsoleMode();

  return 0;
}

