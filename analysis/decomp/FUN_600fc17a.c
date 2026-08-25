// 600fc17a  FUN_600fc17a  size=140 bytes
// --- callers ---
//   600fc110 FUN_600fc110
// --- callees ---
//   600fc04a FUN_600fc04a
//   600fc9fc FUN_600fc9fc
//   600fbc02 FUN_600fbc02
//   600fc29c FUN_600fc29c
//   600fc260 FUN_600fc260
//   600c1a34 FUN_600c1a34


void FUN_600fc17a(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_2d;
  undefined1 auStack_2c [20];
  undefined1 auStack_18 [16];
  
  local_2d = 8;
  FUN_600fc04a(param_1,auStack_18);
  FUN_600fc9fc(auStack_18,param_2 + 4);
  iVar1 = FUN_600fbc02(param_1 + 0x1b6,0x10,auStack_18,0x10,auStack_2c);
  if (iVar1 == 0) {
    FUN_600c1a34(param_1,0x17,&local_2d);
  }
  else if (*(char *)(param_1 + 0x1f2) == '\x01') {
    FUN_600fc29c(param_1,auStack_2c);
  }
  else if (*(char *)(param_1 + 0x1f2) == '\x02') {
    FUN_600fc260(param_1,auStack_2c);
  }
  return;
}


