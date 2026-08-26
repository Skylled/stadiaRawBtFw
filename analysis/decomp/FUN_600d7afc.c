// 600d7afc  FUN_600d7afc  size=24 bytes
// --- callers ---
//   600d7b14 FUN_600d7b14
// --- callees ---
//   600d7ad6 FUN_600d7ad6


undefined4 FUN_600d7afc(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    FUN_600d7ad6(param_1 + 0x14);
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


