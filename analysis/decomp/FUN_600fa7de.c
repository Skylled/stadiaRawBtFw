// 600fa7de  FUN_600fa7de  size=248 bytes
// --- callers ---
//   600fb43a FUN_600fb43a
//   600fb346 FUN_600fb346
//   600fac38 FUN_600fac38
//   600c04c4 FUN_600c04c4
//   600fb4d0 FUN_600fb4d0
//   600fad26 FUN_600fad26
//   600facc4 FUN_600facc4
// --- callees ---


void FUN_600fa7de(int param_1,byte param_2,char param_3)

{
  if ((*(char *)(param_1 + 0x195) == '\0') || ((param_2 != 1 && (param_2 != 8)))) {
    if (*(char *)(param_1 + 0x26) == '\x01') {
      if (param_3 == '\0') {
        *(byte *)(param_1 + 0x1b5) = ~param_2 & *(byte *)(param_1 + 0x1b5);
      }
      else {
        *(byte *)(param_1 + 0x1b4) = ~param_2 & *(byte *)(param_1 + 0x1b4);
      }
    }
    else if (param_3 == '\0') {
      *(byte *)(param_1 + 0x1b4) = ~param_2 & *(byte *)(param_1 + 0x1b4);
    }
    else {
      *(byte *)(param_1 + 0x1b5) = ~param_2 & *(byte *)(param_1 + 0x1b5);
    }
  }
  else {
    *(byte *)(param_1 + 0x1b4) = ~param_2 & *(byte *)(param_1 + 0x1b4);
    *(byte *)(param_1 + 0x1b5) = ~param_2 & *(byte *)(param_1 + 0x1b5);
  }
  return;
}


