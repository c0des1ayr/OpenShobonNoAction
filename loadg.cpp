#include "DxLib.h"

extern int ma, t, tt;
extern SDL_Surface *sprites[161][8];
extern SDL_Surface *graphics[51];
int x1;
extern Mix_Music *music[6];
extern Mix_Chunk *sfx[19];

extern int anx[160], any[160];
extern int ne[40], nf[40];

void loadg(void) {
  for (t = 0; t < 51; t++) {
    graphics[t] = 0;
  }
  for (int i = 0; i < 161; i++) {
    for (int j = 0; j < 8; j++) {
      sprites[i][j] = NULL;
    }
  }

  // 画像読み込み

  // プレイヤー
  graphics[0] = LoadGraph("res/player.PNG");
  // ブロック
  graphics[1] = LoadGraph("res/brock.PNG");
  // アイテム
  graphics[2] = LoadGraph("res/item.PNG");
  // 敵
  graphics[3] = LoadGraph("res/teki.PNG");
  // 背景
  graphics[4] = LoadGraph("res/haikei.PNG");
  // ブロック2
  graphics[5] = LoadGraph("res/brock2.PNG");
  // おまけ
  graphics[6] = LoadGraph("res/omake.PNG");
  // おまけ2
  graphics[7] = LoadGraph("res/omake2.PNG");
  // タイトル
  graphics[30] = LoadGraph("res/syobon3.PNG");

  // プレイヤー読み込み
  sprites[40][0] = DerivationGraph(0, 0, 30, 36, graphics[0]);
  sprites[0][0] = DerivationGraph(31 * 4, 0, 30, 36, graphics[0]);
  sprites[1][0] = DerivationGraph(31 * 1, 0, 30, 36, graphics[0]);
  sprites[2][0] = DerivationGraph(31 * 2, 0, 30, 36, graphics[0]);
  sprites[3][0] = DerivationGraph(31 * 3, 0, 30, 36, graphics[0]);
  sprites[41][0] = DerivationGraph(50, 0, 51, 73, graphics[6]);

  x1 = 1;
  // ブロック読み込み
  for (t = 0; t <= 6; t++) {
    sprites[t][x1] = DerivationGraph(33 * t, 0, 30, 30, graphics[x1]);
    sprites[t + 30][x1] = DerivationGraph(33 * t, 33, 30, 30, graphics[x1]);
    sprites[t + 60][x1] = DerivationGraph(33 * t, 66, 30, 30, graphics[x1]);
    sprites[t + 90][x1] = DerivationGraph(33 * t, 99, 30, 30, graphics[x1]);
  }
  sprites[8][x1] = DerivationGraph(33 * 7, 0, 30, 30, graphics[x1]);
  sprites[16][x1] = DerivationGraph(33 * 6, 0, 24, 27, graphics[2]);
  sprites[10][x1] = DerivationGraph(33 * 9, 0, 30, 30, graphics[x1]);
  sprites[40][x1] = DerivationGraph(33 * 9, 33, 30, 30, graphics[x1]);
  sprites[70][x1] = DerivationGraph(33 * 9, 66, 30, 30, graphics[x1]);
  sprites[100][x1] = DerivationGraph(33 * 9, 99, 30, 30, graphics[x1]);
  // ブロック読み込み2
  x1 = 5;
  for (t = 0; t <= 6; t++) {
    sprites[t][x1] = DerivationGraph(33 * t, 0, 30, 30, graphics[x1]);
  }
  sprites[10][5] = DerivationGraph(33 * 1, 33, 30, 30, graphics[x1]);
  sprites[11][5] = DerivationGraph(33 * 2, 33, 30, 30, graphics[x1]);
  sprites[12][5] = DerivationGraph(33 * 0, 66, 30, 30, graphics[x1]);
  sprites[13][5] = DerivationGraph(33 * 1, 66, 30, 30, graphics[x1]);
  sprites[14][5] = DerivationGraph(33 * 2, 66, 30, 30, graphics[x1]);

  // アイテム読み込み
  x1 = 2;
  for (t = 0; t <= 5; t++) {
    sprites[t][x1] = DerivationGraph(33 * t, 0, 30, 30, graphics[x1]);
  }

  // 敵キャラ読み込み
  x1 = 3;
  sprites[0][x1] = DerivationGraph(33 * 0, 0, 30, 30, graphics[x1]);
  sprites[1][x1] = DerivationGraph(33 * 1, 0, 30, 43, graphics[x1]);
  sprites[2][x1] = DerivationGraph(33 * 2, 0, 30, 30, graphics[x1]);
  sprites[3][x1] = DerivationGraph(33 * 3, 0, 30, 44, graphics[x1]);
  sprites[4][x1] = DerivationGraph(33 * 4, 0, 33, 35, graphics[x1]);
  sprites[5][x1] = DerivationGraph(0, 0, 37, 55, graphics[7]);
  sprites[6][x1] = DerivationGraph(38 * 2, 0, 36, 50, graphics[7]);
  sprites[150][x1] = DerivationGraph(38 * 2 + 37 * 2, 0, 36, 50, graphics[7]);
  sprites[7][x1] = DerivationGraph(33 * 6 + 1, 0, 32, 32, graphics[x1]);
  sprites[8][x1] = DerivationGraph(38 * 2 + 37 * 3, 0, 37, 47, graphics[7]);
  sprites[151][x1] = DerivationGraph(38 * 3 + 37 * 3, 0, 37, 47, graphics[7]);
  sprites[9][x1] = DerivationGraph(33 * 7 + 1, 0, 26, 30, graphics[x1]);
  sprites[10][x1] = DerivationGraph(214, 0, 46, 16, graphics[6]);

  // モララー
  sprites[30][x1] = DerivationGraph(0, 56, 30, 36, graphics[7]);
  sprites[155][x1] = DerivationGraph(31 * 3, 56, 30, 36, graphics[7]);
  sprites[31][x1] = DerivationGraph(50, 74, 49, 79, graphics[6]);

  sprites[80][x1] = DerivationGraph(151, 31, 70, 40, graphics[4]);
  sprites[81][x1] = DerivationGraph(151, 72, 70, 40, graphics[4]);
  sprites[130][x1] = DerivationGraph(151 + 71, 72, 70, 40, graphics[4]);
  sprites[82][x1] = DerivationGraph(33 * 1, 0, 30, 30, graphics[5]);
  sprites[83][x1] = DerivationGraph(0, 0, 49, 48, graphics[6]);
  sprites[84][x1] = DerivationGraph(33 * 5 + 1, 0, 30, 30, graphics[x1]);
  sprites[86][x1] = DerivationGraph(102, 66, 49, 59, graphics[6]);
  sprites[152][x1] = DerivationGraph(152, 66, 49, 59, graphics[6]);

  sprites[90][x1] = DerivationGraph(102, 0, 64, 63, graphics[6]);

  sprites[100][x1] = DerivationGraph(33 * 1, 0, 30, 30, graphics[2]);
  sprites[101][x1] = DerivationGraph(33 * 7, 0, 30, 30, graphics[2]);
  sprites[102][x1] = DerivationGraph(33 * 3, 0, 30, 30, graphics[2]);

  // sprites[104][x1] = DerivationGraph( 33*2, 0, 30, 30, graphics[5]) ;
  sprites[105][x1] = DerivationGraph(33 * 5, 0, 30, 30, graphics[2]);
  sprites[110][x1] = DerivationGraph(33 * 4, 0, 30, 30, graphics[2]);

  // 背景読み込み
  x1 = 4;
  sprites[0][x1] = DerivationGraph(0, 0, 150, 90, graphics[x1]);
  sprites[1][x1] = DerivationGraph(151, 0, 65, 29, graphics[x1]);
  sprites[2][x1] = DerivationGraph(151, 31, 70, 40, graphics[x1]);
  sprites[3][x1] = DerivationGraph(0, 91, 100, 90, graphics[x1]);
  sprites[4][x1] = DerivationGraph(151, 113, 51, 29, graphics[x1]);
  sprites[5][x1] = DerivationGraph(222, 0, 28, 60, graphics[x1]);
  sprites[6][x1] = DerivationGraph(151, 143, 90, 40, graphics[x1]);
  sprites[30][x1] = DerivationGraph(293, 0, 149, 90, graphics[x1]);
  sprites[31][x1] = DerivationGraph(293, 92, 64, 29, graphics[x1]);

  // 中間フラグ
  sprites[20][x1] = DerivationGraph(40, 182, 40, 60, graphics[x1]);

  // グラ
  x1 = 5;
  sprites[0][x1] = DerivationGraph(167, 0, 45, 45, graphics[6]);

  // 敵サイズ収得
  x1 = 3;
  for (t = 0; t <= 140; t++) {
    if (sprites[t][x1]) {
      anx[t] = sprites[t][x1]->w;
      any[t] = sprites[t][x1]->h;
      anx[t] *= 100;
      any[t] *= 100;
    } else {
      anx[t] = 0;
      any[t] = 0;
    }
  }
  anx[79] = 120 * 100;
  any[79] = 15 * 100;
  anx[85] = 25 * 100;
  any[85] = 30 * 10 * 100;

  // 背景サイズ収得
  x1 = 4;
  for (t = 0; t < 40; t++) {
    if (sprites[t][x1]) {
      ne[t] = sprites[t][x1]->w;
      nf[t] = sprites[t][x1]->h;
    } else {
      ne[t] = 0;
      nf[t] = 0;
    }
  }

  // ogg読み込み
  music[1] = LoadMusicMem("BGM/field.ogg");   // 50
  music[2] = LoadMusicMem("BGM/dungeon.ogg"); // 40
  music[3] = LoadMusicMem("BGM/star4.ogg");   // 50
  music[4] = LoadMusicMem("BGM/castle.ogg");  // 50
  music[5] = LoadMusicMem("BGM/puyo.ogg");    // 50

  sfx[1] = LoadSoundMem("SE/jump.ogg");
  sfx[3] = LoadSoundMem("SE/brockbreak.ogg");
  sfx[4] = LoadSoundMem("SE/coin.ogg");
  sfx[5] = LoadSoundMem("SE/humi.ogg");
  sfx[6] = LoadSoundMem("SE/koura.ogg");
  sfx[7] = LoadSoundMem("SE/dokan.ogg");
  sfx[8] = LoadSoundMem("SE/brockkinoko.ogg");
  sfx[9] = LoadSoundMem("SE/powerup.ogg");
  sfx[10] = LoadSoundMem("SE/kirra.ogg");
  sfx[11] = LoadSoundMem("SE/goal.ogg");
  sfx[12] = LoadSoundMem("SE/death.ogg");
  sfx[13] = LoadSoundMem("SE/Pswitch.ogg");
  sfx[14] = LoadSoundMem("SE/jumpBlock.ogg");
  sfx[15] = LoadSoundMem("SE/hintBlock.ogg");
  sfx[16] = LoadSoundMem("SE/4-clear.ogg");
  sfx[17] = LoadSoundMem("SE/allclear.ogg");
  sfx[18] = LoadSoundMem("SE/tekifire.ogg");
}

extern bool sound;
void parseArgs(int argc, char *argv[]) {
  if (argc <= 1) {
    return;
  }
  for (int i = 0; i < argc; i++) {
    if (!strcasecmp(argv[i], "-nosound")) {
      sound = false;
    }
  }
}
