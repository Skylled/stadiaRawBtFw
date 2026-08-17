// 60091c10  obj__60091c10  size=102 bytes
// src: obj.c
// --- callers ---
//   600edc68 FUN_600edc68
//   600e0d54 FUN_600e0d54
//   600ecabe FUN_600ecabe
// --- callees ---
//   600e0c82 FUN_600e0c82
//   600edbf4 FUN_600edbf4
//   600e0552 FUN_600e0552
//   600e0c94 FUN_600e0c94


/* src: obj.c */

int obj__60091c10(uint param_1)

{
  int iVar1;
  undefined1 auStack_20 [8];
  uint local_18;
  
  if (param_1 < 0x3c1) {
    if ((param_1 == 0) || (*(int *)(param_1 * 0x18 + DAT_60091c78 + 8) != 0)) {
      return param_1 * 0x18 + DAT_60091c78;
    }
  }
  else {
    FUN_600e0c82(DAT_60091c7c);
    if ((*DAT_60091c80 != 0) &&
       (local_18 = param_1, iVar1 = FUN_600edbf4(*DAT_60091c80,auStack_20,DAT_60091c88,DAT_60091c84)
       , iVar1 != 0)) {
      FUN_600e0c94(DAT_60091c7c);
      return iVar1;
    }
    FUN_600e0c94(DAT_60091c7c);
  }
  FUN_600e0552(8,0,100,DAT_60091c8c,0x16b);
  return 0;
}


