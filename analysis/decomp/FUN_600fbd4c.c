// 600fbd4c  FUN_600fbd4c  size=132 bytes
// --- callers ---
// --- callees ---
//   600fc438 FUN_600fc438
//   600fc9c4 FUN_600fc9c4
//   600c1a34 FUN_600c1a34
//   600fc2c6 FUN_600fc2c6
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fbd4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  undefined1 auStack_18 [16];
  
  local_1d = 8;
  if (*(char *)(param_1 + 0x195) == '\0') {
    iVar1 = FUN_600fc438(param_1,&local_1c,param_3,&local_1c,param_2);
    if (iVar1 == 0) {
      FUN_600c1a34(param_1,0x17,&local_1d);
      return;
    }
  }
  else {
    local_1b = 0x10;
    local_1c = 0;
    local_1a = 0x2017;
    FUN_600fc9c4(*(undefined1 *)(param_1 + 0x1b1),param_1 + 0x1c6);
    thunk_EXT_FUN_0000b572(auStack_18,param_1 + 0x1c6,0x10);
  }
  FUN_600fc2c6(param_1,&local_1c);
  return;
}


