// 600a0cac  FUN_600a0cac  size=180 bytes
// --- callers ---
//   600a109c FUN_600a109c
//   600a1038 FUN_600a1038
//   600f1786 FUN_600f1786
//   600a0fd4 FUN_600a0fd4
//   600a0e88 FUN_600a0e88
// --- callees ---
//   600b1640 FUN_600b1640
//   600a020c FUN_600a020c
//   600a031c FUN_600a031c
//   600b3c00 FUN_600b3c00
//   600b4dcc FUN_600b4dcc
//   600a0bc4 FUN_600a0bc4


void FUN_600a0cac(void)

{
  if ((*(byte *)(DAT_600a0d60 + 0x88e) & 2) == 0) {
    if ((*(byte *)(DAT_600a0d60 + 0x88e) & 4) == 0) {
      if ((*(byte *)(DAT_600a0d60 + 0x88e) & 0x20) == 0) {
        if ((*(byte *)(DAT_600a0d60 + 0x88e) & 1) == 0) {
          if (*(char *)(DAT_600a0d60 + 0x88e) == '\0') {
            if ((*(byte *)(DAT_600a0d60 + 0x81b) & 2) == 0) {
              if (*(int *)(DAT_600a0d64 + 0xd4) == 0) {
                FUN_600a0bc4();
              }
              else {
                (**(code **)(DAT_600a0d64 + 0xd4))(2,0);
              }
            }
            else {
              FUN_600a020c();
            }
          }
        }
        else {
          FUN_600a031c(1);
        }
      }
      else {
        FUN_600b4dcc(1);
      }
    }
    else if ((*(byte *)(DAT_600a0d60 + 0x88e) & 8) == 0) {
      FUN_600b1640(1,0);
    }
    else {
      FUN_600b1640(1,1);
    }
  }
  else {
    FUN_600b3c00(1);
  }
  return;
}


