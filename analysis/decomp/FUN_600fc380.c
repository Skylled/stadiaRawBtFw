// 600fc380  FUN_600fc380  size=90 bytes
// --- callers ---
//   600c15a8 FUN_600c15a8
// --- callees ---
//   6009abd4 FUN_6009abd4
//   600fbc02 FUN_600fbc02
//   600c1a34 FUN_600c1a34
//   600fc3da FUN_600fc3da


void FUN_600fc380(int param_1)

{
  int iVar1;
  undefined1 local_2d;
  undefined1 auStack_2c [20];
  undefined1 auStack_18 [16];
  
  local_2d = 8;
  FUN_6009abd4(auStack_18);
  iVar1 = FUN_600fbc02(auStack_18,0x10,param_1 + 0x1ea,8,auStack_2c);
  if (iVar1 == 0) {
    FUN_600c1a34(param_1,0x17,&local_2d);
  }
  else {
    FUN_600fc3da(param_1,auStack_2c);
  }
  return;
}


