// 600fc110  FUN_600fc110  size=106 bytes
// --- callers ---
//   600fc232 FUN_600fc232
//   600fc206 FUN_600fc206
// --- callees ---
//   600fbf8a FUN_600fbf8a
//   600fc9fc FUN_600fc9fc
//   600fbc02 FUN_600fbc02
//   600fc17a FUN_600fc17a
//   600c1a34 FUN_600c1a34


void FUN_600fc110(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_2d;
  undefined1 auStack_2c [20];
  undefined1 auStack_18 [16];
  
  local_2d = 8;
  FUN_600fbf8a(param_1,auStack_18);
  FUN_600fc9fc(auStack_18,param_2);
  iVar1 = FUN_600fbc02(param_1 + 0x1b6,0x10,auStack_18,0x10,auStack_2c);
  if (iVar1 == 0) {
    FUN_600c1a34(param_1,0x17,&local_2d);
  }
  else {
    FUN_600fc17a(param_1,auStack_2c);
  }
  return;
}


