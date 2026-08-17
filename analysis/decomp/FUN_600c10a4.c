// 600c10a4  FUN_600c10a4  size=156 bytes
// --- callers ---
//   600c01b8 FUN_600c01b8
// --- callees ---
//   600fc542 FUN_600fc542
//   600fcc88 FUN_600fcc88


void FUN_600c10a4(int param_1)

{
  undefined1 uVar1;
  
  switch(*(undefined1 *)(param_1 + 0x194)) {
  case 4:
  case 5:
    FUN_600fc542(param_1 + 0x10d,param_1 + 0x14d,param_1 + 0x5d,0,param_1 + 0xad);
    break;
  case 6:
  case 7:
    uVar1 = FUN_600fcc88(param_1 + 0xcd,*(undefined1 *)(param_1 + 0x199));
    FUN_600fc542(param_1 + 0x10d,param_1 + 0x14d,param_1 + 0x5d,uVar1,param_1 + 0xad);
    break;
  case 8:
    FUN_600fc542(param_1 + 0x10d,param_1 + 0x10d,param_1 + 0xcd,0,param_1 + 0xad);
  }
  return;
}


