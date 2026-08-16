// 600765a4  FUN_600765a4  size=908 bytes
// --- callers ---
//   600769ec FUN_600769ec
// --- callees ---
//   600c9d44 event_groups__600c9d44
//   601017fc FUN_601017fc
//   600c9de4 queue__600c9de4
//   60084ad4 FUN_60084ad4
//   60084adc FUN_60084adc
//   60084aec FUN_60084aec
//   60084b3c FUN_60084b3c
//   60084b1c FUN_60084b1c
//   600511c8 timer__600511c8
//   60084b0c FUN_60084b0c
//   60084b14 FUN_60084b14
//   60076438 input_task__60076438
//   60084ae4 FUN_60084ae4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60084acc FUN_60084acc
//   60084afc FUN_60084afc
//   60084b34 FUN_60084b34
//   60084b2c FUN_60084b2c
//   60084b4c FUN_60084b4c
//   60084b24 FUN_60084b24
//   601017e8 FUN_601017e8
//   60084b04 FUN_60084b04
//   60084af4 FUN_60084af4
//   60084b44 FUN_60084b44


int * FUN_600765a4(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = DAT_60076930;
  param_1[0x15] = 0;
  FUN_601017fc();
  iVar2 = DAT_60076934;
  param_1[0x1c] = 0;
  param_1[0x18] = iVar2 + 0x20;
  param_1[0x19] = 0;
  iVar1 = DAT_60076938;
  *param_1 = iVar2 + 8;
  param_1[0x1d] = iVar1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x1f,0,0x20);
  iVar2 = event_groups__600c9d44();
  param_1[0x1e] = iVar2;
  iVar2 = queue__600c9de4(0x10,0xc,param_1 + 0x3c,param_1 + 0x27,0);
  param_1[0x80] = 0;
  param_1[0x3b] = iVar2;
  FUN_601017e8(param_1 + 0x6c);
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  *(undefined1 *)(param_1 + 0x84) = 0;
  *(undefined1 *)((int)param_1 + 0x211) = 0;
  param_1[0x89] = 0x800;
  param_1[0x8a] = 0x800;
  param_1[0x8b] = 0x800;
  param_1[0x8c] = 0x800;
  *(undefined1 *)((int)param_1 + 0x212) = 0;
  *(undefined1 *)((int)param_1 + 0x213) = 0;
  *(undefined1 *)(param_1 + 0x85) = 0;
  *(undefined1 *)((int)param_1 + 0x215) = 0;
  *(undefined1 *)((int)param_1 + 0x216) = 0;
  *(undefined1 *)((int)param_1 + 0x217) = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  *(undefined1 *)((int)param_1 + 0x219) = 0;
  *(undefined1 *)((int)param_1 + 0x21a) = 0;
  *(undefined1 *)((int)param_1 + 0x21b) = 0;
  *(undefined1 *)(param_1 + 0x87) = 0;
  *(undefined1 *)((int)param_1 + 0x21d) = 0;
  *(undefined1 *)((int)param_1 + 0x21e) = 0;
  *(undefined1 *)((int)param_1 + 0x21f) = 0;
  *(undefined1 *)(param_1 + 0x88) = 0;
  *(undefined1 *)((int)param_1 + 0x221) = 0;
  *(undefined1 *)((int)param_1 + 0x222) = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  *(undefined1 *)(param_1 + 0x8f) = 0;
  *(undefined1 *)((int)param_1 + 0x23d) = 0;
  *(undefined1 *)((int)param_1 + 0x23e) = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  *(undefined1 *)(param_1 + 0x92) = 0;
  iVar2 = FUN_60084acc();
  param_1[0x93] = iVar2;
  *(undefined1 *)(param_1 + 0x94) = 0;
  param_1[0x95] = 0;
  param_1[0x96] = param_1[0x1d] + 8;
  param_1[0x97] = (int)(param_1 + 0x84);
  iVar2 = FUN_60084afc();
  param_1[0x98] = iVar2;
  *(undefined1 *)(param_1 + 0x99) = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = param_1[0x1d] + 9;
  param_1[0x9c] = (int)param_1 + 0x211;
  iVar2 = FUN_60084ad4();
  param_1[0x9d] = iVar2;
  *(undefined1 *)(param_1 + 0x9e) = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = param_1[0x1d] + 10;
  param_1[0xa1] = (int)param_1 + 0x212;
  iVar2 = FUN_60084adc();
  param_1[0xa2] = iVar2;
  *(undefined1 *)(param_1 + 0xa3) = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = param_1[0x1d] + 0xb;
  param_1[0xa6] = (int)param_1 + 0x213;
  iVar2 = FUN_60084b04();
  param_1[0xa7] = iVar2;
  *(undefined1 *)(param_1 + 0xa8) = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = param_1[0x1d] + 0x10;
  param_1[0xab] = (int)(param_1 + 0x86);
  iVar2 = FUN_60084b0c();
  param_1[0xac] = iVar2;
  *(undefined1 *)(param_1 + 0xad) = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = param_1[0x1d] + 0x11;
  param_1[0xb0] = (int)param_1 + 0x219;
  iVar2 = FUN_60084ae4();
  param_1[0xb1] = iVar2;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = param_1[0x1d] + 0x16;
  param_1[0xb5] = (int)param_1 + 0x21e;
  iVar2 = FUN_60084b14();
  param_1[0xb6] = iVar2;
  *(undefined1 *)(param_1 + 0xb7) = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = param_1[0x1d] + 0x17;
  param_1[0xba] = (int)param_1 + 0x21f;
  iVar2 = FUN_60084b1c();
  param_1[0xbb] = iVar2;
  *(undefined1 *)(param_1 + 0xbc) = 0;
  param_1[0xbd] = 0;
  param_1[0xbe] = param_1[0x1d] + 0xc;
  param_1[0xbf] = (int)(param_1 + 0x85);
  iVar2 = FUN_60084b24();
  param_1[0xc0] = iVar2;
  *(undefined1 *)(param_1 + 0xc1) = 0;
  param_1[0xc2] = 0;
  param_1[0xc3] = param_1[0x1d] + 0xd;
  param_1[0xc4] = (int)param_1 + 0x215;
  iVar2 = FUN_60084b2c();
  param_1[0xc5] = iVar2;
  *(undefined1 *)(param_1 + 0xc6) = 0;
  param_1[199] = 0;
  param_1[200] = param_1[0x1d] + 0xe;
  param_1[0xc9] = (int)param_1 + 0x216;
  iVar2 = FUN_60084b34();
  param_1[0xca] = iVar2;
  *(undefined1 *)(param_1 + 0xcb) = 0;
  param_1[0xcc] = 0;
  param_1[0xcd] = param_1[0x1d] + 0xf;
  param_1[0xce] = (int)param_1 + 0x217;
  iVar2 = FUN_60084aec();
  param_1[0xcf] = iVar2;
  *(undefined1 *)(param_1 + 0xd0) = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = param_1[0x1d] + 0x18;
  param_1[0xd3] = (int)(param_1 + 0x88);
  iVar2 = FUN_60084b3c();
  param_1[0xd4] = iVar2;
  *(undefined1 *)(param_1 + 0xd5) = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = param_1[0x1d] + 0x19;
  param_1[0xd8] = (int)param_1 + 0x221;
  iVar2 = FUN_60084af4();
  param_1[0xd9] = iVar2;
  *(undefined1 *)(param_1 + 0xda) = 0;
  param_1[0xdb] = 0;
  param_1[0xdc] = param_1[0x1d] + 0x1a;
  param_1[0xdd] = (int)param_1 + 0x222;
  iVar2 = FUN_60084b44();
  param_1[0xde] = iVar2;
  *(undefined1 *)(param_1 + 0xdf) = 0;
  param_1[0xe0] = 0;
  param_1[0xe1] = param_1[0x1d] + 0x14;
  param_1[0xe2] = (int)(param_1 + 0x87);
  iVar2 = FUN_60084b4c();
  param_1[0xe3] = iVar2;
  *(undefined1 *)(param_1 + 0xe4) = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = param_1[0x1d] + 0x15;
  param_1[0xe7] = (int)param_1 + 0x21d;
  timer__600511c8(param_1 + 0xe8,DAT_60076940,4,DAT_60076944,DAT_6007693c,1,0);
  param_1[0xf8] = 0;
  param_1[0xfe] = 0x14;
  iVar2 = DAT_60076948;
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  param_1[0xfb] = 0;
  *(undefined1 *)(param_1 + 0xfc) = 0;
  param_1[0xfd] = 0;
  param_1[0xff] = 0;
  param_1[0x100] = 0;
  param_1[0x101] = 0;
  param_1[0x102] = 0;
  param_1[0x103] = 0;
  *(undefined1 *)(param_1 + 0x104) = 0;
  *(undefined1 *)((int)param_1 + 0x411) = 1;
  *(undefined1 *)((int)param_1 + 0x412) = 0;
  *(undefined1 *)((int)param_1 + 0x413) = 0;
  *(undefined1 *)(param_1 + 0x105) = 0;
  *(undefined1 *)((int)param_1 + 0x415) = 0;
  param_1[0x106] = iVar2;
  param_1[0x107] = 0;
  input_task__60076438(param_1,0x10);
  return param_1;
}


