// 600c1204  FUN_600c1204  size=166 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600c12b0 FUN_600c12b0


void FUN_600c1204(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_9;
  
  if (*(char *)(param_1 + 0x26) == '\0') {
    uVar1 = FUN_600c12b0(param_1 + 0x10d,param_1 + 0x14d,param_1 + 0x5d,param_1 + 0x4d,param_2);
    *(undefined4 *)(param_1 + 0x19c) = uVar1;
  }
  else {
    uVar1 = FUN_600c12b0(param_1 + 0x14d,param_1 + 0x10d,param_1 + 0x4d,param_1 + 0x5d,param_2);
    *(undefined4 *)(param_1 + 0x19c) = uVar1;
  }
  if (DAT_600c12ac < *(uint *)(param_1 + 0x19c)) {
    *(undefined1 *)(param_1 + 0x24) = 8;
    local_9 = *(undefined1 *)(param_1 + 0x24);
    FUN_600c1a34(param_1,0x17,&local_9);
  }
  else {
    *(undefined1 *)(param_1 + 0x2a) = 6;
    FUN_600c1a34(param_1,0x22,param_1 + 0x19c);
  }
  return;
}


