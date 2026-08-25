// 600fb848  FUN_600fb848  size=124 bytes
// --- callers ---
//   600fb346 FUN_600fb346
//   600c04c4 FUN_600c04c4
//   600facc4 FUN_600facc4
//   600fac38 FUN_600fac38
//   600fad26 FUN_600fad26
//   600fb43a FUN_600fb43a
//   600fb3fe FUN_600fb3fe
//   600fb4d0 FUN_600fb4d0
//   600fb30a FUN_600fb30a
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600c1a1c FUN_600c1a1c
//   600bff84 FUN_600bff84


void FUN_600fb848(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  if ((*(char *)(param_1 + 0x26) == '\x01') ||
     ((*(char *)(param_1 + 0x1b5) == '\0' && (*(char *)(param_1 + 0x26) == '\0')))) {
    FUN_600bff84(param_1,param_2);
  }
  if (((*(char *)(param_1 + 0x1b4) == '\0') && (*(char *)(param_1 + 0x1b5) == '\0')) &&
     (iVar1 = FUN_600c1a1c(), iVar1 == 0xf)) {
    if (*(short *)(param_1 + 0x1fe) == 0) {
      FUN_600c1a34(param_1,0x17,&local_9);
    }
    else {
      *(undefined1 *)(param_1 + 0x200) = 1;
    }
  }
  return;
}


