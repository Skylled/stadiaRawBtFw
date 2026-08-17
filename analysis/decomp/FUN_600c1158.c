// 600c1158  FUN_600c1158  size=80 bytes
// --- callers ---
//   600c25ac FUN_600c25ac
// --- callees ---
//   600fc542 FUN_600fc542
//   600fcc88 FUN_600fcc88


void FUN_600c1158(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  switch(*(undefined1 *)(param_1 + 0x194)) {
  case 4:
  case 5:
    FUN_600fc542(param_1 + 0x14d,param_1 + 0x10d,param_1 + 0x4d,0,param_2);
    break;
  case 6:
  case 7:
    uVar1 = FUN_600fcc88(param_1 + 0xdd,*(undefined1 *)(param_1 + 0x199));
    FUN_600fc542(param_1 + 0x14d,param_1 + 0x10d,param_1 + 0x4d,uVar1,param_2);
    break;
  case 8:
    FUN_600fc542(param_1 + 0x14d,param_1 + 0x14d,param_1 + 0xdd,0,param_2);
  }
  return;
}


