// 600ff986  FUN_600ff986  size=120 bytes
// --- callers ---
//   600ffa34 FUN_600ffa34
//   600ff9fe FUN_600ff9fe
//   600f4d8e FUN_600f4d8e
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   600f7b26 FUN_600f7b26
//   600b5264 FUN_600b5264


undefined4 FUN_600ff986(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 local_a;
  
  if (*(char *)(param_1 + 0xfc) == '\0') {
    if (*(short *)(param_1 + 0x18) == 4) {
      local_a = FUN_600b5264(4,param_1 + 0xd,param_2);
    }
    else {
      local_a = FUN_600f7b26(*(undefined2 *)(param_1 + 0x18),param_2);
    }
    if (local_a == 0) {
      uVar1 = 0x81;
    }
    else if (local_a == 2) {
      *(undefined1 *)(param_1 + 0xfc) = 1;
      uVar1 = 0x8f;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    FUN_6006dfa4(param_1 + 0x100,param_2);
    uVar1 = 0x8f;
  }
  return uVar1;
}


