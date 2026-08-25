// 600fb8c4  FUN_600fb8c4  size=118 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600fab3e FUN_600fab3e
//   600c19f4 FUN_600c19f4
//   600c1b74 FUN_600c1b74
//   600fcbfa FUN_600fcbfa


void FUN_600fb8c4(int param_1)

{
  undefined1 uVar1;
  undefined1 local_9;
  
  local_9 = 3;
  if ((*(ushort *)(param_1 + 0x28) & 1) == 0) {
    uVar1 = FUN_600fcbfa(param_1);
    *(undefined1 *)(param_1 + 0x194) = uVar1;
    if ((*(char *)(param_1 + 0x193) == '\0') ||
       ((*(char *)(param_1 + 0x195) != '\0' && (*(char *)(param_1 + 0x194) != '\x04')))) {
      FUN_600fab3e(param_1,0);
    }
    else {
      FUN_600c1a34(param_1,0x17,&local_9);
    }
  }
  else {
    FUN_600c19f4(2);
    FUN_600c1b74(0xb,param_1);
  }
  return;
}


