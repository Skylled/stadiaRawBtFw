// 600f1800  FUN_600f1800  size=84 bytes
// --- callers ---
//   600c33f0 FUN_600c33f0
//   600a44bc FUN_600a44bc
//   600c424c FUN_600c424c
//   600a59d0 FUN_600a59d0
//   600a6d70 FUN_600a6d70
//   600c4808 FUN_600c4808
//   600c4570 FUN_600c4570
//   600fd1b2 FUN_600fd1b2
// --- callees ---
//   6009de30 FUN_6009de30
//   600a26ec FUN_600a26ec
//   600a3014 FUN_600a3014


undefined4 FUN_600f1800(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = FUN_600a26ec(param_1);
  if (iVar1 != 0) {
    local_c = iVar1 + 8;
  }
  if (param_3 == '\x02') {
    uVar2 = FUN_6009de30(param_1,local_c,param_2);
  }
  else {
    uVar2 = FUN_600a3014(param_1,local_c,1,0x28,param_2);
  }
  return uVar2;
}


